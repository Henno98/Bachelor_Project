// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Main_Menu_Widget.h"
#include "Components/TextBlock.h"
#include "SaveSlotListWidget.generated.h"

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
    UPROPERTY()
    TWeakObjectPtr<UMain_Menu_Widget> ParentMenu;

    virtual void NativeConstruct() override;

    UFUNCTION()
    void HandleLoadClicked();

    UFUNCTION()
    void HandleSaveClicked();
    UFUNCTION()
    void SetSave();
    UFUNCTION()
    void SetLoad();
};
