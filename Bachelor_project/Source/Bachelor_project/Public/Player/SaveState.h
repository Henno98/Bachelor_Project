// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Test_Character.h"
#include "GameFramework/SaveGame.h"
#include "SaveState.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API USaveState : public USaveGame
{
	GENERATED_BODY()
public:

	// Saved data
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	FString PlayerName;

	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	FVector PlayerLocation;

	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	int32 UserIndex;

	// The current level name to load
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	FString CurrentLevel;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	int Health;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	int BioMass;
	UPROPERTY()
	ATest_Character* Player;
	// The current level name to load


	USaveState();

	static bool SaveGame(UWorld* World, FString SlotName, int32 SlotNumber);
	static bool LoadGame(UWorld* World, FString SlotName, int32 SlotNumber);
	
};
