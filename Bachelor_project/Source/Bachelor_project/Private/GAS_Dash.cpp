// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS_Dash.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameplayTagsManager.h"
#include "Test_Character.h"
#include "Components/CapsuleComponent.h"

UGAS_Dash::UGAS_Dash()
{
	UGameplayTagsManager& Manager = UGameplayTagsManager::Get();
	FGameplayTagContainer RequestTag;
	RequestTag.AddTag(Manager.RequestGameplayTag(FName("Abilities.Dash")));
	SetAssetTags(RequestTag);
}

void UGAS_Dash::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	if (HasAuthorityOrPredictionKey(ActorInfo, &ActivationInfo))
	{
		ATest_Character* Character = CastChecked<ATest_Character>(ActorInfo->AvatarActor.Get());
		if (Character && Character->GetCharacterMovement())
		{
			FVector direction = Character->GetCharacterMovement()->GetLastUpdateVelocity().GetSafeNormal();

			// Disable collision temporarily
			Character->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

			// Reduce ground friction
			Character->GetCharacterMovement()->GroundFriction = 0.1f;

			// Apply dash impulse
			Character->LaunchCharacter(FVector(0, 1600.f * direction.Y, 0), false, false);

			// Reset friction after delay
			FTimerHandle TimerHandle;
			Character->GetWorld()->GetTimerManager().SetTimer(TimerHandle, [Character]()
				{
					Character->GetCharacterMovement()->GroundFriction = 8.0f; // Restore default friction
					Character->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
				}, 0.5f, false);

		}
		else
		{
			EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		}
	}
}

void UGAS_Dash::CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility)
{
	Super::CancelAbility(Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility);
	
	// Call EndAbility to finish the ability
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
