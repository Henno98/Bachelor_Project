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
    FVector CurrentPosition = CrowBoss->GetActorLocation();
    FVector ReturnDirection = (OriginalPosition - CurrentPosition).GetSafeNormal();

    // Set flying mode for return flight
    CrowBoss->GetCharacterMovement()->SetMovementMode(MOVE_Flying);
    CrowBoss->LaunchCharacter(ReturnDirection * (DiveSpeed * 0.5f), true, true);

    // Store the timer handle as a class member so we can reference it properly
    FTimerHandle* CheckTimerPtr = new FTimerHandle();
    FTimerHandle& CheckTimer = *CheckTimerPtr;

    CrowBoss->GetWorldTimerManager().SetTimer(
        CheckTimer,
        [CrowBoss, OriginalPosition, BlackboardComp, CheckTimerPtr]()
        {
            const float Distance = FVector::Dist(CrowBoss->GetActorLocation(), OriginalPosition);

            // Lowered the distance threshold and removed speed check which could be unreliable
            if (Distance < 50.f)
            {
                CrowBoss->GetCharacterMovement()->StopMovementImmediately();
                CrowBoss->SetActorLocation(OriginalPosition); // Force exact position
                CrowBoss->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
                BlackboardComp->SetValueAsBool("IsAttacking", false);
                BlackboardComp->SetValueAsBool("LandedFromDive", false);

                // Clear timer and clean up pointer
                CrowBoss->GetWorldTimerManager().ClearTimer(*CheckTimerPtr);
                delete CheckTimerPtr;
            }
        },
        0.1f, true
    );

    return EBTNodeResult::Succeeded;
}




