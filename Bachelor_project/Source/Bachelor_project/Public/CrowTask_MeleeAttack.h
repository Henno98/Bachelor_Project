// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "CrowTask_MeleeAttack.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API UCrowTask_MeleeAttack : public UBTTaskNode
{
	GENERATED_BODY()

	UCrowTask_MeleeAttack();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere, Category = "Melee")
	float MeleeRange = 150.f;

	UPROPERTY(EditAnywhere, Category = "Melee")
	float AttackDelay = 1.0f;//Endre til kan attack etter animation e ferdi
};
