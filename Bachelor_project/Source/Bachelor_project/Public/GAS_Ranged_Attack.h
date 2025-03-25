// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GAS_Ranged_Attack.generated.h"

/**
 * 
 */

class UGameplayEffect;

UCLASS()
class BACHELOR_PROJECT_API UGAS_Ranged_Attack : public UGameplayAbility
{
	GENERATED_BODY()
	UGAS_Ranged_Attack();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility) override;

	

protected:
	// Cooldown effect applied when ability is used
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability")
	TSubclassOf<UGameplayEffect> CooldownGameplayEffect;
	bool bCanShoot{ true };
};
