// Fill out your copyright notice in the Description page of Project Settings.


#include "AIController_SmallCharger.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/PawnSensingComponent.h"


AAIController_SmallCharger::AAIController_SmallCharger()
{
	SmallCharger_BTC = CreateDefaultSubobject<UBehaviorTreeComponent>("SmallCharger Behavior Tree Component");
	SmallCharger_BBC = CreateDefaultSubobject<UBlackboardComponent>("SmallCharger Blackboard Component");
	SmallCharger_PercetionComponent = CreateDefaultSubobject<UPawnSensingComponent>("SmallCharger Perception Component");




}

void AAIController_SmallCharger::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (SmallCharger_BT != NULL)
	{
		SmallCharger_BBC->InitializeBlackboard(*SmallCharger_BT->BlackboardAsset);
		SmallCharger_BTC->StartTree(*SmallCharger_BT);

		SmallCharger_PercetionComponent->OnSeePawn.AddDynamic(this, &AAIController_SmallCharger::OnEnemySeenItsOwner);

	}
}

void AAIController_SmallCharger::ToCheckSpawnStillAround()
{
	float distanceBetweenEnemyPlayer = FVector::Distance(GetNavAgentLocation(),
		FVector(detectPlayer->GetActorLocation().X,
			detectPlayer->GetActorLocation().Y,
			GetNavAgentLocation().Z
		)
	);

	if (distanceBetweenEnemyPlayer > SmallCharger_PercetionComponent->SightRadius)
	{
		SmallCharger_BBC->SetValueAsBool("SeenPlayer", false);
		GetWorld()->GetTimerManager().ClearTimer(timerHandle);
		seenPlayerFirstTime = true;
	}
}


void AAIController_SmallCharger::OnEnemySeenItsOwner(class APawn* SensedPawn)
{
	if (SmallCharger_BTC != nullptr && SensedPawn != nullptr)
	{
		if (seenPlayerFirstTime == true)
		{
			seenPlayerFirstTime = false;

			SmallCharger_BBC->SetValueAsBool("SeenPlayer", true);
			SmallCharger_BBC->SetValueAsObject("Player", SensedPawn);

			detectPlayer = SensedPawn;

			GetWorldTimerManager().SetTimer(timerHandle, this, &AAIController_SmallCharger::ToCheckSpawnStillAround, 2.0f, true, 3.0f);

		}
	}
}

