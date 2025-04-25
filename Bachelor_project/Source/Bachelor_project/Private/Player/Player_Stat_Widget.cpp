// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Player_Stat_Widget.h"
#include "Components/PanelWidget.h"
#include "Components/Image.h"
#include "Components/ProgressBar.h"
#include "Player/Test_Character.h"

void UPlayer_Stat_Widget::NativeConstruct()
{
	Super::NativeConstruct();
	// Initialize the health (for example, set it to max health)
	ATest_Character* character = Cast<ATest_Character>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	if (character)
	{
		CurrentHealth = character->GetHealth();
		CurrentBioMass = character->GetBioMass();
		MaxBioMass = character->GetMaxBioMass();

		// Do any additional setup here
		character->OnHealthChanged.AddDynamic(this, &UPlayer_Stat_Widget::UpdateHealth);
		character->OnEnergyChanged.AddDynamic(this, &UPlayer_Stat_Widget::UpdateBioMass);
	}

	// Initially, create all health points (images) when the widget is constructed
	CreateHealthPointImages();
	UpdateBioMass(CurrentBioMass);
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

void UPlayer_Stat_Widget::UpdateBioMass(int32 currenthealth)
{
	if (EnergyBar)
	{
		CurrentBioMass = currenthealth;
		float Percent = static_cast<float>(CurrentBioMass) / MaxBioMass;
		EnergyBar->SetPercent(Percent);
	}

}

void UPlayer_Stat_Widget::UpdateTutorialText(const FString& newtext)
{
	if (TutorialTextBlock)
	{
		TutorialTextBlock->SetText(FText::FromString(newtext));
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

		// Position the health images to display them in a row (or other layout)
		FVector2D NewPosition = FVector2D(i * 30.f, 0.f); // Space them 30 units apart
		HealthImage->SetRenderTranslation(NewPosition);
	}
}

void UPlayer_Stat_Widget::CreateBioMassImages()
{

	
}

