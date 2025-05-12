// Fill out your copyright notice in the Description page of Project Settings.


#include "projectile.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Enemies/EnemyInterface.h"
#include "Enemies/Test_Enemy.h"
#include "Kismet/GameplayStatics.h"
#include "Player/Test_Character.h"

/**
 * Aprojectile
 *
 * This actor class represents a generic projectile used by characters or enemies.
 * - Moves forward each tick using a customizable velocity and destroys itself after a randomized lifetime.
 * - Uses a sphere collision component to detect overlaps with valid targets, ignoring the owner and non-character actors.
 * - Ignores collisions with non-pawn objects and selectively applies damage to valid hit targets.
 * - Prevents friendly fire by checking interfaces and actor relationships.
 * - Disables rendering and collision upon "destruction" instead of immediately removing the actor from the world.
 */


// Sets default values
Aprojectile::Aprojectile()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	SetRootComponent(collider);
	collider->SetRelativeScale3D(FVector(Size));
	collider->OnComponentBeginOverlap.AddDynamic(this, &Aprojectile::OnOverlap);
	staticmesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("staticmesh"));
	staticmesh->SetupAttachment(RootComponent);
	staticmesh->SetRelativeScale3D(FVector(0.5f));

	collider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	collider->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic); 
	collider->SetCollisionResponseToAllChannels(ECR_Ignore); 
	collider->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap); 


}
// Called when the game starts or when spawned
void Aprojectile::BeginPlay()
{
	Super::BeginPlay();
	lifetime = FMath::RandRange(5, 10);
	
}

void Aprojectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Travel(DeltaTime);
	
	Timer += DeltaTime;
	if (Timer > lifetime) {
		DestroyActor();
	}

}

void Aprojectile::Travel(float deltatime)
{

	CurrentLocation = GetActorLocation();
	CurrentLocation += Velocity*deltatime;
	SetActorLocation(CurrentLocation);

}

void Aprojectile::SetPosition(FVector position)
{
	CurrentLocation = position;
}

void Aprojectile::DestroyActor()
{
	    SetActorHiddenInGame(true);
		SetActorEnableCollision(false);

}

void Aprojectile::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
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

	if (GetOwner()->Implements<UEnemyInterface>())
	{
		if (OtherActor->Implements<UEnemyInterface>())
		{
			return;
		}
	}
	// Apply damage
	float DamageAmount = GetDamage();
	UGameplayStatics::ApplyDamage(OtherActor, DamageAmount, nullptr, this, nullptr);
	DestroyActor();
	

}

