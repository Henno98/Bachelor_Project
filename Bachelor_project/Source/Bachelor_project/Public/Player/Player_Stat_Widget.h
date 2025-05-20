// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Player_Stat_Widget.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API UPlayer_Stat_Widget : public UUserWidget
{
	GENERATED_BODY()

    // Sets up the widget
    UFUNCTION()
    virtual void NativeConstruct() override;

    // Function to update the health bar
    UFUNCTION()
    void UpdateHealth(int32 currenthealth);

    UFUNCTION()
    void UpdateBioMass(int32 currentbiomass);
protected:
    // Reference to the canvas panel where health images will be added
    UPROPERTY(meta = (BindWidget))
    class UHorizontalBox* HealthBarPanel;
    UPROPERTY(meta = (BindWidget))
    UImage* EnergyBarImage;
    // An array of image slots (set in UMG or dynamically)
    UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "EnergyBar")
    TArray<UTexture2D*> BioMassStageTextures; // Should contain 4 textures in order: [empty, low, mid, full]

    // Max biomass value (should be divisible by 4 for this design)

    // Reference to the image used for a single health point
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthBar")
    class UTexture2D* HealthPointImage;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthBar")
    class UTexture2D* EmptyHealthPointImage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnergyBar")
    class UTexture2D* BioMassImage;


    // Maximum health (for example, set to 10)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthBar")
    int32 MaxHealth = 10;

    // Current health (we will dynamically set this from the player)
    int32 CurrentHealth;

    // Current health (we will dynamically set this from the player)
    int32 CurrentBioMass;

    int32 MaxBioMass;
    // Helper function to create health point images
    void CreateHealthPointImages();

    // Helper function to create health point images
    void CreateBioMassImages();

    

};
