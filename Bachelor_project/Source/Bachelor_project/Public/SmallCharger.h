// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SmallCharger.generated.h"

class UPawnSensingComponent;

UCLASS()
class BACHELOR_PROJECT_API ASmallCharger : public ACharacter
{
	GENERATED_BODY()

public:
	ASmallCharger();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UPawnSensingComponent* SmallCharger_PerceptionComponent;
};



