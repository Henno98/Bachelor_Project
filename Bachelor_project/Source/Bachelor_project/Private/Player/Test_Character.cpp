// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Test_Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "InputActionValue.h"
#include "AbilitySystemComponent.h"
#include "Enemies/Charger.h"
#include "Enemies/CrowBoss.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/GAS_PlayerState.h"
#include "Player/SaveState.h"






// Sets default values
ATest_Character::ATest_Character()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	Springarm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Springarm"));
	Springarm->SetupAttachment(RootComponent);
	Springarm->TargetArmLength = 1000.f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));

	Camera->AttachToComponent(Springarm, FAttachmentTransformRules::KeepRelativeTransform);

	
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ATest_Character::OnOverlap);

	MaxHealth = 10;
	Health = MaxHealth;
	RangedDamage = 5;
	MeleeDamage = 3;
	BioMass = 0;
	MaxBioMass = 400;
	
}
void ATest_Character::OnMeleeHitNotify()
{

	UE_LOG(LogTemp, Warning, TEXT("Started collision check"));

	FVector Start = GetMesh()->GetSocketLocation(TEXT("Hitbox_Right_Hand"));
	FVector ForwardVector = GetActorForwardVector();
	FVector End = Start + (ForwardVector * 200.f);

	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1.0f, 0, 2.0f);
	//DrawDebugSphere(GetWorld(), Start, 150.f, 12, FColor::Blue, false, 1.0f);
	DrawDebugSphere(GetWorld(), End, 150.f, 12, FColor::Blue, false, 1.0f);

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	TArray<FHitResult> HitResults;
	TSet<AActor*> HitActors; // Track unique actors

	bool bHit = GetWorld()->SweepMultiByChannel(
		HitResults,
		Start,
		End,
		FQuat::Identity,
		ECC_Pawn,
		FCollisionShape::MakeSphere(150.f),
		QueryParams
	);

	if (bHit)
	{
		for (const FHitResult& Hit : HitResults)
		{
			AActor* HitActor = Hit.GetActor();
			if (HitActor && !HitActors.Contains(HitActor))
			{
				HitActors.Add(HitActor); // Mark as hit

				UE_LOG(LogTemp, Warning, TEXT("Hit actor: %s"), *HitActor->GetName());
				//DrawDebugSphere(GetWorld(), Hit.ImpactPoint, 10.f, 12, FColor::Red, false, 1.0f);
				if (Hit.GetActor()->IsA<ACharacter>()) {
					if (GetBioMass() <= MaxBioMass) {
						SetBioMass(GetBioMass() + 50);
					}
				}
				UGameplayStatics::ApplyDamage(HitActor, MeleeDamage, GetController(), this, nullptr);
			}
		}
	}

}
// Called when the game starts or when spawned
void ATest_Character::BeginPlay()
{
	Super::BeginPlay();
	SaveGame("Slot_0",0);
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	DashCooldown = 2.f;


}
void ATest_Character::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);
	//GetCharacterMovement()->StopMovementImmediately();
	bFinishJump = true;
	if (bIsRunning)
	{
		GetCharacterMovement()->MaxWalkSpeed = 1400.f;
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = 800.f;
	}

}

