// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PowerUpController.generated.h"


UCLASS()
class BACHELOR_PROJECT_API UPowerUpController : public UObject
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintCallable, Category = "PowerUp")
	virtual void Activate(AActor* Player);


protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PowerUp")
	bool bIsActivated = false;
};
