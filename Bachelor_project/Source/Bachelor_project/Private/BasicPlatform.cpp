// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicPlatform.h"

#include "Components/BoxComponent.h"

// Sets default values
ABasicPlatform::ABasicPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	SetRootComponent(Collider);
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ABasicPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasicPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

