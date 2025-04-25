// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Charger_WanderingTask.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API UCharger_WanderingTask : public UBTTaskNode
{
	GENERATED_BODY()

    UCharger_WanderingTask();
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

    UPROPERTY(EditAnywhere, Category = "Wander")
    float WanderRadius = 1000.0f;

    UPROPERTY(EditAnywhere, Category = "Wander")
    bool UseControllerWanderRadius = true;
};
