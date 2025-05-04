// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/CrowTask_DiveAttack.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"                
#include "TimerManager.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "Enemies/CrowBoss.h"
#include "Enemies/CrowBoss_AIController.h"

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
    if (CrowBoss->GetIsDying() == true) return EBTNodeResult::Failed;
    float DistanceToPlayer = FVector::Dist(AIPawn->GetActorLocation(), TargetActor->GetActorLocation());
    if (DistanceToPlayer > CrowBoss->GetVisionRange()) return EBTNodeResult::Failed;
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

        
        FTimerHandle LandingTimerHandle;
        FTimerDelegate LandingTimerDelegate;
        LandingTimerDelegate.BindLambda([CrowBoss, BlackboardComp, LandingSpot]() {
            if (CrowBoss)
            {
                
                CrowBoss->GetCharacterMovement()->StopMovementImmediately();
                CrowBoss->GetCharacterMovement()->Velocity = FVector::ZeroVector;
                CrowBoss->GetCharacterMovement()->SetMovementMode(MOVE_Walking);

               
                CrowBoss->DiveAttack("DiveAttackSocket");

                
                BlackboardComp->SetValueAsBool("LandedFromDive", true);

                
            }
            });

        
        float EstimatedFlightTime = HorizontalDirection.Size() / DiveSpeed;
        
        EstimatedFlightTime = FMath::Max(EstimatedFlightTime * 0.8f, 0.5f);

        // Set the timer
        AIPawn->GetWorldTimerManager().SetTimer(
            LandingTimerHandle,
            LandingTimerDelegate,
            EstimatedFlightTime,
            false
        );

        return EBTNodeResult::Succeeded;
    }

    return EBTNodeResult::Failed;
}









