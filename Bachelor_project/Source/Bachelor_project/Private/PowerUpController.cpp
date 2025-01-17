

#include "PowerUpController.h"

void UPowerUpController::Activate(AActor* Player)
{
	if (bIsActivated) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("PowerUp er satt på active allerede dumdum"));
		return;
	}

	bIsActivated = true;
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("PowerUp er nå aktivert!!!, great success"));
}