// Called every frame
void ATest_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (Health <= 0)
	{
		Dead();
	}
	if (GetActorLocation().X < 0 || GetActorLocation().X > 0)
	{
		SetActorLocation(FVector(0.f,GetActorLocation().Y, GetActorLocation().Z));
	}
	if (GetCharacterMovement()->IsWalking())
	{
		bStartedJump = false;
		bFinishJump = false;
		bHasDoubleJumped = false;
		

	}
	if (GetCharacterMovement()->IsFalling())
	{
		bMidJump = true;
	}
	else
	{
		bMidJump = false;
	}

	if (Springarm)
	{
		FVector CurrentOffset = Springarm->SocketOffset;
		FVector NewOffset = FMath::VInterpTo(CurrentOffset, TargetSocketOffset, DeltaTime, 0.8f);
		Springarm->SocketOffset = NewOffset;
	}
	/*if (bStartedJump)
	{
		GEngine->AddOnScreenDebugMessage(-1, .1f, FColor::Red, TEXT("Started jump"),false);
	}
	if (bMidJump)
	{
		GEngine->AddOnScreenDebugMessage(-1, .1f, FColor::Orange, TEXT("Mid jump"), false);
	}if (bFinishJump)
	{
		GEngine->AddOnScreenDebugMessage(-1, .1f, FColor::Green, TEXT("Finished jump"), false);
	}*/
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
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &ATest_Character::StopMoving);
		EnhancedInputComponent->BindAction(DropDownInput,ETriggerEvent::Started,this, &ATest_Character::DropDown);

		EnhancedInputComponent->BindAction(RunInput, ETriggerEvent::Started, this, &ATest_Character::Run);
		EnhancedInputComponent->BindAction(RunInput, ETriggerEvent::Completed, this, &ATest_Character::StopRun);
		//PowerUpInputs
		EnhancedInputComponent->BindAction(DashAction, ETriggerEvent::Triggered, this, &ATest_Character::GAS_Dash);

		EnhancedInputComponent->BindAction(WallLatchAction, ETriggerEvent::Ongoing, this, &ATest_Character::GASWallLatch);
		EnhancedInputComponent->BindAction(WallLatchAction, ETriggerEvent::Completed, this, &ATest_Character::GASStopWallLatch);

		//Save
		EnhancedInputComponent->BindAction(MenuInput, ETriggerEvent::Started, this, &ATest_Character::ToggleMenu);

		EnhancedInputComponent->BindAction(RangedAttackInput, ETriggerEvent::Started, this, &ATest_Character::GAS_RangedAttack);
		EnhancedInputComponent->BindAction(MeleeInput, ETriggerEvent::Started ,this, &ATest_Character::MeleeAttack);

	}
}




void ATest_Character::Hit(int Damage)
{
	SetHealth(GetHealth() - Damage);
	// Broadcast to any listeners
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

	if (bStartedJump && bHasDoubleJumped) return;

	if (bStartedJump)
	{
		bHasDoubleJumped = true;
	}

	if (AbilitySystemComponent && GA_Double_Jump)
	{
		bStartedJump = true;
		UWorld* World = GetWorld();
		if (!World) return;
			FGameplayTagContainer tags;
			tags.AddTag(FGameplayTag::RequestGameplayTag(FName("Abilities.Double_Jump")));
			AbilitySystemComponent->TryActivateAbilitiesByTag(tags);
		
	}
}

void ATest_Character::GASStopJump()
{
	if (AbilitySystemComponent) {
		AbilitySystemComponent->AbilityLocalInputReleased(JumpAbilitySpec.InputID);
		//AbilitySystemComponent->CancelAllAbilities();
		//AbilitySystemComponent->CancelAbility(GA_JumpAbility.GetDefaultObject());
		//AbilitySystemComponent->CancelAbilityHandle(JumpAbilitySpec.Handle);

	}
}

void ATest_Character::GAS_Dash()
{
	if (bIsDashing) return;

	bIsDashing = true;
	if (AbilitySystemComponent && GA_Dash)
	{

			FGameplayTagContainer jumpGameTagContainer;
			jumpGameTagContainer.AddTag(FGameplayTag::RequestGameplayTag(FName("Abilities.Dash")));
			AbilitySystemComponent->TryActivateAbilitiesByTag(jumpGameTagContainer);

		
		}
		

	
}

void ATest_Character::GASWallLatch()
{
	if (AbilitySystemComponent && GA_Wall_Latch)
	{
		
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

	if (AbilitySystemComponent && GA_Ranged_Attack && BioMass >= 100)
	{
		bIsRangedAttacking = true;


		FGameplayTagContainer tags;
		tags.AddTag(FGameplayTag::RequestGameplayTag(FName("Abilities.Shoot")));
		AbilitySystemComponent->TryActivateAbilitiesByTag(tags);


		SetBioMass(GetBioMass() - 100);

		FTimerHandle TimerHandle;
		float AnimDuration;

		if (RangedAttackAnim) {
			 AnimDuration = RangedAttackAnim->GetPlayLength();
		}
		else
		{
			AnimDuration = 0.5f;
		}

		GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([this]()
			{
				bIsRangedAttacking = false;
			}), AnimDuration, false); // Adjust based on anim length
	}
}

