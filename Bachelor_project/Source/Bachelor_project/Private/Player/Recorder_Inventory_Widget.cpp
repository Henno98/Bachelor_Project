// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Recorder_Inventory_Widget.h"
#include "Player/VRI_Button_Widget.h"

/**
 * URecorder_Inventory_Widget
 *
 * This class handles the UI functionality for displaying and interacting with a list of voice recorders.
 * - It populates a list of recorder buttons based on a map of recorder IDs and their corresponding recorder instances.
 * - Each recorder button, when clicked, triggers a function to interact with the respective recorder (e.g., loading and playing text).
 */

void URecorder_Inventory_Widget::NativeConstruct()
{
    Super::NativeConstruct();
}

void URecorder_Inventory_Widget::PopulateInventory(const TMap<int32, AVoice_Recorder*>& InRecorderMap)
{
    if (!RecorderListPanel)
    {
        UE_LOG(LogTemp, Warning, TEXT("RecorderListPanel is null. Cannot populate inventory."));
        return;
    }

    RecorderListPanel->ClearChildren();
    RecorderMap = InRecorderMap;

    for (const auto& Pair : RecorderMap)
    {
        int32 RecorderID = Pair.Key;
        AVoice_Recorder* Recorder = Pair.Value;

        if (!Recorder)
        {
            UE_LOG(LogTemp, Warning, TEXT("Recorder with ID %d is null."), RecorderID);
            continue;
        }

        UVRI_Button_Widget* NewButton = CreateWidget<UVRI_Button_Widget>(this, ButtonClass);
        if (NewButton)
        {
            NewButton->SetRecorderID(RecorderID);
            NewButton->SetText(FString::Printf(TEXT("Recording %d"), RecorderID));
            NewButton->OnRecorderClicked.AddDynamic(this, &URecorder_Inventory_Widget::HandleRecorderClicked);

            RecorderListPanel->AddChild(NewButton);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Failed to create button widget for Recorder ID: %d"), RecorderID);
        }
    }
}

void URecorder_Inventory_Widget::HandleRecorderClicked(int32 RecorderID)
{

    if (AVoice_Recorder* const* RecorderPtr = RecorderMap.Find(RecorderID))
    {
        if (*RecorderPtr)
        {
            IInteractable::Execute_LoadText(*RecorderPtr, IInteractable::Execute_GetInteractibleText(*RecorderPtr));
            IInteractable::Execute_PlayText(*RecorderPtr);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Recorder pointer for ID %d is null."), RecorderID);
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No Recorder found in map for ID: %d"), RecorderID);
    }
}