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
private:
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	bool GetHasTarget() const;
	/** Returns the base ranged damage for this entity */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	float GetRangedDamage() const;

	/** Returns the velocity of the projectile */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	float GetRangedAttackVelocity() const;

	/** Called after attack ends to re-enable input or reset state */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	void ReEnableInput();

	/** Returns the bullet/projectile scale */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	FVector GetBulletSize() const;

	/** Returns the target location, if any */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	FVector GetTargetLocation() const;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	FVector GetSpawnLocation() const;
	/** Returns the direction in which to fire */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	FRotator GetFiringDirection() const;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ranged Attack")
	TSubclassOf<AActor> GetProjectileClass()const;
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.

};
