// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Charger_AIController.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API ACharger_AIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTree* Charger_BT;

	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTreeComponent* Charger_BTC;

	UPROPERTY(EditDefaultsOnly)
	class UBlackboardComponent* Charger_BBC;


	


	ACharger_AIController();


public:
	FVector charger_target_location;
	FVector charger_start_location;
	FVector charger_existing_location;
	FTimerHandle TimerHandle;

	UPROPERTY(BlueprintReadWrite, Category = "AI Movement")
	float InitialDistance;

	bool bIsCharging = false;
	FVector ChargeDirection;


	UPROPERTY()
	APawn* Player;

	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float deltaTime) override;

	UFUNCTION(BlueprintCallable)
	void OnSeenPawn(APawn* SeenPawn);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UPawnSensingComponent* Charger_PerceptionComponent;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float ChargingDistance = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float ChargingSpeed = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float NormalSpeed = 400.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float ChargeCooldown = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float ChargeOvershootDistance = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float WanderRadius = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	TArray<class AWandering_Target_Point*> WanderingPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float CurrentCooldownTime = 0.0f;

	int32 CurrentWanderingPoint = 0;

	void UpdateChargeCooldown(float DeltaTime);


	

};




