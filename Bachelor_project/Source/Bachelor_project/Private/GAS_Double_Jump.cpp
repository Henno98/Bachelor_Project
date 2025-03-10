// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS_Double_Jump.h"
#include "GameplayTagsManager.h"
#include "Test_Character.h"
#include "GameFramework/Character.h"

UGAS_Double_Jump::UGAS_Double_Jump()
{
	UGameplayTagsManager& Manager = UGameplayTagsManager::Get();
	FGameplayTagContainer RequestTag;
	RequestTag.AddTag(Manager.RequestGameplayTag(FName("Abilities.Double_Jump")));
	SetAssetTags(RequestTag);

}

void UGAS_Double_Jump::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (HasAuthorityOrPredictionKey(ActorInfo, &ActivationInfo))
	{

		ACharacter* Character = CastChecked<ACharacter>(ActorInfo->AvatarActor.Get());

		if (Character)
		{
			Character->Jump();
		}
		else
		{
			EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		}

	}

}

void UGAS_Double_Jump::CancelAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateCancelAbility)
{
	
	Super::CancelAbility(Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility);
	ACharacter* Character = CastChecked<ACharacter>(ActorInfo->AvatarActor.Get());
	if (Character)
	{
		Character->StopJumping();
	}
	else return;

	// Call EndAbility to finish the ability
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);

}

void UGAS_Double_Jump::InputReleased(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo)
{
	Super::InputReleased(Handle, ActorInfo, ActivationInfo);
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Yellow, TEXT("Cancel Jumping UUUU"));

	if (ActorInfo != NULL && ActorInfo->AvatarActor != NULL)
	{
		CancelAbility(Handle, ActorInfo, ActivationInfo, true);
	}

}
