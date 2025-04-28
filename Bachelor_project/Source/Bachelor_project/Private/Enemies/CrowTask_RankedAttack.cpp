// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/CrowTask_RankedAttack.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Enemies/CrowBoss.h"
#include "Enemies/CrowBoss_AIController.h"
#include "Enemies/CrowBoss_Projectile.h"

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

    // Check distance to player
    float DistanceToPlayer = FVector::Dist(CrowBoss->GetActorLocation(), PlayerActor->GetActorLocation());
    if (DistanceToPlayer > CrowBoss->RangedAttackDistance)
    {
        return EBTNodeResult::Failed;
    }

    // Check cooldown or already attacking?
    if (BlackboardComp->GetValueAsBool("IsAttacking")) return EBTNodeResult::Failed;
    //BlackboardComp->SetValueAsBool("IsAttacking", true);

    // Get projectile spawn location + rotation
    FVector MuzzleLocation = CrowBoss->GetActorLocation() + FVector(0.f, 0.f, 100.f); // Adjust to your mesh/socket
    FRotator MuzzleRotation = (PlayerActor->GetActorLocation() - MuzzleLocation).Rotation();

    if (CrowBoss->ProjectileClass)
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = CrowBoss;
        SpawnParams.Instigator = CrowBoss;

        CrowBoss->GetWorld()->SpawnActor<ACrowBoss_Projectile>(
            CrowBoss->ProjectileClass,
            MuzzleLocation,
            MuzzleRotation,
            SpawnParams
        );
    }

    // Optional delay before "ready to attack again"
    //FTimerHandle AttackResetHandle;
    //CrowBoss->GetWorldTimerManager().SetTimer(
    //    AttackResetHandle,
    //    [BlackboardComp]()
    //    {
    //        BlackboardComp->SetValueAsBool("IsAttacking", false);
    //    },
    //    2.0f, // Cooldown time
    //    false
    //);
	return EBTNodeResult::Succeeded;
}
