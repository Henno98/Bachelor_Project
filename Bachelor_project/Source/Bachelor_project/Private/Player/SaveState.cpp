// Fill out your copyright notice in the Description page of Project Settings.



#include "Player/SaveState.h"

#include "Kismet/GameplayStatics.h"

USaveState::USaveState()
{
	SaveSlotName = TEXT("TestSaveSlot");
	UserIndex = 0;

}

bool USaveState::SaveGame(UWorld* World, FString SlotName, int32 SlotNumber)
{
	// Get the player character from the world
	ATest_Character* Character = Cast<ATest_Character>(UGameplayStatics::GetPlayerCharacter(World, 0));
	if (!Character)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to find player character for saving!"));
		return false;
	}

	// Create a save game instance
	USaveState* SaveGameInstance = Cast<USaveState>(UGameplayStatics::CreateSaveGameObject(USaveState::StaticClass()));
	if (SaveGameInstance)
	{
		SaveGameInstance->PlayerName = TEXT("PlayerOne");
		SaveGameInstance->PlayerLocation = Character->GetActorLocation();
		SaveGameInstance->Health = Character->GetHealth();
		SaveGameInstance->BioMass = Character->GetBioMass();

		// Get the current level name and save it
		SaveGameInstance->CurrentLevel = World->GetMapName();  // Get current level name

		// Save the game to the slot
		if (UGameplayStatics::SaveGameToSlot(SaveGameInstance, SlotName, SlotNumber))
		{
			UE_LOG(LogTemp, Log, TEXT("Game saved successfully to slot: %s (%d)"), *SlotName, SlotNumber);
			return true;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Failed to save game to slot: %s (%d)"), *SlotName, SlotNumber);
	return false;
}

bool USaveState::LoadGame(UWorld* World, FString SlotName, int32 SlotNumber)
{
	// Get the player character from the world
	ATest_Character* Character = Cast<ATest_Character>(UGameplayStatics::GetPlayerCharacter(World, 0));
	if (!Character)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to find player character for loading!"));
		return false;
	}

	// Check if a save game exists in the slot
	if (UGameplayStatics::DoesSaveGameExist(SlotName, SlotNumber))
	{
		USaveState* LoadedGame = Cast<USaveState>(UGameplayStatics::LoadGameFromSlot(SlotName, SlotNumber));
		if (LoadedGame)
		{
			
			//// Load the saved level (if needed)
			//FString LevelName = LoadedGame->CurrentLevel;
			//if (!LevelName.IsEmpty())
			//{
			//	UGameplayStatics::OpenLevel(World, FName(*LevelName));
			//}


			//if (World->GetCurrentLevel()->GetName() == FName(*LevelName)) {
			//	
				if (World->GetBegunPlay())
				{// Apply the loaded data
					Character->SetActorEnableCollision(true);
					Character->SetActorHiddenInGame(false);
					Character->SetActorLocation(LoadedGame->PlayerLocation);
					Character->SetHealth(LoadedGame->Health);
					Character->SetBioMass(LoadedGame->BioMass);

					Character->OnHealthChanged.Broadcast(LoadedGame->Health);
					Character->OnEnergyChanged.Broadcast(LoadedGame->BioMass);

					APlayerController* PC = UGameplayStatics::GetPlayerController(World, 0);
					PC->SetPause(false);
					Character->ToggleMenu();
					UE_LOG(LogTemp, Log, TEXT("Level is loaded!"));
				}
				else
				{
					FTimerHandle LoadDelay;
					World->GetTimerManager().ClearTimer(LoadDelay);
					World->GetTimerManager().SetTimer(LoadDelay, FTimerDelegate::CreateLambda([Character, LoadedGame]()
						{
							Character->SetActorEnableCollision(true);
							Character->SetActorHiddenInGame(false);
							Character->SetActorLocation(LoadedGame->PlayerLocation);
							Character->SetHealth(LoadedGame->Health);
							Character->SetBioMass(LoadedGame->BioMass);

							Character->OnHealthChanged.Broadcast(LoadedGame->Health);
							Character->OnEnergyChanged.Broadcast(LoadedGame->BioMass);
							Character->ToggleMenu();

						}), 3.f, false);
					UE_LOG(LogTemp, Log, TEXT("Level is not loaded delaying"));
				}

			//}
			UE_LOG(LogTemp, Log, TEXT("Game loaded successfully from slot: %s (%d)"), *SlotName, SlotNumber);
			return true;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("No save game found in slot: %s (%d)"), *SlotName, SlotNumber);
	return false;
}
