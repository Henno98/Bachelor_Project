// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraSystem.h"
#include "GameFramework/Character.h"
#include "CrowBoss.generated.h"

UCLASS()
class BACHELOR_PROJECT_API ACrowBoss : public ACharacter
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	                  int32 OtherBodyIndex);
	// Sets default values for this character's properties
	ACrowBoss();
	 
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY()
	int Health;
	UPROPERTY()
	float MovementSpeed;
	UPROPERTY()
	float AttackDamage;
	UPROPERTY()
	float Stamina;
	UPROPERTY()
	AActor* Target;
	UPROPERTY()
	float AttackRange;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	                 AActor* DamageCauser);
	UFUNCTION()
	void MeleeAttack();
	UFUNCTION()
	void FeatherAttack();
	UFUNCTION()
	void SpecialAttack();
	UFUNCTION()
	void Collision();
	UFUNCTION()
	void Death();
	void OnHit(int damage);


	//Getters and setters
	//Health
	UFUNCTION()
	int GetHealth(){return Health;}
	UFUNCTION()
	void SetHealth(int newHealth){Health = newHealth;}
	//Stamina
	UFUNCTION()
	float GetStamina() { return Stamina; }
	UFUNCTION()
	void SetStamina(float newstamina) { Stamina = newstamina;}
	//AttackTarget
	UFUNCTION()
	AActor* GetAttackTarget() { return Target; }
	UFUNCTION()
	void SetAttackTarget(AActor* newtarget) { Target = newtarget; }
	float GetAttackRange() { return AttackRange; }
	int GetDamage() { return  AttackDamage; }
	UPROPERTY(EditDefaultsOnly, Category = "VFX")
	UNiagaraSystem* DiveImpactEffect;

};
