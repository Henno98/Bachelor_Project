// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/PlantTask_ShootAttack.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/Actor.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Enemies/Plant.h"
#include "Player/Test_Character.h"

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
		UE_LOG(LogTemp, Log, TEXT("ShootTask: Plant implements IIsRangedAttacker interface. Setting ranged parameters."));

		Plant->SetTargetLocation_Implementation(Plant->GetActorForwardVector());
		Plant->SetDamage(1.f);
		Plant->SetRangedAttackVelocity_Implementation(400.f);
		Plant->SetBulletSize_Implementation(FVector(2.f));
		Plant->SetFiringDirection_Implementation(Plant->GetActorRotation());

		UE_LOG(LogTemp, Log, TEXT("ShootTask: Parameters set: Damage=1.0, Velocity=400.0, BulletSize=(2.0, 2.0, 2.0)"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ShootTask: Plant does NOT implement IIsRangedAttacker."));
	}

	UE_LOG(LogTemp, Log, TEXT("ShootTask: Calling Plant->CallGAS_RangedAttack()"));
	Plant->CallGAS_RangedAttack();  // You mentioned "How to get GAS???" — see below

	return EBTNodeResult::Succeeded;
}