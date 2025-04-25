// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Charger_ChargeTask.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API UCharger_ChargeTask : public UBTTaskNode
{
	GENERATED_BODY()

	UCharger_ChargeTask();

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;


private:
    UPROPERTY(EditAnywhere, Category = "Charge")
    float ChargeSpeedMultiplier = 2.5f;

    UPROPERTY(EditAnywhere, Category = "Charge")
    float MaxChargeTime = 2.0f;

    struct FChargeTaskMemory
    {
        float ElapsedTime;
        FVector StartLocation;
        FVector TargetLocation;
        FVector ChargeDirection;
        bool bChargeStarted;
    };

    virtual uint16 GetInstanceMemorySize() const override
    {
        return sizeof(FChargeTaskMemory);
    }
	
};
