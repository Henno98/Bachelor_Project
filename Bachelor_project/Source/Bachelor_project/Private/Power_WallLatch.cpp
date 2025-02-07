// Fill out your copyright notice in the Description page of Project Settings.


#include "Power_WallLatch.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/CapsuleComponent.h"

UPower_WallLatch::UPower_WallLatch()
{
}

void UPower_WallLatch::OnActivate(AActor* Player)
{
    if (!Player) return;

    ACharacter* Character = Cast<ACharacter>(Player);
    if (!Character) return;

    UCharacterMovementComponent* MovementComponent = Character->GetCharacterMovement();
    if (!MovementComponent) return;

    // Get capsule for line trace start position
    UCapsuleComponent* Capsule = Character->GetCapsuleComponent();
    if (!Capsule) return;

    // Calculate line trace points
    FVector Start = Capsule->GetComponentLocation();

    // Check multiple directions for more robust wall detection
    TArray<FVector> DirectionsToCheck = {
        Capsule->GetForwardVector(),
        Capsule->GetRightVector(),
        -Capsule->GetRightVector()
    };

    FHitResult BestHitResult;
    bool bHit = false;

    for (const FVector& Direction : DirectionsToCheck)
    {
        FVector End = Start + (Direction * WallCheckDistance);
        FHitResult HitResult;
        FCollisionQueryParams Params;
        Params.AddIgnoredActor(Character);

        bool bSingleHit = GetWorld()->LineTraceSingleByChannel(
            HitResult,
            Start,
            End,
            ECC_WorldStatic,
            Params
        );

        if (bSingleHit)
        {
            bHit = true;
            BestHitResult = HitResult;
            break;
        }
    }

    // Handle wall latching if a wall is detected
    if (bHit)
    {
        LatchToWall(Character, BestHitResult.Normal);
    }
    else
    {
        // Provide feedback if no wall is found
        //GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("No wall detected!"));
    }
}

void UPower_WallLatch::LatchToWall(ACharacter* Character, const FVector& WallNormal)
{
    if (!Character) return;

    UCharacterMovementComponent* Movement = Character->GetCharacterMovement();
    if (Movement)
    {
        // Temporarily reduce gravity while wall latching
        //Movement->GravityScale = 0.1f;  // Slow descent
        FVector CurrentVelocity = Movement->Velocity;
        CurrentVelocity.Z *= 0.f;  // stop movement 
        Movement->Velocity = CurrentVelocity;
    }

    
    FVector NewPosition = Character->GetActorLocation() - WallNormal * 20.0f;
    Character->SetActorLocation(NewPosition);

    //GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Latched to wall!"));

    
    FTimerHandle TimerHandle;
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, [Movement]()
        {
            if (Movement)
            {
                Movement->GravityScale = 3.0f;
            }
        }, 0.1f, false);
}