void ATest_Character::DropDown()
{
	FVector TestDirection = -this->GetActorUpVector();
	FVector Start = this->GetActorLocation() + FVector(0.f, 30.f, 0.f);
	FVector End = Start + (TestDirection * 100.f);

	TArray<FHitResult> HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	// Define the sweep shape (e.g., a sphere with radius x units)
	FCollisionShape SweepShape = FCollisionShape::MakeSphere(150.f);

	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1.0f, 0, 2.0f);
	//DrawDebugSphere(GetWorld(), Start, 100.f, 12, FColor::Blue, false, 1.0f);
	DrawDebugSphere(GetWorld(), End, 150.f, 12, FColor::Blue, false, 1.0f);

	bool bSweepHit = GetWorld()->SweepMultiByChannel(
		HitResult,
		Start,
		End,
		FQuat::Identity,
		ECC_WorldStatic,
		SweepShape,
		Params
	);


	if (bSweepHit)
	{
		for (const FHitResult& Hit : HitResult)
		{
			AActor* HitActor = Hit.GetActor();
			if (IsValid(HitActor))
			{
				if (HitActor->GetFName().ToString().Contains(FString("Platform")) == true)
				{
					UE_LOG(LogTemp, Warning, TEXT("Hit actor: %s"), *Hit.GetActor()->GetName());
					HitActor->SetActorEnableCollision(false);

					FTimerHandle TimerHandle;
					GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([HitActor]()
						{
							HitActor->SetActorEnableCollision(true);

						}), 0.5f, false);


				}

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

void ATest_Character::ToggleMenu()
{
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
	{
		APlayer_HUD* PlayerHUD = Cast<APlayer_HUD>(PC->GetHUD());
		if (PlayerHUD)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Toggling Menu"));
			PlayerHUD->ToggleMenu();
		}
		
	}
	
}

void ATest_Character::Run(const FInputActionValue& Value)
{

	

	if (GetCharacterMovement()->IsMovingOnGround())
	{
		bIsRunning = true;
		GetCharacterMovement()->MaxWalkSpeed = 1400.f;
	}
}

void ATest_Character::StopRun()
{

	bIsRunning = false;
	GetCharacterMovement()->MaxWalkSpeed = 800.f;
}




void ATest_Character::UpdateJumpState()
{
	bStartedJump = true;
	
}

float ATest_Character::GetAnimationDuration(UAnimMontage* Montage)
{
	return Montage->GetPlayLength();
}




void ATest_Character::Move(const FInputActionValue& Value)
{
	const FVector2D moveVector = Value.Get<FVector2D>();

	// Only respond if the stick is moved enough (ignore tiny noise)
	if (FMath::Abs(moveVector.X) > 0.5f)
	{
		// Snap rotation based on left/right input
		if (moveVector.X > 0.0f)
		{
			// Moving right: face right (0 degrees yaw)
			TargetSocketOffset = FVector(0.f, 300.f, 0.f); // Player at left
			SetActorRotation(FRotator(0.f, 90.f, 0.f));
		}
		else
		{
			// Moving left: face left (180 degrees yaw)
			TargetSocketOffset = FVector(0.f, -300.f, 0.f); // Player at right
			SetActorRotation(FRotator(0.f, -90, 0.f));
		}

		// Move character along its forward vector (in sidescroller, usually X axis)
		const FVector directionVector = GetActorForwardVector();
		AddMovementInput(directionVector, FMath::Abs(moveVector.X)); // Always positive

		// Set running state
		bIsMoving = true;
	}
	else
	{
		// Not moving
		bIsMoving = false;
	}
	
	// Stick flick downward to trigger DropDown
	if (moveVector.Y < -0.8f) // Stick pushed down
	{
			DropDown();
	}
	
}

void ATest_Character::StopMoving()
{
	bIsMoving = false;
}

void ATest_Character::MeleeAttack(const FInputActionValue& Value)
{
	if (bIsMeleeAttacking)
	{
		// If we are already attacking, do not start another attack
		return;
	}

	// Log to confirm we entered the attack function
	UE_LOG(LogTemp, Error, TEXT("Started attack"));

	// If we have a valid melee animation
	if (MeleeAnim)
	{
		bIsMeleeAttacking = true;
		GetCharacterMovement()->StopActiveMovement();

	}

	
}

// This function will be called once the attack animation finishes
void ATest_Character::EndMeleeAttack()
{
	//bIsMeleeAttacking = false; // Allow the next attack to start
	UE_LOG(LogTemp, Error, TEXT("Melee attack completed."));
}
void ATest_Character::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this || OtherActor->GetOwner() != this) {
		if (OtherActor->IsA<ACharger>())
		{
			//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("found charger"));
			ACharger* charger = Cast<ACharger>(OtherActor);
			int dmg = charger->GetDamage();
			Hit(1);

		}
		if (OtherActor->IsA<ACrowBoss>())
		{
			//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("found Crow"));

			ACrowBoss* Boss = Cast<ACrowBoss>(OtherActor);
			int dmg = Boss->GetDamage();
			Hit(1);

		}
		if (OtherActor->IsA<Aprojectile>())
		{
			Aprojectile* bullet = Cast<Aprojectile>(OtherActor);
			if (bullet && (!bullet->GetOwner() || bullet->GetOwner() != this)) // bullet is valid and either no owner or not owned by self
			{
				int dmg = bullet->GetDamage();
				Hit(dmg);
				bullet->Destroy(); // Optionally destroy the projectile after hitting
			}
		}
		else
		{
			//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("found nothing"));

		}

	}

}

