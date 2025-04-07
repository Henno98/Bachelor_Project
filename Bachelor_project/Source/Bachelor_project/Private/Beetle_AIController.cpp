// Fill out your copyright notice in the Description page of Project Settings.


#include "Beetle_AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Perception/PawnSensingComponent.h"


ABeetle_AIController::ABeetle_AIController()
{
	Beetle_BTC = CreateDefaultSubobject<UBehaviorTreeComponent>("Beetle Behavior Tree Component");
	Beetle_BBC = CreateDefaultSubobject<UBlackboardComponent>("Beetle Blackboard Component");
	Beetle_PerceptionComponent = CreateDefaultSubobject<UPawnSensingComponent>("Beetle Perception Component");


}

void ABeetle_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (Beetle_BT != NULL)
	{
		Beetle_BBC->InitializeBlackboard(*Beetle_BT->BlackboardAsset);
		Beetle_BTC->StartTree(*Beetle_BT);

		Beetle_PerceptionComponent->OnSeePawn.AddDynamic(this, &ABeetle_AIController::OnEnemySeeItsTarget);

	}
}

void ABeetle_AIController::ToCheckSpawnStillAround()
{
	float distanceBetweenEnemyPlayer = FVector::Distance(GetNavAgentLocation(),
		FVector(detectPlayer->GetActorLocation().X,
			detectPlayer->GetActorLocation().Y,
			GetNavAgentLocation().Z
		)
	);

	if (distanceBetweenEnemyPlayer > Beetle_PerceptionComponent->SightRadius)
	{
		Beetle_BBC->SetValueAsBool("SeenPlayer", false);
		GetWorld()->GetTimerManager().ClearTimer(timerHandle);


		ACharacter* BeetleCharacter = Cast<ACharacter>(GetPawn());
		if (BeetleCharacter)
		{
			BeetleCharacter->GetCharacterMovement()->MaxWalkSpeed = 600.0f; // Normal walk speed
		}
	}
}



void ABeetle_AIController::OnEnemySeeItsTarget(APawn* SensedPawn)
{
	if (Beetle_BTC != nullptr && SensedPawn != nullptr)
	{
		

			Beetle_BBC->SetValueAsBool("SeenPlayer", true);

			Beetle_BBC->SetValueAsObject("Player", SensedPawn);

			FVector LastSeenLocation = SensedPawn->GetActorLocation();
			Beetle_BBC->SetValueAsVector("LastSeenLocation", LastSeenLocation);

		
			detectPlayer = SensedPawn;

			GetWorldTimerManager().SetTimer(timerHandle, this, &ABeetle_AIController::ToCheckSpawnStillAround, 2.0f, true, 3.0f);
		
	}
}