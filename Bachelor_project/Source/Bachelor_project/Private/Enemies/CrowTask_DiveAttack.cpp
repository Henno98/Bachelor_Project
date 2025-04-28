// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemies/CrowTask_DiveAttack.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"                
#include "TimerManager.h"
#include "Enemies/CrowBoss_AIController.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include <Enemies/CrowBoss.h>


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



    ACrowBoss* CrowBoss = Cast<ACrowBoss>(AIPawn);

    float DistanceToPlayer = FVector::Dist(AIPawn->GetActorLocation(), TargetActor->GetActorLocation());
    float DiveRange = CrowBoss->DiveAttackRange;

    if (DistanceToPlayer > DiveRange) return EBTNodeResult::Failed;
    //if (DistanceToPlayer > 600.0f) return EBTNodeResult::Failed;
    

    

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

    
    if (CrowBoss)
    {
        FVector HorizontalDirection = (LandingSpot - CurrentLocation);
        HorizontalDirection.Z = 0.f;

        FVector DiveDirection = (HorizontalDirection - FVector(0, 0, 400.f)).GetSafeNormal(); 
        CrowBoss->GetCharacterMovement()->SetMovementMode(MOVE_Flying);
        CrowBoss->LaunchCharacter(DiveDirection * DiveSpeed, true, true);

        float DiveDistance = FVector::Dist(CurrentLocation, LandingSpot);
        float FlightTime = DiveDistance / DiveSpeed;

        
        FTimerHandle DelayHandle;
        CrowBoss->GetWorldTimerManager().SetTimer(
            DelayHandle,
            [CrowBoss, BlackboardComp]()
            {
                // Stop movement and reset mode
                CrowBoss->GetCharacterMovement()->StopMovementImmediately();
                CrowBoss->GetCharacterMovement()->Velocity = FVector::ZeroVector;
                CrowBoss->GetCharacterMovement()->SetMovementMode(MOVE_Walking);

                // Mark dive complete
                BlackboardComp->SetValueAsBool("LandedFromDive", true);

            },
            FlightTime,
            false
        );


        return EBTNodeResult::Succeeded;
    }

    return EBTNodeResult::Failed;
}






