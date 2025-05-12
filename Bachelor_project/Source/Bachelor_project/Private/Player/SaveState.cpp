// Fill out your copyright notice in the Description page of Project Settings.



#include "Player/SaveState.h"

#include "Plagued_Knight_GameInstance.h"
#include "Enemies/EnemyInterface.h"
#include "Kismet/GameplayStatics.h"
#include "World/Plagued_Knight_GameMode.h"

USaveState::USaveState()
{
	SaveSlotName = TEXT("TestSaveSlot");
	UserIndex = 0;

}


bool USaveState::SaveGame(UWorld* World, FString SlotName, int32 SlotNumber)
{
    if (!ensure(World))
    {
        UE_LOG(LogTemp, Error, TEXT("SaveGame failed: World is null."));
        return false;
    }

    ATest_Character* Character = Cast<ATest_Character>(UGameplayStatics::GetPlayerCharacter(World, 0));
    if (!ensure(Character))
    {
        UE_LOG(LogTemp, Warning, TEXT("SaveGame failed: Player character not found."));
        return false;
    }
    USaveState* SaveGameInstance = nullptr;

    if (UGameplayStatics::DoesSaveGameExist(SlotName, SlotNumber))
    {
        SaveGameInstance = Cast<USaveState>(UGameplayStatics::LoadGameFromSlot(SlotName, SlotNumber));
        if (!ensure(SaveGameInstance))
        {
            UE_LOG(LogTemp, Error, TEXT("SaveGame failed: Could not load existing save game."));
            return false;
        }
    }
    else
    {
        SaveGameInstance = Cast<USaveState>(UGameplayStatics::CreateSaveGameObject(USaveState::StaticClass()));
        if (!ensure(SaveGameInstance))
        {
            UE_LOG(LogTemp, Error, TEXT("SaveGame failed: Could not create new save game instance."));
            return false;
        }
    }
    UPlagued_Knight_GameInstance* GameInstance = Cast<UPlagued_Knight_GameInstance>(UGameplayStatics::GetGameInstance(World));
    if (GameInstance)
    {
        for (const TPair<int32, AVoice_Recorder*>& Pair : GameInstance->GetRecorderInventory())
        {
            SaveGameInstance->SavedRecorderIDs.Add(Pair.Key);
        }
    }
    // Save player-related data
    SaveGameInstance->PlayerName = TEXT("PlayerOne");
    SaveGameInstance->PlayerLocation = Character->GetActorLocation();
    SaveGameInstance->Health = Character->GetHealth();
    SaveGameInstance->BioMass = Character->GetBioMass();
    SaveGameInstance->GameTime = APlagued_Knight_GameMode::GetGameTime();
    // Save level info
    ULevel* CurrentLevel = World->GetCurrentLevel();
    SaveGameInstance->LastPlayedLevel = CurrentLevel ? CurrentLevel->GetFName() : NAME_None;
    SaveGameInstance->EnemiesInLevel = SaveEnemies(World);

    // Final save
    if (UGameplayStatics::SaveGameToSlot(SaveGameInstance, SlotName, SlotNumber))
    {
        UE_LOG(LogTemp, Log, TEXT("Game saved successfully to slot: %s (%d)"), *SlotName, SlotNumber);
        return true;
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("SaveGame failed: SaveGameToSlot returned false."));
        return false;
    }
}
bool USaveState::LoadGame(UWorld* World, FString SlotName, int32 SlotNumber)
{
    if (!World) return false;

    // Get the player character
    ATest_Character* Character = Cast<ATest_Character>(UGameplayStatics::GetPlayerCharacter(World, 0));
    if (!Character)
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to find player character for loading!"));
        return false;
    }

    if (!UGameplayStatics::DoesSaveGameExist(SlotName, SlotNumber))
    {
        UE_LOG(LogTemp, Warning, TEXT("No save game found in slot: %s (%d)"), *SlotName, SlotNumber);
        return false;
    }

    USaveState* LoadedGame = Cast<USaveState>(UGameplayStatics::LoadGameFromSlot(SlotName, SlotNumber));
    if (!LoadedGame)
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to cast loaded game!"));
        return false;
    }


    UPlagued_Knight_GameInstance* GameInstance = Cast<UPlagued_Knight_GameInstance>(UGameplayStatics::GetGameInstance(World));
    if (!GameInstance)
    {
        UE_LOG(LogTemp, Warning, TEXT("No valid GameInstance found."));
        return false;
    }
    GameInstance->StoreSavedData(LoadedGame->PlayerLocation, LoadedGame->Health, LoadedGame->BioMass, LoadedGame->LastPlayedLevel);
    FName LevelToLoad = GameInstance->GetTargetLevel();

    FLatentActionInfo LatentInfo;
    LatentInfo.CallbackTarget = Character; // Or the character
    LatentInfo.ExecutionFunction = "OnSublevelLoaded";
    LatentInfo.Linkage = 0;
    LatentInfo.UUID = __LINE__; // Unique ID per call

    UGameplayStatics::LoadStreamLevel(World, LevelToLoad, true, false, LatentInfo);

    if (GameInstance && LoadedGame)
    {

        for (int32 ID : LoadedGame->SavedRecorderIDs)
        {
            AVoice_Recorder* Recorder = GameInstance->FindRecorderByID(ID); // Custom method using TActorIterator or similar
            if (Recorder)
            {if (!GameInstance->HasRecorder(ID))
                GameInstance->AddRecorder(ID, Recorder);
            }
        }
    }
    /*for (const FEnemySaveData& EnemyData : LoadedGame->EnemiesInLevel)
    {
        TSoftClassPtr<AActor> SoftClass(EnemyData.EnemyClassPath);
        UClass* EnemyClass = SoftClass.LoadSynchronous();
        if (!EnemyClass)
        {
            UE_LOG(LogTemp, Warning, TEXT("Failed to load class at path: %s"), *EnemyData.EnemyClassPath);
            continue;
        }

        FActorSpawnParameters SpawnParams;
        AActor* SpawnedEnemy = World->SpawnActor<AActor>(EnemyClass, EnemyData.Location, EnemyData.Rotation, SpawnParams);

        if (SpawnedEnemy && SpawnedEnemy->GetClass()->ImplementsInterface(UEnemyInterface::StaticClass()))
        {
            IEnemyInterface* EnemyInterface = Cast<IEnemyInterface>(SpawnedEnemy);
            if (EnemyInterface)
            {
                EnemyInterface->SetHealth(EnemyData.Health);
                EnemyInterface->SetDamage(EnemyData.Damage);

            }
        }if (!SpawnedEnemy)
        {
            UE_LOG(LogTemp, Warning, TEXT("Failed to spawn enemy of class: %s"), *EnemyClass->GetName());
        }
    }*/
    UE_LOG(LogTemp, Log, TEXT("Started async level load: %s"), *LoadedGame->LastPlayedLevel.ToString());
    return true;
}

TArray<FEnemySaveData> USaveState::SaveEnemies(UWorld* World)
{
    TArray<AActor*> EnemyActors;
    UGameplayStatics::GetAllActorsWithInterface(World, UEnemyInterface::StaticClass(), EnemyActors);

    TArray<FEnemySaveData> Enemies;

    for (AActor* Enemy : EnemyActors)
    {
        if (!IsValid(Enemy)) continue;

        IEnemyInterface* EnemyInterface = Cast<IEnemyInterface>(Enemy);
        if (!EnemyInterface || !Enemy->Implements<UEnemyInterface>()) continue;

        FEnemySaveData EnemyData;
        EnemyData.Location = Enemy->GetActorLocation();
        EnemyData.Rotation = Enemy->GetActorRotation();
        EnemyData.Health = EnemyInterface->GetHealth();
        EnemyData.Damage = EnemyInterface->GetDamage();
        EnemyData.EnemyClassPath = Enemy->GetClass()->GetPathName();

        Enemies.Emplace(EnemyData);
    }

    return Enemies;
}
