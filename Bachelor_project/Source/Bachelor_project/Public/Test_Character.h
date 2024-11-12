// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputActionValue.h"
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
	;
    UPROPERTY(EditAnywhere,BlueprintReadWrite)
     USpringArmComponent* Springarm;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    class UCameraComponent* Camera;

    void Move(const FInputActionValue& Value);
    void Jump();

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Variables")
    float JumpVelocity{ 600.f };
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
