// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "projectile.h"
#include "UObject/Interface.h"
#include "IsRangedAttacker.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIsRangedAttacker : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BACHELOR_PROJECT_API IIsRangedAttacker
{
protected:
	GENERATED_BODY()

public:
	// Existing Getters
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	bool GetHasTarget() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	float GetRangedDamage() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	float GetRangedAttackVelocity() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	FVector GetBulletSize() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	FVector GetTargetLocation() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	FVector GetSpawnLocation() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	FRotator GetFiringDirection() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	TSubclassOf<AActor> GetProjectileClass() const;

	// New Setters
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	void SetHasTarget(bool bHasTarget);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	void SetRangedDamage(float Damage);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	void SetRangedAttackVelocity(float Velocity);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	void SetBulletSize(FVector BulletSize);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	void SetTargetLocation(FVector TargetLocation);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	void SetSpawnLocation(FVector SpawnLocation);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	void SetFiringDirection(FRotator FiringDirection);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	void SetProjectileClass(TSubclassOf<AActor> ProjectileClass);

};
