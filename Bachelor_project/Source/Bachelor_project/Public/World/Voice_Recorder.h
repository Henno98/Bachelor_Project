// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Voice_Recorder.generated.h"

class UStringTable;
UCLASS()
class BACHELOR_PROJECT_API AVoice_Recorder : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVoice_Recorder();
   
    // ==== Properties ====

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
    FName StringTableName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
    TArray<USoundBase*> AudioClips;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
    TArray<FString> DialogueKeys;  // Matches audio index
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
    float LineDelay;

    FTimerHandle LinePlaybackTimer;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ID")
    int32 ID;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
    USkeletalMeshComponent* Mesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
    UBoxComponent* Collider;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
    UStringTable* StringTableAsset;

    // ==== Playback ====

        // Interface implementation
    virtual void InteractableAction_Implementation() override;
    virtual int32 GetID_Implementation() override { return ID; };

    UFUNCTION(BlueprintCallable, Category = "Dialogue")
    void PlayNextLine();
private:
    int32 CurrentIndex = 0;

    void ShowDialogueLine(const FString& Key);
	void LoadAllDialogueKeysFromTable();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
