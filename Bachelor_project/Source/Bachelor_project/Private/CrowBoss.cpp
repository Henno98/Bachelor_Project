// Fill out your copyright notice in the Description page of Project Settings.


#include "CrowBoss.h"

// Sets default values
ACrowBoss::ACrowBoss()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACrowBoss::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACrowBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACrowBoss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACrowBoss::MeleeAttack()
{
	//Activate Melee Hitbox

	//Check for player collision

	//if yes, dmg

	//if no, end attack
}

void ACrowBoss::FeatherAttack()
{
	//Activate Feather Hitbox

	//Launch Feathers

	//Check for player collision

	//if yes, dmg

	//if no, end attack

}

void ACrowBoss::SpecialAttack()
{
	//Init Special Hitbox

	//Check for player collision

	//if yes, dmg

	//if no, end attack


}

void ACrowBoss::Collision()
{
	//on collision

	//launch player away

	//Player takes damage

	//GG


}

void ACrowBoss::Death()
{
	//Health Reaches 0

	//Despawn boss

	//Spawn PowerUp

}

