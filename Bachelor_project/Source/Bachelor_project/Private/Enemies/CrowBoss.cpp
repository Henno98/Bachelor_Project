// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/CrowBoss.h"

#include "projectile.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/Test_Character.h"

// Sets default values
ACrowBoss::ACrowBoss()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ACrowBoss::OnOverlap);
	GetCapsuleComponent()->SetGenerateOverlapEvents(true);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap); // or ECR_Overlap based on your needs
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

	if (GetHealth() <= 0)
	{
		bIsDying = true;
		if (bIsDead) {
			Death();
		}
	}
}

// Called to bind functionality to input
void ACrowBoss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ACrowBoss::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	// Default damage handling (e.g., subtract health)
	Health -= DamageAmount;

	// Ensure health doesn't go below 0
	//Health = FMath::Max(Health, 0.0f);
	GetCharacterMovement()->StopMovementImmediately();
	// Optionally, apply other effects like playing an animation or sound
	// For example: PlayHitReaction();
	UE_LOG(LogTemp, Error, TEXT("Crow took damage"));
	// Return the remaining health or amount of damage absorbed
	return DamageAmount;
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
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	//Health Reaches 0

	//Despawn boss

	//Spawn PowerUp

}

void ACrowBoss::OnHit(int damage)
{

	SetHealth(GetHealth() - damage);
}

void ACrowBoss::DiveAttack(const FName& Socket)
{
	UE_LOG(LogTemp, Warning, TEXT("Started collision check"));

	FVector Start = GetMesh()->GetSocketLocation(Socket);
	FVector ForwardVector = GetActorForwardVector();
	FVector End = Start + (ForwardVector);

	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1.0f, 0, 2.0f);
	//DrawDebugSphere(GetWorld(), Start, 150.f, 12, FColor::Blue, false, 1.0f);
	DrawDebugSphere(GetWorld(), End, 200.f, 12, FColor::Blue, false, 1.0f);

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	TArray<FHitResult> HitResults;
	TSet<AActor*> HitActors; // Track unique actors

	bool bHit = GetWorld()->SweepMultiByChannel(
		HitResults,
		Start,
		End,
		FQuat::Identity,
		ECC_Pawn,
		FCollisionShape::MakeSphere(200.f),
		QueryParams
	);

	if (bHit)
	{
		for (const FHitResult& Hit : HitResults)
		{
			AActor* HitActor = Hit.GetActor();
			if (HitActor && !HitActors.Contains(HitActor))
			{
				HitActors.Add(HitActor); // Mark as hit

				UE_LOG(LogTemp, Warning, TEXT("Hit actor: %s"), *HitActor->GetName());
				//DrawDebugSphere(GetWorld(), Hit.ImpactPoint, 10.f, 12, FColor::Red, false, 1.0f);
				if (Hit.GetActor()->IsA<ACharacter>()) {
					
				}
				UGameplayStatics::ApplyDamage(HitActor, GetDamage(), GetController(), this, nullptr);
			}
		}
	}

}


void ACrowBoss::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                          UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this || OtherActor->GetOwner() != this)
	{
		if (OtherActor->IsA<Aprojectile>())
		{
			Aprojectile* projectile = Cast<Aprojectile>(OtherActor);
			float dmg = projectile->GetDamage();
			OnHit(dmg);


		}
		

	}
}

void ACrowBoss::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
}

