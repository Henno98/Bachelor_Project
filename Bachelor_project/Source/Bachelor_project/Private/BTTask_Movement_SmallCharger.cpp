// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Movement_SmallCharger.h"
#include "Wandering_Target_Point.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTree.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "SmallCharger_AIController.h"



//EBTNodeResult::Type UBTTask_Movement_SmallCharger::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
//{
//	int i = FMath::RandRange(0, 3);
//
//	TArray<AActor*> targets;
//	UGameplayStatics::GetAllActorsOfClass(OwnerComp.GetOwner()->GetWorld(), AWandering_Target_Point::StaticClass(), targets);
//	OwnerComp.GetBlackboardComponent()->SetValueAsVector("Wandering_Point", targets[i]->GetActorLocation());
//	return EBTNodeResult::Succeeded;
//}


EBTNodeResult::Type UBTTask_Movement_SmallCharger::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	UBlackboardComponent* smallcharger_bb_component = OwnerComp.GetBlackboardComponent();

	TArray<AActor*> WanderingPoints;
	UGameplayStatics::GetAllActorsOfClass(OwnerComp.GetOwner()->GetWorld(), AWandering_Target_Point::StaticClass(), WanderingPoints);

	if (WanderingPoints.Num() == 0)
	{
		return EBTNodeResult::Failed;
		
	}

	//find AI controller
	ASmallCharger_AIController* AI_smallcharger_ai_controller = Cast<ASmallCharger_AIController>(OwnerComp.GetAIOwner());


	//set start location
	AWandering_Target_Point* old_targetPoint = Cast<AWandering_Target_Point>(smallcharger_bb_component->GetValueAsObject("Wandering_Point"));


	if (old_targetPoint == nullptr) {
		AI_smallcharger_ai_controller->smallCharger_start_location = AI_smallcharger_ai_controller->GetNavAgentLocation();

	}
	else {
		AI_smallcharger_ai_controller->smallCharger_start_location = old_targetPoint->GetActorLocation();
	}


	//set new location
	AWandering_Target_Point* new_smallcharger_wandering_point = Cast<AWandering_Target_Point>(WanderingPoints[FMath::RandRange(0, WanderingPoints.Num() - 1)]);

	smallcharger_bb_component->SetValueAsObject("Wandering_Point", new_smallcharger_wandering_point);

	AI_smallcharger_ai_controller->smallCharger_target_location = new_smallcharger_wandering_point->GetActorLocation();


	//calculate initial distance
	AI_smallcharger_ai_controller->initialDistance = FVector::Distance(
		AI_smallcharger_ai_controller->smallCharger_start_location,
		AI_smallcharger_ai_controller->smallCharger_target_location
	);

	return EBTNodeResult::Succeeded;
}
