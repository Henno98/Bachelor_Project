// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyInterface.h"
#include "IsRangedAttacker.h"
#include "NiagaraSystem.h"
#include "GameFramework/Character.h"
#include "CrowBoss.generated.h"

UCLASS()
class BACHELOR_PROJECT_API ACrowBoss : public ACharacter,public IEnemyInterface, public IIsRangedAttacker
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
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,AActor* DamageCauser) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	bool bHasTarget = true;
	//Variables we want for the attack
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	float RangedAttackDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	float Velocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FVector BulletSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FVector Target;;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FVector SpawnLocation = GetActorLocation();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FRotator Direction;
	//Functions from the interface we can call in GAS_RangedAttack
	// Interface function implementations (with inline return values)
	virtual float GetRangedDamage_Implementation() const override { return RangedAttackDamage; }
	virtual float GetRangedAttackVelocity_Implementation() const override { return Velocity; }
	virtual FVector GetBulletSize_Implementation() const override { return BulletSize; }
	virtual FVector GetTargetLocation_Implementation() const override { return Target; }
	virtual FRotator GetFiringDirection_Implementation() const override { return Direction; }
	virtual bool GetHasTarget_Implementation() const override { return bHasTarget; };
	virtual TSubclassOf<AActor> GetProjectileClass_Implementation() const override { return ProjectileClass; };
	virtual FVector GetSpawnLocation_Implementation() const override { return SpawnLocation; };

	// Setters for the interface
	virtual void SetHasTarget_Implementation(bool bNewHasTarget) override { bHasTarget = bNewHasTarget; }
	virtual void SetRangedDamage_Implementation(float NewDamage) override { RangedAttackDamage = NewDamage; }
	virtual void SetRangedAttackVelocity_Implementation(float NewVelocity) override { Velocity = NewVelocity; }
	virtual void SetBulletSize_Implementation(FVector NewBulletSize) override { BulletSize = NewBulletSize; }
	virtual void SetTargetLocation_Implementation(FVector NewTarget) override { Target = NewTarget; }
	virtual void SetSpawnLocation_Implementation(FVector NewSpawnLocation) override { SpawnLocation = NewSpawnLocation; }
	virtual void SetFiringDirection_Implementation(FRotator NewDirection) override { Direction = NewDirection; }
	virtual void SetProjectileClass_Implementation(TSubclassOf<AActor> NewProjectileClass) override { ProjectileClass = NewProjectileClass; }

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
	TSubclassOf< AActor> ProjectileClass;


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
