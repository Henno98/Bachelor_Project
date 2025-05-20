// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/KeyBindsWidget.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Player/KeyBindListWidget.h"
#include "GameFramework/PlayerController.h"


/**
 * UKeyBindsWidget
 *
 * Widget class for managing and displaying the player's key bindings.
 * - Displays current key mappings for both keyboard and gamepad.
 * - Allows the player to modify input bindings dynamically.
 * - Updates the input mappings within the Enhanced Input System.
 * - Rebinds keys and updates the UI when changes are made.
 */


void UKeyBindsWidget::NativeConstruct()
{
	Super::NativeConstruct();
   
    
    ConstructWidget();
}

void UKeyBindsWidget::ConstructWidget()
{
    //VerticalBox->ClearChildren();
    KeyBindsScrollBox->ClearChildren();
     APlayerController* PC = GetOwningPlayer();
    if (!PC)
        return;

    ULocalPlayer* LocalPlayer = PC->GetLocalPlayer();
    if (!LocalPlayer)
        return;

    UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
    if (!Subsystem)
        return;
   
    TMultiMap<UInputAction*, FKey> KeyboardKeys;
    TMultiMap<UInputAction*, FKey> GamepadKeys;
    // Get mappings from the input context
    TArray<FEnhancedActionKeyMapping> Mappings = MappingContext->GetMappings();
    if (KeyBindsScrollBox)
    {
        for (const auto& Mapping : MappingContext->GetMappings())
        {
            if (!Mapping.Action)
                continue;

            if (Mapping.Key.IsGamepadKey())
                GamepadKeys.Emplace(Mapping.Action, Mapping.Key);
            else
                KeyboardKeys.Emplace(Mapping.Action, Mapping.Key);
        }

        TSet<UInputAction*> AllActions;
        for (auto& Pair : KeyboardKeys)
            AllActions.Add(Pair.Key);
        for (auto& Pair : GamepadKeys)
            AllActions.Add(Pair.Key);
        for (UInputAction* Action : AllActions)
        {
            TArray<FKey> ActionKeyboardKeys;
            KeyboardKeys.MultiFind(Action, ActionKeyboardKeys);

            TArray<FKey> ActionGamepadKeys;
            GamepadKeys.MultiFind(Action, ActionGamepadKeys);

            UKeyBindListWidget* Row = CreateWidget<UKeyBindListWidget>(GetWorld(), KeyBindListWidgetClass);
            if (Row)
            {
                Row->InitializeKeyBinding(Action, ActionKeyboardKeys, ActionGamepadKeys);
                Row->ParentMenu = this;
                KeyBindsScrollBox->AddChild(Row);
            }
        }
    }
}

void UKeyBindsWidget::CloseWidget()
{    RemoveFromParent();
}




void UKeyBindsWidget::OnKeySelected(FInputChord SelectedKey)
{
    FKey NewKey = SelectedKey.Key;

}

void UKeyBindsWidget::UpdateKeyBindDisplay()
{
   
    ConstructWidget();
}

void UKeyBindsWidget::RebindKey(UInputAction* Action, FKey OldKey, FKey NewKey, bool SecondaryKey)
{
    if (!MappingContext || !Action)
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid parameters: MappingContext or Action is null"));
        return;
    }

    UE_LOG(LogTemp, Log, TEXT("Rebinding Action: %s | OldKey: %s -> NewKey: %s"),
        *Action->GetName(), *OldKey.ToString(), *NewKey.ToString());

    TArray<FEnhancedActionKeyMapping> ExistingMappings = MappingContext->GetMappings();
    TArray<FEnhancedActionKeyMapping> UpdatedMappings;

    bool bKeyUpdated = false;

    // Copy mappings while replacing OldKey with NewKey for the target Action
    for (const auto& Mapping : ExistingMappings)
    {
        if (Mapping.Action == Action && Mapping.Key == OldKey && !Mapping.Key.IsGamepadKey())
        {
            FEnhancedActionKeyMapping NewMapping = Mapping;
            NewMapping.Key = NewKey;
            UpdatedMappings.Add(NewMapping);
            bKeyUpdated = true;
        }
        else
        {
            UpdatedMappings.Add(Mapping);
        }
    }

    if (!bKeyUpdated)
    {
        UE_LOG(LogTemp, Warning, TEXT("OldKey not found among mapped keys for action %s"), *Action->GetName());
        return;
    }

    // Clear all mappings
    MappingContext->UnmapAll();

    // Re-add all mappings with updated key
    for (const auto& Mapping : UpdatedMappings)
    {
        MappingContext->MapKey(Mapping.Action, Mapping.Key);
    }

    // Reapply the mapping context
    if (APlayerController* PC = GetOwningPlayer())
    {
        if (ULocalPlayer* LocalPlayer = PC->GetLocalPlayer())
        {
            if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
            {
                Subsystem->RemoveMappingContext(MappingContext);
                Subsystem->AddMappingContext(MappingContext, 0);
            }
        }
    }
}

