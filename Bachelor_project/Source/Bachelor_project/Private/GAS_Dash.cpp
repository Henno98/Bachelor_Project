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
		ATest_Character* Character = Cast<ATest_Character>(ActorInfo->AvatarActor.Get());
		if (!Character || !Character->GetCharacterMovement())
		{
			EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
			return;
		}
		
		// Get movement direction
		FVector Direction = Character->GetCharacterMovement()->GetForwardVector().GetSafeNormal();
		Character->PauseInput();
		
		// Temporarily disable collision
		Character->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

		// Reduce friction to allow smooth dashing
		Character->GetCharacterMovement()->GroundFriction = 0.1f;

		// Apply dash force
		Character->LaunchCharacter(FVector(0,Direction.Y * 2000.f,0), false, false);

		// Reset friction and restore collision after delay
		FTimerHandle TimerHandle;
		Character->GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([Character]()
			{

				if (Character && Character->GetCharacterMovement())
				{
					Character->GetCharacterMovement()->GroundFriction = 8.0f; // Restore default friction
					Character->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
					Character->ReEnableInput();
				
					
				}

			}), 0.5f, false);
	}
}

void UGAS_Dash::CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility)
{
	Super::CancelAbility(Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility);
	
	// Call EndAbility to finish the ability
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
