// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Plagued_Knight_GameMode.generated.h"

/**
 * 
 */


UCLASS()
class BACHELOR_PROJECT_API APlagued_Knight_GameMode : public AGameModeBase
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

private:
	static float AutoSaveTimer;
	static float GameTime;

};
