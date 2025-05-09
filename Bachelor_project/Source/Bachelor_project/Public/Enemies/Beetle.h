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
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	//Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int Health{ 5 };
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int Damage{ 1 };
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable")
	float PatrolSpeed{ 400.f };
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable")
	float ChaseSpeed{ 500.f };


	//Animation state
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsDead = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsDying = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsChasing = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsPatrolling = false;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void Destroy();
	void OnHit(int Damage);
	// IEnemyInterface implementations
	virtual float GetHealth() const override { return Health; };
	virtual float GetDamage() const override { return Damage; };
	virtual void SetHealth(float NewHealth) override { Health = NewHealth; };
	virtual void SetDamage(float NewDamage) override { Damage = NewDamage; };
	

	float GetWalkSpeed() { return PatrolSpeed; }
	float GetChargeSpeed() { return ChaseSpeed; }


	bool GetIsDying() { return bIsDying; }
	bool GetIsDead() { return bIsDead; }
	bool GetIsChasing() { return bIsChasing; }
	bool GetIsPatrolling() { return bIsPatrolling; }

	void SetIsDying(bool state) { bIsDying = state; };
	void SetIsDead(bool state) { bIsDead = state; };
	void SetIsCharging(bool state) { bIsChasing = state; };
	void SetIsPatrolling(bool state) { bIsPatrolling = state; };
};
