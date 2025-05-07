// Fill out your copyright notice in the Description page of Project Settings.



#include "Player/SaveState.h"

#include "Plagued_Knight_GameInstance.h"
#include "Kismet/GameplayStatics.h"

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

    USaveState* SaveGameInstance = Cast<USaveState>(UGameplayStatics::CreateSaveGameObject(USaveState::StaticClass()));
    if (!ensure(SaveGameInstance))
    {
        UE_LOG(LogTemp, Error, TEXT("SaveGame failed: Could not create save game instance."));
        return false;
    }

    // Save player-related data
    SaveGameInstance->PlayerName = TEXT("PlayerOne");
    SaveGameInstance->PlayerLocation = Character->GetActorLocation();
    SaveGameInstance->Health = Character->GetHealth();
    SaveGameInstance->BioMass = Character->GetBioMass();

    // Save level name (from level streaming or manually tracked)
    ULevel* CurrentLevel = World->GetCurrentLevel();
    SaveGameInstance->LastPlayedLevel = CurrentLevel ? CurrentLevel->GetFName() : NAME_None;

    // Final save
    if (UGameplayStatics::SaveGameToSlot(SaveGameInstance, SlotName, SlotNumber))
    {
        UE_LOG(LogTemp, Log, TEXT("Game saved successfully to slot: %s (%d)"), *SlotName, SlotNumber);
        return true;
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("SaveGame failed: SaveGameToSlot returned false."));
    }


  


    return false;
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

    UE_LOG(LogTemp, Log, TEXT("Started async level load: %s"), *LoadedGame->LastPlayedLevel.ToString());
    return true;
}
