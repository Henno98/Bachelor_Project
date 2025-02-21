// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "AbilitySystemInterface.h"
#include "GAS_Double_Jump.h"

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

	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
public:
	UPROPERTY()
	TSubclassOf<UGAS_Double_Jump> JumpAbility;

};
