// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/GAS_Ranged_Attack.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameplayTagsManager.h"
#include "AbilitySystemComponent.h"
#include "IsRangedAttacker.h"
#include "EntitySystem/MovieSceneEntitySystemRunner.h"
#include "Player/Test_Character.h"


UGAS_Ranged_Attack::UGAS_Ranged_Attack()
{
	UGameplayTagsManager& Manager = UGameplayTagsManager::Get();
	FGameplayTagContainer RequestTag;
	RequestTag.AddTag(Manager.RequestGameplayTag(FName("Abilities.Shoot")));
	SetAssetTags(RequestTag);

	CooldownGameplayEffect = nullptr;
}

void UGAS_Ranged_Attack::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (HasAuthorityOrPredictionKey(ActorInfo, &ActivationInfo))
	{

		// Check if Ability System is valid
		UAbilitySystemComponent* ASC = ActorInfo->AbilitySystemComponent.Get();
		if (!ASC)
		{
			EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
			return;
		}

		ACharacter* Character = Cast<ACharacter>(ActorInfo->AvatarActor.Get());
		if (!Character || !Character->GetCharacterMovement())
		{
			EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
			return;
		}

		// **Apply Cooldown Effect**
		if (CooldownGameplayEffect)
		{
			FGameplayEffectSpecHandle CooldownSpecHandle = ASC->MakeOutgoingSpec(CooldownGameplayEffect, 1.f, ASC->MakeEffectContext());
			if (CooldownSpecHandle.IsValid())
			{
				ASC->ApplyGameplayEffectSpecToSelf(*CooldownSpecHandle.Data.Get());
			}
		}
		Character->GetCharacterMovement()->StopMovementImmediately();
		Character->GetCharacterMovement()->Velocity = FVector::ZeroVector;
		Character->GetCharacterMovement()->GravityScale = 0.1f;

		FVector SpawnLocation = Character->GetActorLocation() + (Character->GetActorForwardVector().GetSafeNormal() * 50);
		FVector FiringDirection = Character->GetActorForwardVector().GetSafeNormal();
		FRotator SpawnRotation = IIsRangedAttacker::Execute_GetFiringDirection(Character);
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = Character;

		
		// Get the actor class from the interface
		TSubclassOf<AActor> ActorClass = IIsRangedAttacker::Execute_GetProjectileClass(Character);

		// Spawn the projectile
		UWorld* World = GetWorld();
		if (World)
		{
			if (bCanShoot) {
				AActor* SpawnedActor = World->SpawnActor<AActor>(ActorClass, SpawnLocation, SpawnRotation, SpawnParams);
				if (SpawnedActor)
				{
					Aprojectile* SpawnedProjectile = Cast<Aprojectile>(SpawnedActor);
					if (SpawnedProjectile)
					{
						float Velocity = IIsRangedAttacker::Execute_GetRangedAttackVelocity(Character);
						float Damage = IIsRangedAttacker::Execute_GetRangedDamage(Character);

						FVector BulletSize = IIsRangedAttacker::Execute_GetBulletSize(Character);
						SpawnedProjectile->lifetime = 1.f;
						if (IIsRangedAttacker::Execute_GetHasTarget(Character))
						{
							FVector Direction = IIsRangedAttacker::Execute_GetTargetLocation(Character);
							SpawnedProjectile->Velocity = Direction * Velocity;

						}
						else
						{
							SpawnedProjectile->Velocity = FiringDirection * Velocity;
						}
						SpawnedProjectile->SetDamage(Damage);
						SpawnedProjectile->SetActorScale3D(BulletSize);
					}
				}
			}
		}
		FTimerHandle TimerHandle;
		Character->GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([Character,this]()
			{

				if (Character && Character->GetCharacterMovement())
				{
					
					//Character->ReEnableInput();
				
					Character->GetCharacterMovement()->GravityScale = 4.5;
				
					bCanShoot = true;
				}

			}), 0.2f, false);
	}
}

void UGAS_Ranged_Attack::CancelAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateCancelAbility)
{
	Super::CancelAbility(Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility);
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);

}
