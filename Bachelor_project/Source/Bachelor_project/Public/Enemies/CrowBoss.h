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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variable)
	int Health{20};
	UPROPERTY()
	float MovementSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variable)
	float AttackDamage{2};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variable)
	float Stamina;
	UPROPERTY()
	AActor* Target;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = Variable)
	float AttackRange {300.f};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variable)
	float VisionRange{ 2000.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsDead = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsDying = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsDiving = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsPatrolling = false;

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
	UFUNCTION(BlueprintCallable)
	void DiveAttack(const FName& Socket);

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
	float GetVisionRange() { return VisionRange; }
	int GetDamage() { return  AttackDamage; }


	UPROPERTY(EditDefaultsOnly, Category = "VFX")
	UNiagaraSystem* DiveImpactEffect;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float RangedAttackDistance = 1500.f;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<class ACrowBoss_Projectile> ProjectileClass;


	bool GetIsDying() { return bIsDying; }
	bool GetIsDead() { return bIsDead; }
	bool GetIsDiving() { return bIsDiving; }
	bool GetIsPatrolling() { return bIsPatrolling; }

	void SetIsDying(bool state) { bIsDying = state; };
	void SetIsDead(bool state) { bIsDead = state; };
	void SetIsDiving(bool state) { bIsDiving = state; };
	void SetIsPatrolling(bool state) { bIsPatrolling = state; };
};
