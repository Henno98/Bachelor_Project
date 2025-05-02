// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CrowBoss_AIController.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API ACrowBoss_AIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTree* CrowBoss_BT;

	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTreeComponent* CrowBoss_BTC;

	UPROPERTY(EditDefaultsOnly)
	class UBlackboardComponent* CrowBoss_BBC;

	


	ACrowBoss_AIController();
	

public:
	FVector crowBoss_target_location;
	FVector crowBoss_start_location;
	FVector crowBoss_existing_location;
	FTimerHandle TimerHandle;

	UPROPERTY()
	APawn* Player;

	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float deltaTime) override;

	UFUNCTION(BlueprintCallable)
	void OnSeenPawn(APawn* SeenPawn);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UPawnSensingComponent* CrowBoss_PerceptionComponent;




	
};
