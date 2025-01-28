#include "Power_DoubleJump.h"

#include <string>

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


void UPower_DoubleJump::OnActivate(AActor* Player)
{
    if (!Player)
    {
        return;
    }

    ACharacter* Character = Cast<ACharacter>(Player);
    if (Character && Character->GetCharacterMovement()->IsFalling() && !bHasDoubleJumped)
    {
       
    	// Perform the double jump
       // FVector LaunchVelocity = FVector(0, 0, 400.f); // Adjust jump strength
       // Character->LaunchCharacter(LaunchVelocity, false, false);
      //  Character->Jump();
        // Enable AirControl if needed
        Character->GetCharacterMovement()->AirControl = 1.f;

        bHasDoubleJumped = true;
        GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Double Jump Great Success!"));
    }
}