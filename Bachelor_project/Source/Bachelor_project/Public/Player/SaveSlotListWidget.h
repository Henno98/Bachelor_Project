// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "SaveSlotListWidget.generated.h"

class UMain_Menu_Widget;
/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API USaveSlotListWidget : public UUserWidget
{
	GENERATED_BODY()
public:
    UPROPERTY(meta = (BindWidget))
    UButton* Button;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* SlotNameText;

    FString SlotName;
    int32 SlotIndex;
    float GameTime;
    UPROPERTY()
    TObjectPtr<UMain_Menu_Widget> ParentMenu;

    virtual void NativeConstruct() override;

    UFUNCTION()
    void HandleLoadClicked();

    UFUNCTION()
    void HandleSaveClicked();
    UFUNCTION()
    void SetSave();
    UFUNCTION()
    void SetLoad();

    // Function to update the displayed time
    UFUNCTION(BlueprintCallable, Category = "UI")
    FString GetFormattedSaveTime() const
    {
        // Convert the timestamp to a readable format
        FDateTime SaveTime = FDateTime::FromUnixTimestamp(GameTime);
        return SaveTime.ToString(TEXT("%H:%M:%S"));  // Format like: "2025-05-10 14:30:25"
    }
};
