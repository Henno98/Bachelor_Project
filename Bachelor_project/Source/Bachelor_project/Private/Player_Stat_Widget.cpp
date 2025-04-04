// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_Stat_Widget.h"
#include "Components/PanelWidget.h"
#include "Components/Image.h"
#include "Components/ProgressBar.h"

void UPlayer_Stat_Widget::NativeConstruct()
{
	Super::NativeConstruct();
	// Initialize the health (for example, set it to max health)
	CurrentHealth = MaxHealth;

	// Initially, create all health points (images) when the widget is constructed
	CreateHealthPointImages();
}

void UPlayer_Stat_Widget::UpdateHealth(int32 currenthealth)
{
	CurrentHealth = currenthealth;

	// Clear the previous health point images
	if (HealthBarPanel)
	{
		HealthBarPanel->ClearChildren();
	}

	// Create the health point images based on the current health
	CreateHealthPointImages();
}

void UPlayer_Stat_Widget::CreateHealthPointImages()
{
 if(!HealthBarPanel || !HealthPointImage)
		return;

	// Loop through and add images for each health point
	for (int32 i = 0; i < MaxHealth; i++)
	{
		UImage* HealthImage = NewObject<UImage>(this);

		// Set the health point image (the visual representation of each health point)
		HealthImage->SetBrushFromTexture(HealthPointImage);

		// Add the image to the health bar panel (canvas)
		if (HealthBarPanel)
		{
			HealthBarPanel->AddChild(HealthImage);
		}

		// Position the health images to display them in a row (or other layout)
		FVector2D NewPosition = FVector2D(i * 30.f, 0.f); // Space them 30 units apart
		HealthImage->SetRenderTranslation(NewPosition);
	}
}

