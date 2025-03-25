// Fill out your copyright notice in the Description page of Project Settings.


#include "CrowBoss_AIController.h"

#include "Test_Character.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/PawnSensingComponent.h"


ACrowBoss_AIController::ACrowBoss_AIController()
{
	CrowBoss_PerceptionComponent = CreateDefaultSubobject<UPawnSensingComponent>("CrowBoss Perception Component");
	CrowBoss_BBC = CreateDefaultSubobject<UBlackboardComponent>("BlackBoardComp");
	CrowBoss_BTC = CreateDefaultSubobject<UBehaviorTreeComponent>("CrowBoss Behavior Tree Component");
}


void ACrowBoss_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (CrowBoss_BT != NULL) 
	{
		CrowBoss_BBC->InitializeBlackboard(*CrowBoss_BT->BlackboardAsset);
		CrowBoss_BTC->StartTree(*CrowBoss_BT);

		CrowBoss_PerceptionComponent->OnSeePawn.AddDynamic(this, &ACrowBoss_AIController::OnSeenPawn);

	}
}

void ACrowBoss_AIController::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	APawn* Crow = GetPawn();
	if (!Crow) return;

	if (Player)
	{
		float Distance = FVector::Dist(Player->GetActorLocation(), Crow->GetActorLocation());
		if (Distance < 500.f)
		{
			CrowBoss_BBC->SetValueAsBool("SeenPlayer", true);
		}
		else
		{
			CrowBoss_BBC->SetValueAsBool("SeenPlayer", false);
		}
	}
}

void ACrowBoss_AIController::OnSeenPawn(APawn* SeenPawn)
{
	if (!SeenPawn) return;

	if (SeenPawn->IsA<ATest_Character>()) 
	{
		
		Player = SeenPawn; 
		CrowBoss_BBC->SetValueAsObject("Player", SeenPawn);
		CrowBoss_BBC->SetValueAsBool("SeenPlayer", true);
		UE_LOG(LogTemp, Warning, TEXT("Boss saw the player!"));

		
	}
}




