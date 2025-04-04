// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "CrowTask_DiveAttack.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API UCrowTask_DiveAttack : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UCrowTask_DiveAttack();

    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
    struct FReturnData {
        FVector LastPosition;
        float StationaryTime;
        bool HasMoved;
    };

    void StartReturnJourneyTracking(ACharacter* CrowBoss, UBlackboardComponent* BlackboardComp, FVector OriginalPosition);

    FTimerHandle CheckPositionTimerHandle;
    FTimerHandle SafetyTimerHandle;

protected:
    UPROPERTY(EditAnywhere, Category = "Blackboard")
    FBlackboardKeySelector TargetLocationKey;

    UPROPERTY(EditAnywhere, Category = "Dive")
    float DiveSpeed = 2000.f;

    UPROPERTY(EditAnywhere, Category = "Dive")
    float GroundZ = 0.f;

};
