// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/Test_Enemy.h"
#include "projectile.h"
#include "Components/BoxComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Player/Test_Character.h"

/**
 * ATest_Enemy
 *
 * Simple enemy character with projectile and movement behavior. Not interactable in game. used for practice and testing
 * - Moves back and forth along the Y-axis, with a timer to control direction.
 * - Detects overlaps with the player character using a vision sphere and box collider.
 * - Spawns a projectile towards the player's location when detected.
 * - Applies damage to the player character if collided with the box collider.
 * - Destroys itself when health reaches zero and hides from the game.
 * - Integrated with a projectile class for ranged attacks.
 */


// Sets default values
ATest_Enemy::ATest_Enemy()
{
	PrimaryActorTick.bCanEverTick = true;
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	SetRootComponent(Collider);
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);
	Vision = CreateDefaultSubobject<USphereComponent>(TEXT("Vision"));
	Vision->SetupAttachment(RootComponent);
	Vision->SetSphereRadius(500.f);
	Vision->OnComponentBeginOverlap.AddDynamic(this, &ATest_Enemy::OnOverlap);
}

// Called when the game starts or when spawned
void ATest_Enemy::BeginPlay()
{
	Super::BeginPlay();
	Position = GetActorLocation();
	
}

void ATest_Enemy::Walk(float deltatime)
{

	
	Timer += deltatime;
	FVector CurrentPosition = GetActorLocation();
	if (Timer <= 2.f)
	{
		CurrentPosition.Y += WalkSpeed * deltatime;
		SetActorRotation(FRotator(0.f, 0.f, 0.f));
	}
	else if (Timer <= 4.f)
	{
		CurrentPosition.Y -= WalkSpeed * deltatime;
		SetActorRotation(FRotator(0.f, -180.f, 0.f));

	}
	else if (Timer >= 2.f)
	{
		Timer = 0.f;
		bHasSpawnedProjectile = false;
		
	}
	SetActorLocation(CurrentPosition);
	
}

void ATest_Enemy::Look()
{
	//not needed

}

void ATest_Enemy::AttackLoop()
{
	//not needed

}

void ATest_Enemy::Attack(FVector TargetLocation)
{
	if (!ProjectileClass || TargetLocation.IsZero())
	{
		return;
	}

	// Calculate spawn location and rotation
	 SpawnLocation = GetActorLocation() + FVector(0.f, 0.f, 100.f);
	if (SpawnLocation.IsZero()) 
	{
		return;
	}

	FRotator SpawnRotation = (TargetLocation - SpawnLocation).Rotation();
	FTimerHandle AttackDelayHandle;
	UWorld* World = GetWorld();
	if (World)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;

		Aprojectile* SpawnedProjectile = World->SpawnActor<Aprojectile>(
			ProjectileClass,
			SpawnLocation,
			SpawnRotation,
			SpawnParams
		);

		if (SpawnedProjectile)
		{
			FVector Direction = (TargetLocation - SpawnLocation).GetSafeNormal();
			SpawnedProjectile->Velocity = Direction * 200.f;
			SpawnedProjectile->Owner = this;
			SpawnedProjectile->SetActorScale3D(BulletSize);
		}

		
		GetWorldTimerManager().SetTimer(AttackDelayHandle, this, &ATest_Enemy::AttackLoop, 1.f, false);
		bHasSpawnedProjectile = true;
	}
}



void ATest_Enemy::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA<ATest_Character>() && OverlappedComponent->IsA<USphereComponent>())
	{
		if (!bHasSpawnedProjectile) 
		{
			
		FVector position = OtherActor->GetActorLocation();
		Attack(position);
		}
	}
	if (OtherActor->IsA<ATest_Character>() && OverlappedComponent->IsA<UBoxComponent>())
	{
		ATest_Character* collidedPlayer = Cast<ATest_Character>(OtherActor);
		if (collidedPlayer && collidedPlayer->GetMovementComponent())
		{
			FVector velocity = collidedPlayer->GetMovementComponent()->Velocity;
			collidedPlayer->LaunchCharacter(velocity * -1, true, true);

			
		}
	}
	}

void ATest_Enemy::Destroy()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	SetActorLocation(FVector(0));
}

void ATest_Enemy::OnHit(int damage)
{
	Health -= damage;
}

void ATest_Enemy::OnOverlapEnd()
{
	bHasSpawnedProjectile = false;
}

// Called every frame
void ATest_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Walk(DeltaTime);
	if (Health <= 0)
	{

		Destroy();
	}
}

