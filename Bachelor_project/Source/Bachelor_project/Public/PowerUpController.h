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
    void Activate(AActor* Player);
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PowerUp")
    bool bIsActivated = true;

protected:
    // Base activation behavior for subclasses to implement
    virtual void OnActivate(AActor* Player) PURE_VIRTUAL(UPowerUpController::OnActivate, );

    
};

