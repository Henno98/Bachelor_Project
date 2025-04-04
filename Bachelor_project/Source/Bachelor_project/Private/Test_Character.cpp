// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputActionValue.h"
#include "AbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include <Power_DoubleJump.h>
#include "GAS_PlayerState.h"
#include "Tools/UEdMode.h"

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
	

	Springarm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Springarm"));
	Springarm->SetupAttachment(RootComponent);
	Springarm->TargetArmLength = 1000.f;
	
	
	//AbilitySystemComponent = CreateDefaultSubobject<UASC_AbilitySystem>("AbilitySystemComponent");


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	Camera->AttachToComponent(Springarm, FAttachmentTransformRules::KeepRelativeTransform);
	
	HurtBox = CreateDefaultSubobject<USphereComponent>(TEXT("Hurtbox"));
	HurtBox->SetRelativeLocation(FVector(GetActorLocation().X,GetActorLocation().Y + 100,GetActorLocation().Z));
	HurtBox->SetSphereRadius(01.f);
	HurtBox->SetupAttachment(RootComponent);


	
	Health = 10;
	RangedDamage = 5;
	MeleeDamage = 1;
	BioMass = 0;
	
}
// Called when the game starts or when spawned
void ATest_Character::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->JumpZVelocity = JumpVelocity;

	

	SaveGame();
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	DashCooldown = 2.f;


	GEngine->AddOnScreenDebugMessage(-1, 25.0f, FColor::Orange, TEXT("Press E to use RANGED ATTACK"));
	GEngine->AddOnScreenDebugMessage(-1, 25.0f, FColor::Orange, TEXT("Press SPACE to use jump and double jump"));
	GEngine->AddOnScreenDebugMessage(-1, 25.0f, FColor::Orange, TEXT("Press CTRL to use wall latch"));
	GEngine->AddOnScreenDebugMessage(-1, 25.0f, FColor::Orange, TEXT("Press SHIFT to Dash"));


}
void ATest_Character::SaveGame()
{
	if (USaveState* SaveGameInstance = Cast<USaveState>(UGameplayStatics::CreateSaveGameObject(USaveState::StaticClass())))
	{
		// Set data on the savegame object.
		SaveGameInstance->PlayerName = TEXT("PlayerOne");
		SaveGameInstance->PlayerLocation = this->GetActorLocation();
		//SaveGameInstance->bHasDoubleJumpPowerUp = DoubleJumpPowerUp != nullptr;  // Save if the power-up is assigned
		//SaveGameInstance->bHasWallLatchPowerUp = WallLatchPowerUp != nullptr;  // Save if the power-up is assigned
		SaveGameInstance->SavedWorld = GetWorld();
		// Save the data immediately.
		if (UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("Slot 1"), 0))
		{
			// Save succeeded.
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Saved Game"));

		}
	}
}
void ATest_Character::LoadGame()
{
	if (USaveState* SaveGameInstance = Cast<USaveState>(UGameplayStatics::CreateSaveGameObject(USaveState::StaticClass())))
	{
		if (SaveGameInstance = Cast<USaveState>(UGameplayStatics::LoadGameFromSlot("Slot 1", 0)))
		{
			SetActorEnableCollision(true);
			SetActorHiddenInGame(false);
			this->SetActorLocation(SaveGameInstance->PlayerLocation);
			//// Reinitialize power-ups based on saved state
			//if (SaveGameInstance->bHasDoubleJumpPowerUp)
			//{
			//	// You would reassign or reinitialize the DoubleJumpPowerUp here
			//	DoubleJumpPowerUp = NewObject<UPower_DoubleJump>();
			//}
			//if (SaveGameInstance->bHasWallLatchPowerUp)
			//{
			//	// You would reassign or reinitialize the WallLatchPowerUp here
			//	WallLatchPowerUp = NewObject<UPower_WallLatch>();
			//}


			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Loaded Game"));

		}
	}
}
// Called every frame
void ATest_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (BioMass < 500) {
		BioMass += 1;
	}
	if (Health <= 0)
	{
		Dead();
	}
	

}
// Called to bind functionality to input
void ATest_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ATest_Character::GASJump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ATest_Character::GASStopJump);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATest_Character::Move);
		EnhancedInputComponent->BindAction(DropDownInput,ETriggerEvent::Started,this, &ATest_Character::DropDown);
		//PowerUpInputs
		EnhancedInputComponent->BindAction(DashAction, ETriggerEvent::Triggered, this, &ATest_Character::GAS_Dash);
		EnhancedInputComponent->BindAction(DoubleJumpAction, ETriggerEvent::Started, this, &ATest_Character::DoubleJump);

		EnhancedInputComponent->BindAction(WallLatchAction, ETriggerEvent::Ongoing, this, &ATest_Character::GASWallLatch);
		EnhancedInputComponent->BindAction(WallLatchAction, ETriggerEvent::Completed, this, &ATest_Character::GASStopWallLatch);

		//Save
		EnhancedInputComponent->BindAction(SaveAction, ETriggerEvent::Started, this, &ATest_Character::SaveGame);
		EnhancedInputComponent->BindAction(LoadAction, ETriggerEvent::Started, this, &ATest_Character::LoadGame);

		EnhancedInputComponent->BindAction(RangedAttackInput, ETriggerEvent::Started, this, &ATest_Character::GAS_RangedAttack);
	}
}



