// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemies/CrowBoss.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/Test_Character.h"

/**
 * ACrowBoss
 *
 * Boss enemy character that can fly and perform multiple attacks.
 * - Handles flight movement, air control, and speed adjustments.
 * - Detects overlaps with characters and handles its own death logic (hides, disables collisions, and destroys itself).
 * - Takes damage and transitions into a dying state when health reaches zero.
 * - Performs melee, ranged, and special dive attacks with collision detection.
 * - Applies damage to hit actors during attacks.
 * - Integrated with AI logic for movement and behavior.
 */

// Sets default values
ACrowBoss::ACrowBoss()
{
    PrimaryActorTick.bCanEverTick = true;

    GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ACrowBoss::OnOverlap);
    GetCapsuleComponent()->SetGenerateOverlapEvents(true);
    GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

    auto Movement = GetCharacterMovement();
    Movement->SetMovementMode(MOVE_Flying);
    Movement->MaxFlySpeed = 800.f;

    Movement->BrakingDecelerationFlying = 2000.f;
    Movement->bUseSeparateBrakingFriction = true;
    Movement->BrakingFrictionFactor = 2.0f;
    Movement->AirControl = 0.80f;
    Movement->AirControlBoostMultiplier = 2.0f;
}

void ACrowBoss::BeginPlay()
{
    Super::BeginPlay();
}

void ACrowBoss::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

   
        if (bIsDead) {
            
            Death();
        }
    
}

void ACrowBoss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACrowBoss::Landed(const FHitResult& Hit)
{
    Super::Landed(Hit);

    if (bIsDying || bIsDead) return;

        GetCharacterMovement()->StopMovementImmediately();
        GetCharacterMovement()->Velocity = FVector::ZeroVector;
        SetIsPreparingDive(false);
        SetIsDiving(false);
        Attack("MeleeSocket",200.f);
        GetCharacterMovement()->SetMovementMode(MOVE_Walking);
		SetIsWalking(true);

}

float ACrowBoss::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
    SetHealth(GetHealth()-DamageAmount);
    if (GetHealth() <= 0)
    {
        bIsDying = true;
    }

    GetCharacterMovement()->StopMovementImmediately();
    return DamageAmount;
}

void ACrowBoss::MeleeAttack()
{
    // Got its own class
}

void ACrowBoss::FeatherAttack()
{
    // Now RangedAttack(RankedAttack)
}

void ACrowBoss::SpecialAttack()
{
    // Now DiveAttack
}

void ACrowBoss::Collision()
{
    // Implemented elsewhere
}

void ACrowBoss::Death()
{
    SetActorHiddenInGame(true);
    SetActorEnableCollision(false);
    Destroy();
    // Implement further Death logic (e.g. spawn powerup)
}

void ACrowBoss::OnHit(int damage)
{
    SetHealth(GetHealth() - damage);
}

void ACrowBoss::Attack(const FName& Socket, float attackrange)
{

    FVector Start = GetMesh()->GetSocketLocation(Socket);
    FVector ForwardVector = GetActorForwardVector();
    FVector End = Start + ForwardVector;

    DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1.0f, 0, 2.0f);
    DrawDebugSphere(GetWorld(), End, attackrange, 12, FColor::Blue, false, 1.0f);

    FCollisionQueryParams QueryParams;
    QueryParams.AddIgnoredActor(this);

    TArray<FHitResult> HitResults;
    TSet<AActor*> HitActors;

    bool bHit = GetWorld()->SweepMultiByChannel(
        HitResults,
        Start,
        End,
        FQuat::Identity,
        ECC_Pawn,
        FCollisionShape::MakeSphere(attackrange),
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

                if (HitActor->IsA<ACharacter>())
                {
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

float ACrowBoss::GetHealth() const
{
    return Health;
}

float ACrowBoss::GetDamage() const
{
    return AttackDamage;
}

void ACrowBoss::SetHealth(float NewHealth)
{
    Health = NewHealth;
}

void ACrowBoss::SetDamage(float NewDamage)
{
    AttackDamage = NewDamage;
}

void ACrowBoss::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                          UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor != this || OtherActor->GetOwner() != this)
    {
        
    }
}

void ACrowBoss::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
    
}
