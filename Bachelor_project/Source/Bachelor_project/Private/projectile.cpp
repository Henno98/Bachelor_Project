// Fill out your copyright notice in the Description page of Project Settings.


#include "projectile.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Enemies/EnemyInterface.h"
#include "Enemies/Test_Enemy.h"
#include "Kismet/GameplayStatics.h"
#include "Player/Test_Character.h"

// Sets default values
Aprojectile::Aprojectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	SetRootComponent(collider);
	collider->SetRelativeScale3D(FVector(Size));
	collider->OnComponentBeginOverlap.AddDynamic(this, &Aprojectile::OnOverlap);
	//collider->SetWorldScale3D(FVector(0.5f));
	staticmesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("staticmesh"));
	staticmesh->SetupAttachment(RootComponent);
	staticmesh->SetRelativeScale3D(FVector(0.5f));

	
	collider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	collider->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic); // Should be something like Pawn or WorldDynamic
	collider->SetCollisionResponseToAllChannels(ECR_Ignore); // Ignore other actors by default
	collider->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap); // Set overlap with player characters (ECC_Pawn)
	//collider->IgnoreActorWhenMoving(GetOwner(),true);

}
// Called when the game starts or when spawned
void Aprojectile::BeginPlay()
{
	Super::BeginPlay();
	//SetActorLocation(CurrentLocation);
	lifetime = FMath::RandRange(5, 10);
	
}
// Called every frame
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
		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Destroyed projectile", true);

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
	
	// Log the actor we hit
	UE_LOG(LogTemp, Log, TEXT("Aprojectile::OnOverlap - Overlapped with actor: %s"), *OtherActor->GetName());
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
	// Confirm damage was applied
	UE_LOG(LogTemp, Log, TEXT("Aprojectile::OnOverlap - Applied %f damage to %s"), DamageAmount, *OtherActor->GetName());

}

