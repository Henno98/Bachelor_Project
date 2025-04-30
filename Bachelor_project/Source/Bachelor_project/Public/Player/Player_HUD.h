// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Main_Menu_Widget.h"
#include "Text_Widget.h"
#include "GameFramework/HUD.h"
#include "Player_HUD.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API  APlayer_HUD : public AHUD
{
	GENERATED_BODY()

protected:
    virtual void BeginPlay() override;

    // Widget classes (set these in the Blueprint/Details panel)
    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UMain_Menu_Widget> MainMenuWidgetClass;

    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UPlayer_Stat_Widget> StatWidgetClass;

    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UText_Widget> TextWidgetClass;

    // Widget instances
    UPROPERTY()
    class UMain_Menu_Widget* Main_Menu;

    UPROPERTY()
    class UPlayer_Stat_Widget* Player_Stat_Widget;
    UPROPERTY()
    class UText_Widget* TextBoxWidget;

    FTimerHandle TextHideTimerHandle;
    bool bMenuVisible = false;

public:
    // Show tutorial text on the screen
    void LoadPlayerHud();
    void ClosePlayerHud();
    void OpenMenu();
    void CloseMenu();
    UFUNCTION(BlueprintCallable)
    void ShowText(const FString& Text);

    UFUNCTION(BlueprintCallable)
    void HideText();

	// Toggle menu from ESC key
    void ToggleMenu();
};


