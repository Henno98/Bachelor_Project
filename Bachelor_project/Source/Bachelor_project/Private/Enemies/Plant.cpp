// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/Plant.h"

#include "Player/GAS_PlayerState.h"

// Sets default values
APlant::APlant()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlant::BeginPlay()
{
	Super::BeginPlay();
	InitAbilitySystem();
}

// Called every frame
void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlant::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlant::InitAbilitySystem()
{
	AGAS_PlayerState* GASPlayerState = GetPlayerState<AGAS_PlayerState>();

	if (ensure(GASPlayerState))
	{
		GASPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(GASPlayerState, this);
		AbilitySystemComponent = GASPlayerState->GetAbilitySystemComponent();
		GA_Ranged_Attack = GASPlayerState->RangedAttack;
		RangedAttackAbilitySpec = FGameplayAbilitySpec(GA_Ranged_Attack);
		AbilitySystemComponent->GiveAbility(RangedAttackAbilitySpec);

	}
}

void APlant::CallGAS_RangedAttack()
{
	if (AbilitySystemComponent && GA_Ranged_Attack)
	{
		bIsRangedAttacking = true;


		FGameplayTagContainer tags;
		tags.AddTag(FGameplayTag::RequestGameplayTag(FName("Abilities.Shoot")));
		AbilitySystemComponent->TryActivateAbilitiesByTag(tags);


		FTimerHandle TimerHandle;
		float AnimDuration;

	
			AnimDuration = 1.f;
		

		GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([this]()
			{
				bIsRangedAttacking = false;
			}), AnimDuration, false); // Adjust based on anim length
	}
}

