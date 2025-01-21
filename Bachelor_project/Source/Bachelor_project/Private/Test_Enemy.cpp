// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_Enemy.h"

#include "projectile.h"
#include "Test_Character.h"
#include "Components/BoxComponent.h"

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
	Vision->SetSphereRadius(1000.f);
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
	if (Timer <= 2.f)
	{
		Position.Y += WalkSpeed * deltatime;
		SetActorLocation(Position);
	}
	if(Timer >= 2.f && Timer <= 4.f)
	{
		Position.Y -= WalkSpeed * deltatime;
		SetActorLocation(Position);
	}
	if(Timer >= 5)
	{
		Timer = 0.f;
	}
	
}

void ATest_Enemy::Look()
{


}

void ATest_Enemy::Attack(FVector location)
{

	// Get the spawn location and rotation
	FVector SpawnLocation = GetActorLocation() + FVector(0.f, 0.f, 50.f); // Adjust Z to avoid ground collisions
	FRotator SpawnRotation = (location - SpawnLocation).Rotation();

	// Spawn the projectile
	UWorld* World = GetWorld();
	if (World)
	{
		// Spawn the projectile

		Aprojectile* SpawnedProjectile = World->SpawnActor<Aprojectile>(ProjectileClass, SpawnLocation, SpawnRotation);
		if (!ProjectileClass)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ProjectileClass is not set!"));
			return;
		}
		if (SpawnedProjectile)
		{
			GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Cyan,TEXT("Spawned projectile"));
			// Calculate the direction vector
			FVector Direction = (location - SpawnLocation).GetSafeNormal();
			SpawnedProjectile->Velocity = Direction * 1.f;

		}
	}
}

void ATest_Enemy::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA<ATest_Character>())
	{

		GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Red, TEXT("Collided"));
		FVector position = OtherActor->GetActorLocation();
		Attack(position);
	}
}

// Called every frame
void ATest_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Walk(DeltaTime);
}

