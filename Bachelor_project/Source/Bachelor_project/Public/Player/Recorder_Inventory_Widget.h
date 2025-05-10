// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Recorder_Inventory.h"
#include "VRI_Button_Widget.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/WrapBox.h"
#include "Recorder_Inventory_Widget.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API URecorder_Inventory_Widget : public UUserWidget
{
	GENERATED_BODY()

public:
    void PopulateInventory(const TMap<int32, AVoice_Recorder*>& InRecorderMap);

protected:
    virtual void NativeConstruct() override;
    UPROPERTY(meta = (BindWidget))
    UWrapBox* RecorderListPanel;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
    TSubclassOf<UVRI_Button_Widget> ButtonClass;

    TMap<int32, AVoice_Recorder*> RecorderMap;

    UFUNCTION()
    void HandleRecorderClicked(int32 RecorderID);
};
