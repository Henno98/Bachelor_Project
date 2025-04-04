// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIController_SmallCharger.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API AAIController_SmallCharger : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTree* SmallCharger_BT;

	class UBehaviorTreeComponent* SmallCharger_BTC;
	class UBlackboardComponent* SmallCharger_BBC;


	AAIController_SmallCharger();

	virtual void OnPossess(APawn* InPawn)override;

	APawn* detectPlayer;

	FTimerHandle timerHandle;

	void ToCheckSpawnStillAround();

	bool seenPlayerFirstTime = true;

public:
	FVector smallCharger_target_location;
	FVector smallCharger_start_location;
	FVector smallCharger_existing_location;

	float initialDistance;

	UFUNCTION()
	void OnEnemySeenItsOwner(class APawn* SensedPawn);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UPawnSensingComponent* SmallCharger_PercetionComponent;


	
};
