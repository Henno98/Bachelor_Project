// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Player_Stat_Widget.h"
#include "Components/PanelWidget.h"
#include "Components/Image.h"
#include "Components/ProgressBar.h"
#include "Player/Test_Character.h"

/**
 * UPlayer_Stat_Widget
 *
 * This class manages the player's health and biomass UI stats.
 * It listens for changes in the player's health and biomass and updates the UI accordingly.
 * - The health bar is represented as a series of images, each image corresponding to a health point.
 * - The biomass bar is represented as a progress bar showing the player's current biomass percentage.
 */


void UPlayer_Stat_Widget::NativeConstruct()
{
	Super::NativeConstruct();
	ATest_Character* character = Cast<ATest_Character>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	if (character)
	{
		CurrentHealth = character->GetHealth();
		CurrentBioMass = character->GetBioMass();
		MaxBioMass = character->GetMaxBioMass();
		if (IsValid(character))
		{
			character->OnEnergyChanged.RemoveDynamic(this, &UPlayer_Stat_Widget::UpdateBioMass);
			character->OnEnergyChanged.AddDynamic(this, &UPlayer_Stat_Widget::UpdateBioMass);

			character->OnHealthChanged.RemoveDynamic(this, &UPlayer_Stat_Widget::UpdateHealth);
			character->OnHealthChanged.AddDynamic(this, &UPlayer_Stat_Widget::UpdateHealth);
		}
	}

	UpdateHealth(CurrentHealth);
	UpdateBioMass(CurrentBioMass);
}

void UPlayer_Stat_Widget::UpdateHealth(int32 currenthealth)
{
	CurrentHealth = currenthealth;

	if (HealthBarPanel)
	{
		HealthBarPanel->ClearChildren();
	}

	CreateHealthPointImages();
}

void UPlayer_Stat_Widget::UpdateBioMass(int32 currentbiomass)
{
	if (EnergyBar)
	{
		CurrentBioMass = currentbiomass;
		float Percent = static_cast<float>(CurrentBioMass) / MaxBioMass;
		EnergyBar->SetPercent(Percent);
	}

}


void UPlayer_Stat_Widget::CreateHealthPointImages()
{
 if(!HealthBarPanel || !HealthPointImage)
		return;
	// Loop through and add images for each health point
	for (int32 i = 0; i < CurrentHealth; i++)
	{
		UImage* HealthImage = NewObject<UImage>(this);

		// Set the health point image (the visual representation of each health point)
		HealthImage->SetBrushFromTexture(HealthPointImage);

		// Add the image to the health bar panel (canvas)
		if (HealthBarPanel)
		{
			HealthBarPanel->AddChild(HealthImage);
		}

		FVector2D NewPosition = FVector2D(i * 30.f, 0.f); 
		HealthImage->SetRenderTranslation(NewPosition);
	}
}

void UPlayer_Stat_Widget::CreateBioMassImages()
{

	
}

