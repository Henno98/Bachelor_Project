// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/Charger_AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/PawnSensingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/Test_Character.h"

ACharger_AIController::ACharger_AIController()
{
	Charger_PerceptionComponent = CreateDefaultSubobject<UPawnSensingComponent>("Charger Perception Component");
	Charger_BBC = CreateDefaultSubobject<UBlackboardComponent>("BlackBoardComp");
	Charger_BTC = CreateDefaultSubobject<UBehaviorTreeComponent>("Charger Behavior Tree Component");

	// Set up perception properties
	if (Charger_PerceptionComponent)
	{
		Charger_PerceptionComponent->SetPeripheralVisionAngle(180.0f);
		Charger_PerceptionComponent->SightRadius = 1000.0f;
		Charger_PerceptionComponent->LOSHearingThreshold = 2000.0f;
		Charger_PerceptionComponent->HearingThreshold = 1000.0f;
		Charger_PerceptionComponent->bHearNoises = true;
	}
}

void ACharger_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (Charger_BT != NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("Initializing Charger AI"));
		Charger_BBC->SetValueAsBool("SeenPlayer", false);
		Charger_BBC->SetValueAsBool("IsCharging", false);
		Charger_BBC->SetValueAsBool("CanCharge", true);
		Charger_BBC->SetValueAsFloat("ChargeCooldown", 0.0f);
		Charger_BBC->InitializeBlackboard(*Charger_BT->BlackboardAsset);
		Charger_BTC->StartTree(*Charger_BT);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Behavior Tree is NULL"));
	}
}

void ACharger_AIController::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	APawn* Charger = GetPawn();
	if (!Charger) return;

	UpdateChargeCooldown(deltaTime);

	// Debug check for player detection
	TArray<AActor*> AllPlayers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATest_Character::StaticClass(), AllPlayers);
	if (AllPlayers.Num() > 0)
	{
		APawn* TestPlayer = Cast<APawn>(AllPlayers[0]);
		if (TestPlayer)
		{
			FVector PlayerLocation = TestPlayer->GetActorLocation();
			FVector ChargerLocation = Charger->GetActorLocation();
			float Distance = FVector::Dist(PlayerLocation, ChargerLocation);
		}
	}

	if (Player)
	{
		FVector PlayerLocation = Player->GetActorLocation();
		FVector ChargerLocation = Charger->GetActorLocation();
		float Distance = FVector::Dist(PlayerLocation, ChargerLocation);
		Charger_BBC->SetValueAsFloat("DistanceToPlayer", Distance);
		if (Distance > 600.f)
		{
			Player = nullptr;
			Charger_BBC->SetValueAsObject("Player", nullptr);
			Charger_BBC->SetValueAsBool("SeenPlayer", false);
			return;
		}
	}
}


void ACharger_AIController::UpdateChargeCooldown(float DeltaTime) {
	if (CurrentCooldownTime > 0.0f)
	{
		CurrentCooldownTime -= DeltaTime;
		Charger_BBC->SetValueAsFloat("ChargeCooldown", CurrentCooldownTime);

		if (CurrentCooldownTime <= 0.0f)
		{
			// Cooldown finished
			Charger_BBC->SetValueAsBool("CanCharge", true);
			CurrentCooldownTime = 0.0f;
		}
	}
}

void ACharger_AIController::OnSeenPawn(APawn* SeenPawn)
{
	if (!SeenPawn) return;

	if (SeenPawn->IsA<ATest_Character>())
	{

		Player = SeenPawn;
		Charger_BBC->SetValueAsObject("Player", SeenPawn);
		Charger_BBC->SetValueAsBool("SeenPlayer", true);
		UE_LOG(LogTemp, Warning, TEXT("Boss saw the player!"));


	}
}