void ATest_Character::SaveGame(FString SlotName, int32 SlotNumber)
{

	USaveState* SaveGameInstance = Cast<USaveState>(UGameplayStatics::CreateSaveGameObject(USaveState::StaticClass()));
	if (SaveGameInstance)
	{
		// Set data
		SaveGameInstance->PlayerName = TEXT("PlayerOne");
		SaveGameInstance->PlayerLocation = GetActorLocation();
		SaveGameInstance->SavedWorld = GetWorld(); // Optional, only if needed
		SaveGameInstance->Health = Health;
		SaveGameInstance->BioMass = BioMass;

		// Save to slot
		if (UGameplayStatics::SaveGameToSlot(SaveGameInstance, SlotName, SlotNumber))
		{
			UE_LOG(LogTemp, Log, TEXT("Game saved successfully to slot: %s (%d)"), *SlotName, SlotNumber);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to save game to slot: %s (%d)"), *SlotName, SlotNumber);
		}
	}
}

void ATest_Character::LoadGame(FString SlotName, int32 SlotNumber)
{
	if (UGameplayStatics::DoesSaveGameExist(SlotName, SlotNumber))
	{
		USaveState* LoadedGame = Cast<USaveState>(UGameplayStatics::LoadGameFromSlot(SlotName, SlotNumber));
		if (LoadedGame)
		{
			SetActorEnableCollision(true);
			SetActorHiddenInGame(false);
			SetActorLocation(LoadedGame->PlayerLocation);
			SetHealth(LoadedGame->Health);
			BioMass = LoadedGame->BioMass;

			OnHealthChanged.Broadcast(Health);
			OnEnergyChanged.Broadcast(BioMass);
			APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
			PC->SetPause(false);
			ToggleMenu();
			UE_LOG(LogTemp, Log, TEXT("Game loaded successfully from slot: %s (%d)"), *SlotName, SlotNumber);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to load game from slot: %s (%d)"), *SlotName, SlotNumber);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No save game found in slot: %s (%d)"), *SlotName, SlotNumber);
	}
}
