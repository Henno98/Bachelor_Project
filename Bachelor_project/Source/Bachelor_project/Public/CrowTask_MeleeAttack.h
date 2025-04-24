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

public:
    UCrowTask_MeleeAttack();

protected:
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
    virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
    class ACrowBoss_AIController* BossAI;
    class ACharacter* CrowBoss;
    class AActor* PlayerActor;
    class UBlackboardComponent* Blackboard;

    FTimerHandle AttackTimer;

    float ChaseRange = 250.f;     
    float HitRange = 200.f;       


    bool bHasAttacked;
    float AttackRange;
};
