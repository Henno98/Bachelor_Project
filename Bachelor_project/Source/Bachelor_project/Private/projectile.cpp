// Fill out your copyright notice in the Description page of Project Settings.


#include "projectile.h"

// Sets default values
Aprojectile::Aprojectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	SetRootComponent(collider);
	collider->SetWorldScale3D(FVector(0.1f));
	staticmesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("staticmesh"));
	staticmesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void Aprojectile::BeginPlay()
{
	Super::BeginPlay();
	//SetActorLocation(CurrentLocation);
	
}

// Called every frame
void Aprojectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Travel(DeltaTime);

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

