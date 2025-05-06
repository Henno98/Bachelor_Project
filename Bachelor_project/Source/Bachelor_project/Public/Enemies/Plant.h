// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "IsRangedAttacker.h"
#include "GameFramework/Character.h"
#include "Player/GAS_Ranged_Attack.h"
#include "Plant.generated.h"

//Add the Interface with info for the GAS class
UCLASS()
class BACHELOR_PROJECT_API APlant : public ACharacter, public IIsRangedAttacker
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
	

	UPROPERTY()
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
	virtual void ReEnableInput_Implementation() override {/* implement logic in .cpp if needed */ }
	virtual FVector GetBulletSize_Implementation() const override { return BulletSize; }
	virtual FVector GetTargetLocation_Implementation() const override { return Target; }
	virtual FRotator GetFiringDirection_Implementation() const override { return Direction; }
	virtual bool GetHasTarget_Implementation() const override { return bHasTarget; };
	virtual TSubclassOf<AActor> GetProjectileClass_Implementation() const override { return ProjectileClass; };
	virtual FVector GetSpawnLocation_Implementation() const override { return SpawnLocation; };
	//Create the //Initiate GAS
	void InitAbilitySystem();
	//GAS ability we want it to have
	UPROPERTY(EditAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY()
	TSubclassOf<UGAS_Ranged_Attack> GA_Ranged_Attack;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GASGameplayAbility")
	FGameplayTagContainer RangedAttackAbilityTag;
	FGameplayAbilitySpec RangedAttackAbilitySpec;
	//Function to call on GAS ability
	virtual void CallGAS_RangedAttack();
};
