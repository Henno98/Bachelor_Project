// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "EnemyInterface.h"
#include "IsRangedAttacker.h"
#include "GameFramework/Character.h"
#include "Player/GAS_Ranged_Attack.h"
#include "Plant.generated.h"

//Add the Interface with info for the GAS class
UCLASS()
class BACHELOR_PROJECT_API APlant : public ACharacter, public IIsRangedAttacker,public IEnemyInterface, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlant();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	TSubclassOf<Aprojectile> ProjectileClass;
	//Give plant GAS
	
	//Limit on shooting so it doesnt shoot each frame
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	bool bIsRangedAttacking = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	bool bHasTarget = true;
	//Variables we want for the attack
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Variables")
	float RangedAttackDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	float Velocity;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Variables")
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

	//Create the //Initiate GAS
	void InitAbilitySystem();
	//GAS ability we want it to have
	UPROPERTY(EditAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;


	UPROPERTY()
	TSubclassOf<UGAS_Ranged_Attack> GA_Ranged_Attack;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GASGameplayAbility")
	FGameplayTagContainer RangedAttackAbilityTag;
	FGameplayAbilitySpec RangedAttackAbilitySpec;
	//Function to call on GAS ability
	virtual void CallGAS_RangedAttack();

	// IEnemyInterface implementations
	virtual float GetHealth() const override { return Health; };
	virtual float GetDamage() const override { return Damage; };
	virtual void SetHealth(float NewHealth) override { Health = NewHealth; };
	virtual void SetDamage(float NewDamage) override { Damage = NewDamage; };
	float Health;
	float Damage;
	
};
