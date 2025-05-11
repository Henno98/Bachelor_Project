// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/Plant.h"

#include "Player/GAS_PlayerState.h"

// Sets default values
APlant::APlant()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    // Create and register the AbilitySystemComponent
    AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    UE_LOG(LogTemp, Log, TEXT("AbilitySystemComponent created for Plant."));
}

// Called when the game starts or when spawned
void APlant::BeginPlay()
{
	Super::BeginPlay();
	SpawnLocation = GetMesh()->GetSocketLocation(TEXT("PlantMouth")); // FIXED HERE
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

