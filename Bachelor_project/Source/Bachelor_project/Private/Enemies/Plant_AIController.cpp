// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/Plant_AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/PawnSensingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/Test_Character.h"

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

//void APlant_AIController::Tick(float deltaTime)
//{
//	Super::Tick(deltaTime);
//	APawn* Plant = GetPawn();
//	if (!Plant) return;
//
//	// Debug check for player detection
//	TArray<AActor*> AllPlayers;
//	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATest_Character::StaticClass(), AllPlayers);
//	if (AllPlayers.Num() > 0)
//	{
//		APawn* TestPlayer = Cast<APawn>(AllPlayers[0]);
//		if (TestPlayer)
//		{
//			FVector PlayerLocation = TestPlayer->GetActorLocation();
//			FVector PlantLocation = Plant->GetActorLocation();
//			float Distance = FVector::Dist(PlayerLocation, PlantLocation);
//		}
//	}
//
//	if (Player)
//	{
//		FVector PlayerLocation = Player->GetActorLocation();
//		FVector PlantLocation = Plant->GetActorLocation();
//		float Distance = FVector::Dist(PlayerLocation, PlantLocation);
//		Plant_BBC->SetValueAsFloat("DistanceToPlayer", Distance);
//		if (Distance > 600.f)
//		{
//			Player = nullptr;
//			Plant_BBC->SetValueAsObject("Player", nullptr);
//			Plant_BBC->SetValueAsBool("SeenPlayer", false);
//			return;
//		}
//	}
//}



void APlant_AIController::OnSeenPawn(APawn* SeenPawn)
{
	if (!SeenPawn) return;

	if (SeenPawn->IsA<ATest_Character>())
	{

		Player = SeenPawn;
		Plant_BBC->SetValueAsObject("Player", SeenPawn);
		Plant_BBC->SetValueAsBool("SeenPlayer", true);
		UE_LOG(LogTemp, Warning, TEXT("Plant saw the player!"));


	}
}
