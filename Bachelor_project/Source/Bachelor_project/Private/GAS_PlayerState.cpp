// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS_PlayerState.h"
#include "ASC_AbilitySystemComponent.h"

AGAS_PlayerState::AGAS_PlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UASC_AbilitySystemComponent>("AbilitySystemComponent");

}

UAbilitySystemComponent* AGAS_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;

}
