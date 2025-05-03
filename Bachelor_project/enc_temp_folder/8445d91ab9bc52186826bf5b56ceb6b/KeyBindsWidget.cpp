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
    if (CloseButton)
    {
        CloseButton->OnClicked.AddDynamic(this, &UKeyBindsWidget::CloseWidget);
    }
    if (KeyBindListWidgetClass)
    {
        //KeyBindListWidget = CreateWidget<UKeyBindListWidget>(GetWorld(), KeyBindListWidgetClass);
    }
    CreateWidget();
}

void UKeyBindsWidget::CreateWidget()
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
   

    // Get mappings from the input context
    TArray<FEnhancedActionKeyMapping> Mappings = MappingContext->GetMappings();
    if (VerticalBox)
    {
        for (const auto& Mapping : Mappings)
        {
         
                 if (KeyBindListWidget)
				  {
                    // Initialize the key binding row
                     KeyBindListWidget->InitializeKeyBinding(Mapping.Action, Mapping.Key);

                    // Add the row to the VerticalBox
                    VerticalBox->AddChildToVerticalBox(KeyBindListWidget);
                
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
    
    
}

void UKeyBindsWidget::RebindKey(UInputAction* Action, FKey NewKey)
{
    if (!MappingContext || !Action)
        return;

    // Remove all existing mappings for this action
    TArray<FEnhancedActionKeyMapping> ExistingMappings = MappingContext->GetMappings();
    for (const FEnhancedActionKeyMapping& Mapping : ExistingMappings)
    {
        if (Mapping.Action == Action)
        {
            MappingContext->UnmapKey(Mapping.Action, Mapping.Key);
        }
    }

    // Add the new key binding
    MappingContext->MapKey(Action, NewKey);

    // Optional: Reapply the mapping context to update the input system
    if (APlayerController* PC = GetOwningPlayer())
    {
        if (ULocalPlayer* LocalPlayer = PC->GetLocalPlayer())
        {
            if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
            {
                // Remove and re-add to ensure updates
                Subsystem->RemoveMappingContext(MappingContext);
                Subsystem->AddMappingContext(MappingContext, 0);
            }
        }
    }

    // Optional: Print debug log
    UE_LOG(LogTemp, Log, TEXT("Rebound action '%s' to key '%s'"),
        *Action->GetFName().ToString(), *NewKey.ToString());
}

