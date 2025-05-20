// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/Plant.h"
#include "Player/GAS_PlayerState.h"

/**
 * APlant
 *
 * Plant enemy character class with Ability System integration.
 * - Initializes and manages an Ability System Component for the Plant.
 * - Initializes and activates abilities (specifically ranged attack) upon spawn.
 * - Handles the ranged attack using the gameplay ability system.
 * - Takes damage and destroys the actor when health reaches zero.
 */


// Sets default values
APlant::APlant()
{
	PrimaryActorTick.bCanEverTick = true;
    // Create and register the AbilitySystemComponent
    AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

// Called when the game starts or when spawned
void APlant::BeginPlay()
{
	Super::BeginPlay();

        Direction = GetActorRotation();
	SpawnLocation = GetMesh()->GetSocketLocation(TEXT("PlantMouth")); 
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
    // Give abilities to the plant
    if (AbilitySystemComponent)
    {
        if (RangedAttackAbilityClass)
        {
            RangedAttackAbilitySpec = FGameplayAbilitySpec(RangedAttackAbilityClass);
            AbilitySystemComponent->GiveAbility(RangedAttackAbilitySpec);
        }
    }
}

UAbilitySystemComponent* APlant::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void APlant::CallGAS_RangedAttack()
{
    if (AbilitySystemComponent)
    {
      
        FGameplayTagContainer tags;
        tags.AddTag(FGameplayTag::RequestGameplayTag(FName("Abilities.Shoot")));
    

        if (AbilitySystemComponent->TryActivateAbilitiesByTag(tags))
        {
            UE_LOG(LogTemp, Log, TEXT("Plant activated ranged attack."));
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Ranged attack could not be activated."));
        }
    }
	
}

float APlant::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator,
	AActor* DamageCauser)
{
    SetHealth(GetHealth() - DamageAmount);
    if (GetHealth() <= 0)
    {
        SetActorHiddenInGame(true);
        SetActorEnableCollision(false);
        Destroy();

    }
	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}

