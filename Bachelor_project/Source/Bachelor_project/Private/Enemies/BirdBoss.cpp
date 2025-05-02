// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/BirdBoss.h"

// Sets default values
ABirdBoss::ABirdBoss()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABirdBoss::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABirdBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABirdBoss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

