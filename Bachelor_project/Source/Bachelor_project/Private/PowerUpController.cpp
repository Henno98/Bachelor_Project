

#include "PowerUpController.h"


void UPowerUpController::Activate(AActor* Player)
{
    if (bIsActivated == false)
    {
        GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("PowerUp is inactive and cannot be used!"));
        return;
    }

    OnActivate(Player);
}


