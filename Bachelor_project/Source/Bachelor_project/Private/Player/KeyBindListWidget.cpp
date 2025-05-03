// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/KeyBindListWidget.h"
#include "Player/KeyBindsWidget.h"


void UKeyBindListWidget::NativeConstruct()
{
	Super::NativeConstruct();

    // Bind the key selection event to the OnKeySelected function
    if (KeySelector)
    {
        KeySelector->OnKeySelected.Clear();
        KeySelector->OnKeySelected.AddDynamic(this, &UKeyBindListWidget::OnKeySelected);
    }
}

void UKeyBindListWidget::InitializeKeyBinding(UInputAction* Action, FKey DefaultKey)
{
    InputAction = Action;

    // Set the action name text
    if (ActionTextBlock)
    {
        ActionTextBlock->SetText(FText::FromName(Action->GetFName()));
    }

    // Set the default key in the key selector
    if (KeySelector)
    {
        KeySelector->SetSelectedKey(FInputChord(DefaultKey));
    }
}

void UKeyBindListWidget::OnKeySelected(FInputChord SelectedKey)
{
    // Call a function in your main widget or player controller to rebind the key
    if (InputAction)
    {
        if (ParentMenu) {
            // Rebind the key via your rebind function
            UKeyBindsWidget* PC = Cast<UKeyBindsWidget>(ParentMenu);
            if (PC)
            {
                PC->RebindKey(InputAction, SelectedKey.Key);
            }
        }
    }
}

