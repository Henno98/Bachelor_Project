// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/KeyBindListWidget.h"
#include "Player/KeyBindsWidget.h"


void UKeyBindListWidget::NativeConstruct()
{
	Super::NativeConstruct();

    // Bind the key selection event to the OnKeySelected function
    if (KeyboardKeySelector)
    {
        KeyboardKeySelector->OnKeySelected.Clear();
        KeyboardKeySelector->OnKeySelected.AddDynamic(this, &UKeyBindListWidget::OnKeyboardKeySelected);
    }

    if (ControllerKeySelector)
    {
        ControllerKeySelector->OnKeySelected.Clear();
        ControllerKeySelector->OnKeySelected.AddDynamic(this, &UKeyBindListWidget::OnControllerKeySelected);
    }
}


void UKeyBindListWidget::InitializeKeyBinding(UInputAction* Action, const TArray<FKey>& KeyboardKeys,
	const TArray<FKey>& GamepadKeys)
{
    InputAction = Action;

    if (ActionTextBlock)
        ActionTextBlock->SetText(FText::FromName(Action->GetFName()));

    if (KeyboardKeySelector && KeyboardKeys.Num() > 0)
        KeyboardKeySelector->SetSelectedKey(FInputChord(KeyboardKeys[0]));

    if (ControllerKeySelector && GamepadKeys.Num() > 0)
        ControllerKeySelector->SetSelectedKey(FInputChord(GamepadKeys[0]));
}

void UKeyBindListWidget::OnKeyboardKeySelected(FInputChord SelectedKey)
{
    if (InputAction && ParentMenu && !SelectedKey.Key.IsGamepadKey())
    {
        Cast<UKeyBindsWidget>(ParentMenu)->RebindKey(InputAction, SelectedKey.Key);
    }
}

void UKeyBindListWidget::OnControllerKeySelected(FInputChord SelectedKey)
{
    if (InputAction && ParentMenu && SelectedKey.Key.IsGamepadKey())
    {
        Cast<UKeyBindsWidget>(ParentMenu)->RebindKey(InputAction, SelectedKey.Key);
    }
}


