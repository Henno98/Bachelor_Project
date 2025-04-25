// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CrowBoss.generated.h"

UCLASS()
class BACHELOR_PROJECT_API ACrowBoss : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACrowBoss();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackRange")
	float AttackRange = 2000.f;
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
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DiveAttackRange = 600.f;

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
	UFUNCTION()
	void OnHit(int damage);


	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);

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
	UFUNCTION()
	float GetAttackRange(){return AttackRange;}
	

};
