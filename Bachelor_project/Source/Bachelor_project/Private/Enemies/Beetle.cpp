// Fill out your copyright notice in the Description page of Project Settings.



#include "Enemies/Beetle.h"

// Sets default values
ABeetle::ABeetle()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABeetle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABeetle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABeetle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

