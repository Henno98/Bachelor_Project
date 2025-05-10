// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Recorder_Inventory_Widget.h"

#include "Player/VRI_Button_Widget.h"


void URecorder_Inventory_Widget::NativeConstruct()
{
    Super::NativeConstruct();
    UE_LOG(LogTemp, Log, TEXT("Recorder Inventory Widget Constructed."));
}

void URecorder_Inventory_Widget::PopulateInventory(const TMap<int32, AVoice_Recorder*>& InRecorderMap)
{
    if (!RecorderListPanel)
    {
        UE_LOG(LogTemp, Warning, TEXT("RecorderListPanel is null. Cannot populate inventory."));
        return;
    }

    UE_LOG(LogTemp, Log, TEXT("Populating inventory with %d items."), InRecorderMap.Num());

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
            UE_LOG(LogTemp, Log, TEXT("Added button for Recorder ID: %d"), RecorderID);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Failed to create button widget for Recorder ID: %d"), RecorderID);
        }
    }
}

void URecorder_Inventory_Widget::HandleRecorderClicked(int32 RecorderID)
{
    UE_LOG(LogTemp, Log, TEXT("Recorder button clicked: ID %d"), RecorderID);

    if (AVoice_Recorder* const* RecorderPtr = RecorderMap.Find(RecorderID))
    {
        if (*RecorderPtr)
        {
            IInteractable::Execute_LoadText(*RecorderPtr, IInteractable::Execute_GetInteractibleText(*RecorderPtr));
            UE_LOG(LogTemp, Log, TEXT("Playing text for Recorder ID: %d"), RecorderID);
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