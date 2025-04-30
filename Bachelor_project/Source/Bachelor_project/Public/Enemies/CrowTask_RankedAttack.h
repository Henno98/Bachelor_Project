// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTNode.h"
#include "BehaviorTree/BTTaskNode.h"
#include "CrowTask_RankedAttack.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API UCrowTask_RankedAttack : public UBTTaskNode
{
	GENERATED_BODY()

	UCrowTask_RankedAttack();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;


};
