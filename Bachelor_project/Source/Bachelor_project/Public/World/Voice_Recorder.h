// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Voice_Recorder.generated.h"

UCLASS()
class BACHELOR_PROJECT_API AVoice_Recorder : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVoice_Recorder();
	TArray<FString> TextLines;
	int32 CurrentLineIndex = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = " Playback")
	FString TextFilePath;
	FTimerHandle LinePlaybackTimer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = " Playback")
	TArray<USoundBase*> AudioClips;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = " Playback")
	int32 RecorderID;
	void DisplayNextLine();
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Basic")
	USkeletalMeshComponent* Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic")

	UBoxComponent* Collider;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual bool GetIsInteractible_Implementation() const override;
	virtual FString GetInteractibleText_Implementation() const override;
	virtual void LoadText_Implementation(const FString& FilePath)  override;
	virtual void PlayText_Implementation()  override;
	virtual int32 GetID_Implementation() override;
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
