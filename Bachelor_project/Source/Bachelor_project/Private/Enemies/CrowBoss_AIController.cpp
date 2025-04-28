// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/CrowBoss_AIController.h"

#include "Player/Test_Character.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
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


void ACrowBoss_AIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    APawn* Crow = GetPawn();
    if (!Crow) return;


    bool bIsAttacking = CrowBoss_BBC->GetValueAsBool("IsAttacking");


    if (bIsAttacking)
    {
        return;
    }


    if (Player)
    {
        FVector PlayerLocation = Player->GetActorLocation();
        FVector CrowLocation = Crow->GetActorLocation();
        float Distance = FVector::Dist(PlayerLocation, CrowLocation);

        if (Distance > 1500.f)
        {
            Player = nullptr;
            CrowBoss_BBC->SetValueAsObject("Player", nullptr);
            CrowBoss_BBC->SetValueAsBool("SeenPlayer", false);
            return;
        }

        // Hover above the player
        FVector TargetLocation = PlayerLocation + FVector(0.f, 0.f, 300.f);
        FVector DirectionToTarget = (TargetLocation - CrowLocation);
        float DistanceToTarget = DirectionToTarget.Size();
        DirectionToTarget = DirectionToTarget.GetSafeNormal();


        float MovementSpeed = FMath::Clamp(DistanceToTarget / 500.f, 0.1f, 1.0f);
        Crow->AddMovementInput(DirectionToTarget, MovementSpeed);


        CrowBoss_BBC->SetValueAsBool("SeenPlayer", true);


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
        UE_LOG(LogTemp, Warning, TEXT("Boss saw the player!"));


    }
}