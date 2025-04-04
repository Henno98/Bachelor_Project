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
        HealthBarWidget = CreateWidget<UPlayer_Stat_Widget>(GetWorld(), HUDWidgetClass);
        if (HealthBarWidget)
        {
            HealthBarWidget->AddToViewport();
        }
    }
}
