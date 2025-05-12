#include "Enemies/CrowTask_DiveAttack.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Enemies/CrowBoss.h"
#include "Enemies/CrowBoss_AIController.h"

DEFINE_LOG_CATEGORY_STATIC(LogCrowDiveAttack, Log, All);

/**
 * UCrowTask_DiveAttack
 *
 * Behavior Tree Task node responsible for executing the Crow Boss's dive attack.
 *
 * Task Flow:
 * - Checks if the player has been seen and is within dive range.
 * - Calculates a suitable landing spot beneath the player using a line trace.
 * - Transitions the Crow Boss into flying movement mode and initiates the dive.
 * - Applies launch velocity toward the landing point.
 * - Upon reaching the ground, sets blackboard flags to transition back to standard behavior.
 *
 * Notes:
 * - Uses Blackboard keys: "IsAttacking", "IsDiving", "SeenPlayer", "Player", "DiveLandingSpot", "OriginalPosition", "IsGrounded", "NeedReturnToOrigin"
 * - This task finishes instantly after applying launch.
 */


UCrowTask_DiveAttack::UCrowTask_DiveAttack()
{
    bNotifyTick = true; 

}

EBTNodeResult::Type UCrowTask_DiveAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

    ACrowBoss_AIController* BossAI = Cast<ACrowBoss_AIController>(OwnerComp.GetAIOwner());
    if (!BossAI)
    {
        UE_LOG(LogCrowDiveAttack, Error, TEXT("ExecuteTask: Invalid AI Controller"));
        return EBTNodeResult::Failed;
    }

    ACrowBoss* CrowBoss = Cast<ACrowBoss>(BossAI->GetPawn());
    if (!CrowBoss || CrowBoss->GetIsDying())
    {
        UE_LOG(LogCrowDiveAttack, Warning, TEXT("ExecuteTask: CrowBoss is invalid or dying"));
        return EBTNodeResult::Failed;
    }
   

    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (!BlackboardComp)
    {
        UE_LOG(LogCrowDiveAttack, Error, TEXT("ExecuteTask: Blackboard component is null"));
        return EBTNodeResult::Failed;
    }

    if (!BlackboardComp->GetValueAsBool("SeenPlayer"))
    {
        UE_LOG(LogCrowDiveAttack, Warning, TEXT("ExecuteTask: Player not seen — aborting dive"));
        return EBTNodeResult::Failed;
    }

    AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject("Player"));
    if (!TargetActor)
    {
        UE_LOG(LogCrowDiveAttack, Error, TEXT("ExecuteTask: No valid player actor in blackboard"));
        return EBTNodeResult::Failed;
    }

    float DistanceToPlayer = FVector::Dist(CrowBoss->GetActorLocation(), TargetActor->GetActorLocation());

    if (DistanceToPlayer > CrowBoss->GetDiveAttackRange())
    {
        UE_LOG(LogCrowDiveAttack, Warning, TEXT("ExecuteTask: Player too far for dive"));
        return EBTNodeResult::Failed;
    }


    BlackboardComp->SetValueAsBool("IsAttacking", true);
    BlackboardComp->SetValueAsBool("IsDiving", true);
    CrowBoss->SetIsPreparingDive(true);
    CrowBoss->SetIsPatrolling(false);
    // Calculate landing spot
    FVector Start = TargetActor->GetActorLocation() + FVector(0.f, 0.f, 100.f);
    FVector End = TargetActor->GetActorLocation() - FVector(0.f, 0.f, 2000.f);
    FHitResult Hit;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(CrowBoss);
    Params.AddIgnoredActor(TargetActor);

    FVector LandingSpot = TargetActor->GetActorLocation();
    if (CrowBoss->GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
    {
        LandingSpot = Hit.ImpactPoint;
        UE_LOG(LogCrowDiveAttack, Log, TEXT("ExecuteTask: Found landing spot at %s"), *LandingSpot.ToString());
        DrawDebugSphere(CrowBoss->GetWorld(), LandingSpot, 50.f, 12, FColor::Red, false, 3.0f);
    }
    else
    {
        UE_LOG(LogCrowDiveAttack, Warning, TEXT("ExecuteTask: Could not find landing spot, using player location"));
    }

    // Face the landing spot
    FVector Direction = (LandingSpot - CrowBoss->GetActorLocation()).GetSafeNormal();
    FRotator LookAtRotation = Direction.Rotation();
    CrowBoss->SetActorRotation(CrowBoss->GetActorRotation());

    BlackboardComp->SetValueAsVector("DiveLandingSpot", LandingSpot);
    BlackboardComp->SetValueAsVector("OriginalPosition", CrowBoss->GetActorLocation());

    CrowBoss->GetCharacterMovement()->SetMovementMode(MOVE_Flying);

    UE_LOG(LogCrowDiveAttack, Log, TEXT("ExecuteTask: Dive attack setup complete — entering InProgress"));

    return EBTNodeResult::InProgress;
}


void UCrowTask_DiveAttack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    ACrowBoss_AIController* BossAI = Cast<ACrowBoss_AIController>(OwnerComp.GetAIOwner());
    if (!BossAI)
    {
        UE_LOG(LogCrowDiveAttack, Error, TEXT("TickTask: Invalid AI Controller"));
        return;
    }

    ACrowBoss* CrowBoss = Cast<ACrowBoss>(BossAI->GetPawn());
    if (!CrowBoss || CrowBoss->GetIsDying())
    {
        UE_LOG(LogCrowDiveAttack, Warning, TEXT("TickTask: CrowBoss is invalid or dying"));
        return;
    }

    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (!BlackboardComp)
    {
        UE_LOG(LogCrowDiveAttack, Error, TEXT("TickTask: Blackboard component is null"));
        return;
    }
    if (!CrowBoss->GetIsDiving())
    {

        return ;
    }
    FVector LandingSpot = BlackboardComp->GetValueAsVector("DiveLandingSpot");
    FVector CurrentPosition = CrowBoss->GetActorLocation();

    FVector Direction = (LandingSpot - CurrentPosition).GetSafeNormal();
    CrowBoss->GetCharacterMovement()->SetMovementMode(MOVE_Falling); 
    CrowBoss->LaunchCharacter(Direction * DiveSpeed, true, true);    

    float Distance = FVector::Dist(CurrentPosition, LandingSpot);

    BlackboardComp->SetValueAsBool("IsGrounded", true);
    BlackboardComp->SetValueAsBool("NeedReturnToOrigin", true);
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
}

