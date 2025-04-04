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

	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTreeComponent* SmallCharger_BTC;

	UPROPERTY(EditDefaultsOnly)
	class UBlackboardComponent* SmallCharger_BBC;


	ASmallCharger_AIController();

	virtual void OnPossess(APawn* InPawn)override;


	APawn* Player;

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
	void OnSeenPawn(APawn* SeenPawn);
	void RestartBehaviorTree();


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UPawnSensingComponent* SmallCharger_PerceptionComponent;


};

