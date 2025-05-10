// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "CrowBoss_RandomService.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API UCrowBoss_RandomService : public UBTService
{
	GENERATED_BODY()

public:
	UCrowBoss_RandomService();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

};
