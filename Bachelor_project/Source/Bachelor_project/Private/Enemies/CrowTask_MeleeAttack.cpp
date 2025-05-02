
#include "Enemies/CrowTask_MeleeAttack.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "TimerManager.h"
#include "Enemies/CrowBoss.h"
#include "Engine/World.h"

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

    AttackRange = CrowBoss->GetAttackRange();
    bHasAttacked = false;

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
            //Draw
            // Sphere(CrowBoss->GetWorld(), HitLocation, 60.f, 12, FColor::Red, false, 1.0f);

            bHasAttacked = true;
            CrowBoss->DiveAttack("MeleeSocket");
            // Stop immediately after attacking
            CrowBoss->GetCharacterMovement()->StopMovementImmediately();

            // Delay to simulate recovery after the attack
            CrowBoss->GetWorldTimerManager().SetTimer(AttackTimer, [this, &OwnerComp]()
                {
                    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
                }, 1.0f, false);
        }
    }
}

