// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PointLightComponent.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Actor.h"
#include "Lamp.generated.h"

UCLASS()
class BACHELOR_PROJECT_API ALamp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALamp();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// Timeline update function
	UFUNCTION()
	void OnTimelineUpdate(float Value);

	// Components
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UPointLightComponent* PointLightComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTimelineComponent* FlickerTimeline;

	// Float Curve for flickering
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCurveFloat* FlickerCurve;
};
