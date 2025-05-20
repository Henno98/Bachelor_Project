// Fill out your copyright notice in the Description page of Project Settings.


#include "World/Plagued_Knight_GameMode.h"

#include "GameFramework/SaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "Player/SaveState.h"
// Define static variables
float APlagued_Knight_GameMode::AutoSaveTimer = 0.0f;
float APlagued_Knight_GameMode::GameTime = 0.0f;


APlagued_Knight_GameMode::APlagued_Knight_GameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	
}

void APlagued_Knight_GameMode::BeginPlay()
{
	Super::BeginPlay();

	FString SlotName = "Main_Save";
	int32 UserIndex = 0;

	if (!UGameplayStatics::DoesSaveGameExist(SlotName, UserIndex))
	{
		USaveState::SaveGame(GetWorld(), SlotName, UserIndex);
	}
}

void APlagued_Knight_GameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Autosave timer using static float
	GameTime += DeltaSeconds;
	AutoSaveTimer += DeltaSeconds;

	float AutosaveInterval = 60.f;
	if (AutoSaveTimer >= AutosaveInterval)
	{
		// Call your autosave logic here
		UE_LOG(LogTemp, Log, TEXT("Autosave triggered."));

		// Example: UGameplayStatics::SaveGameToSlot(...);
		USaveState::SaveGame(GetWorld(), "Auto_Save", 2);
		// Reset timer
		AutoSaveTimer = 0.0f;

	}
}
