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

    if (!Container) return;
    Container->ClearChildren();
    // Always create the Action Text first, if it's not already part of the UI
    if (ActionTextBlock)
    {
        ActionTextBlock->SetText(FText::FromName(Action->GetFName()));
        UHorizontalBoxSlot* LabelSlot = Container->AddChildToHorizontalBox(ActionTextBlock);
        if (LabelSlot)
        {
            LabelSlot->SetPadding(FMargin(20.f));  // Add padding of 20 between widgets
            LabelSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));  // Fill space equally
            LabelSlot->SetHorizontalAlignment(HAlign_Left); // Align the text centered
        }
    }

    // Add keyboard key input first
    if (KeyboardKeySelector && KeyboardKeys.Num() > 0)
    {
        PrimaryKey = KeyboardKeys[0];
    	KeyboardKeySelector->SetSelectedKey(FInputChord(KeyboardKeys[0]));
        UHorizontalBoxSlot* KeySlot = Container->AddChildToHorizontalBox(KeyboardKeySelector);
        if (KeySlot)
        {
            KeySlot->SetPadding(FMargin(20.f));  // Padding of 20
            KeySlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));  // Equal fill space
        }
    }

    // Add secondary keyboard input (only if available)
    if (KeyboardKeys.Num() > 1)
    {
        SecondKey = KeyboardKeys[1];
        ExtraKeyboardKeySelector = NewObject<UInputKeySelector>(this, UInputKeySelector::StaticClass());
        if (ExtraKeyboardKeySelector)
        {
            ExtraKeyboardKeySelector->SetSelectedKey(FInputChord(KeyboardKeys[1]));
            ExtraKeyboardKeySelector->OnKeySelected.Clear();
            ExtraKeyboardKeySelector->OnKeySelected.AddDynamic(this, &UKeyBindListWidget::OnSecondaryKeyboardKeySelected);
            UHorizontalBoxSlot* ExtraKeySlot = Container->AddChildToHorizontalBox(ExtraKeyboardKeySelector);
            if (ExtraKeySlot)
            {
                ExtraKeySlot->SetPadding(FMargin(20.f));  // Padding of 20
                ExtraKeySlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));  // Equal fill space
            }
        }
    }

    // Add gamepad key last
    if (ControllerKeySelector && GamepadKeys.Num() > 0)
    {
        ControllerOldKey = GamepadKeys[0];
        ControllerKeySelector->SetSelectedKey(FInputChord(GamepadKeys[0]));
        UHorizontalBoxSlot* GamepadSlot = Container->AddChildToHorizontalBox(ControllerKeySelector);
        if (GamepadSlot)
        {
            GamepadSlot->SetPadding(FMargin(20.f));  // Padding of 20
            GamepadSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));  // Equal fill space
        }
    }
}

void UKeyBindListWidget::OnKeyboardKeySelected(FInputChord SelectedKey)
{
    if (InputAction && ParentMenu && !SelectedKey.Key.IsGamepadKey())
    {
        Cast<UKeyBindsWidget>(ParentMenu)->RebindKey(InputAction,PrimaryKey, SelectedKey.Key, false);
    }
}

void UKeyBindListWidget::OnSecondaryKeyboardKeySelected(FInputChord SelectedKey)
{
    if (InputAction && ParentMenu && !SelectedKey.Key.IsGamepadKey())
    {
        Cast<UKeyBindsWidget>(ParentMenu)->RebindKey(InputAction,SecondKey, SelectedKey.Key, true);
    }
}

void UKeyBindListWidget::OnControllerKeySelected(FInputChord SelectedKey)
{
    if (InputAction && ParentMenu && SelectedKey.Key.IsGamepadKey())
    {
        Cast<UKeyBindsWidget>(ParentMenu)->RebindKey(InputAction, ControllerOldKey, SelectedKey.Key,false);
    }
}


