// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/KeyBindsWidget.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Player/KeyBindListWidget.h"
#include "GameFramework/PlayerController.h"


void UKeyBindsWidget::NativeConstruct()
{
	Super::NativeConstruct();
   
    
    ConstructWidget();
}

void UKeyBindsWidget::ConstructWidget()
{
    VerticalBox->ClearChildren();
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
    if (VerticalBox)
    {
        for (const auto& Mapping : MappingContext->GetMappings())
        {
            if (!Mapping.Action)
                continue;

            if (Mapping.Key.IsGamepadKey())
                GamepadKeys.Add(Mapping.Action, Mapping.Key);
            else
                KeyboardKeys.Add(Mapping.Action, Mapping.Key);
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
                VerticalBox->AddChildToVerticalBox(Row);
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

    // Now call your rebind function
   // RebindKey(TargetInputAction, NewKey);
}

void UKeyBindsWidget::UpdateKeyBindDisplay()
{
   
    ConstructWidget();
}

void UKeyBindsWidget::RebindKey(UInputAction* Action, FKey NewKey)
{
    if (!MappingContext || !Action)
        return;

    // Remove only matching key type
    TArray<FEnhancedActionKeyMapping> ExistingMappings = MappingContext->GetMappings();
    for (const auto& Mapping : ExistingMappings)
    {
        if (Mapping.Action == Action &&
            Mapping.Key.IsGamepadKey() == NewKey.IsGamepadKey()) // Match by input type
        {
            MappingContext->UnmapKey(Mapping.Action, Mapping.Key);
        }
    }

    MappingContext->MapKey(Action, NewKey);

    // Reapply context to take effect
    if (auto* PC = GetOwningPlayer())
    {
        if (auto* LocalPlayer = PC->GetLocalPlayer())
        {
            if (auto* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
            {
                Subsystem->RemoveMappingContext(MappingContext);
                Subsystem->AddMappingContext(MappingContext, 0);
            }
        }
    }

    UE_LOG(LogTemp, Log, TEXT("Rebound action %s to %s"), *Action->GetName(), *NewKey.ToString());
}

