// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/GAS_Ranged_Attack.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameplayTagsManager.h"
#include "AbilitySystemComponent.h"
#include "IsRangedAttacker.h"
#include "Player/Test_Character.h"

/**
 * UGAS_Ranged_Attack
 *
 * Gameplay Ability class that handles the ranged attack for a character.
 * - Stops movement and modifies gravity before shooting.
 * - Uses the IIsRangedAttacker interface to get projectile properties like spawn location, firing direction, and velocity.
 * - Spawns a projectile and applies velocity, damage, and lifetime properties.
 * - Handles cooldown with a timer, allowing the character to shoot again after a short delay.
 * - Ends the ability if certain conditions are not met, such as missing components or interface implementation.
 */


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
			UE_LOG(LogTemp, Warning, TEXT("GAS_Ranged_Attack: Ability System does not exist."));
			EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
			return;
		}

		ACharacter* Character = Cast<ACharacter>(ActorInfo->AvatarActor.Get());
		if (!Character || !Character->GetCharacterMovement())
		{
			UE_LOG(LogTemp, Warning, TEXT("GAS_Ranged_Attack: Character or Character Movement not found."));
			EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
			return;
		}

		if (!Character->GetClass()->ImplementsInterface(UIsRangedAttacker::StaticClass()))
		{
			UE_LOG(LogTemp, Warning, TEXT("GAS_Ranged_Attack: Character does not implement IIsRangedAttacker."));
			EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
			return;
		}


		// Stop movement immediately and apply a gravity modifier
		Character->GetCharacterMovement()->StopMovementImmediately();
		Character->GetCharacterMovement()->Velocity = FVector::ZeroVector;
		Character->GetCharacterMovement()->GravityScale = 0.1f;

		FVector SpawnLocation = IIsRangedAttacker::Execute_GetSpawnLocation(Character);
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
			if (bCanShoot)
			{
				AActor* SpawnedActor = World->SpawnActor<AActor>(ActorClass, SpawnLocation, SpawnRotation, SpawnParams);
				if (SpawnedActor)
				{
					Aprojectile* SpawnedProjectile = Cast<Aprojectile>(SpawnedActor);
					if (SpawnedProjectile)
					{
						float Velocity = IIsRangedAttacker::Execute_GetRangedAttackVelocity(Character);
						float Damage = IIsRangedAttacker::Execute_GetRangedDamage(Character);
						FVector BulletSize = IIsRangedAttacker::Execute_GetBulletSize(Character);

						// Set properties on the projectile
						if (IIsRangedAttacker::Execute_GetHasTarget(Character))
						{
							FVector Direction = IIsRangedAttacker::Execute_GetTargetLocation(Character);
							SpawnedProjectile->Velocity = Direction * Velocity;
						}
						else
						{
							SpawnedProjectile->Velocity = FiringDirection * Velocity;
						}
						SpawnedProjectile->lifetime = IIsRangedAttacker::Execute_GetLifeTime(Character);
						SpawnedProjectile->SetDamage(Damage);
						SpawnedProjectile->SetActorScale3D(BulletSize);
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("GAS_Ranged_Attack: Failed to cast SpawnedActor to Aprojectile."));
					}
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("GAS_Ranged_Attack: Failed to spawn actor."));
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("GAS_Ranged_Attack: Cannot shoot yet (Cooldown or some other condition)."));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("GAS_Ranged_Attack: World is null."));
		}

		FTimerHandle TimerHandle;
		Character->GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([Character, this]()
			{
				if (Character && Character->GetCharacterMovement())
				{
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
