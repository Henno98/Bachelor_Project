// Fill out your copyright notice in the Description page of Project Settings.


#include "Charger_WanderingTask.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"
#include "Charger_AIController.h"
#include "Wandering_Target_Point.h"
#include "Kismet/GameplayStatics.h"

UCharger_WanderingTask::UCharger_WanderingTask()
{
}

EBTNodeResult::Type UCharger_WanderingTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (!BlackboardComp) return EBTNodeResult::Failed;

    // Get all wandering points in the level
    TArray<AActor*> WanderingPoints;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWandering_Target_Point::StaticClass(), WanderingPoints);

    UE_LOG(LogTemp, Warning, TEXT("Found %d wandering points"), WanderingPoints.Num());

    if (WanderingPoints.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("No wandering points found!"));
        return EBTNodeResult::Failed;
    }

    ACharger_AIController* ChargerController = Cast<ACharger_AIController>(OwnerComp.GetAIOwner());
    if (!ChargerController) return EBTNodeResult::Failed;

    // Get the previous wandering point (if any)
    AWandering_Target_Point* OldTargetPoint = Cast<AWandering_Target_Point>(BlackboardComp->GetValueAsObject("WanderingPoint"));

    // Store the starting location
    FVector StartLocation;
    if (OldTargetPoint)
    {
        StartLocation = OldTargetPoint->GetActorLocation();
    }
    else
    {
        StartLocation = ChargerController->GetNavAgentLocation();
    }

    // Randomly select a new wandering point
    int32 RandomIndex = FMath::RandRange(0, WanderingPoints.Num() - 1);
    AWandering_Target_Point* NewWanderingPoint = Cast<AWandering_Target_Point>(WanderingPoints[RandomIndex]);

    if (!NewWanderingPoint) return EBTNodeResult::Failed;

    UE_LOG(LogTemp, Warning, TEXT("Selected new wandering point: %s"), *NewWanderingPoint->GetName());

    // Set the new wandering point in the blackboard
    BlackboardComp->SetValueAsObject("WanderingPoint", NewWanderingPoint);

    // Store target location and other useful information in controller
    FVector TargetLocation = NewWanderingPoint->GetActorLocation();
    ChargerController->charger_start_location = StartLocation;
    ChargerController->charger_target_location = TargetLocation;
    ChargerController->InitialDistance = FVector::Distance(StartLocation, TargetLocation);

    // Set the target destination for actual movement in a separate task or service
    BlackboardComp->SetValueAsVector("MoveToLocation", TargetLocation);

    return EBTNodeResult::Succeeded;
}

