// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_Enemy.h"
#include "projectile.h"
#include "Test_Character.h"
#include "Components/BoxComponent.h"
#include "GameFramework/PawnMovementComponent.h"

// Sets default values
ATest_Enemy::ATest_Enemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	SetRootComponent(Collider);
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);
	Vision = CreateDefaultSubobject<USphereComponent>(TEXT("Vision"));
	Vision->SetupAttachment(RootComponent);
	Vision->SetSphereRadius(500.f);
	Vision->OnComponentBeginOverlap.AddDynamic(this, &ATest_Enemy::OnOverlap);
	//Vision->OnComponentEndOverlap.AddDynamic(this, &ATest_Enemy::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ATest_Enemy::BeginPlay()
{
	Super::BeginPlay();
	Position = GetActorLocation();
	Health = 6;
	Damage = 1;
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
	else if (Timer >= 5.f)
	{
		Timer = 0.f;
		bHasSpawnedProjectile = false;
	}
	SetActorLocation(CurrentPosition);
	
}

void ATest_Enemy::Look()
{


}

void ATest_Enemy::Attack(FVector location)
{

	// Spawn the projectile
	if (!ProjectileClass)
	{
		return;
	}

	// Get the spawn location and rotation
	 // Adjust Z to avoid ground collisions
	SpawnLocation = GetActorLocation() + FVector(0.f, 0.f, 100.f);
	FRotator SpawnRotation = (location - SpawnLocation).Rotation();

	if (location.IsZero())
	{
		return;
	}
	if (SpawnLocation.IsZero())
	{
		return;
	}

	// Spawn the projectile
	UWorld* World = GetWorld();
	if (World)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		Aprojectile* SpawnedProjectile = World->SpawnActor<Aprojectile>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
		if (SpawnedProjectile)
		{
			// Calculate the direction vector
			FVector Direction = (location - SpawnLocation).GetSafeNormal();
			SpawnedProjectile->Velocity = Direction * 200.f;
			SpawnedProjectile->Owner = this;
			SpawnedProjectile->SetActorScale3D(BulletSize);
		}
	}
}


void ATest_Enemy::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA<ATest_Character>() && OverlappedComponent->IsA<USphereComponent>())
	{
		if (!bHasSpawnedProjectile) 
		{
			bHasSpawnedProjectile = true;
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

