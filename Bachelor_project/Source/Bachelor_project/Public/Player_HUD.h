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

protected:
    virtual void BeginPlay() override;

    // Widget classes (set these in the Blueprint/Details panel)
    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<class UMain_Menu_Widget> MainMenuWidgetClass;

    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<class UPlayer_Stat_Widget> StatWidgetClass;

    // Widget instances
    UPROPERTY()
    class UMain_Menu_Widget* Main_Menu;

    UPROPERTY()
    class UPlayer_Stat_Widget* Player_Stat_Widget;

    bool bMenuVisible = false;

public:
    // Show tutorial text on the screen
    UFUNCTION()
    void ShowTutorialText(const FString& Text);

    UFUNCTION()
    void ClearText();

    void LoadPlayerHud();
    void ClosePlayerHud();
    void OpenMenu();
    void CloseMenu();

    // Toggle menu from ESC key
    void ToggleMenu();
};


