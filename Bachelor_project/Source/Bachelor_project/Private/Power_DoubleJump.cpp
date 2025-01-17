#include "Power_DoubleJump.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UPower_DoubleJump::Activate(AActor* Player)
{
    if (!Player)
    {
        return;
    }

    ACharacter* Character = Cast<ACharacter>(Player);
    if (Character && Character->GetCharacterMovement()->IsFalling() && !bHasDoubleJumped)
    {
        // Perform the double jump
        FVector LaunchVelocity = FVector(0, 0, 400.f); // Example launch vector
        Character->LaunchCharacter(LaunchVelocity, false, false);

        // Enable AirControl if needed
        Character->GetCharacterMovement()->AirControl = 0.8f;

        bHasDoubleJumped = true; // Mark the double jump as used
        GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Double Jump Activated!"));
    }
}
