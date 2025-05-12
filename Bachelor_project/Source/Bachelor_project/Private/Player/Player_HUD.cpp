// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Player_HUD.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"


/**
 * APlayer_HUD
 *
 * This class manages the player interface (HUD) for the game.
 * - Handles the creation, display, and removal of various UI elements like the player stats, main menu, and text boxes.
 * - Provides functionality for toggling the main menu, showing/hiding text messages, and managing input modes.
 * - Controls the visibility and updates of the player HUD and menu elements during gameplay.
 */


void APlayer_HUD::BeginPlay()
{
	Super::BeginPlay();

    if (StatWidgetClass)
    {
        if (!Player_Stat_Widget) {
            Player_Stat_Widget = CreateWidget<UPlayer_Stat_Widget>(GetWorld(), StatWidgetClass);
        }
    }
    if (TextWidgetClass)
    {
        if (!TextBoxWidget) {
            TextBoxWidget = CreateWidget<UText_Widget>(GetWorld(), TextWidgetClass);
        }
        if (TextBoxWidget)
        {
            TextBoxWidget->AddToViewport();
            TextBoxWidget->SetVisibility(ESlateVisibility::Hidden); 
        }
    }
    if (MainMenuWidgetClass)
    {
        if (IsValid(Main_Menu))
        {
            Main_Menu->RemoveFromParent();
            Main_Menu = nullptr; 
        }

        Main_Menu = CreateWidget<UMain_Menu_Widget>(GetWorld(), MainMenuWidgetClass);
        ToggleMenu();
        
    }
    if (KeyBindWidgetClass)
    {
        KeyBindWidget = CreateWidget<UKeyBindsWidget>(GetWorld(), KeyBindWidgetClass);
        

    }

}



void APlayer_HUD::LoadPlayerHud()
{

    if (Player_Stat_Widget)
    {
        Player_Stat_Widget->AddToViewport();
    }
}

void APlayer_HUD::ClosePlayerHud()
{
    if (Player_Stat_Widget)
    {
        Player_Stat_Widget->RemoveFromParent();
    }
}

void APlayer_HUD::OpenMenu()
{
    if (Main_Menu)
    {
        Main_Menu->AddToViewport();
      
    }
}
void APlayer_HUD::CloseMenu()
{

    if (Main_Menu)
    {
        Main_Menu->RemoveFromParent();
       
    }
}

void APlayer_HUD::ShowText(const FString& Text)
{
    if (TextBoxWidget)
    {
        TextBoxWidget->UpdateWidget(Text);
        TextBoxWidget->SetVisibility(ESlateVisibility::Visible);
        GetWorld()->GetTimerManager().ClearTimer(TextHideTimerHandle);
        GetWorld()->GetTimerManager().SetTimer(TextHideTimerHandle, this, &APlayer_HUD::HideText, 5.0f, false);
  
    }
}

void APlayer_HUD::HideText()
{
    if (TextBoxWidget)
    {
        TextBoxWidget->SetVisibility(ESlateVisibility::Hidden);
    }
}


void APlayer_HUD::ToggleMenu()
{
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (!PC || !IsValid(Main_Menu)) return;

    if (Main_Menu->IsInViewport())
    {
        // Close menu
        CloseMenu();
        LoadPlayerHud();

        PC->bShowMouseCursor = false;
        PC->SetInputMode(FInputModeGameOnly());
        PC->SetPause(false);
    }
    else
    {
        // Open menu
        ClosePlayerHud();
        OpenMenu();
        FInputModeUIOnly InputMode;
        if (Main_Menu->GetCachedWidget().IsValid())
        {
            InputMode.SetWidgetToFocus(Main_Menu->TakeWidget());
        }

        InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
        PC->SetInputMode(InputMode);
        PC->bShowMouseCursor = true;
        PC->SetPause(true);
    }
}
