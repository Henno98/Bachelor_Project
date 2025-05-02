// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "AbilitySystemInterface.h"
#include "GAS_Dash.h"
#include "GAS_Double_Jump.h"
#include "GAS_Ranged_Attack.h"
#include "GAS_Wall_Latch.h"

#include "GAS_PlayerState.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API AGAS_PlayerState : public APlayerState,public IAbilitySystemInterface
{
	GENERATED_BODY()
public:

	AGAS_PlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities system")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	TSubclassOf<UGAS_Double_Jump> JumpAbility;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	TSubclassOf<UGAS_Wall_Latch> WallLatchAbility;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	TSubclassOf<UGAS_Dash> DashAbility;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	TSubclassOf<UGAS_Ranged_Attack> RangedAttack;

};
