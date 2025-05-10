// Fill out your copyright notice in the Description page of Project Settings.


#include "World/Plagued_Knight_GameMode.h"

#include "GameFramework/SaveGame.h"
#include "Player/SaveState.h"
// Define static variables
float APlagued_Knight_GameMode::AutoSaveTimer = 0.0f;
float APlagued_Knight_GameMode::GameTime = 0.0f;


void APlagued_Knight_GameMode::BeginPlay()
{
	Super::BeginPlay();
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
