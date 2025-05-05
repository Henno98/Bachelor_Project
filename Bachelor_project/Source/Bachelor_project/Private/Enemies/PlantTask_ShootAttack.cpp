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
	if (!AICon) return EBTNodeResult::Failed;

	APawn* AIPawn = AICon->GetPawn();
	if (!AIPawn) return EBTNodeResult::Failed;

	APlant* Plant = Cast<APlant>(AICon->GetPawn());
	if (!Plant) return  EBTNodeResult::Failed;

	Plant->CallGAS_RangedAttack();
	//How to get GAS???

	return EBTNodeResult::Succeeded;
}