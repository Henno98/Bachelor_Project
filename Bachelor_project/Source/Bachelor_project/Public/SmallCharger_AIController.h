// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SmallCharger_AIController.generated.h"

/**
 *
 */
UCLASS()
class BACHELOR_PROJECT_API ASmallCharger_AIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTree* SmallCharger_BT;

	class UBehaviorTreeComponent* SmallCharger_BTC;
	class UBlackboardComponent* SmallCharger_BBC;


	ASmallCharger_AIController();

	//virtual void OnPossess(APawn* InPawn)override;


	APawn* detectPlayer;

	FTimerHandle timerHandle;

	void ToCheckSpawnStillAround();

	bool seenPlayerFirstTime = true;

public:
	FVector smallCharger_target_location;
	FVector smallCharger_start_location;
	FVector smallCharger_existing_location;

	float initialDistance;

	//UFUNCTION()
	//void OnEnemySeenItsOwner(class APawn* SensedPawn);


	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;

	UFUNCTION(BlueprintCallable)
	void OnSeenPawn(APawn* _pawn);
	void RestartBehaviorTree();


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UPawnSensingComponent* SmallCharger_PerceptionComponent;


};

