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
    if (!Capsule) {
        GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("Capsule Not Found"));


        return;
    }
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
    UWorld* World = Player->GetWorld();

    if (!World)
    {

        GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("World not Found"));
            return;

    }
        for (const FVector& Direction : DirectionsToCheck)
        {
            FVector End = Start + (Direction * WallCheckDistance);
            FHitResult HitResult;
            FCollisionQueryParams Params;
            Params.AddIgnoredActor(Character);

            bool bSingleHit = World->LineTraceSingleByChannel(
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
                // Debug the trace
                DrawDebugLine(World, Start, End, FColor::Red, false, 1.f, 0, 1.f);
                break;
            }
            else
            {
                // Debug the trace when no hit occurs
                DrawDebugLine(World, Start, End, FColor::Blue, false, 1.f, 0, 1.f);
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
           // GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("No wall detected!"));
        }

    
}

void UPower_WallLatch::LatchToWall(ACharacter* Character, const FVector& WallNormal)
{
    if (!Character)
    {
        UE_LOG(LogTemp, Warning, TEXT("Character is null in LatchToWall"));
        return;
    }
    UWorld* World = Character->GetWorld();
    if (!World) {


        GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("World not Found"));

        return;
    }

    UCharacterMovementComponent* Movement = Character->GetCharacterMovement();
    if (!Movement)
    {
        UE_LOG(LogTemp, Warning, TEXT("Movement component is null in LatchToWall"));
        return;
    }

    // Temporarily reduce gravity while wall latching
    Movement->GravityScale = 0.1f;  // Slow descent

    FVector CurrentVelocity = Movement->Velocity;
    CurrentVelocity.Z *= 0.f;  // Stop vertical movement
    Movement->Velocity = CurrentVelocity;

    FVector NewPosition = Character->GetActorLocation() - WallNormal * 20.0f;

    // Ensure the new position is valid
    UE_LOG(LogTemp, Warning, TEXT("Latched Position: %s"), *NewPosition.ToString());

    // Check if the position is valid before setting it
    if (!NewPosition.IsZero())
    {
        Character->SetActorLocation(NewPosition);
    }

   // GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Latched to wall!"));

    // Timer to restore gravity
    FTimerHandle TimerHandle;
    World->GetTimerManager().SetTimer(TimerHandle, [Movement]()
        {
            if (Movement)
            {
                Movement->GravityScale = 3.0f;  // Set gravity back to normal
            }
        }, 0.1f, false);
}






