// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemies/CrowTask_RankedAttack.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Enemies/CrowBoss.h"
#include "Enemies/CrowBoss_AIController.h"
#include "Enemies/CrowBoss_Projectile.h"

/**
 * UCrowTask_RankedAttack
 *
 * Behavior Tree Task for the Crow Boss AI to perform a ranged attack.
 * - Checks if the player is within ranged attack distance.
 * - Spawns a projectile aimed at the player if the boss is not already attacking.
 * - Sets blackboard flags for attack state management.
 */


UCrowTask_RankedAttack::UCrowTask_RankedAttack()
{
}

EBTNodeResult::Type UCrowTask_RankedAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

    ACrowBoss_AIController* BossAI = Cast<ACrowBoss_AIController>(OwnerComp.GetAIOwner());
    if (!BossAI) return EBTNodeResult::Failed;

    ACrowBoss* CrowBoss = Cast<ACrowBoss>(BossAI->GetPawn());
    if (!CrowBoss) return EBTNodeResult::Failed;

    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (!BlackboardComp) return EBTNodeResult::Failed;

    AActor* PlayerActor = Cast<AActor>(BlackboardComp->GetValueAsObject("Player"));
    if (!PlayerActor) return EBTNodeResult::Failed;


    float DistanceToPlayer = FVector::Dist(CrowBoss->GetActorLocation(), PlayerActor->GetActorLocation());
    if (DistanceToPlayer > CrowBoss->RangedAttackDistance)
    {
        return EBTNodeResult::Failed;
    }


    if (BlackboardComp->GetValueAsBool("IsAttacking")) return EBTNodeResult::Failed;

    BlackboardComp->SetValueAsBool("IsRangedAttacking", true);
    BlackboardComp->SetValueAsBool("IsAttacking", true);
    CrowBoss->SetIsRangedAttacking(true);
    // Get projectile spawn location + rotation
    FVector MuzzleLocation = CrowBoss->GetActorLocation() + FVector(0.f, 0.f, 100.f);
    FRotator MuzzleRotation = (PlayerActor->GetActorLocation() - MuzzleLocation).Rotation();


     if (CrowBoss->ProjectileClass)
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = CrowBoss;
        SpawnParams.Instigator = CrowBoss;

        ACrowBoss_Projectile* SpawnedActor = CrowBoss->GetWorld()->SpawnActor<ACrowBoss_Projectile>(
            CrowBoss->ProjectileClass,
            MuzzleLocation,
            MuzzleRotation,
            SpawnParams);

        SpawnedActor->LookAt(PlayerActor->GetActorLocation());
         
    }
    
    return EBTNodeResult::Succeeded;
}

