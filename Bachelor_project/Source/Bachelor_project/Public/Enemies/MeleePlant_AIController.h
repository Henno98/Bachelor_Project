// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MeleePlant_AIController.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API AMeleePlant_AIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTree* MeleePlant_BT;
	class UBehaviorTreeComponent* MeleePlant_BTC;
	class UBlackboardComponent* MeleePlant_BBC;

	AMeleePlant_AIController();

	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float DeltaTime)override;

	APawn* Player;

	FTimerHandle timerHandle;

	FTimerHandle AttackCooldownTimer;
	bool bCanAttack = true;

	UFUNCTION()
	void PerformAttack();
	void ResetAttack();

	

public:
	FVector MeleePlant_target_location;
	FVector MeleePlant_start_location;
	FVector MeleePlant_existing_location;

	float InitialDistance;

	UFUNCTION()
	void OnEnemySeeItsTarget(class APawn* SensedPawn);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UPawnSensingComponent* MeleePlant_PerceptionComponent;
};
