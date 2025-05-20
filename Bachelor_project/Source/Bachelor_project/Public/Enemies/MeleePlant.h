// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyInterface.h"
#include "GameFramework/Character.h"
#include "MeleePlant.generated.h"

UCLASS()
class BACHELOR_PROJECT_API AMeleePlant : public ACharacter, public IEnemyInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMeleePlant();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int Health{ 1 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int Damage{ 1 };

	// State flags
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsDead = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsDying = false;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator,
	                 AActor* DamageCauser);
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	               int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	                  int32 OtherBodyIndex);

	UFUNCTION()
	bool CanAttack() const;

	UFUNCTION()
	void PerformMeleeAttack();

	UPROPERTY()
	TArray<AActor*> HitActors;


	void ResetAttackCooldown();

	void OnHit(int IncomingDamage);
	void DestroyActor();

	// Interface implementations
	virtual float GetHealth() const override { return Health; }
	virtual float GetDamage() const override { return Damage; }
	virtual void SetHealth(float NewHealth) override { Health = FMath::RoundToInt(NewHealth); }
	virtual void SetDamage(float NewDamage) override { Damage = FMath::RoundToInt(NewDamage); }

	// Getters
	bool GetIsDying() const { return bIsDying; }
	bool GetIsDead() const { return bIsDead; }


	// Setters
	void SetIsDying(bool bState) { bIsDying = bState; }
	void SetIsDead(bool bState) { bIsDead = bState; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float AttackRange = 350;

private:
	UPROPERTY()
	bool bCanAttack = true;

	FTimerHandle AttackCooldownHandle;


};
