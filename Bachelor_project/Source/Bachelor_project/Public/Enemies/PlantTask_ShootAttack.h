// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "PlantTask_ShootAttack.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API UPlantTask_ShootAttack : public UBTTaskNode
{
	GENERATED_BODY()

	UPlantTask_ShootAttack();

	UPROPERTY(EditAnywhere, Category = "GAS")
	TSubclassOf<class UGameplayAbility> AttackAbility;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
