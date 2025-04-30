// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Player_HUD.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void APlayer_HUD::BeginPlay()
{
	Super::BeginPlay();

    if (StatWidgetClass)
    {
        Player_Stat_Widget = CreateWidget<UPlayer_Stat_Widget>(GetWorld(), StatWidgetClass);
       
    }
    if (TextWidgetClass)
    {
        TextBoxWidget = CreateWidget<UText_Widget>(GetWorld(), TextWidgetClass);
        if (TextBoxWidget)
        {
            TextBoxWidget->AddToViewport();
            TextBoxWidget->SetVisibility(ESlateVisibility::Hidden); // start hidden
        }
    }
    if (MainMenuWidgetClass)
    {
        Main_Menu = CreateWidget<UMain_Menu_Widget>(GetWorld(), MainMenuWidgetClass);
        ToggleMenu(); // You can comment this out if you don't want the menu at start

        
    }
}



void APlayer_HUD::LoadPlayerHud()
{

    if (Player_Stat_Widget && !Player_Stat_Widget->IsInViewport())
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
      //  Main_Menu->SlotListContainer->ClearChildren();
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
         // Clear any existing timer before setting a new one
        GetWorld()->GetTimerManager().ClearTimer(TextHideTimerHandle);

        // Set timer to hide text after 5 seconds
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
    if (!PC) return;

    if (Main_Menu && Main_Menu->IsInViewport())
    {
        // If menu is open, close it
        CloseMenu();
        LoadPlayerHud();

        PC->bShowMouseCursor = false;
        PC->SetInputMode(FInputModeGameOnly());
        PC->SetPause(false); // unpause when closing menu
    }
    else
    {
       
        // If menu is not open, open it
        ClosePlayerHud();
        OpenMenu();

        // Set input mode for UI
        FInputModeUIOnly InputMode;
        InputMode.SetWidgetToFocus(Main_Menu->TakeWidget());
        InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

        PC->SetInputMode(InputMode);
        PC->bShowMouseCursor = true;
        PC->SetPause(true); // Pause after input mode is set

    }

}
