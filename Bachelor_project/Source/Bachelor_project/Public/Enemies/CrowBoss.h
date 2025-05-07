// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyInterface.h"
#include "NiagaraSystem.h"
#include "GameFramework/Character.h"
#include "CrowBoss.generated.h"

UCLASS()
class BACHELOR_PROJECT_API ACrowBoss : public ACharacter,public IEnemyInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	                  int32 OtherBodyIndex);
	// Sets default values for this character's properties
	ACrowBoss();
	 virtual void Landed(const FHitResult& Hit) override;
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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsDead = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsDying = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsPreppingToDive = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsDiving = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsPatrolling = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsMeleeAttacking = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsWalking = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsRangedAttacking = false;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	                 AActor* DamageCauser) override;
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
	void Attack(const FName& Socket,float attackrange);

	//Getters and setters
	//Health
	 // IEnemyInterface implementations
	virtual float GetHealth() const override;
	virtual float GetDamage() const override;
	virtual void SetHealth(float NewHealth) override;
	virtual void SetDamage(float NewDamage) override;
	//AttackTarget
	UFUNCTION()
	AActor* GetAttackTarget() { return Target; }
	UFUNCTION()
	void SetAttackTarget(AActor* newtarget) { Target = newtarget; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variable)
	float AttackRange{ 300.f };
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variable)
	float VisionRange{ 2000.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variable)
	float DiveAttackRange{ 1000.f };


	float GetAttackRange() { return AttackRange; }
	float GetVisionRange() { return VisionRange; }
	float GetDiveAttackRange() { return DiveAttackRange; }
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
	bool GetIsWalking() { return bIsWalking; }
	bool GetIsRangedAttacking() { return bIsRangedAttacking; }
	bool GetIsMeleeAttacking() { return bIsMeleeAttacking; }


	void SetIsDying(bool state) { bIsDying = state; };
	void SetIsDead(bool state) { bIsDead = state; };
	void SetIsDiving(bool state) { bIsDiving = state; };
	void SetIsPatrolling(bool state) { bIsPatrolling = state; };
	void SetIsMeleeAttacking(bool state) { bIsMeleeAttacking = state; };
	void SetIsRangedAttacking(bool state) { bIsRangedAttacking = state; };
	void SetIsWalking(bool state) { bIsWalking = state; };
	void SetIsPreparingDive(bool state) { bIsPreppingToDive = state; };
};
