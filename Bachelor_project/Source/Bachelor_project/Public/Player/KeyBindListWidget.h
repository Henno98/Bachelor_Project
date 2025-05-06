// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/InputKeySelector.h"
#include "Components/TextBlock.h"
#include "KeyBindListWidget.generated.h"


class UKeyBindsWidget;

UCLASS()
class BACHELOR_PROJECT_API UKeyBindListWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
    // The InputAction for this keybinding row
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KeyBinding")
    UInputAction* InputAction;

    // TextBlock to display the action name
    UPROPERTY(meta = (BindWidget))
    UTextBlock* ActionTextBlock;


    UPROPERTY(meta = (BindWidget))
    UHorizontalBox* Container;
    // KeySelector for the key binding
    UPROPERTY(meta = (BindWidget))
    UInputKeySelector* KeyboardKeySelector;
	UPROPERTY()
    UInputKeySelector* ExtraKeyboardKeySelector;
    UPROPERTY(meta = (BindWidget))
    UInputKeySelector* ControllerKeySelector;
    UPROPERTY()
    TObjectPtr<UKeyBindsWidget> ParentMenu;
    UPROPERTY(BlueprintReadOnly, Category = "KeyBinding")
	bool bHasMultipleKeyboardBindings;

    float Padding;

    FKey PrimaryKey;
    FKey SecondKey;
    FKey ControllerOldKey;
	// Initialize the widget with an action and key
    void InitializeKeyBinding(UInputAction* Action, const TArray<FKey>& KeyboardKeys, const TArray<FKey>& GamepadKeys);

    // Event when key is selected
    UFUNCTION()
    void OnKeyboardKeySelected(FInputChord SelectedKey);
    UFUNCTION()
    void OnSecondaryKeyboardKeySelected(FInputChord SelectedKey);
	UFUNCTION()
	void OnControllerKeySelected(FInputChord SelectedKey);

		
   
};

