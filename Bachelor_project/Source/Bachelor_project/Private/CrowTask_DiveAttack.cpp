// Fill out your copyright notice in the Description page of Project Settings.


#include "CrowTask_DiveAttack.h"
#include "CrowBoss_AIController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
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

    bool bSeenPlayer = BlackboardComp->GetValueAsBool("SeenPlayer");
    if (!bSeenPlayer) return EBTNodeResult::Failed;

    AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject("Player"));
    if (!TargetActor) return EBTNodeResult::Failed;

    float DistanceToPlayer = FVector::Dist(AIPawn->GetActorLocation(), TargetActor->GetActorLocation());

    float AttackRange = 600.0f;
    if (DistanceToPlayer > AttackRange) return EBTNodeResult::Failed;

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
        FVector HorizontalDirection = FVector(
            LandingSpot.X - CurrentLocation.X,
            LandingSpot.Y - CurrentLocation.Y,
            0.0f
        ).GetSafeNormal();

        FVector DiveDirection = HorizontalDirection - FVector(0.0f, 0.0f, 1.0f);
        DiveDirection = DiveDirection.GetSafeNormal();

        CrowBoss->GetCharacterMovement()->SetMovementMode(MOVE_Flying);
        CrowBoss->LaunchCharacter(DiveDirection * DiveSpeed, true, true);

        FTimerHandle LandTimerHandle;
        CrowBoss->GetWorldTimerManager().SetTimer(
            LandTimerHandle,
            [CrowBoss, BlackboardComp]()
            {
                CrowBoss->GetCharacterMovement()->StopMovementImmediately();
                CrowBoss->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
            },
            0.5f,
            false
        );

        FTimerHandle ReturnTimerHandle;
        CrowBoss->GetWorldTimerManager().SetTimer(
            ReturnTimerHandle,
            [this, CrowBoss, BlackboardComp]()
            {
                CrowBoss->GetCharacterMovement()->SetMovementMode(MOVE_Flying);
                FVector CurrentPos = CrowBoss->GetActorLocation();
                FVector OriginalPosition = BlackboardComp->GetValueAsVector("OriginalPosition");

                // Log starting position for debugging
                UE_LOG(LogTemp, Warning, TEXT("Starting return journey from %s to %s"),
                    *CurrentPos.ToString(), *OriginalPosition.ToString());

                // Calculate return direction and launch
                FVector ReturnDirection = (OriginalPosition - CurrentPos).GetSafeNormal();
                CrowBoss->LaunchCharacter(ReturnDirection * (DiveSpeed * 0.5f), true, true);

                // Instead of nested lambdas with timer handles, use a class member
                // to track the return journey
                StartReturnJourneyTracking(CrowBoss, BlackboardComp, OriginalPosition);
            },
            5.0f, // Wait 5 seconds after dive before starting return
            false
        );

        return EBTNodeResult::Succeeded;
    }

    return EBTNodeResult::Failed;
}

void UCrowTask_DiveAttack::StartReturnJourneyTracking(ACharacter* CrowBoss, UBlackboardComponent* BlackboardComp, FVector OriginalPosition)
{
    struct FReturnData* ReturnData = new FReturnData();
    ReturnData->LastPosition = CrowBoss->GetActorLocation();
    ReturnData->StationaryTime = 0.0f;
    ReturnData->HasMoved = false;

    // Use member variables instead of local variables
    CrowBoss->GetWorldTimerManager().SetTimer(
        CheckPositionTimerHandle,
        [CrowBoss, BlackboardComp, OriginalPosition, ReturnData, this]()
        {
            FVector CurrentPos = CrowBoss->GetActorLocation();
            float DistToOriginal = FVector::Dist(CurrentPos, OriginalPosition);
            float MovementSinceLast = FVector::Dist(CurrentPos, ReturnData->LastPosition);

            if (MovementSinceLast > 10.0f) {
                ReturnData->HasMoved = true;
                ReturnData->StationaryTime = 0.0f;
            }
            else {
                ReturnData->StationaryTime += 0.1f;
            }

            ReturnData->LastPosition = CurrentPos;

            bool isComplete = (DistToOriginal < 100.0f) ||
                (ReturnData->HasMoved && ReturnData->StationaryTime > 0.5f);

            if (isComplete)
            {
                CrowBoss->GetCharacterMovement()->StopMovementImmediately();

                if (DistToOriginal > 50.0f) {
                    CrowBoss->SetActorLocation(OriginalPosition);
                }

                BlackboardComp->SetValueAsBool("IsAttacking", false);

                // Clear both timers using member variables
                CrowBoss->GetWorldTimerManager().ClearTimer(CheckPositionTimerHandle);
                CrowBoss->GetWorldTimerManager().ClearTimer(SafetyTimerHandle);

                UE_LOG(LogTemp, Warning, TEXT("Boss returned to position. Distance: %f, Stationary time: %f"),
                    DistToOriginal, ReturnData->StationaryTime);

                delete ReturnData;
            }
        },
        0.1f, true
    );

    CrowBoss->GetWorldTimerManager().SetTimer(
        SafetyTimerHandle,
        [CrowBoss, BlackboardComp, ReturnData, this]()
        {
            CrowBoss->GetCharacterMovement()->StopMovementImmediately();
            BlackboardComp->SetValueAsBool("IsAttacking", false);

            CrowBoss->GetWorldTimerManager().ClearTimer(CheckPositionTimerHandle);

            UE_LOG(LogTemp, Warning, TEXT("Safety timer triggered - force stopping return"));

            delete ReturnData;
        },
        5.0f, false
    );
}



