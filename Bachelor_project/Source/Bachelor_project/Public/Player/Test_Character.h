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
#include "GAS_Dash.h"
#include "GAS_Double_Jump.h"
#include "GAS_Ranged_Attack.h"
#include "GAS_Wall_Latch.h"
#include "IsRangedAttacker.h"
#include "Player_HUD.h"
#include "Test_Character.generated.h"

class UInputAction;
class UInputMappingContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, int32, NewHealth);

UCLASS()
class BACHELOR_PROJECT_API ATest_Character : public ACharacter, public IAbilitySystemInterface,public IIsRangedAttacker
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    void OnMeleeHitNotify();
    ATest_Character();

    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnHealthChangedSignature OnHealthChanged;
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnHealthChangedSignature OnEnergyChanged;  // Same delegate type is fine
protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    //checks for landing
    virtual void Landed(const FHitResult& Hit) override;
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
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
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
    UAnimationAsset* StartJumpAnim;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
    UAnimationAsset* MidJumpAnim;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
    UAnimationAsset* EndJumpAnim;




    //Input mapping and input actions
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
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputAction* MenuInput;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* RunInput;





    //default components
    UPROPERTY(EditAnywhere,BlueprintReadWrite)
    USpringArmComponent* Springarm;
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    class UCameraComponent* Camera;





    // Animation/State flags
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
    bool bIsDashing{ false };

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
    bool bHasDoubleJumped{ false };
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
    bool bIsMoving{ false };
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
    bool bIsRunning;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
    bool bIsMeleeAttacking{ false };

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
    bool bIsRangedAttacking{ false };
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
    bool bStartedJump{ false };
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
    bool bMidJump{ false };
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
    bool bFinishJump{ false };


    bool Attack1{false};
    bool Attack2{false};
    bool Attack3{false};
  


protected:
    //AbilitySystemComponent
    UPROPERTY(EditAnywhere)
    TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

    //Stats and variables
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int MaxHealth;
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Stats")
    int Health;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int MaxBioMass;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int BioMass;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int MeleeDamage{2};
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int RangedDamage{5};
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Save")
    bool bCanSave = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
    float DashCooldown;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
    float VerticalVelocity;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
    float JumpVelocity;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
    FVector BulletSize{ FVector(1.f) };

    FVector TargetSocketOffset;



public:
    //Functions
    int GetHealth() { return Health; }
   
    void SetHealth(int newhealth){Health = newhealth; OnHealthChanged.Broadcast(Health);}
   
    int GetMaxHealth() { return MaxHealth; }
 
    int GetBioMass() { return BioMass; }
 
    void SetBioMass(int newbiomass) { BioMass = newbiomass; OnEnergyChanged.Broadcast(BioMass);}

    int GetMaxBioMass() { return MaxBioMass; }
 
    int GetRangedDamage() { return RangedDamage; }
  
    int GetMeleeDamage() { return MeleeDamage; }

    float GetJumpVelocity() { return JumpVelocity; }

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
    void ToggleMenu();
    void Run(const FInputActionValue& Value);
    void StopRun();
    void UpdateJumpState();
    float GetAnimationDuration(UAnimMontage* Montage);
    UFUNCTION()
    void SaveGame(FString slotname, int32 slotnumber);
    UFUNCTION()
    void LoadGame(FString slotname, int32 slotnumber);
    UFUNCTION()
    void Move(const FInputActionValue& Value);
    UFUNCTION()
    void StopMoving();
    UFUNCTION()
    void MeleeAttack(const FInputActionValue& Value);
    UFUNCTION()
    void EndMeleeAttack();
    UFUNCTION()
    void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
        int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
    float Velocity = 1000.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
    FVector Target;;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
    FRotator Direction = GetActorRotation();;
    // Interface function implementations (with inline return values)
    virtual float GetRangedDamage_Implementation() const override { return RangedDamage; }
    virtual float GetRangedAttackVelocity_Implementation() const override { return Velocity; }
    virtual void ReEnableInput_Implementation() override {/* implement logic in .cpp if needed */ }
    virtual FVector GetBulletSize_Implementation() const override { return BulletSize; }
    virtual FVector GetTargetLocation_Implementation() const override { return Target; }
    virtual FRotator GetFiringDirection_Implementation() const override { return Direction; }
    virtual TSubclassOf<AActor> GetProjectileClass_Implementation() const override { return RangedAttackClass; };



    //Subclasses
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
    TSubclassOf<UGAS_Dash> GA_Dash;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GASGameplayAbility")
    FGameplayTagContainer DashAbilityTag;
    FGameplayAbilitySpec DashAbilitySpec;

    UPROPERTY()
    TSubclassOf<UGAS_Ranged_Attack> GA_Ranged_Attack;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GASGameplayAbility")
    FGameplayTagContainer RangedAttackAbilityTag;
    FGameplayAbilitySpec RangedAttackAbilitySpec;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile class")
    TSubclassOf<class Aprojectile> RangedAttackClass;

};

inline float ATest_Character::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator, AActor* DamageCauser)
{
    Hit(DamageAmount);

	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}
