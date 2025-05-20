// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/PlantTask_ShootAttack.h"
#include "GameFramework/Actor.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Enemies/Plant.h"
#include "Player/Test_Character.h"

/**
 * UPlantTask_ShootAttack
 *
 * Behavior tree task for the Plant to perform a ranged attack.
 * - Checks if the AIController and the Plant pawn are valid before proceeding.
 * - Verifies that the Plant pawn implements the IIsRangedAttacker interface.
 * - Sets up the ranged attack parameters, including target location, damage, velocity, bullet size, and firing direction.
 * - Calls the Plant's ranged attack function through the gameplay ability system (GAS).
 * - Logs warnings if any required components are missing or if the Plant does not implement the required interface.
 * - Successfully completes the task if the ranged attack setup is executed correctly.
 */


UPlantTask_ShootAttack::UPlantTask_ShootAttack()
{
}

EBTNodeResult::Type UPlantTask_ShootAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AICon = OwnerComp.GetAIOwner();
	if (!AICon) {
		UE_LOG(LogTemp, Warning, TEXT("ShootTask: No AIController found."));
		return EBTNodeResult::Failed;
	}

	APawn* AIPawn = AICon->GetPawn();
	if (!AIPawn) {
		UE_LOG(LogTemp, Warning, TEXT("ShootTask: No Pawn found."));
		return EBTNodeResult::Failed;
	}

	APlant* Plant = Cast<APlant>(AIPawn);
	if (!Plant) {
		UE_LOG(LogTemp, Warning, TEXT("ShootTask: Pawn is not of type APlant."));
		return EBTNodeResult::Failed;
	}

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) {
		UE_LOG(LogTemp, Warning, TEXT("ShootTask: No BlackboardComponent found."));
		return EBTNodeResult::Failed;
	}

	if (Plant->GetClass()->ImplementsInterface(UIsRangedAttacker::StaticClass()))
	{
		Plant->SetDamage(1.f);
		Plant->SetRangedAttackVelocity_Implementation(400.f);
		Plant->SetBulletSize_Implementation(FVector(2.f));

		// Update spawn location a bit in front of the plant
		FVector SpawnLoc = Plant->GetActorLocation() + Plant->GetActorForwardVector() * 100.f;
		Plant->SetSpawnLocation_Implementation(SpawnLoc);

		// Update firing direction based on forward vector rotation
		FRotator FireDir = Plant->GetActorForwardVector().Rotation();
		Plant->SetFiringDirection_Implementation(FireDir);

		// Optionally set target location (if your AI tracks a player)
		AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject("Player"));
		if (TargetActor)
		{
			Plant->SetHasTarget_Implementation(true);
			Plant->SetTargetLocation_Implementation(TargetActor->GetActorLocation());
		}
		else
		{
			Plant->SetHasTarget_Implementation(false);
			Plant->SetTargetLocation_Implementation(FVector::ZeroVector);
		}
		
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ShootTask: Plant does NOT implement IIsRangedAttacker."));
	}

	Plant->CallGAS_RangedAttack();  

	return EBTNodeResult::Succeeded;
}