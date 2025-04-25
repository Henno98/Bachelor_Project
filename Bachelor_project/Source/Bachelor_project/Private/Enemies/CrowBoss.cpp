// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/CrowBoss.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
ACrowBoss::ACrowBoss()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	auto Movement = GetCharacterMovement();
	Movement->SetMovementMode(MOVE_Flying);
	Movement->MaxFlySpeed = 800.f;

	// Aggressive deceleration
	Movement->BrakingDecelerationFlying = 2000.f;  // Increased from previous values

	// Enhanced stopping behavior
	Movement->bUseSeparateBrakingFriction = true;
	Movement->BrakingFrictionFactor = 2.0f;

	// Additional flying-specific tuning
	Movement->AirControl = 0.80f;  // Increased air control
	Movement->AirControlBoostMultiplier = 2.0f;
	

	


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

