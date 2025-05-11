// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/CrowBoss_Projectile.h"
#include "GameFramework/Character.h"
#include "IsRangedAttacker.h"
#include "Enemies/EnemyInterface.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"


ACrowBoss_Projectile::ACrowBoss_Projectile()
{
    PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	//Mesh->SetRelativeRotation(FRotator(0.f, 90.f, 0.f)); // Example if forward is along Y
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
	UE_LOG(LogTemp, Warning, TEXT("Projectile overlapped with: %s"), *OtherActor->GetClass()->GetName());

	if (!OtherActor->IsA<ACharacter>())
	{
		UE_LOG(LogTemp, Warning, TEXT("Not a character. Ignoring."));
		return;
	}
	// Log the actor we hit
	UE_LOG(LogTemp, Log, TEXT("Aprojectile::OnOverlap - Overlapped with actor: %s"), *OtherActor->GetName());
	if (GetOwner() && GetOwner()->Implements<UIsRangedAttacker>()) {
		// Apply damage
		float DamageAmount = IIsRangedAttacker::Execute_GetRangedDamage(GetOwner());
		UGameplayStatics::ApplyDamage(OtherActor, DamageAmount, nullptr, this, nullptr);
		DestroyActor();

		// Confirm damage was applied
		UE_LOG(LogTemp, Log, TEXT("Aprojectile::OnOverlap - Applied %f damage to %s"), DamageAmount, *OtherActor->GetName());
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
	UE_LOG(LogTemp, Warning, TEXT("Projectile overlapped with: %s"), *OtherActor->GetClass()->GetName());

	if (!OtherActor->IsA<ACharacter>())
	{
		UE_LOG(LogTemp, Warning, TEXT("Not a character. Ignoring."));
		return;
	}
	// Log the actor we hit
	UE_LOG(LogTemp, Log, TEXT("Aprojectile::OnOverlap - Overlapped with actor: %s"), *OtherActor->GetName());
	if (GetOwner() && GetOwner()->Implements<UIsRangedAttacker>()) {
		// Apply damage
		float DamageAmount = IIsRangedAttacker::Execute_GetRangedDamage(GetOwner());
		UGameplayStatics::ApplyDamage(OtherActor, DamageAmount, nullptr, this, nullptr);
		DestroyActor();

		// Confirm damage was applied
		UE_LOG(LogTemp, Log, TEXT("Aprojectile::OnOverlap - Applied %f damage to %s"), DamageAmount, *OtherActor->GetName());
	}
}

FRotator ACrowBoss_Projectile::LookAt(FVector target)
{
	FVector Direction = (target - GetActorLocation()).GetSafeNormal();
	FRotator LookAtRotation = Direction.Rotation();
	SetActorRotation(LookAtRotation);
	return LookAtRotation;
}
