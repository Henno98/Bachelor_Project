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

		FVector Direction = Character->GetActorUpVector();
		FVector Start = Character->GetActorLocation();
		FVector End = Start + (Direction * 300.f);
		FHitResult HitResult;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(Character);

		bool bSingleHit = GetWorld()->LineTraceSingleByChannel(
			HitResult,
			Start,
			End,
			ECC_WorldStatic,
			Params);
		DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 1.0f, 0, 2.0f);

		if (bSingleHit)
		{
			if (IsValid(HitResult.GetActor()))
			{
				if (HitResult.GetActor()->GetFName().ToString().Contains(FString("Platform")) == true)
				{
					DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1.0f, 0, 2.0f);

					HitResult.GetActor()->SetActorEnableCollision(false);

					FTimerHandle TimerHandle;
					GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([HitResult]()
						{
							HitResult.GetActor()->SetActorEnableCollision(true);

						}), 0.5f, false);


				}

			}

		}
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
