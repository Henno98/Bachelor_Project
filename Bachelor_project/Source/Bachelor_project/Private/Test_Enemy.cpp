// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_Enemy.h"

#include "projectile.h"
#include "Test_Character.h"
#include "Components/BoxComponent.h"
#include "EntitySystem/MovieSceneEntitySystemRunner.h"
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

}

void ATest_Enemy::Walk(float deltatime)
{

	
	Timer += deltatime;
	FVector CurrentPosition = GetActorLocation();
	if (Timer <= 2.f)
	{
		CurrentPosition.Y += WalkSpeed * deltatime;
	}
	else if (Timer <= 4.f)
	{
		CurrentPosition.Y -= WalkSpeed * deltatime;
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
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ProjectileClass is not set!"));
		return;
	}

	// Get the spawn location and rotation
	 // Adjust Z to avoid ground collisions
	SpawnLocation = GetActorLocation() + FVector(0.f, 0.f, 100.f);
	FRotator SpawnRotation = (location - SpawnLocation).Rotation();

	if (location.IsZero())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Target location is zero!"));
		return;
	}
	if (SpawnLocation.IsZero())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT(" Spawn location is zero!"));
		return;
	}

	// Spawn the projectile
	UWorld* World = GetWorld();
	if (World)
	{
		Aprojectile* SpawnedProjectile = World->SpawnActor<Aprojectile>(ProjectileClass, SpawnLocation, SpawnRotation);
		if (SpawnedProjectile)
		{
			GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Cyan,TEXT("Spawned projectile"));
			// Calculate the direction vector
			FVector Direction = (location - SpawnLocation).GetSafeNormal();
			SpawnedProjectile->Velocity = Direction * 200.f;
			
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
		GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Red, TEXT("Collided"));
		FVector position = OtherActor->GetActorLocation();
		Attack(position);
		}
	}
	if (OtherActor && OtherActor->IsA<ATest_Character>() && OverlappedComponent && OverlappedComponent->IsA<UBoxComponent>())
	{
		ATest_Character* collidedPlayer = Cast<ATest_Character>(OtherActor);
		if (collidedPlayer && collidedPlayer->GetMovementComponent())
		{
			FVector velocity = collidedPlayer->GetMovementComponent()->Velocity;
			collidedPlayer->LaunchCharacter(velocity * -1, true, true);

			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(
					-1, // Use -1 to avoid overwriting messages.
					2.f,
					FColor::Orange,
					TEXT("Pushed player")
				);
			}
		}
	}
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
}

