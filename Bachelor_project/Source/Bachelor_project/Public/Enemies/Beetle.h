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
	TSet<AActor*> HitActors;
	FTimerHandle AttackCooldown;
protected:
	// Lifecycle
	virtual void BeginPlay() override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator, AActor* DamageCauser) override;

	// Stats
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int Health{ 5 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int Damage{ 1 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float PatrolSpeed{ 400.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float ChaseSpeed{ 500.f };

	// State flags
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsDead = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsDying = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsChasing = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsPatrolling = false;

public:
	// Tick
	virtual void Tick(float DeltaTime) override;

	// Input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Overlaps
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);

	// Damage handling
	void OnHit(int IncomingDamage);
	void DestroyActor();

	// Interface implementations
	virtual float GetHealth() const override { return Health; }
	virtual float GetDamage() const override { return Damage; }
	virtual void SetHealth(float NewHealth) override { Health = FMath::RoundToInt(NewHealth); }
	virtual void SetDamage(float NewDamage) override { Damage = FMath::RoundToInt(NewDamage); }

	// Movement speeds
	float GetWalkSpeed() const { return PatrolSpeed; }
	float GetChaseSpeed() const { return ChaseSpeed; }

	// Getters
	bool GetIsDying() const { return bIsDying; }
	bool GetIsDead() const { return bIsDead; }
	bool GetIsChasing() const { return bIsChasing; }
	bool GetIsPatrolling() const { return bIsPatrolling; }

	// Setters
	void SetIsDying(bool bState) { bIsDying = bState; }
	void SetIsDead(bool bState) { bIsDead = bState; }
	void SetIsChasing(bool bState) { bIsChasing = bState; }
	void SetIsPatrolling(bool bState) { bIsPatrolling = bState; }
};
