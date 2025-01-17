// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "PowerUpController.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Power_DoubleJump.generated.h"


UCLASS()
class BACHELOR_PROJECT_API UPower_DoubleJump : public UPowerUpController
{
    GENERATED_BODY()

public:
    virtual void Activate(AActor* Player) override;

    bool bHasDoubleJumped = false;


    
};
