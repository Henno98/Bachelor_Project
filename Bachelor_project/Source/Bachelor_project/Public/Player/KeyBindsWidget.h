// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "Components/ScrollBox.h"
#include "Components/VerticalBox.h"
#include "KeyBindsWidget.generated.h"

class UKeyBindListWidget;
/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API UKeyBindsWidget : public UUserWidget
{
	GENERATED_BODY()

public:
    virtual void NativeConstruct() override;
    UFUNCTION()
    void ConstructWidget();
    UFUNCTION()
    void CloseWidget();

    // Assign these before using
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    TObjectPtr<UInputAction> InputAction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    TObjectPtr<UInputMappingContext> MappingContext;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    TSubclassOf<UKeyBindListWidget> KeyBindListWidgetClass;
    UPROPERTY()
    class UKeyBindListWidget* KeyBindListWidget;
    UPROPERTY(meta = (BindWidget))
    UScrollBox* KeyBindsScrollBox;
   
   

    UFUNCTION()
    void OnKeySelected(FInputChord SelectedKey);
   
	bool bWaitingForKey;
    UFUNCTION()
	void UpdateKeyBindDisplay();
    UFUNCTION()
	void RebindKey(UInputAction* Action, FKey OldKey, FKey NewKey, bool SecondaryKey);
	
};
