// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicPlatform.generated.h"

class UStaticMeshComponent;
class UBoxComponent;
UCLASS()
class BACHELOR_PROJECT_API ABasicPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasicPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
    // Trigger Volume component
    UPROPERTY(VisibleAnywhere)
    class UBoxComponent* TriggerBox;
    FTimerHandle TutorialTextTimerHandle;
    // Tutorial text to show when player enters the volume
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tutorial")
    FString TutorialText;

    // When the player enters the trigger, show tutorial text
    UFUNCTION()
    void OnPlayerEnterTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    // Function to handle the end overlap event
    UFUNCTION()
    void LeftTriggerBox();

};
