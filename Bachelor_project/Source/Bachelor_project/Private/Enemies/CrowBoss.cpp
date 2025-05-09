// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemies/CrowBoss.h"

#include "projectile.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Iris/Serialization/NetSerializer.h"
#include "Kismet/GameplayStatics.h"
#include "Player/Test_Character.h"

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

    UE_LOG(LogTemp, Warning, TEXT("CrowBoss constructed"));
}

void ACrowBoss::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("CrowBoss BeginPlay called"));
}

void ACrowBoss::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

   
        if (bIsDead) {
            UE_LOG(LogTemp, Warning, TEXT("CrowBoss marked for death"));
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
    UE_LOG(LogTemp, Log, TEXT("CrowBoss::Landed called"));

        GetCharacterMovement()->StopMovementImmediately();
        GetCharacterMovement()->Velocity = FVector::ZeroVector;
        SetIsPreparingDive(false);
        SetIsDiving(false);
        Attack("DiveAttackSocket",200.f);
        GetCharacterMovement()->SetMovementMode(MOVE_Walking);
		SetIsWalking(true);

}

float ACrowBoss::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
    SetHealth(GetHealth()-DamageAmount);
    if (GetHealth() <= 0)
    {
        bIsDying = true;
        GetCharacterMovement()->SetMovementMode(MOVE_NavWalking);
    }
    UE_LOG(LogTemp, Error, TEXT("CrowBoss took %f damage, current health: %d"), DamageAmount, Health);
    GetCharacterMovement()->StopMovementImmediately();
    return DamageAmount;
}

void ACrowBoss::MeleeAttack()
{
    // Implement MeleeAttack logic here
}

void ACrowBoss::FeatherAttack()
{
    // Implement FeatherAttack logic here
}

void ACrowBoss::SpecialAttack()
{
    // Implement SpecialAttack logic here
}

void ACrowBoss::Collision()
{
    // Implement Collision logic here
}

void ACrowBoss::Death()
{
    UE_LOG(LogTemp, Error, TEXT("CrowBoss has died"));
    SetActorHiddenInGame(true);
    SetActorEnableCollision(false);
    // Implement further Death logic (e.g. spawn powerup)
}

void ACrowBoss::OnHit(int damage)
{
    UE_LOG(LogTemp, Warning, TEXT("CrowBoss received %d damage through OnHit"), damage);
    SetHealth(GetHealth() - damage);
}

void ACrowBoss::Attack(const FName& Socket, float attackrange)
{
    UE_LOG(LogTemp, Warning, TEXT("Started DiveAttack at socket: %s"), *Socket.ToString());

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
        UE_LOG(LogTemp, Warning, TEXT("DiveAttack hit %d actors"), HitResults.Num());

        for (const FHitResult& Hit : HitResults)
        {
            AActor* HitActor = Hit.GetActor();
            if (HitActor && !HitActors.Contains(HitActor))
            {
                HitActors.Add(HitActor);
                UE_LOG(LogTemp, Warning, TEXT("DiveAttack hitting actor: %s"), *HitActor->GetName());

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
        if (OtherActor->IsA<Aprojectile>())
        {
            Aprojectile* projectile = Cast<Aprojectile>(OtherActor);
            int dmg = projectile->GetDamage();
            UE_LOG(LogTemp, Warning, TEXT("CrowBoss overlapped with projectile. Applying %d damage."), dmg);
            OnHit(dmg);
        }
    }
}

void ACrowBoss::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
    // Optional: Add debug log if needed
}
