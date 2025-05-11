// Fill out your copyright notice in the Description page of Project Settings.



#include "Enemies/Beetle.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/Test_Character.h"


// Sets default values
ABeetle::ABeetle()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ABeetle::OnOverlap);
	GetCapsuleComponent()->SetGenerateOverlapEvents(true);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

}

// Called when the game starts or when spawned
void ABeetle::BeginPlay()
{
	Super::BeginPlay();
	
}

float ABeetle::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator, AActor* DamageCauser)
{

	Health -= DamageAmount;
	GetCharacterMovement()->StopMovementImmediately();

	return DamageAmount;
}

// Called every frame
void ABeetle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetHealth() <= 0)
	{
		bIsDying = true;
		if (bIsDead) {
			DestroyActor();
		}

	}
}

void ABeetle::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this || OtherActor->GetOwner() != this)
	{
		if (OtherActor->IsA<Aprojectile>())
		{
			Aprojectile* projectile = Cast<Aprojectile>(OtherActor);
			int dmg = projectile->GetDamage();
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

void ABeetle::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
}

// Called to bind functionality to input
void ABeetle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABeetle::DestroyActor()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	Destroy();
}

void ABeetle::OnHit(int damage)
{
	SetHealth(GetHealth() - damage);
}

