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
		void RestartBehaviorTree();


		UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UPawnSensingComponent* SmallCharger_PercetionComponent;

		FORCEINLINE FAIRequestID GetChargeRequestId() const { return ChargeRequestId; }

		void ChargeToTarget(FVector NewTarget, float ArriveDistance) {
		};

private:
	 uint32 NextChargeRequestId;  // Incrementing ID for each charge request
	FAIRequestID ChargeRequestId;

	FORCEINLINE void StoreChargeRequestId() { ChargeRequestId = NextChargeRequestId++; }


	

};











