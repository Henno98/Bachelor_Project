// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/KeyBindListWidget.h"
#include "Player/KeyBindsWidget.h"


/**
 * UKeyBindListWidget
 *
 * Widget class for displaying and managing individual key bindings.
 * - Displays the key bindings for both keyboard and gamepad inputs.
 * - Allows for re-binding keys by interacting with the UI.
 * - Handles selection events for keyboard and gamepad keys.
 * - Updates the parent menu widget when a key is selected for rebinding.
 * - Organizes the layout into sections for keyboard and gamepad keys.
 */

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
    SetIsFocusable(true);
}


void UKeyBindListWidget::InitializeKeyBinding(UInputAction* Action, const TArray<FKey>& KeyboardKeys,
	const TArray<FKey>& GamepadKeys)
{
    InputAction = Action;
    if (!Container) return;
    Container->ClearChildren();

    // --- 1. Action Text Block (1/3) ---
    if (ActionTextBlock)
    {
        ActionTextBlock->SetText(FText::FromName(Action->GetFName()));
        UHorizontalBoxSlot* LabelSlot = Container->AddChildToHorizontalBox(ActionTextBlock);
        if (LabelSlot)
        {
            LabelSlot->SetPadding(FMargin(20.f));  
            LabelSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));  
            LabelSlot->SetHorizontalAlignment(HAlign_Center);  
        }
    }

    // --- 2. Keyboard Keys Section (1/3) ---
    // Create a new Horizontal Box for the Keyboard Section to occupy 1/3 width
    UHorizontalBox* KeyboardContainer = NewObject<UHorizontalBox>(this, UHorizontalBox::StaticClass());
    UHorizontalBoxSlot* KeyboardSlot = Container->AddChildToHorizontalBox(KeyboardContainer);
    if (KeyboardSlot)
    {
        KeyboardSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));  // Occupy 1/3 of the space

        // Loop through all the keyboard keys and add them to the KeyboardContainer
        for (int32 i = 0; i < KeyboardKeys.Num(); ++i)
        {
            PrimaryKey = KeyboardKeys[i];
            ExtraKeyboardKeySelector = NewObject<UInputKeySelector>(this, UInputKeySelector::StaticClass());
            if (ExtraKeyboardKeySelector)
            {
            	ExtraKeyboardKeySelector->SetSelectedKey(PrimaryKey);
                ExtraKeyboardKeySelector->OnKeySelected.Clear();
                ExtraKeyboardKeySelector->OnKeySelected.AddDynamic(this, &UKeyBindListWidget::OnSecondaryKeyboardKeySelected);
               
                // Add each keyboard key selector to the KeyboardContainer
                UHorizontalBoxSlot* KeySlot = KeyboardContainer->AddChildToHorizontalBox(ExtraKeyboardKeySelector);
                if (KeySlot)
                {
                    // Ensure the FSlateBrush is initialized for each key
                    FSlateBrush ExtraKeyBrush;
                    ExtraKeyBrush.SetResourceObject(ButtonImage);  // Assuming ButtonImage is valid

                    // Set the button style with the brush
                    FButtonStyle ExtraKeyStyle;
                    ExtraKeyStyle.SetNormal(ExtraKeyBrush);
                    ExtraKeyStyle.SetHovered(ExtraKeyBrush);
                    ExtraKeyStyle.SetPressed(ExtraKeyBrush);
                    ExtraKeyboardKeySelector->SetButtonStyle(ExtraKeyStyle);

                    // Ensure equal size for all keys
                    KeySlot->SetPadding(FMargin(5.f));  // Padding between keys
                    KeySlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));  // Each key will take equal space within the 1/3 width
                }
            }
        }
    }

    // --- 3. Gamepad Keys Section (1/3) ---
    if (ControllerKeySelector && GamepadKeys.Num() > 0)
    {
        ControllerOldKey = GamepadKeys[0];
        ControllerKeySelector->SetSelectedKey(FInputChord(GamepadKeys[0]));
        UHorizontalBoxSlot* GamepadSlot = Container->AddChildToHorizontalBox(ControllerKeySelector);
        if (GamepadSlot)
        {
            // Ensure the FSlateBrush is initialized
            FSlateBrush GamepadKeyBrush;
            GamepadKeyBrush.SetResourceObject(ButtonImage);  // Assuming ButtonImage is valid

            FButtonStyle GamepadKeyStyle;
            GamepadKeyStyle.SetNormal(GamepadKeyBrush);
            GamepadKeyStyle.SetHovered(GamepadKeyBrush);
            GamepadKeyStyle.SetPressed(GamepadKeyBrush);
            ControllerKeySelector->SetButtonStyle(GamepadKeyStyle);

            // Padding and size settings (take 1/3 of the space)
            GamepadSlot->SetPadding(FMargin(20.f));  // Padding of 20
            GamepadSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));  // Equal fill space (1/3 of the width)
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
        Cast<UKeyBindsWidget>(ParentMenu)->RebindKey(InputAction, PrimaryKey, SelectedKey.Key, true);
    }
}

void UKeyBindListWidget::OnControllerKeySelected(FInputChord SelectedKey)
{
    if (InputAction && ParentMenu && SelectedKey.Key.IsGamepadKey())
    {
        Cast<UKeyBindsWidget>(ParentMenu)->RebindKey(InputAction, ControllerOldKey, SelectedKey.Key,false);
    }
}


