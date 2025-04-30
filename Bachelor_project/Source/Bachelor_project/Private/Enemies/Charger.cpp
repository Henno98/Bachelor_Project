// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/Charger.h"

#include "projectile.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/Test_Character.h"

// Sets default values
ACharger::ACharger()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ACharger::OnOverlap);
	GetCapsuleComponent()->SetGenerateOverlapEvents(true);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap); // or ECR_Overlap based on your needs
}

// Called when the game starts or when spawned
void ACharger::BeginPlay()
{
	Super::BeginPlay();
	
}

float ACharger::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	// Default damage handling (e.g., subtract health)
	Health -= DamageAmount;
	GetCharacterMovement()->StopMovementImmediately();
	// Ensure health doesn't go below 0
	//Health = FMath::Max(Health, 0.0f);

	// Optionally, apply other effects like playing an animation or sound
	// For example: PlayHitReaction();
	UE_LOG(LogTemp, Error, TEXT("Charger took damage"));
	// Return the remaining health or amount of damage absorbed
	return DamageAmount;
}

// Called every frame
void ACharger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetHealth()<=0)
	{
		bIsDying = true;
		if (bIsDead) {
			Destroy();
		}

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

void ACharger::Destroy()
{
	
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

void ACharger::OnHit(int damage)
{
	SetHealth(GetHealth()-damage);
}

