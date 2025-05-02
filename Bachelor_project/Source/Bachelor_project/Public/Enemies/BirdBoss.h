// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BirdBoss.generated.h"

UCLASS()
class BACHELOR_PROJECT_API ABirdBoss : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABirdBoss();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "AttackRange")
	float AttackRange = 2000.f;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
