// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_Enemy.h"

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

void ATest_Enemy::Attack()
{
}

// Called every frame
void ATest_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Walk(DeltaTime);
}

