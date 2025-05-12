// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/Plant_AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/PawnSensingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/Test_Character.h"

/**
 * APlant_AIController
 *
 * AI controller for the Plant enemy character.
 * - Sets up perception components such as sight and hearing, including radius and angle settings.
 * - On possession, initializes the blackboard and behavior tree components, starts the behavior tree, and sets up the perception component to detect the player.
 * - Handles the "OnPossess" method by setting the "SeenPlayer" blackboard value to false and starting the behavior tree if it's valid.
 * - If the Plant AI perceives the player, it updates the blackboard with the player's reference and sets the "SeenPlayer" value to true.
 */

APlant_AIController::APlant_AIController()
{
	Plant_PerceptionComponent = CreateDefaultSubobject<UPawnSensingComponent>("Plant Perception Component");
	Plant_BBC = CreateDefaultSubobject<UBlackboardComponent>("BlackBoardComp");
	Plant_BTC = CreateDefaultSubobject<UBehaviorTreeComponent>("Plant Behavior Tree Component");

	// Set up perception properties
	if (Plant_PerceptionComponent)
	{
		Plant_PerceptionComponent->SetPeripheralVisionAngle(180.0f);
		Plant_PerceptionComponent->SightRadius = 1000.0f;
		Plant_PerceptionComponent->LOSHearingThreshold = 2000.0f;
		Plant_PerceptionComponent->HearingThreshold = 1000.0f;
		Plant_PerceptionComponent->bHearNoises = true;

	}
}

void APlant_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (Plant_BT != NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("Initializing Charger AI"));
		Plant_BBC->SetValueAsBool("SeenPlayer", false);
		Plant_BBC->InitializeBlackboard(*Plant_BT->BlackboardAsset);
		Plant_BTC->StartTree(*Plant_BT);
		Plant_PerceptionComponent->OnSeePawn.AddDynamic(this, &APlant_AIController::OnSeenPawn);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Behavior Tree is NULL"));
	}
}

void APlant_AIController::OnSeenPawn(APawn* SeenPawn)
{
	if (!SeenPawn) return;

	if (SeenPawn->IsA<ATest_Character>())
	{

		Player = SeenPawn;
		Plant_BBC->SetValueAsObject("Player", SeenPawn);
		Plant_BBC->SetValueAsBool("SeenPlayer", true);

		

	}
}
