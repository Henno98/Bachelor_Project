// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemies/ReturnToOrigin_Task.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Enemies/CrowBoss.h"
#include "Enemies/CrowBoss_AIController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

/**
 * UReturnToOrigin_Task
 *
 * Behavior tree task for the CrowBoss to return to its original position.
 * - The task makes the CrowBoss fly towards a stored "OriginalPosition".
 * - During the movement, it sets various blackboard values related to the state of the AI (e.g., walking, patrolling, grounded).
 * - Continuously moves the CrowBoss towards the original position using movement input.
 * - Once the CrowBoss is close to the original position (within 100 units), it stops movement and sets the AI's attack state to false.
 * - The task finishes successfully when the CrowBoss reaches the original position.
 * - Randomly sets attack-related states (ranged, melee, dive) to false before finishing.
 */


UReturnToOrigin_Task::UReturnToOrigin_Task()
{
    bNotifyTick = true; 
}

EBTNodeResult::Type UReturnToOrigin_Task::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    ACrowBoss_AIController* BossAI = Cast<ACrowBoss_AIController>(OwnerComp.GetAIOwner());
    if (!BossAI) return EBTNodeResult::Failed;
    ACrowBoss* CrowBoss = Cast<ACrowBoss>(BossAI->GetPawn());
    if (!CrowBoss) return EBTNodeResult::Failed;
    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (!BlackboardComp) return EBTNodeResult::Failed;
    CrowBoss->GetCharacterMovement()->SetMovementMode(MOVE_Flying);
    FVector OriginalPosition = BlackboardComp->GetValueAsVector("OriginalPosition");
    FVector CurrentPosition = CrowBoss->GetActorLocation();
    CrowBoss->SetIsWalking(false);
    CrowBoss->SetIsPatrolling(true);
    BlackboardComp->SetValueAsBool("IsGrounded", false);

   return EBTNodeResult::InProgress;
}

void UReturnToOrigin_Task::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    ACrowBoss_AIController* BossAI = Cast<ACrowBoss_AIController>(OwnerComp.GetAIOwner());
    if (!BossAI) return ;
    ACrowBoss* CrowBoss = Cast<ACrowBoss>(BossAI->GetPawn());
    if (!CrowBoss) return ;
    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (!BlackboardComp) return;
    if (!CrowBoss || !BlackboardComp) return;
    FVector OriginalPosition = BlackboardComp->GetValueAsVector("OriginalPosition");
    FVector CurrentPosition = CrowBoss->GetActorLocation();
    FVector Direction = (OriginalPosition - CurrentPosition).GetSafeNormal();
    
    CrowBoss->AddMovementInput(Direction, 1.0f);
    // Face the landing spot
     FRotator LookAtRotation = Direction.Rotation();
    CrowBoss->SetActorRotation(CrowBoss->GetActorRotation() + LookAtRotation*DeltaSeconds);
    float Distance = FVector::Dist(CurrentPosition, OriginalPosition);
    if (Distance < 100.0f)
    {
        int random = FMath::RandRange(1,3);
        int meleechance = FMath::RandRange(0, 1);
        if (random == 1)
        {
            BlackboardComp->SetValueAsBool("IsDiving", false);
        }
        if (random == 2)
        {
            BlackboardComp->SetValueAsBool("IsRangedAttacking", false);

        } if (random == 3)
        {
            BlackboardComp->SetValueAsBool("IsRangedAttacking", false);
            BlackboardComp->SetValueAsBool("IsDiving", false);

        }
        if (meleechance == 1) {
            BlackboardComp->SetValueAsBool("IsMeleeAttacking", false);
        }

        CrowBoss->SetActorLocation(OriginalPosition); 
        CrowBoss->GetCharacterMovement()->StopMovementImmediately();
        BlackboardComp->SetValueAsBool("IsAttacking", false);
        BlackboardComp->SetValueAsBool("LandedFromDive", false);
      
        
        FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    }
}




