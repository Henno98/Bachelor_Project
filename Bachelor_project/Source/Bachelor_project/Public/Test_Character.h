// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
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
        class UInputAction* JumpAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
        class UCameraComponent* Camera;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
        class UStaticMeshComponent* StaticMesh;

    void Move(const FInputActionValue& Value);
    void Jump();

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
