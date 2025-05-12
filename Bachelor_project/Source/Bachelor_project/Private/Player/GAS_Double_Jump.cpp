// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/GAS_Double_Jump.h"
#include "GameplayTagsManager.h"
#include "Player/Test_Character.h"
#include "GameFramework/Character.h"
#include "World/LevelStreamingActor.h"

/**
 * UGAS_Double_Jump
 *
 * Gameplay Ability class that handles the double jump ability for a character.
 * - Performs a sweep check to ensure the character can double jump by detecting if the character is close to a platform.
 * - Temporarily disables collision on platforms the character is close to, allowing for smooth double jumping.
 * - The character can jump a second time after the first jump, given the conditions are met.
 * - Ends the ability if certain conditions are not met or if the character is invalid.
 * - Provides functionality to cancel the ability and stop jumping if needed.
 */


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
		FVector Start = Character->GetActorLocation() + FVector(0.f, 0, 50.f);
		FVector End = Start + (Direction * 200.f);

		TArray<FHitResult> HitResult;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(Character);
		TArray<AActor*> StreamingActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ALevelStreamingActor::StaticClass(), StreamingActors);

		for (AActor* Actor : StreamingActors)
		{
			Params.AddIgnoredActor(Actor);
		}
	
		FCollisionShape SweepShape = FCollisionShape::MakeSphere(200.f);

		bool bSweepHit = GetWorld()->SweepMultiByChannel(
			HitResult,
			Start,
			End,
			FQuat::Identity,
			ECC_WorldStatic,
			SweepShape,
			Params
		);
		
		
		if (bSweepHit)
		{
			for (const FHitResult& Hit : HitResult)
			{
				AActor* HitActor = Hit.GetActor();
				if (IsValid(HitActor))
				{
					if (HitActor->GetFName().ToString().Contains(FString("Platform")) == true)
					{
						HitActor->SetActorEnableCollision(false);

						FTimerHandle TimerHandle;
						GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([HitActor]()
							{
							if (IsValid(HitActor))
								HitActor->SetActorEnableCollision(true);

							}), 0.5f, false);


					}

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


	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);

}

void UGAS_Double_Jump::InputReleased(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo)
{
	Super::InputReleased(Handle, ActorInfo, ActivationInfo);
	
	if (ActorInfo != NULL && ActorInfo->AvatarActor != NULL)
	{
		CancelAbility(Handle, ActorInfo, ActivationInfo, true);
	}

}
