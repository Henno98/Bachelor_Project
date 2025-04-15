// Fill out your copyright notice in the Description page of Project Settings.


#include "CrowTask_DiveAttack.h"
#include "CrowBoss_AIController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"                
#include "TimerManager.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"


UCrowTask_DiveAttack::UCrowTask_DiveAttack()
{
}

EBTNodeResult::Type UCrowTask_DiveAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    ACrowBoss_AIController* BossAI = Cast<ACrowBoss_AIController>(OwnerComp.GetAIOwner());
    if (!BossAI) return EBTNodeResult::Failed;

    APawn* AIPawn = BossAI->GetPawn();
    if (!AIPawn) return EBTNodeResult::Failed;

    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (!BlackboardComp) return EBTNodeResult::Failed;

    if (!BlackboardComp->GetValueAsBool("SeenPlayer")) return EBTNodeResult::Failed;

    AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject("Player"));
    if (!TargetActor) return EBTNodeResult::Failed;

    float DistanceToPlayer = FVector::Dist(AIPawn->GetActorLocation(), TargetActor->GetActorLocation());
    if (DistanceToPlayer > 600.0f) return EBTNodeResult::Failed;

    if (BlackboardComp->GetValueAsBool("IsAttacking")) return EBTNodeResult::Failed;

    BlackboardComp->SetValueAsBool("IsAttacking", true);

    FVector PlayerLocation = TargetActor->GetActorLocation();
    FVector CurrentLocation = AIPawn->GetActorLocation();

    FVector Start = PlayerLocation + FVector(0.f, 0.f, 100.f);
    FVector End = PlayerLocation - FVector(0.f, 0.f, 2000.f);

    FHitResult Hit;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(AIPawn);
    Params.AddIgnoredActor(TargetActor);

    bool bHit = AIPawn->GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params);

    FVector LandingSpot = PlayerLocation;
    if (bHit)
    {
        LandingSpot = Hit.ImpactPoint;
        DrawDebugSphere(AIPawn->GetWorld(), LandingSpot, 50.f, 12, FColor::Red, false, 3.0f);
    }

    BlackboardComp->SetValueAsVector("DiveLandingSpot", LandingSpot);
    BlackboardComp->SetValueAsVector("OriginalPosition", CurrentLocation);

    ACharacter* CrowBoss = Cast<ACharacter>(AIPawn);
    if (CrowBoss)
    {
        FVector HorizontalDirection = (LandingSpot - CurrentLocation);
        HorizontalDirection.Z = 0.f;

        FVector DiveDirection = (HorizontalDirection - FVector(0, 0, 400.f)).GetSafeNormal(); 
        CrowBoss->GetCharacterMovement()->SetMovementMode(MOVE_Flying);
        CrowBoss->LaunchCharacter(DiveDirection * DiveSpeed, true, true);

        
        FTimerHandle DelayHandle;
        CrowBoss->GetWorldTimerManager().SetTimer(
            DelayHandle,
            [CrowBoss, BlackboardComp]()
            {
                // Ensure the boss stops moving completely
                CrowBoss->GetCharacterMovement()->StopMovementImmediately();
                CrowBoss->GetCharacterMovement()->Velocity = FVector::ZeroVector;
                CrowBoss->GetCharacterMovement()->SetMovementMode(MOVE_Walking);

                // Set blackboard key to continue behavior
                BlackboardComp->SetValueAsBool("LandedFromDive", true);
            },
            0.3f,
            false
        );


        return EBTNodeResult::Succeeded;
    }

    return EBTNodeResult::Failed;
}






