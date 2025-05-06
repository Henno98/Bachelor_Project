// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/KeyBindsWidget.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Player/KeyBindListWidget.h"
#include "GameFramework/PlayerController.h"


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
        //VerticalBox->AddChildToVerticalBox(KeyBindsScrollBox);
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

    // Now call your rebind function
   // RebindKey(TargetInputAction, NewKey);
}

void UKeyBindsWidget::UpdateKeyBindDisplay()
{
   
    ConstructWidget();
}

void UKeyBindsWidget::RebindKey(UInputAction* Action, FKey OldKey, FKey NewKey, bool SecondaryKey)
{
    // Check if the parameters are valid
    if (!MappingContext || !Action)
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid parameters: MappingContext or Action is null"));
        return;
    }

    UE_LOG(LogTemp, Log, TEXT("Starting key rebind for Action: %s, NewKey: %s"), *Action->GetName(), *NewKey.ToString());
    UE_LOG(LogTemp, Log, TEXT( "OldKey is: %s") ,*NewKey.ToString());
    
    // Retrieve existing mappings
    TArray<FEnhancedActionKeyMapping> ExistingMappings = MappingContext->GetMappings();
    UE_LOG(LogTemp, Log, TEXT("Existing mappings size: %d"), ExistingMappings.Num());

    TArray<FKey> KeyboardKeys;
    // Search for the existing primary and secondary keys
    for (const auto& Mapping : ExistingMappings)
    {
        if (Mapping.Action == Action)
        {
            if (!Mapping.Key.IsGamepadKey()) // Only care about keyboard keys
            {
                
                UE_LOG(LogTemp, Log, TEXT("Found key mapping: %s"), *Mapping.Key.ToString());
                KeyboardKeys.Add(Mapping.Key);
            }
        }
    }

    // If no relevant keys found, log it
    if (KeyboardKeys.Num() == 0)
    {
        UE_LOG(LogTemp, Log, TEXT("No existing keyboard keys found for this action"));
    }

    // Iterate through the found keyboard keys and check for matches with the new key
    bool bKeyRebinded = false;
    for (const auto& Keys : KeyboardKeys)
    {
        if (Keys == OldKey)
        {
            UE_LOG(LogTemp, Log, TEXT("New key matches existing key: %s. Rebinding..."), *NewKey.ToString());
            MappingContext->UnmapKey(Action, OldKey);  // Remove the existing mapping
            MappingContext->MapKey(Action, NewKey);  // Map the new key

            bKeyRebinded = true;
          
        }
        else
        {
            MappingContext->UnmapKey(Action, Keys);  // Remove the existing mapping
            MappingContext->MapKey(Action, Keys);

        }
    }
    

    // Log if no match was found and no rebind occurred
    if (!bKeyRebinded)
    {
        UE_LOG(LogTemp, Log, TEXT("No matching key found for rebind: %s"), *NewKey.ToString());
    }

    // Log before reapplying the mapping context
    UE_LOG(LogTemp, Log, TEXT("Reapplying the mapping context to ensure the new binding takes effect"));

    // Reapply the mapping context to take effect
    if (auto* PC = GetOwningPlayer())
    {
        if (auto* LocalPlayer = PC->GetLocalPlayer())
        {
            if (auto* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
            {
                UE_LOG(LogTemp, Log, TEXT("Removing and adding mapping context to input subsystem"));

                // Remove and reapply the mapping context to update the input system
                Subsystem->RemoveMappingContext(MappingContext);
                Subsystem->AddMappingContext(MappingContext, 0);

                UE_LOG(LogTemp, Log, TEXT("Mapping context successfully reapplied"));
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("Subsystem not found for the local player"));
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("LocalPlayer not found for the owning player"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Owning player not found"));
    }
}

