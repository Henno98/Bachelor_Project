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

    if (MainMenuWidgetClass)
    {
        Main_Menu = CreateWidget<UMain_Menu_Widget>(GetWorld(), MainMenuWidgetClass);
        ToggleMenu(); // You can comment this out if you don't want the menu at start

        
    }
}

void APlayer_HUD::ShowTutorialText(const FString& Text)
{

    if (Player_Stat_Widget)
    {
        UTextBlock* TextBlock = Cast<UTextBlock>(Player_Stat_Widget->GetWidgetFromName(TEXT("TutorialTextBlock")));
        if (TextBlock)
        {
            TextBlock->SetText(FText::FromString(Text));
        }
    }
}

void APlayer_HUD::ClearText()
{
    if (Player_Stat_Widget)
    {
        // Ensure the widget is added to the viewport
        UTextBlock* TextBlock = Cast<UTextBlock>(Player_Stat_Widget->GetWidgetFromName(TEXT("TutorialTextBlock")));
        if (TextBlock)
        {
            // Clear the text
            TextBlock->SetText(FText::FromString(""));
        }
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
