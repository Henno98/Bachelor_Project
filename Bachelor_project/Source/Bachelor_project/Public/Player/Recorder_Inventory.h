// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "World/Voice_Recorder.h"
#include "Recorder_Inventory.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API URecorder_Inventory : public UObject
{
	GENERATED_BODY()
    UPROPERTY()
    TMap<int32, AVoice_Recorder*> RecorderMap;
public:
    UFUNCTION(BlueprintCallable)
    void AddRecorder(int32 ID, AVoice_Recorder* Recorder)
    {
        if (Recorder)
        {
            RecorderMap.Add(ID, Recorder);
        }
    }

    UFUNCTION(BlueprintCallable)
    AVoice_Recorder* GetRecorderID(int32 ID) const
    {
        return RecorderMap.Contains(ID) ? RecorderMap[ID] : nullptr;
    }
    TMap<int32, AVoice_Recorder*> GetRecorderMap() { return RecorderMap; }
};
