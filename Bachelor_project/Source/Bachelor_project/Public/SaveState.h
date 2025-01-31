// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PowerUpController.h"
#include "Kismet/GameplayStatics.h"
#include "SaveState.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API USaveState : public USaveGame
{
	GENERATED_BODY()
public:

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString PlayerName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	uint32 UserIndex;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FVector PlayerLocation;

	UPROPERTY()
	class UPowerUpController* Powerups;

	UPROPERTY()
	class UWorld* SavedWorld;

	USaveState();
};
