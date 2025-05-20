// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EngineUtils.h"
#include "Engine/GameInstance.h"
#include "Player/Recorder_Inventory.h"
#include "Plagued_Knight_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API UPlagued_Knight_GameInstance : public UGameInstance
{
	GENERATED_BODY()
protected:
    FVector SavedLocation;
    float SavedHealth;
    float SavedBioMass;
    FName TargetLevel;
    UPROPERTY()
    FString CurrentSubLevel;
    UPROPERTY()
    int32 GlobalProgress;
    // In GameInstance:
    UPROPERTY(BlueprintReadOnly)
    bool bIsRecorderPlaying = false;

    UPROPERTY(BlueprintReadOnly)
    int32 CurrentPlayingRecorderID = -1;
public:

  
    
    void StoreSavedData(const FVector& Loc, float Health, float BioMass, FName Level);
    void StoreInventory(URecorder_Inventory* Inventory);
    // Getters
    FVector GetSavedLocation() const;
    float GetSavedHealth() const;
    float GetSavedBioMass() const;
    FName GetTargetLevel() const;
    FString GetCurrentSubLevelName() const;
    int32 GetGlobalProgress() const;
    // Optional: Clear saved data after restoring
    void ClearSavedData();
    UPROPERTY(BlueprintReadOnly)
    TMap<int32, AVoice_Recorder*> RecorderInventory;

    void AddRecorder(int32 ID, AVoice_Recorder* Recorder)
    {
        if (!Recorder)
        {
            UE_LOG(LogTemp, Warning, TEXT("AddRecorder failed: Recorder is null."));
            return;
        }

        if (!RecorderInventory.Contains(ID))
        {
            RecorderInventory.Add(ID, Recorder);
            UE_LOG(LogTemp, Log, TEXT("Recorder with ID %d added to inventory."), ID);
        }
        else
        {
            UE_LOG(LogTemp, Log, TEXT("Recorder with ID %d already exists in inventory."), ID);
        }
    }

    bool HasRecorder(int32 ID) const
    {
        return RecorderInventory.Contains(ID);
    }

    const TMap<int32, AVoice_Recorder*>& GetRecorderInventory() const
    {
        return RecorderInventory;
    }
    AVoice_Recorder* FindRecorderByID(int32 ID) const
    {
        for (TActorIterator<AVoice_Recorder> It(GetWorld()); It; ++It)
        {
            AVoice_Recorder* Recorder = *It;
            if (Recorder && IInteractable::Execute_GetID(Recorder) == ID)
            {
                return Recorder;
            }
        }
        return nullptr;
    }
    AVoice_Recorder* GetRecorder(int32 ID)
    {
        if (AVoice_Recorder** FoundRecorder = RecorderInventory.Find(ID))
        {
            return *FoundRecorder;
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Recorder with ID %d not found in inventory."), ID);
            return nullptr;
        }
    }
    void PlayRecorder(int32 ID)
    {
        if (bIsRecorderPlaying)
        {
            UE_LOG(LogTemp, Warning, TEXT("A recorder is already playing (ID %d)."), CurrentPlayingRecorderID);
            return;
        }

        if (AVoice_Recorder* Recorder = GetRecorder(ID))
        {
            if (Recorder->Implements<UInteractable>())
            {
                IInteractable::Execute_InteractableAction(Recorder);
                UE_LOG(LogTemp, Log, TEXT("Playing recorder with ID %d."), ID);

                bIsRecorderPlaying = true;
                CurrentPlayingRecorderID = ID;
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("Recorder with ID %d does not implement IInteractable."), ID);
            }
        }
    }
};
