// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/Charger.h"
#include "projectile.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/Test_Character.h"

/**
 * ACharger
 *
 * Enemy character that charges at the player when detected.
 * - Detects overlaps with projectiles and player characters.
 * - Takes damage, dies when health reaches zero.
 * - Handles its own collision, health, and damage logic.
 * - Integrated with behavior tree for AI logic via controller.
 */

ACharger::ACharger()
{
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ACharger::OnOverlap);
	GetCapsuleComponent()->SetGenerateOverlapEvents(true);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap); 
}

// Called when the game starts or when spawned
void ACharger::BeginPlay()
{
	Super::BeginPlay();
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetHealth(Health);

}

float ACharger::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	SetHealth(GetHealth()-DamageAmount);
	GetCharacterMovement()->StopMovementImmediately();
	if (GetHealth() <= 0)
	{
		bIsDying = true;
	}
	return DamageAmount;
}

// Called every frame
void ACharger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsDead) {
		DestroyActor();
	}
}

void ACharger::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this || OtherActor->GetOwner() != this)
	{
		if (OtherActor->IsA<Aprojectile>())
		{
			Aprojectile* projectile = Cast<Aprojectile>(OtherActor);
			int dmg  = projectile->GetDamage();
			OnHit(dmg);
			projectile->DestroyActor();
		}
		if (OtherActor->IsA<ATest_Character>())
		{

			ATest_Character* player = Cast<ATest_Character>(OtherActor);
			player->Hit(GetDamage());
		}

	}
}

void ACharger::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
}

// Called to bind functionality to input
void ACharger::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharger::DestroyActor()
{
	
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	Destroy();
}

void ACharger::OnHit(int damage)
{
	SetHealth(GetHealth()-damage);
}

float ACharger::GetHealth() const
{
	return Health;
}

float ACharger::GetDamage() const
{
	return Damage;
}

void ACharger::SetHealth(float NewHealth)
{
	Health = NewHealth;
}

void ACharger::SetDamage(float NewDamage)
{
	Damage = NewDamage;
}

