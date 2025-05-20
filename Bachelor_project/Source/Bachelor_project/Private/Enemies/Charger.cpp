// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/Charger.h"

#include "projectile.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/Test_Character.h"

// Sets default values
ACharger::ACharger()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ACharger::OnOverlap);
	GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &ACharger::OnOverlapEnd);

	GetCapsuleComponent()->SetGenerateOverlapEvents(true);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap); // or ECR_Overlap based on your needs
}

// Called when the game starts or when spawned
void ACharger::BeginPlay()
{
	Super::BeginPlay();
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetHealth(Health);

}

float ACharger::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	// Default damage handling (e.g., subtract health)
	SetHealth(GetHealth()-DamageAmount);
	//GetCharacterMovement()->StopMovementImmediately();
	if (GetHealth() <= 0)
	{
		SetIsDying(true);
		SetActorEnableCollision(false);
		GetCharacterMovement()->DisableMovement();

	}
	// Ensure health doesn't go below 0
	//Health = FMath::Max(Health, 0.0f);

	// Optionally, apply other effects like playing an animation or sound
	// For example: PlayHitReaction();
	UE_LOG(LogTemp, Error, TEXT("Charger took damage"));
	// Return the remaining health or amount of damage absorbed
	return DamageAmount;
}

// Called every frame
void ACharger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetIsDead()) {
		DestroyActor();
	}
}

void ACharger::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this || OtherActor->GetOwner() != this)
	{
		if (!HitActors.IsEmpty())
		{
			HitActors.Empty();
		}
		if (OtherActor->IsA<ATest_Character>())
		{

			FVector Start = GetMesh()->GetSocketLocation("ChargeSocket");
			FVector ForwardVector = GetActorForwardVector();
			FVector End = Start + ForwardVector;


			FCollisionQueryParams QueryParams;
			QueryParams.AddIgnoredActor(this);

			TArray<FHitResult> HitResults;
			

			bool bHit = GetWorld()->SweepMultiByChannel(
				HitResults,
				Start,
				End,
				FQuat::Identity,
				ECC_Pawn,
				FCollisionShape::MakeSphere(80),
				QueryParams
			);

			if (bHit)
			{
				
				for (const FHitResult& Hit : HitResults)
				{
					AActor* HitActor = Hit.GetActor();
					if (HitActor && !HitActors.Contains(HitActor))
					{
						HitActors.Add(HitActor);
						
						if (HitActor->IsA<ACharacter>() && HitActor->Implements<UEnemyInterface>())
						{
							return;
							// Add character-specific logic here
						}

						UGameplayStatics::ApplyDamage(HitActor, GetDamage(), GetController(), this, nullptr);
						//GetCharacterMovement()->StopActiveMovement();
					}
				}
			}
			
		}
		

	}

	
}

void ACharger::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	if (!HitActors.IsEmpty())
	{
		HitActors.Empty();
	}
}

// Called to bind functionality to input
void ACharger::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharger::DestroyActor()
{
	
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	Destroy();
}

void ACharger::OnHit(int damage)
{
	SetHealth(GetHealth()-damage);
}

float ACharger::GetHealth() const
{
	return Health;
}

float ACharger::GetDamage() const
{
	return Damage;
}

void ACharger::SetHealth(float NewHealth)
{
	Health = NewHealth;
}

void ACharger::SetDamage(float NewDamage)
{
	Damage = NewDamage;
}

