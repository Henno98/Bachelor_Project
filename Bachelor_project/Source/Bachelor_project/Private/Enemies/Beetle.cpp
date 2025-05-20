// Fill out your copyright notice in the Description page of Project Settings.



#include "Enemies/Beetle.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/Test_Character.h"

/**
 * ABeetle
 *
 * Enemy character being a simple creature only able to patrol and chase enemy.
 * - Patrols between predefined points and chases the player when spotted.
 * - Handles overlap events with projectiles and the player.
 * - Takes damage, dies upon reaching 0 health, and destroys itself.
 */

ABeetle::ABeetle()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ABeetle::OnOverlap);
    GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &ABeetle::OnOverlapEnd);
	GetCapsuleComponent()->SetGenerateOverlapEvents(true);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

}

// Called when the game starts or when spawned
void ABeetle::BeginPlay()
{
	Super::BeginPlay();
	
}

float ABeetle::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator, AActor* DamageCauser)
{

	Health -= DamageAmount;
	GetCharacterMovement()->StopMovementImmediately();
    if (GetHealth() <= 0)
    {
        bIsDying = true;
        GetCharacterMovement()->DisableMovement();
        SetActorEnableCollision(false);
       

    }
	return DamageAmount;
}

// Called every frame
void ABeetle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if (bIsDead) {
        DestroyActor();
    }
}

void ABeetle::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this || OtherActor->GetOwner() != this)
	{
        if (!HitActors.IsEmpty())
        {
            HitActors.Empty();
        }
		if (OtherActor->IsA<ATest_Character>())
		{

         
            FVector Start = GetMesh()->GetSocketLocation("BiteSocket");
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
                FCollisionShape::MakeSphere(100),
                QueryParams
            );

            if (bHit)
            {
                UE_LOG(LogTemp, Warning, TEXT("DiveAttack hit %d actors"), HitResults.Num());

                for (const FHitResult& Hit : HitResults)
                {
                    AActor* HitActor = Hit.GetActor();
                    if (HitActor && !HitActors.Contains(HitActor))
                    {
                        HitActors.Add(HitActor);
                        UE_LOG(LogTemp, Warning, TEXT("DiveAttack hitting actor: %s"), *HitActor->GetName());

                        if (HitActor->IsA<ACharacter>() && HitActor->Implements<UEnemyInterface>())
                        {
								return;
                            // Add character-specific logic here
                        }

                        UGameplayStatics::ApplyDamage(HitActor, GetDamage(), GetController(), this, nullptr);
                       
                    }
                }
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("DiveAttack did not hit any actors"));
            }
			
		}

	}

  
}

void ABeetle::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	
}

// Called to bind functionality to input
void ABeetle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABeetle::DestroyActor()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	Destroy();
}

void ABeetle::OnHit(int damage)
{
	SetHealth(GetHealth() - damage);
}

