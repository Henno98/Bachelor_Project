// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyInterface.h"
#include "GameFramework/Character.h"
#include "Beetle.generated.h"

UCLASS()
class BACHELOR_PROJECT_API ABeetle : public ACharacter,public IEnemyInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABeetle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// IEnemyInterface implementations
	virtual float GetHealth() const override { return Health; };
	virtual float GetDamage() const override { return Damage; };
	virtual void SetHealth(float NewHealth) override { Health = NewHealth; };
	virtual void SetDamage(float NewDamage) override { Damage = NewDamage; };
	float Health;
	float Damage;
};
