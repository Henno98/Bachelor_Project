// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/BeetleTask_Wandering.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Enemies/Beetle.h"
#include "Enemies/Beetle_AIController.h"
#include "Enemies/Wandering_Target_Point.h"
#include "Kismet/GameplayStatics.h"

/**
 * UBeetleTask_Wandering
 *
 * Behavior Tree Task for the Beetle AI to choose a new random wandering target.
 * - Selects a random AWandering_Target_Point from the world.
 * - Updates blackboard with new target location and point.
 * - Initializes movement data for the Beetle AI.
 * - Fails if no points are found or if the chosen point is too far.
 */

UBeetleTask_Wandering::UBeetleTask_Wandering()
{
}

EBTNodeResult::Type UBeetleTask_Wandering::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return EBTNodeResult::Failed;

	TArray<AActor*> WanderingPoints;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWandering_Target_Point::StaticClass(), WanderingPoints);

	if (WanderingPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No wandering points found!"));
		return EBTNodeResult::Failed;
	}

	ABeetle_AIController* BeetleController = Cast<ABeetle_AIController>(OwnerComp.GetAIOwner());
	if (!BeetleController) return EBTNodeResult::Failed;

	APawn* Pawn = BeetleController->GetPawn();
	ABeetle* Beetle = Cast<ABeetle>(Pawn);
	if (!Beetle || Beetle->GetIsDying()) return EBTNodeResult::Failed;

	Beetle->SetIsPatrolling(true);

	AWandering_Target_Point* OldTargetPoint = Cast<AWandering_Target_Point>(BlackboardComp->GetValueAsObject("WanderingPoint"));

	FVector StartLocation = OldTargetPoint ? OldTargetPoint->GetActorLocation() : BeetleController->GetNavAgentLocation();

	int32 RandomIndex = FMath::RandRange(0, WanderingPoints.Num() - 1);
	AWandering_Target_Point* NewWanderingPoint = Cast<AWandering_Target_Point>(WanderingPoints[RandomIndex]);

	if (!NewWanderingPoint) return EBTNodeResult::Failed;

	if (FVector::Dist(OwnerComp.GetOwner()->GetActorLocation(), NewWanderingPoint->GetActorLocation()) > 2000)
		return EBTNodeResult::Failed;


	BlackboardComp->SetValueAsObject("WanderingPoint", NewWanderingPoint);

	FVector TargetLocation = NewWanderingPoint->GetActorLocation();
	BeetleController->beetle_start_location = StartLocation;
	BeetleController->beetle_target_location = TargetLocation;
	BeetleController->InitialDistance = FVector::Distance(StartLocation, TargetLocation);

	BlackboardComp->SetValueAsVector("MoveToLocation", TargetLocation);

	return EBTNodeResult::Succeeded;
	
}
