// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Player_Stat_Widget.h"

#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
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
		if (IsValid(character))
		{
			character->OnEnergyChanged.RemoveDynamic(this, &UPlayer_Stat_Widget::UpdateBioMass);
			character->OnEnergyChanged.AddDynamic(this, &UPlayer_Stat_Widget::UpdateBioMass);

			character->OnHealthChanged.RemoveDynamic(this, &UPlayer_Stat_Widget::UpdateHealth);
			character->OnHealthChanged.AddDynamic(this, &UPlayer_Stat_Widget::UpdateHealth);
		}
	}

	// Initially, create all health points (images) when the widget is constructed
	UpdateHealth(CurrentHealth);
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

void UPlayer_Stat_Widget::UpdateBioMass(int32 currentbiomass)
{
	if (!EnergyBarImage || BioMassStageTextures.Num() < 4)
		return;

	CurrentBioMass = FMath::Clamp(currentbiomass, 0, MaxBioMass);
	float BiomassPercent = static_cast<float>(CurrentBioMass) / MaxBioMass;

	// Select texture index based on biomass level
	int32 TextureIndex = FMath::Clamp(FMath::FloorToInt(BiomassPercent * 4.0f), 0, 3);

	// Set brush from selected texture
	if (UTexture2D* SelectedTexture = BioMassStageTextures[TextureIndex])
	{
		FSlateBrush Brush;
		Brush.SetResourceObject(SelectedTexture);
		Brush.ImageSize = FVector2D(SelectedTexture->GetSizeX(), SelectedTexture->GetSizeY());

		EnergyBarImage->SetBrush(Brush);
	}
}


void UPlayer_Stat_Widget::CreateHealthPointImages()
{
	for (int32 i = 0; i < MaxHealth; i++)
	{
		UImage* HealthImage = NewObject<UImage>(this);

		FSlateBrush Brush;
		if (i < CurrentHealth)
		{
			// Full health point
			Brush.SetResourceObject(HealthPointImage);
		}
		else
		{
			// Empty health point
			Brush.SetResourceObject(EmptyHealthPointImage); // A dimmed or grey version
		}

		Brush.ImageSize = FVector2D(32, 32); // Consistent size
		HealthImage->SetBrush(Brush);

		if (UHorizontalBoxSlot* BoxSlot = Cast<UHorizontalBoxSlot>(HealthBarPanel->AddChild(HealthImage)))
		{
			BoxSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
			BoxSlot->SetHorizontalAlignment(HAlign_Fill);
			BoxSlot->SetVerticalAlignment(VAlign_Fill);
			BoxSlot->SetPadding(FMargin(2.0f));
		}
	}
}

void UPlayer_Stat_Widget::CreateBioMassImages()
{

	
}

