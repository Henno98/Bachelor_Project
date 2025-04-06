// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_HUD.h"

#include "Player_Stat_Widget.h"
#include "Blueprint/UserWidget.h"

void APlayer_HUD::BeginPlay()
{
	Super::BeginPlay();

  /*  if (HUDWidgetClass)
    {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);

        if (CurrentWidget)
        {
            CurrentWidget->AddToViewport();

        }

    }*/

    
    if (HUDWidgetClass)
    {
        Player_Stat_Widget = CreateWidget<UPlayer_Stat_Widget>(GetWorld(), HUDWidgetClass);
        if (Player_Stat_Widget)
        {
            
            Player_Stat_Widget->AddToViewport();
        }
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
