// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PowerUpController.h"
#include "Power_WallLatch.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API UPower_WallLatch : public UPowerUpController
{
    GENERATED_BODY()

public:
    UPower_WallLatch();

    // Override the OnActivate method from UPowerUpController
    virtual void OnActivate(AActor* Player) override;

 

    void Tick(float DeltaTime, ACharacter* Character);
    void LatchToWall(ACharacter* Character, const FVector& WallNormal);

protected:


private:
    bool bIsWallLatching = false;
    bool bIsWallLatchActive = false;
    float LatchDuration = 5.0f;

    UPROPERTY()
    float WallCheckDistance = 50;
};

