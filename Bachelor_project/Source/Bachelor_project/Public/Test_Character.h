// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputActionValue.h"
#include "PowerUpController.h"
#include "Power_WallLatch.h"
#include "Test_Character.generated.h"

UCLASS()
class BACHELOR_PROJECT_API ATest_Character : public ACharacter
{
    GENERATED_BODY()
public:
    // Sets default values for this character's properties
    ATest_Character();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
        class UInputMappingContext* DefaultMappingContext;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
        class UInputAction* MoveAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* JumpAction;
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Input")
    UInputAction* DashAction;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* DoubleJumpAction;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* WallLatchAction;
    


    UPROPERTY(EditAnywhere,BlueprintReadWrite)
     USpringArmComponent* Springarm;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    class UCameraComponent* Camera;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PowerUps")
    UPowerUpController* DoubleJumpPowerUp;

    UPROPERTY()
    class UPower_WallLatch* WallLatchPowerUp;

   

    

    void Move(const FInputActionValue& Value);
    void Jump();
    void DoubleJump(const FInputActionValue& Value);
    void WallLatch(const FInputActionValue& Value);
    void Dash();
    bool bIsDashing{false};
    bool bHasDoubleJumped{ false };
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Variables")
    float DashCooldown;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Variables")
    float JumpVelocity{ 600.f };
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

 
};
