// Fill out your copyright notice in the Description page of Project Settings.



#include "Enemies/Beetle_AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Perception/PawnSensingComponent.h"
#include "Player/Test_Character.h"


ABeetle_AIController::ABeetle_AIController()
{
	Beetle_BTC = CreateDefaultSubobject<UBehaviorTreeComponent>("Beetle Behavior Tree Component");
	Beetle_BBC = CreateDefaultSubobject<UBlackboardComponent>("Beetle Blackboard Component");
	Beetle_PerceptionComponent = CreateDefaultSubobject<UPawnSensingComponent>("Beetle Perception Component");

	Beetle_PerceptionComponent->SetPeripheralVisionAngle(90.0f);
	Beetle_PerceptionComponent->SightRadius = 700.0f;
}

void ABeetle_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (Beetle_BT)
	{
		Beetle_BBC->InitializeBlackboard(*Beetle_BT->BlackboardAsset);
		Beetle_BTC->StartTree(*Beetle_BT);

		Beetle_PerceptionComponent->OnSeePawn.AddDynamic(this, &ABeetle_AIController::OnEnemySeeItsTarget);

		// Initial blackboard values
		Beetle_BBC->SetValueAsBool("SeenPlayer", false);
	}
}

void ABeetle_AIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// If we’ve lost the player, stop chasing
	if (Player)
	{
		float Distance = FVector::Dist(GetPawn()->GetActorLocation(), Player->GetActorLocation());
		if (Distance > Beetle_PerceptionComponent->SightRadius)
		{
			Beetle_BBC->SetValueAsBool("SeenPlayer", false);
			Beetle_BBC->SetValueAsObject("Player", nullptr);
			Player = nullptr;

			ACharacter* BeetleChar = Cast<ACharacter>(GetPawn());
			if (BeetleChar)
			{
				BeetleChar->GetCharacterMovement()->MaxWalkSpeed = 400.f; 
			}
		}
	}
}


void ABeetle_AIController::OnEnemySeeItsTarget(APawn* SensedPawn)
{
	if (SensedPawn && SensedPawn->IsA<ATest_Character>())
	{
		Player = SensedPawn;

		Beetle_BBC->SetValueAsObject("Player", SensedPawn);
		Beetle_BBC->SetValueAsBool("SeenPlayer", true);
		Beetle_BBC->SetValueAsVector("LastSeenLocation", SensedPawn->GetActorLocation());

		ACharacter* BeetleChar = Cast<ACharacter>(GetPawn());
		if (BeetleChar)
		{
			BeetleChar->GetCharacterMovement()->MaxWalkSpeed = 500.f; // Slightly increased speed when chasing
		}
	}
}