// Fill out your copyright notice in the Description page of Project Settings.


#include "SmallCharger_AIController.h"

#include "Test_Character.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Perception/PawnSensingComponent.h"



ASmallCharger_AIController::ASmallCharger_AIController()
{

	SmallCharger_PerceptionComponent = CreateDefaultSubobject<UPawnSensingComponent>("SmallCharger Perception Component");
	SmallCharger_BBC = CreateDefaultSubobject<UBlackboardComponent>("BlackBoardComp");
	SmallCharger_BTC = CreateDefaultSubobject<UBehaviorTreeComponent>("SmallCharger BehaviorTree Component");
}

void ASmallCharger_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (SmallCharger_BT!=NULL)
	{
		SmallCharger_BBC->InitializeBlackboard(*SmallCharger_BT->GetBlackboardAsset());
		//RunBehaviorTree(SmallCharger_BT);
		SmallCharger_BTC->StartTree(*SmallCharger_BT);
		SmallCharger_PerceptionComponent->OnSeePawn.AddDynamic(this, &ASmallCharger_AIController::OnSeenPawn);

		SmallCharger_BBC->SetValueAsVector("TargetLocation", FVector(0.f));
	}

}

void ASmallCharger_AIController::BeginPlay()
{
	Super::BeginPlay();

}


void ASmallCharger_AIController::Tick(float deltaTime) {
	Super::Tick(deltaTime);
	/*if (AActor* player = Cast<AActor>(SmallCharger_BBC->GetValueAsObject("Player")))
	{
		if (FVector::Distance(GetNavAgentLocation(), player->GetActorLocation()) > SmallCharger_PerceptionComponent->SightRadius)
		{
			SmallCharger_BBC->SetValueAsBool("SeenPlayer", false);
			SmallCharger_BBC->SetValueAsObject("Player", nullptr);
		}
	}*/

	APawn* ControlledPawn = GetPawn();

	ACharacter* ControlledCharacter = Cast<ACharacter>(ControlledPawn);

	
	if (!ControlledPawn) return;

	if (Player)
	{
		float Distance = FVector::Dist(Player->GetActorLocation(), ControlledPawn->GetActorLocation());
		float ChaseSpeed = 1200.f;
		float WalkSpeed = 600.f;
		if (Distance < 500.f)
		{
			SmallCharger_BBC->SetValueAsBool("SeenPlayer", true);
			ControlledCharacter->GetCharacterMovement()->MaxWalkSpeed = ChaseSpeed;
		}
		else
		{
			SmallCharger_BBC->SetValueAsBool("SeenPlayer", false);
			ControlledCharacter->GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
		}
	}
}

void ASmallCharger_AIController::OnSeenPawn(APawn* SeenPawn)
{
		if (SeenPawn->IsA<ATest_Character>())
	{
		if (!SmallCharger_BBC->GetValueAsBool("SeenPlayer"))
		{
			SmallCharger_BBC->SetValueAsBool("SeenPlayer", true);
			SmallCharger_BBC->SetValueAsObject("Player", SeenPawn);
		}
	}
}

