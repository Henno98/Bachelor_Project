// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Player_HUD.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API APlayer_HUD : public AHUD
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	UPROPERTY()
	class UUserWidget* CurrentWidget;

	// Pointer to the actual health bar widget
	UPROPERTY()
	class UPlayer_Stat_Widget* HealthBarWidget;
};
