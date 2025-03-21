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
}

void ASmallCharger_AIController::BeginPlay()
{
	Super::BeginPlay();

	if (!SmallCharger_BT)
	{
		UE_LOG(LogTemp, Error, TEXT("SmallCharger_BT is NULL! AI will not function."));
		return;
	}

	if (!SmallCharger_BBC)
	{
		UE_LOG(LogTemp, Error, TEXT("SmallCharger_BBC (Blackboard Component) is NULL!"));
		return;
	}

	SmallCharger_BBC->InitializeBlackboard(*SmallCharger_BT->GetBlackboardAsset());
	RunBehaviorTree(SmallCharger_BT);

	SmallCharger_BBC->SetValueAsVector("TargetLocation", FVector(0.f));

	if (SmallCharger_PerceptionComponent)
	{
		SmallCharger_PerceptionComponent->OnSeePawn.AddDynamic(this, &ASmallCharger_AIController::OnSeenPawn);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("SmallCharger_PerceptionComponent is NULL!"));
	}
}


void ASmallCharger_AIController::Tick(float deltaTime) {
	Super::Tick(deltaTime);
	if (AActor* player = Cast<AActor>(SmallCharger_BBC->GetValueAsObject("Player")))
	{
		if (FVector::Distance(GetNavAgentLocation(), player->GetActorLocation()) > SmallCharger_PerceptionComponent->SightRadius)
		{
			SmallCharger_BBC->SetValueAsBool("SeenPlayer", false);
			SmallCharger_BBC->SetValueAsObject("Player", nullptr);
		}
	}
}

void ASmallCharger_AIController::OnSeenPawn(APawn* _pawn)
{
	UE_LOG(LogTemp, Warning, TEXT("SmallCharger saw: %s"), *_pawn->GetName());
	if (_pawn->IsA<ATest_Character>())
	{
		if (!SmallCharger_BBC->GetValueAsBool("SeenPlayer"))
		{
			SmallCharger_BBC->SetValueAsBool("SeenPlayer", true);
			SmallCharger_BBC->SetValueAsObject("Player", _pawn);
		}
	}
}


//ASmallCharger_AIController::ASmallCharger_AIController()
//{
//	SmallCharger_BTC = CreateDefaultSubobject<UBehaviorTreeComponent>("SmallCharger Behavior Tree Component");
//	SmallCharger_BBC = CreateDefaultSubobject<UBlackboardComponent>("SmallCharger Blackboard Component");
//	SmallCharger_PerceptionComponent = CreateDefaultSubobject<UPawnSensingComponent>("SmallCharger Perception Component");
//
//
//
//
//}
//
//void ASmallCharger_AIController::OnPossess(APawn* InPawn)
//{
//	Super::OnPossess(InPawn);
//
//	if (SmallCharger_BT != NULL)
//	{
//		SmallCharger_BBC->InitializeBlackboard(*SmallCharger_BT->BlackboardAsset);
//		SmallCharger_BTC->StartTree(*SmallCharger_BT);
//
//		SmallCharger_PerceptionComponent->OnSeePawn.AddDynamic(this, &ASmallCharger_AIController::OnEnemySeenItsOwner);
//
//	}
//}
//
//void ASmallCharger_AIController::ToCheckSpawnStillAround()
//{
//	float distanceBetweenEnemyPlayer = FVector::Distance(GetNavAgentLocation(),
//		FVector(detectPlayer->GetActorLocation().X,
//			detectPlayer->GetActorLocation().Y,
//			GetNavAgentLocation().Z
//		)
//	);
//
//	if (distanceBetweenEnemyPlayer > SmallCharger_PerceptionComponent->SightRadius)
//	{
//		SmallCharger_BBC->SetValueAsBool("SeenPlayer", false);
//		GetWorld()->GetTimerManager().ClearTimer(timerHandle);
//		seenPlayerFirstTime = true;
//
//
//		ACharacter* SmallChargerCharacter = Cast<ACharacter>(GetPawn());
//		if (SmallChargerCharacter)
//		{
//			SmallChargerCharacter->GetCharacterMovement()->MaxWalkSpeed = 600.0f; // Normal walk speed
//		}
//	}
//}
//
//void ASmallCharger_AIController::RestartBehaviorTree()
//{
//	SmallCharger_BTC->RestartTree();
//}
//
//
//void ASmallCharger_AIController::OnEnemySeenItsOwner(APawn* SensedPawn)
//{
//	if (SmallCharger_BTC != nullptr && SensedPawn != nullptr)
//	{
//		UE_LOG(LogTemp, Warning, TEXT("AI saw player at: %s"), *SensedPawn->GetActorLocation().ToString());
//
//		if (seenPlayerFirstTime == true)
//		{
//			seenPlayerFirstTime = false;
//
//			SmallCharger_BBC->SetValueAsBool("SeenPlayer", true);
//
//			SmallCharger_BBC->SetValueAsObject("Player", SensedPawn);
//
//			FVector LastSeenLocation = SensedPawn->GetActorLocation();
//			SmallCharger_BBC->SetValueAsVector("LastSeenLocation", LastSeenLocation);
//
//			UE_LOG(LogTemp, Warning, TEXT("LastSeenLocation set to: %s"), *LastSeenLocation.ToString());
//
//			detectPlayer = SensedPawn;
//
//			ACharacter* SmallChargerCharacter = Cast<ACharacter>(GetPawn());
//			if (SmallChargerCharacter)
//			{
//				SmallChargerCharacter->GetCharacterMovement()->MaxWalkSpeed = 1200.0f; // Charge speed
//			}
//
//			GetWorldTimerManager().SetTimer(timerHandle, this, &ASmallCharger_AIController::ToCheckSpawnStillAround, 2.0f, true, 3.0f);
//		}
//	}
//}
