
#include "Enemies/CrowTask_MeleeAttack.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"
#include "Enemies/CrowBoss.h"
#include "Engine/World.h"

/**
 * UCrowTask_MeleeAttack
 *
 * Behavior Tree Task for the Crow Boss AI to perform a melee attack.
 * - Begins moving toward the player if out of range.
 * - Faces the player during movement.
 * - Triggers a melee attack when within striking distance.
 * - Sets blackboard flags to control animation and behavior state.
 * - Handles attack delay/recovery using a timer, then signals task completion.
 */


UCrowTask_MeleeAttack::UCrowTask_MeleeAttack()
{
    bNotifyTick = true;
    NodeName = "MeleeAttack";
}

EBTNodeResult::Type UCrowTask_MeleeAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    BossAI = Cast<ACrowBoss_AIController>(OwnerComp.GetAIOwner());
    if (!BossAI) return EBTNodeResult::Failed;

    Blackboard = OwnerComp.GetBlackboardComponent();
    if (!Blackboard) return EBTNodeResult::Failed;

    CrowBoss = Cast<ACrowBoss>(BossAI->GetPawn());
    if (!CrowBoss) return EBTNodeResult::Failed;

    if (CrowBoss->GetIsDying() == true) return EBTNodeResult::Failed;

    PlayerActor = Cast<AActor>(Blackboard->GetValueAsObject("Player"));
    if (!PlayerActor) return EBTNodeResult::Failed;

    Blackboard->SetValueAsBool("IsMeleeAttacking", true);
    Blackboard->SetValueAsBool("IsAttacking", true);
  

    AttackRange = CrowBoss->GetAttackRange();
    bHasAttacked = false;
    CrowBoss->SetIsWalking(true);
    CrowBoss->GetCharacterMovement()->SetMovementMode(MOVE_Walking);

    return EBTNodeResult::InProgress;
}

void UCrowTask_MeleeAttack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    if (!CrowBoss || !PlayerActor) return;

    FVector ToPlayer = PlayerActor->GetActorLocation() - CrowBoss->GetActorLocation();
    float Distance = ToPlayer.Size();

    // Face the player
    FRotator LookAt = ToPlayer.Rotation();
    CrowBoss->SetActorRotation(FMath::RInterpTo(CrowBoss->GetActorRotation(), LookAt, DeltaSeconds, 5.0f));


    

    if (!bHasAttacked)
    {
        if (Distance > ChaseRange)
        {
            
            CrowBoss->AddMovementInput(ToPlayer.GetSafeNormal(), 1.0f);
        }
        else
        {
            // In range to ATTEMPT an attack (whether it lands or not)
            FVector HitLocation = CrowBoss->GetActorLocation() + CrowBoss->GetActorForwardVector() * HitRange;

            bHasAttacked = true;
            CrowBoss->SetIsMeleeAttacking(true);
            CrowBoss->GetCharacterMovement()->StopMovementImmediately();

            CrowBoss->GetWorldTimerManager().SetTimer(AttackTimer, [this, &OwnerComp]()
                {   CrowBoss->SetIsMeleeAttacking(false);
				//Blackboard->SetValueAsBool("IsMeleeAttacking", false);
            Blackboard->SetValueAsBool("NeedReturnToOrigin", true);
                    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
                }, 1.0f, false);
        }
    }
}

