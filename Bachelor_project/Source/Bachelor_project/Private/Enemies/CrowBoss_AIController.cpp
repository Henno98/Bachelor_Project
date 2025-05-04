// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemies/CrowBoss_AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Enemies/CrowBoss.h"
#include "Perception/PawnSensingComponent.h"
#include "Player/Test_Character.h"


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

void ACrowBoss_AIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    APawn* Crow = GetPawn();
    if (!Crow) return;
    ACrowBoss* CrowBoss = Cast<ACrowBoss>(Crow);
    if (!CrowBoss) return;

    // Don't do anything if the boss is currently attacking
    bool bIsAttacking = CrowBoss_BBC->GetValueAsBool("IsAttacking");
    if (bIsAttacking)
    {
        // Important: Return here to prevent any movement during attack
        return;
    }

    // Rest of your existing code remains the same
    if (Player)
    {
        FVector PlayerLocation = Player->GetActorLocation();
        FVector CrowLocation = Crow->GetActorLocation();
        float Distance = FVector::Dist(PlayerLocation, CrowLocation);
        // Player is too far, stop chasing
        if (Distance > CrowBoss->DiveAttackRange)
        {
            Player = nullptr;
            CrowBoss_BBC->SetValueAsObject("Player", nullptr);
            CrowBoss_BBC->SetValueAsBool("SeenPlayer", false);
            return;
        }
        // Hover above the player
        FVector TargetLocation = PlayerLocation + FVector(0.f, 0.f, 300.f);
        FVector DirectionToTarget = TargetLocation - CrowLocation;
        float DistanceToTarget = DirectionToTarget.Size();
        DirectionToTarget = DirectionToTarget.GetSafeNormal();
        float MovementSpeed = FMath::Clamp(DistanceToTarget / 500.f, 0.1f, 1.0f);
        Crow->AddMovementInput(FVector(DirectionToTarget.X, DirectionToTarget.Y, 0), MovementSpeed);
        // Update blackboard
        CrowBoss_BBC->SetValueAsBool("SeenPlayer", true);
        // Smoothly rotate toward the player
        FRotator LookAt = (PlayerLocation - CrowLocation).Rotation();
        Crow->SetActorRotation(FMath::RInterpTo(
            Crow->GetActorRotation(),
            LookAt,
            DeltaTime,
            5.0f
        ));
    }
    else
    {
        // Didn't see anyone this frame
        CrowBoss_BBC->SetValueAsBool("SeenPlayer", false);
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

        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("Player Seen!"));
			
	}
}




