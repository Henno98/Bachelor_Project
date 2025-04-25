// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Beetle_AIController.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API ABeetle_AIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTree* Beetle_BT;
	class UBehaviorTreeComponent* Beetle_BTC;
	class UBlackboardComponent* Beetle_BBC;

	ABeetle_AIController();

	virtual void OnPossess(APawn* InPawn) override;

	APawn* detectPlayer;

	FTimerHandle timerHandle;

	void ToCheckSpawnStillAround();

public:
	FVector beetle_target_location;
	FVector beetle_start_location;
	FVector beetle_existing_location;

	float initialDistance;

	UFUNCTION()
	void OnEnemySeeItsTarget(class APawn* SensedPawn);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UPawnSensingComponent* Beetle_PerceptionComponent;



};
