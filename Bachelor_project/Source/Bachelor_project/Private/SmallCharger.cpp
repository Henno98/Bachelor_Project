// Fill out your copyright notice in the Description page of Project Settings.


#include "SmallCharger.h"

#include "SmallCharger_AIController.h"
#include "Perception/PawnSensingComponent.h"

ASmallCharger::ASmallCharger()
{
	PrimaryActorTick.bCanEverTick = true;

	SmallCharger_PerceptionComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));

	// Set sensing range and FOV here or in Blueprint
	SmallCharger_PerceptionComponent->SightRadius = 1500.f;
	SmallCharger_PerceptionComponent->SetPeripheralVisionAngle(90.f);
	SmallCharger_PerceptionComponent->bHearNoises = false;
}

// Called when the game starts or when spawned
void ASmallCharger::BeginPlay()
{
	Super::BeginPlay();

	if (SmallCharger_PerceptionComponent)
	{
		if (ASmallCharger_AIController* AIController = Cast<ASmallCharger_AIController>(GetController()))
		{
			SmallCharger_PerceptionComponent->OnSeePawn.AddDynamic(AIController, &ASmallCharger_AIController::OnSeenPawn);
		}
		else
		{
				}
	}
}


// Called every frame
void ASmallCharger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASmallCharger::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//void ASmallCharger::Destroy()
//{
//	SetActorHiddenInGame(true);
//	SetActorEnableCollision(false);
//	
//}

