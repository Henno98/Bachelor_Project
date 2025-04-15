// Fill out your copyright notice in the Description page of Project Settings.


#include "CrowTask_MeleeAttack.h"
#include "CrowBoss_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

UCrowTask_MeleeAttack::UCrowTask_MeleeAttack()
{
    
}

EBTNodeResult::Type UCrowTask_MeleeAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    ACrowBoss_AIController* BossAI = Cast<ACrowBoss_AIController>(OwnerComp.GetAIOwner());
    if (!BossAI) return EBTNodeResult::Failed;

    ACharacter* CrowBoss = Cast<ACharacter>(BossAI->GetPawn());
    if (!CrowBoss) return EBTNodeResult::Failed;

    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (!BlackboardComp) return EBTNodeResult::Failed;

    AActor* Target = Cast<AActor>(BlackboardComp->GetValueAsObject("Player"));
    if (!Target) return EBTNodeResult::Failed;

    FVector BossLocation = CrowBoss->GetActorLocation();
    FVector TargetLocation = Target->GetActorLocation();
    float Distance = FVector::Dist(BossLocation, TargetLocation);

    // Draw debug sphere for melee range
    DrawDebugSphere(
        CrowBoss->GetWorld(),
        BossLocation,
        MeleeRange,
        12,
        FColor::Red,
        false,
        1.0f
    );

    // Draw line to target if in range
    if (Distance <= MeleeRange)
    {
        DrawDebugLine(
            CrowBoss->GetWorld(),
            BossLocation,
            TargetLocation,
            FColor::Green,
            false,
            1.0f,
            0,
            3.0f
        );
    }

    if (Distance > MeleeRange) return EBTNodeResult::Failed;

    //BlackboardComp->SetValueAsBool("IsAttacking", true);
    CrowBoss->GetCharacterMovement()->StopMovementImmediately();

    //Damooge
    

    FTimerHandle DelayHandle;
    CrowBoss->GetWorldTimerManager().SetTimer(
        DelayHandle,
        [BlackboardComp]()
        {
            BlackboardComp->SetValueAsBool("IsAttacking", false);
        },
        AttackDelay,
        false
    );

    return EBTNodeResult::Succeeded;
}
