// Fill out your copyright notice in the Description page of Project Settings.



#include "Player/GAS_Wall_Latch.h"
#include "GameplayTagsManager.h"
#include "GameFramework/Character.h"
#include "Player/Test_Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

UGAS_Wall_Latch::UGAS_Wall_Latch()
{

	UGameplayTagsManager& Manager = UGameplayTagsManager::Get();
	FGameplayTagContainer RequestTag;
	RequestTag.AddTag(Manager.RequestGameplayTag(FName("Abilities.Wall_Latch")));
	SetAssetTags(RequestTag);
}


void UGAS_Wall_Latch::LatchToWall(ACharacter* Character, const FVector& WallNormal)
{
    if (!Character)
    {
        return;
    }
    UWorld* World = Character->GetWorld();
    if (!World) {
        return;
    }

    UCharacterMovementComponent* Movement = Character->GetCharacterMovement();
    if (!Movement)
    {
         return;
    }

    // Temporarily reduce gravity while wall latching
    Movement->GravityScale = 0.1f;  // Slow descent


    FVector CurrentVelocity = Movement->Velocity;
    CurrentVelocity.Z *= 0.f;  // Stop vertical movement
    Movement->Velocity = CurrentVelocity;

    FVector NewPosition = Character->GetActorLocation() - WallNormal * 20.0f;

    // Ensure the new position is valid
 
    // Check if the position is valid before setting it
    if (!NewPosition.IsZero())
    {
        Character->SetActorLocation(NewPosition);
    }

   
     // Timer to restore gravity
    FTimerHandle TimerHandle;
    World->GetTimerManager().SetTimer(TimerHandle, [Movement]()
        {
            if (Movement)
            {
                Movement->GravityScale = 4.0f;  // Set gravity back to normal
            }
        }, 0.1f, false);
}


void UGAS_Wall_Latch::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                      const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                      const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (HasAuthorityOrPredictionKey(ActorInfo, &ActivationInfo))
	{

		ACharacter* Character = CastChecked<ACharacter>(ActorInfo->AvatarActor.Get());

		if (Character)
		{
           
            if (!Character) return;

            UCharacterMovementComponent* MovementComponent = Character->GetCharacterMovement();
            if (!MovementComponent) return;

            // Get capsule for line trace start position
            UCapsuleComponent* Capsule = Character->GetCapsuleComponent();
            if (!Capsule) {
              

                return;
            }
            // Calculate line trace points
            FVector Start = Capsule->GetComponentLocation();

            // Check multiple directions for more robust wall detection
            TArray<FVector> DirectionsToCheck = {
                Capsule->GetForwardVector(),
                Capsule->GetRightVector(),
                -Capsule->GetRightVector()
            };

            FHitResult BestHitResult;
            bool bHit = false;
            UWorld* World = Character->GetWorld();

            if (!World)
            {

                return;

            }
            for (const FVector& Direction : DirectionsToCheck)
            {
                FVector End = Start + (Direction * 80.f);
                FHitResult HitResult;
                FCollisionQueryParams Params;
                Params.AddIgnoredActor(Character);

                bool bSingleHit = World->LineTraceSingleByChannel(
                    HitResult,
                    Start,
                    End,
                    ECC_WorldStatic,
                    Params
                );

                if (bSingleHit)
                {
                    bHit = true;
                    BestHitResult = HitResult;
                    // Debug the trace
                  break;
                }
                else
                {
                   
                }
            }


            // Handle wall latching if a wall is detected
            if (bHit)
            {
               
                Character->ResetJumpState();
                Character->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
            	LatchToWall(Character, BestHitResult.Normal);
            }
		}
		else
		{
			EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		}

	}

}

void UGAS_Wall_Latch::CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility)
{
	Super::CancelAbility(Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility);
    // Call EndAbility to finish the ability
    EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

void UGAS_Wall_Latch::InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo)
{
	Super::InputReleased(Handle, ActorInfo, ActivationInfo);
    
    if (ActorInfo != NULL && ActorInfo->AvatarActor != NULL)
    {
        CancelAbility(Handle, ActorInfo, ActivationInfo, true);
    }
}
