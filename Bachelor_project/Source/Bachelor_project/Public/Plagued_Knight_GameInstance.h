// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
        if (!RecorderInventory.Contains(ID)) {
            RecorderInventory.Add(ID, Recorder);
        }
    }

    const TMap<int32, AVoice_Recorder*>& GetRecorderInventory() const
    {
        return RecorderInventory;
    }
};
