// Fill out your copyright notice in the Description page of Project Settings.


#include "ReturnToOrigin_Task.h"
#include "CrowBoss_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UReturnToOrigin_Task::UReturnToOrigin_Task()
{
    
}

EBTNodeResult::Type UReturnToOrigin_Task::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    ACrowBoss_AIController* BossAI = Cast<ACrowBoss_AIController>(OwnerComp.GetAIOwner());
    if (!BossAI) return EBTNodeResult::Failed;

    ACharacter* CrowBoss = Cast<ACharacter>(BossAI->GetPawn());
    if (!CrowBoss) return EBTNodeResult::Failed;

    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (!BlackboardComp) return EBTNodeResult::Failed;

    FVector OriginalPosition = BlackboardComp->GetValueAsVector("OriginalPosition");
    FVector CurrentPos = CrowBoss->GetActorLocation();

    // Check the distance to the original position
    float DistanceToOriginal = FVector::Dist(CurrentPos, OriginalPosition);

    // If the boss is close enough to the original position
    if (DistanceToOriginal < 100.0f)
    {
        // Snap to the original position if necessary
        CrowBoss->SetActorLocation(OriginalPosition);
        BlackboardComp->SetValueAsBool("IsAttacking", false);
        return EBTNodeResult::Succeeded; // Task succeeded
    }

    // Otherwise, move towards the original position
    FVector DirectionToOriginal = (OriginalPosition - CurrentPos).GetSafeNormal();
    CrowBoss->GetCharacterMovement()->SetMovementMode(MOVE_Flying);
    CrowBoss->LaunchCharacter(DirectionToOriginal * (DiveSpeed * 0.5f), true, true);

    return EBTNodeResult::InProgress; // Task is still in progress
}