void ATest_Character::Hit(int Damage)
{
	Health -= Damage;
	//// Reduce health
	//CurrentHealth -= Damage;
	//if (CurrentHealth < 0) CurrentHealth = 0;

	//// Update health bar widget (if it's available)
	//AMyHUD* MyHUD = Cast<AMyHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	//if (MyHUD && MyHUD->HealthBarWidget)
	//{
	//	MyHUD->HealthBarWidget->UpdateHealth(CurrentHealth);
	//}
}

void ATest_Character::Dead()
{
	SetActorEnableCollision(false);
	SetActorHiddenInGame(true);
}

void ATest_Character::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilitySystem();
}

void ATest_Character::InitAbilitySystem()
{
	GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Yellow, TEXT("Initialize Ability System"));

	AGAS_PlayerState* GASPlayerState = GetPlayerState<AGAS_PlayerState>();

	if (ensure(GASPlayerState))
	{
		GASPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(GASPlayerState, this);
		AbilitySystemComponent = GASPlayerState->GetAbilitySystemComponent();
		//Init jump
		GA_Double_Jump = GASPlayerState->JumpAbility;
		JumpAbilitySpec = FGameplayAbilitySpec(GA_Double_Jump);
		AbilitySystemComponent->GiveAbility(JumpAbilitySpec);
		//init wall latch
		GA_Wall_Latch = GASPlayerState->WallLatchAbility;
		WallLatchAbilitySpec = FGameplayAbilitySpec(GA_Wall_Latch);
		AbilitySystemComponent->GiveAbility(WallLatchAbilitySpec);
		//init Dash
		GA_Dash = GASPlayerState->DashAbility;
		DashAbilitySpec = FGameplayAbilitySpec(GA_Dash);
		AbilitySystemComponent->GiveAbility(DashAbilitySpec);

		GA_Ranged_Attack = GASPlayerState->RangedAttack;
		RangedAttackAbilitySpec = FGameplayAbilitySpec(GA_Ranged_Attack);
		AbilitySystemComponent->GiveAbility(RangedAttackAbilitySpec);

		}

}

UAbilitySystemComponent* ATest_Character::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ATest_Character::GASJump()
{
	if (AbilitySystemComponent && GA_Double_Jump)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Yellow, TEXT("Jumping ability"));


		}
		FGameplayTagContainer jumpGameTagContainer;
		jumpGameTagContainer.AddTag(FGameplayTag::RequestGameplayTag(FName("Abilities.Double_Jump")));
		AbilitySystemComponent->TryActivateAbilitiesByTag(jumpGameTagContainer);


	}

}

void ATest_Character::GASStopJump()
{
	if (GetVelocity().Z > 0)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Yellow, TEXT("Still jumping"));

		AbilitySystemComponent->AbilityLocalInputReleased(JumpAbilitySpec.InputID);
		//AbilitySystemComponent->CancelAllAbilities();
		//AbilitySystemComponent->CancelAbility(GA_JumpAbility.GetDefaultObject());
		//AbilitySystemComponent->CancelAbilityHandle(JumpAbilitySpec.Handle);
	}

}

void ATest_Character::GAS_Dash()
{
	if (AbilitySystemComponent && GA_Wall_Latch)
	{
		if (!bIsDashing) {
			bIsDashing = true;
			FGameplayTagContainer jumpGameTagContainer;
			jumpGameTagContainer.AddTag(FGameplayTag::RequestGameplayTag(FName("Abilities.Dash")));
			AbilitySystemComponent->TryActivateAbilitiesByTag(jumpGameTagContainer);

			FTimerHandle TimerHandle;
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([this]()
				{

					bIsDashing = false;

				}), 1.f, false);
		}
		

	}
}

void ATest_Character::GASWallLatch()
{
	if (AbilitySystemComponent && GA_Wall_Latch)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Yellow, TEXT("Wall latch ability"));
		}
		FGameplayTagContainer jumpGameTagContainer;
		jumpGameTagContainer.AddTag(FGameplayTag::RequestGameplayTag(FName("Abilities.Wall_Latch")));
		AbilitySystemComponent->TryActivateAbilitiesByTag(jumpGameTagContainer);


	}
}

void ATest_Character::GASStopWallLatch()
{
	AbilitySystemComponent->AbilityLocalInputReleased(JumpAbilitySpec.InputID);
}

void ATest_Character::GAS_Space()
{
}

