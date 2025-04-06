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

	

	// Pointer to the actual health bar widget
	UPROPERTY()
	class UPlayer_Stat_Widget* Player_Stat_Widget;
public:
	// Show tutorial text on the screen
	UFUNCTION()
	void ShowTutorialText(const FString& Text);
	UFUNCTION()
	void ClearText();
};


