// Fill out your copyright notice in the Description page of Project Settings.



#include "Enemies/Charger_ChargeTask.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Enemies/Charger.h"
#include "Enemies/Charger_AIController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

/**
 * UCharger_ChargeTask
 *
 * This task handles the Charger enemy’s charge attack.
 * When triggered, it:
 * - Calculates direction and overshoots past the player.
 * - Increases movement speed to simulate a charge.
 * - Monitors distance and time to end the charge.
 * - Resets speed and sets a cooldown after the charge.
 *
 * Uses Blackboard to control states like "IsCharging" and "CanCharge".
 * Only runs if the player is detected and the AI is not dying.
 */

UCharger_ChargeTask::UCharger_ChargeTask()
{
    bNotifyTick = true; 
}

EBTNodeResult::Type UCharger_ChargeTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
   

    AAIController* AIController = OwnerComp.GetAIOwner();
    if (!AIController) return EBTNodeResult::Failed;

    APawn* ControlledPawn = AIController->GetPawn();
    if (!ControlledPawn) return EBTNodeResult::Failed;

    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (!BlackboardComp) return EBTNodeResult::Failed;

    // Get player reference
    AActor* Target = Cast<AActor>(BlackboardComp->GetValueAsObject("Player"));
    if (!Target) return EBTNodeResult::Failed;

    FChargeTaskMemory* Memory = (FChargeTaskMemory*)NodeMemory;

    // Setup charge parameters
    Memory->StartLocation = ControlledPawn->GetActorLocation();
    Memory->TargetLocation = Target->GetActorLocation();

    // Calculate direction vector
    Memory->ChargeDirection = (Memory->TargetLocation - Memory->StartLocation).GetSafeNormal();

    ACharger_AIController* ChargerController = Cast<ACharger_AIController>(OwnerComp.GetAIOwner());
    if (!ChargerController) return EBTNodeResult::Failed;
    APawn* Pawn = ChargerController->GetPawn();
    ACharger* Charger = Cast<ACharger>(Pawn);
    if (!Charger || Charger->GetIsDying()) return EBTNodeResult::Failed;
    if (Charger->GetIsDying()) return EBTNodeResult::Failed;
    Charger->SetIsPatrolling(false);
    Charger->SetIsCharging(true);
    if (ChargerController)
    {
        // Calculate overshoot position
        Memory->TargetLocation = Memory->TargetLocation + (Memory->ChargeDirection * ChargerController->ChargeOvershootDistance);

        BlackboardComp->SetValueAsBool("IsCharging", true);

        // Increase speed for charging
        ACharacter* CharacterPawn = Cast<ACharacter>(ControlledPawn);
        if (CharacterPawn && CharacterPawn->GetCharacterMovement())
        {
            CharacterPawn->GetCharacterMovement()->MaxWalkSpeed = Charger->GetChargeSpeed();
        }
    }

    // Initialize task memory
    Memory->ElapsedTime = 0.0f;
    Memory->bChargeStarted = true;
 
    // Move toward the target
    AIController->MoveToLocation(Memory->TargetLocation, -1.0f, true);

    return EBTNodeResult::Succeeded;
}

void UCharger_ChargeTask::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

    ACharger* Charger = Cast<ACharger>(OwnerComp.GetOwner());
    if (Charger->GetIsDying())  {FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
    return;
}

    FChargeTaskMemory* Memory = (FChargeTaskMemory*)NodeMemory;
    if (!Memory->bChargeStarted) return;

    AAIController* AIController = OwnerComp.GetAIOwner();
    if (!AIController)
    {
        FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
        return;
    }

    APawn* ControlledPawn = AIController->GetPawn();
    if (!ControlledPawn)
    {
        FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
        return;
    }

    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (!BlackboardComp)
    {
        FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
        return;
    }

    Memory->ElapsedTime += DeltaSeconds;

    // Check if we've reached the target or exceeded max charge time
    FVector CurrentLocation = ControlledPawn->GetActorLocation();
    float DistanceToTarget = FVector::Dist2D(CurrentLocation, Memory->TargetLocation);

    // Check if we've completed the charge
    bool bChargeComplete = Memory->ElapsedTime >= MaxChargeTime || DistanceToTarget < 100.0f;

    if (bChargeComplete)
    {
        // Charge complete - start cooldown
        ACharger_AIController* ChargerController = Cast<ACharger_AIController>(AIController);
        if (ChargerController)
        {
            // Reset speed
            ACharacter* CharacterPawn = Cast<ACharacter>(ControlledPawn);
            if (CharacterPawn && CharacterPawn->GetCharacterMovement())
            {
                CharacterPawn->GetCharacterMovement()->MaxWalkSpeed = Charger->GetWalkSpeed();
            }

            ChargerController->CurrentCooldownTime = ChargerController->ChargeCooldown;
            BlackboardComp->SetValueAsBool("CanCharge", false);
            BlackboardComp->SetValueAsFloat("ChargeCooldown", ChargerController->ChargeCooldown);
        }

        BlackboardComp->SetValueAsBool("IsCharging", false);
        Charger->SetIsCharging(false);
        AIController->StopMovement();
        
        FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    }
}
