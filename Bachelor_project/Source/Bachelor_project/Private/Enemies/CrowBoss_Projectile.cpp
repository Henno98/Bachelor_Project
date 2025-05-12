// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/CrowBoss_Projectile.h"
#include "GameFramework/Character.h"
#include "IsRangedAttacker.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"


/**
 * ACrowBoss_Projectile
 *
 * Represents a projectile fired by the Crow Boss in the game.
 *
 * Key Features:
 * - Uses UProjectileMovementComponent for forward movement with no gravity.
 * - Mesh component handles physics collision (OnHit).
 * - Capsule collider handles overlap events (OnOverlap).
 * - Applies damage to ACharacter targets using the ranged damage value from the projectile's owner if it implements the UIsRangedAttacker interface.
 * - Automatically deactivates (hides and disables collision) after hitting a valid target.
 *
 * Important Notes:
 * - Avoids applying damage to the projectile's owner.
 * - Uses both hit and overlap events to cover different collision types (e.g., static vs. dynamic actors).
 * - Logging included for debugging collision and damage application.
 */


ACrowBoss_Projectile::ACrowBoss_Projectile()
{
    PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	Mesh->SetSimulatePhysics(false);
	Mesh->SetNotifyRigidBodyCollision(true);
	Mesh->OnComponentHit.AddDynamic(this, &ACrowBoss_Projectile::OnHit);
	Collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	Collider->SetupAttachment(RootComponent);
	Collider->OnComponentBeginOverlap.AddDynamic(this, &ACrowBoss_Projectile::OnOverlap);
    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->InitialSpeed = 1200.0f;
    ProjectileMovement->MaxSpeed = 1200.0f;
    ProjectileMovement->bRotationFollowsVelocity = true;
    ProjectileMovement->ProjectileGravityScale = 0.0f;
	ProjectileMovement->bRotationFollowsVelocity = true;
}

// Called when the game starts or when spawned
void ACrowBoss_Projectile::BeginPlay()
{
    Super::BeginPlay();
	
}

// Called every frame
void ACrowBoss_Projectile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
	
}

void ACrowBoss_Projectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
    FVector NormalImpulse, const FHitResult& Hit)
{
	// Null check for OtherActor
	if (!OtherActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Aprojectile::OnOverlap - OtherActor is null."));
		return;
	}

	// Skip if the projectile hits its owner
	if (OtherActor == GetOwner())
	{
		UE_LOG(LogTemp, Warning, TEXT("Aprojectile::OnOverlap - Ignoring overlap with owner: %s"), *OtherActor->GetName());
		return;
	}


	if (!OtherActor->IsA<ACharacter>())
	{
		UE_LOG(LogTemp, Warning, TEXT("Not a character. Ignoring."));
		return;
	}

	if (GetOwner() && GetOwner()->Implements<UIsRangedAttacker>()) {
		// Apply damage
		float DamageAmount = IIsRangedAttacker::Execute_GetRangedDamage(GetOwner());
		UGameplayStatics::ApplyDamage(OtherActor, DamageAmount, nullptr, this, nullptr);
		DestroyActor();
	}
}

void ACrowBoss_Projectile::DestroyActor()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);

}

void ACrowBoss_Projectile::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                     UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Null check for OtherActor
	if (!OtherActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Aprojectile::OnOverlap - OtherActor is null."));
		return;
	}

	// Skip if the projectile hits its owner
	if (OtherActor == GetOwner())
	{
		UE_LOG(LogTemp, Warning, TEXT("Aprojectile::OnOverlap - Ignoring overlap with owner: %s"), *OtherActor->GetName());
		return;
	}

	if (!OtherActor->IsA<ACharacter>())
	{
		UE_LOG(LogTemp, Warning, TEXT("Not a character. Ignoring."));
		return;
	}

	if (GetOwner() && GetOwner()->Implements<UIsRangedAttacker>()) {
		// Apply damage
		float DamageAmount = IIsRangedAttacker::Execute_GetRangedDamage(GetOwner());
		UGameplayStatics::ApplyDamage(OtherActor, DamageAmount, nullptr, this, nullptr);
		DestroyActor();
	}
}

FRotator ACrowBoss_Projectile::LookAt(FVector target)
{
	FVector Direction = (target - GetActorLocation()).GetSafeNormal();
	FRotator LookAtRotation = Direction.Rotation();
	SetActorRotation(LookAtRotation);
	return LookAtRotation;
}
