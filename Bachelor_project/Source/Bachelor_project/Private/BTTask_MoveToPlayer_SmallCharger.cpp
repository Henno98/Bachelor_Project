// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MoveToPlayer_SmallCharger.h"

#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UBTTask_MoveToPlayer_SmallCharger::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type result = EBTNodeResult::Failed;
	UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent();
	if (AActor* player = Cast<AActor>(BB->GetValueAsObject("Player")))
	{
		FVector Direction = (player->GetActorLocation() - OwnerComp.GetOwner()->GetActorLocation()).GetSafeNormal();

		float OvershootDistance = 200.f;
		FVector TargetLocation = player->GetActorLocation() + Direction * OvershootDistance;

		TargetLocation.Z = OwnerComp.GetOwner()->GetActorLocation().Z;
		BB->SetValueAsVector("TargetLocation", FVector(TargetLocation.X, TargetLocation.Y, OwnerComp.GetOwner()->GetActorLocation().Z));
		result = EBTNodeResult::Succeeded;
	}
	return result;
}


