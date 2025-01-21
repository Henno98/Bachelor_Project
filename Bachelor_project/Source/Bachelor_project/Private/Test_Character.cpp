// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputActionValue.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATest_Character::ATest_Character()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	//GetCharacterMovement()->bOrientRotationToMovement = false;
	//GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);

	GetCharacterMovement()->JumpZVelocity = JumpVelocity;


	Springarm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Springarm"));
	Springarm->SetupAttachment(RootComponent);
	Springarm->TargetArmLength = 200.f;

	

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	Camera->AttachToComponent(Springarm, FAttachmentTransformRules::KeepRelativeTransform);
	
	HurtBox = CreateDefaultSubobject<USphereComponent>(TEXT("Hurtbox"));
	HurtBox->SetSphereRadius(01.f);
	HurtBox->SetupAttachment(RootComponent);
	HurtVisibility = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HurtVisibility"));
	HurtVisibility->SetupAttachment(HurtBox);
	HurtVisibility->SetWorldScale3D(FVector(0.1f));
}

// Called when the game starts or when spawned
void ATest_Character::BeginPlay()
{
	Super::BeginPlay();
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	GetCharacterMovement()->AirControl = 0.8f;
	GetCharacterMovement()->MaxWalkSpeed = 800.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->MaxAcceleration = 1000.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	DashCooldown = 2.f;
}



// Called every frame
void ATest_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(bIsDashing)
	{
		DashCooldown -= DeltaTime;

		if(DashCooldown <= 0)
		{

			bIsDashing = false;
			//DashCooldown = 2.f;
		}
	}
	if(!GetCharacterMovement()->IsFalling())
	{
		bHasDoubleJumped = false;

	}
}

// Called to bind functionality to input
void ATest_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATest_Character::Move);
		//PowerUpInputs
		EnhancedInputComponent->BindAction(DashAction, ETriggerEvent::Started, this, &ATest_Character::MeleeAttack);
		EnhancedInputComponent->BindAction(DoubleJumpAction, ETriggerEvent::Started, this, &ATest_Character::DoubleJump);
	}
}

void ATest_Character::Move(const FInputActionValue& Value)
{
	const FVector2D moveVector = Value.Get<FVector2D>();
	const FRotator moveRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);

	if (moveVector.X > 0.05f || moveVector.X < -0.05f) {
		const FVector directionVector = moveRotation.RotateVector(FVector::RightVector);
		AddMovementInput(directionVector, moveVector.X);
	}
	
	if (moveVector.Y > 0.05f || moveVector.Y < -0.05f) {
		const FVector directionVector = moveRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(directionVector, moveVector.Y);
	}
}

void ATest_Character::Jump()
{
	ACharacter::Jump();
}

void ATest_Character::DoubleJump(const FInputActionValue& Value)
{
	const FVector2D moveVector = Value.Get<FVector2D>();
	if(GetCharacterMovement()->IsFalling() && !bHasDoubleJumped)
	{
		 
		LaunchCharacter(FVector(0,moveVector.Y*400, 400.f ), false, false);
		
		bHasDoubleJumped = true;
	}
}

void ATest_Character::Dash()
{
	if(!bIsDashing && !GetCharacterMovement()->IsFalling())
	{
		
		LaunchCharacter(GetVelocity() * 1.4, false, false);
		DashCooldown = 2.f;
		bIsDashing = true;
	}

}

void ATest_Character::MeleeAttack(const FInputActionValue& Value)
{ 

	FTimerHandle AttackTimer;
	if (!Attack1)
	{
		Attack1 = true;
		//Play Animation
		HurtBox->SetRelativeLocation(FVector(0.f, 100.f, 20.f));
		HurtBox->SetWorldScale3D(FVector(10.f));



	}
	if (Attack1 && !Attack2)
	{
		Attack2 = true;
		//play anim
	}
	if (Attack1 && Attack2)
	{
		Attack3 = true;
		//Play anim

	}
	Attack1 = false;
	Attack2 = false;
	Attack3 = false;
	//Play Animation
	/*HurtBox->SetRelativeLocation(FVector(0.f));
	HurtBox->SetWorldScale3D(FVector(1.f));*/

}