void ATest_Character::GAS_RangedAttack()
{

	if (AbilitySystemComponent && GA_Ranged_Attack)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Yellow, TEXT("Ranged attack ability"));
		}
		if (BioMass > 100) {
			FGameplayTagContainer jumpGameTagContainer;
			jumpGameTagContainer.AddTag(FGameplayTag::RequestGameplayTag(FName("Abilities.Shoot")));
			AbilitySystemComponent->TryActivateAbilitiesByTag(jumpGameTagContainer);
			BioMass -= 100;
		}

	}
}

void ATest_Character::DropDown()
{
	FVector Direction = GetActorUpVector();
	FVector Start = GetActorLocation();
	FVector End = Start - (Direction * 120.f);
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	bool bSingleHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		Start,
		End,
		ECC_WorldStatic,
		Params);
	DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 1.0f, 0, 2.0f);

	if (bSingleHit)
	{
		if (IsValid(HitResult.GetActor()))
		{
			if (HitResult.GetActor()->GetFName().ToString().Contains(FString("Platform")) == true)
			{
				DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1.0f, 0, 2.0f);

				HitResult.GetActor()->SetActorEnableCollision(false);

				FTimerHandle TimerHandle;
				GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([HitResult]()
					{
						HitResult.GetActor()->SetActorEnableCollision(true);

					}), 1.f, false);
			

			}

		}

	}
	
}

void ATest_Character::ReEnableInput()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	this->EnableInput(PlayerController);
}

void ATest_Character::PauseInput()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	this->DisableInput(PlayerController);
}

//void ATest_Character::RangedAttack()
//{
//	if (!RangedAttackClass)
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ProjectileClass is not set!"));
//		return;
//	}
//
//	FVector SpawnLocation = GetActorLocation() + (GetActorForwardVector().GetSafeNormal() * 50);
//	FVector FiringDirection = GetActorForwardVector().GetSafeNormal();
//	FRotator SpawnRotation = GetActorRotation();
//	FActorSpawnParameters SpawnParams;
//	SpawnParams.Owner = this;
//
//	// Spawn the projectile
//	UWorld* World = GetWorld();
//	if (World)
//	{
//		Aprojectile* SpawnedProjectile = World->SpawnActor<Aprojectile>(RangedAttackClass, SpawnLocation, SpawnRotation, SpawnParams);
//		if (SpawnedProjectile)
//		{
//			//GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Cyan, TEXT("Spawned projectile"));
//			// Calculate the direction vector
//			//FVector Direction = SpawnLocation.GetSafeNormal();
//			SpawnedProjectile->Velocity = FiringDirection * 2000.f;
//			SpawnedProjectile->lifetime = 0.3f;
//			SpawnedProjectile->Owner = this;
//		}
//	}
//
//
//}

void ATest_Character::Move(const FInputActionValue& Value)
{
	const FVector2D moveVector = Value.Get<FVector2D>();
	const FRotator moveRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);

	if (moveVector.X > 0.05f ) {
		 SetActorRotation(FRotator(0.f,90.f,0.f));
		const FVector directionVector = moveRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(directionVector, moveVector.X);

		// (if (moveVector.X < -0.05f)
		// 	//	Springarm->SetRelativeRotation(FRotator(0,90.f , 0));
		//
		// 	if (moveVector.X > 0.05f)
		// 		//Springarm->SetRelativeRotation(FRotator(0, -90.f, 0));)
	}
	if ( moveVector.X < -0.05f)
	{
		SetActorRotation(FRotator(0.f, -90.f, 0.f));
		const FVector directionVector = moveRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(directionVector, moveVector.X);

	}
	
	if (moveVector.Y > 0.05f || moveVector.Y < -0.05f) {
		const FVector directionVector = moveRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(directionVector, moveVector.Y);
		//Springarm->SetRelativeRotation(FRotator(0, 10, 0));

	}
}

//void ATest_Character::Jump()
//{
//	ACharacter::Jump();
//}
//
void ATest_Character::DoubleJump(const FInputActionValue& Value)
{
   
}

//void ATest_Character::WallLatch(const FInputActionValue& Value)
//{
//	
//	if (GetCharacterMovement()->IsFalling())
//	{
//		if (WallLatchPowerUp)
//		{
//			WallLatchPowerUp->Activate(this);
//			JumpCurrentCount = 0;
//		}
//		else
//		{
//			
//			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Wall Latch PowerUp not assigned!"));
//
//		}
//	}
//	else
//	{
//		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("Can only wall latch while falling!"));
//	}
//}
//
//void ATest_Character::Dash()
//{
//	if(!bIsDashing && !GetCharacterMovement()->IsFalling())
//	{
//		FVector direction = GetCharacterMovement()->GetLastUpdateVelocity().GetSafeNormal();
//		//SetActorEnableCollision(false);
//		GetCharacterMovement()->GroundFriction = 0.1f;
//		LaunchCharacter(FVector(0,1600.f*direction.Y,0), false, false);
//		DashCooldown = 2.f;
//	
//		bIsDashing = true;
//	}
//
//}

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
