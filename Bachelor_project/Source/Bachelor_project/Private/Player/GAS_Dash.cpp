// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/GAS_Dash.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameplayTagsManager.h"
#include "Components/CapsuleComponent.h"
#include "Player/Test_Character.h"

/**
 * UGAS_Dash
 *
 * This Gameplay Ability class handles the dash ability for the character.
 * - The dash is executed by launching the character forward with a high velocity.
 * - Temporarily adjusts movement properties (like gravity and friction) to simulate the dash effect.
 * - Disables collision detection during the dash for smooth movement, then restores collision and movement properties after a brief delay.
 * - Provides functionality to cancel the ability and reset movement properties as necessary.
 */


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
		ATest_Character* Character = Cast<ATest_Character>(ActorInfo->AvatarActor.Get());
		if (!Character || !Character->GetCharacterMovement())
		{
			EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
			return;
		}
		
		// Get movement direction
		FVector Direction = Character->GetCharacterMovement()->GetForwardVector().GetSafeNormal();
		Character->PauseInput();
		Character->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		Character->GetCharacterMovement()->GroundFriction = 0.1f;
		Character->GetCharacterMovement()->GravityScale = 0.f;

		// Apply dash force
		Character->LaunchCharacter(FVector(0,Direction.Y * 5000.f,0), true, true);

		// Reset friction and restore collision after delay
		FTimerHandle TimerHandle;
		Character->GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([Character]()
			{

				if (Character && Character->GetCharacterMovement())
				{
					Character->GetCharacterMovement()->GroundFriction = 8.0f;
					Character->GetCharacterMovement()->GravityScale = 4.5f;
					Character->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
					Character->ReEnableInput();
				
				}

			}), .1f, false);
	}
}

void UGAS_Dash::CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility)
{
	Super::CancelAbility(Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
