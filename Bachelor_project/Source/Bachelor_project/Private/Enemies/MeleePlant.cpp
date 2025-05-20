// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/MeleePlant.h"

#include "Components/CapsuleComponent.h"
#include "Enemies/EnemyInterface.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/Test_Character.h"

// Sets default values
AMeleePlant::AMeleePlant()
{
 	
	PrimaryActorTick.bCanEverTick = true;
    /*GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AMeleePlant::OnOverlap);
    GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &AMeleePlant::OnOverlapEnd);*/
    GetCapsuleComponent()->SetGenerateOverlapEvents(true);
    GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

// Called when the game starts or when spawned
void AMeleePlant::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMeleePlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsDead) {
		DestroyActor();
	}
}

// Called to bind functionality to input
void AMeleePlant::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AMeleePlant::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator, AActor* DamageCauser)
{

	Health -= DamageAmount;
	GetCharacterMovement()->StopMovementImmediately();
	if (GetHealth() <= 0)
	{
		bIsDead = true; //change bIsDying for animations
		GetCharacterMovement()->DisableMovement();
		SetActorEnableCollision(false);
        bCanAttack = false;


	}
	return DamageAmount;
}

void AMeleePlant::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    

}

void AMeleePlant::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{

}

void AMeleePlant::DestroyActor()
{
    SetActorHiddenInGame(true);
    SetActorEnableCollision(false);
    Destroy();
}

void AMeleePlant::OnHit(int damage)
{
    SetHealth(GetHealth() - damage);
}

bool AMeleePlant::CanAttack() const
{
	return bCanAttack;
}

void AMeleePlant::PerformMeleeAttack()
{
    if (!bCanAttack) return;

    HitActors.Empty();

    UE_LOG(LogTemp, Warning, TEXT("MeleePlant performs melee attack!"));
    DrawDebugString(GetWorld(), GetActorLocation() + FVector(0, 0, 100), TEXT("ATTACK!"), nullptr, FColor::Red, 1.0f);

    FVector Start = GetMesh()->GetSocketLocation("BiteSocket") + FVector(0.f, 0.f, 50.f);
    FVector ForwardVector = GetActorForwardVector();
    FVector End = Start + ForwardVector * AttackRange + FVector(0.f, 0.f, 20.f);

    FCollisionQueryParams QueryParams;
    QueryParams.AddIgnoredActor(this);

    TArray<FHitResult> HitResults;

    bool bHit = GetWorld()->SweepMultiByChannel(
        HitResults,
        Start,
        End,
        FQuat::Identity,
        ECC_Pawn,
        FCollisionShape::MakeSphere(100.f),
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

                if (!HitActor->IsA<ATest_Character>())
                    continue;

                UGameplayStatics::ApplyDamage(HitActor, GetDamage(), GetController(), this, nullptr);
                UE_LOG(LogTemp, Warning, TEXT("MeleePlant hit actor: %s"), *HitActor->GetName());
            }
        }
    }

    bCanAttack = false;
    GetWorld()->GetTimerManager().SetTimer(AttackCooldownHandle, this, &AMeleePlant::ResetAttackCooldown, 2.0f, false);
}


void AMeleePlant::ResetAttackCooldown()
{
	bCanAttack = true;

}
