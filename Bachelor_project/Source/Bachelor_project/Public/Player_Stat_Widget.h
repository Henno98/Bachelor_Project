// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Player_Stat_Widget.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API UPlayer_Stat_Widget : public UUserWidget
{
	GENERATED_BODY()

    // Sets up the widget
    virtual void NativeConstruct() override;

    // Function to update the health bar
    void UpdateHealth(int32 currenthealth);

protected:
    // Reference to the canvas panel where health images will be added
    UPROPERTY(meta = (BindWidget))
    class UPanelWidget* HealthBarPanel;

    // Reference to the image used for a single health point
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthBar")
    class UTexture2D* HealthPointImage;

    // Maximum health (for example, set to 10)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthBar")
    int32 MaxHealth = 10;

    // Current health (we will dynamically set this from the player)
    int32 CurrentHealth;

    // Helper function to create health point images
    void CreateHealthPointImages();

};
