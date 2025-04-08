// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputActionValue.h"
#include "Components/SphereComponent.h"
#include "projectile.h"
#include "AbilitySystemInterface.h"
#include "GameplayAbilitySpec.h"
#include "GAS_Double_Jump.h"
#include "GAS_Ranged_Attack.h"
#include "GAS_Wall_Latch.h"
#include "Test_Character.generated.h"

class UInputAction;
class UInputMappingContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, int32, NewHealth);

UCLASS()
class BACHELOR_PROJECT_API ATest_Character : public ACharacter, public IAbilitySystemInterface
{
    GENERATED_BODY()
public:
    ATest_Character();

    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnHealthChangedSignature OnHealthChanged;
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnHealthChangedSignature OnEnergyChanged;  // Same delegate type is fine
protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
public:
    // Animations
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
    UAnimationAsset* IdleAnim;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
    UAnimationAsset* MeleeAnim;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
    UAnimationAsset* RangedAttackAnim;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
    UAnimationAsset* DeathAnim;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
    UAnimationAsset* MoveAnim;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* DefaultMappingContext;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* JumpAction;
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Input")
    UInputAction* DashAction;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* DoubleJumpAction;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* WallLatchAction;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputAction* SaveAction;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputAction* LoadAction;

    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Input")
    UInputAction* RangedAttackInput;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* DropDownInput;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* MeleeInput;
    //default components
    UPROPERTY(EditAnywhere,BlueprintReadWrite)
     USpringArmComponent* Springarm;

     UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Hurtbox")
     USphereComponent* HurtBox;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    class UCameraComponent* Camera;

    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Projectile class")
    TSubclassOf<class Aprojectile> RangedAttackClass;
    UFUNCTION()
    void Move(const FInputActionValue& Value);
    UFUNCTION()
    void MeleeAttack(const FInputActionValue& Value);
    UFUNCTION()
    void EndMeleeAttack();
    UFUNCTION()
    void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
                   int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    bool bIsDashing{ false };
    bool bHasDoubleJumped{ false };
    bool Attack1{false};
    bool Attack2{false};
    bool Attack3{false};

    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Variables")
    float DashCooldown;

    UFUNCTION()
    void SaveGame();
    UFUNCTION()
    void LoadGame();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Variables")
    float JumpVelocity{ 1300.f };
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
    FVector BulletSize {FVector(1.f)};

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    UPROPERTY(EditAnywhere)
    TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int MaxHealth;
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Stats")
    int Health;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int BioMass;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int MeleeDamage;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int RangedDamage;
public:

    int GetHealth() { return Health; }
    void SetHealth(int newhealth){Health = newhealth;}
    int GetBioMass() { return BioMass; }
    int GetRangedDamage() { return RangedDamage; }
    int GetMeleeDamage() { return MeleeDamage; }


   void Hit(int Damage);
    void Dead();
    virtual void PossessedBy(AController* NewController) override;


    void InitAbilitySystem();
    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
    void GASJump();
    void GASStopJump();
    void GAS_Dash();
    void GASWallLatch();
    void GASStopWallLatch();
    void GAS_Space();
    void GAS_RangedAttack();
    void DropDown();
    void ReEnableInput();
    void PauseInput();

    UPROPERTY()
    TSubclassOf<UGAS_Double_Jump> GA_Double_Jump;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GASGameplayAbility")
    FGameplayTagContainer JumpAbilityTag;
    FGameplayAbilitySpec JumpAbilitySpec;

    UPROPERTY()
    TSubclassOf<UGAS_Wall_Latch> GA_Wall_Latch;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GASGameplayAbility")
    FGameplayTagContainer WallLatchAbilityTag;
    FGameplayAbilitySpec WallLatchAbilitySpec;

    UPROPERTY()
    TSubclassOf<UGAS_Wall_Latch> GA_Dash;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GASGameplayAbility")
    FGameplayTagContainer DashAbilityTag;
    FGameplayAbilitySpec DashAbilitySpec;

    UPROPERTY()
    TSubclassOf<UGAS_Ranged_Attack> GA_Ranged_Attack;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GASGameplayAbility")
    FGameplayTagContainer RangedAttackAbilityTag;
    FGameplayAbilitySpec RangedAttackAbilitySpec;
};
