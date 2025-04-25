// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ReturnToOrigin_Task.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API UReturnToOrigin_Task : public UBTTaskNode
{
	GENERATED_BODY()

	UReturnToOrigin_Task();
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

	UPROPERTY(EditAnywhere, Category = "Dive")
	float DiveSpeed = 2000.f;
};
