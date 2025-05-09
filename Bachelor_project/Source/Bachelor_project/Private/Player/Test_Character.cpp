// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Test_Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "InputActionValue.h"
#include "AbilitySystemComponent.h"
#include "Interactable.h"
#include "Plagued_Knight_GameInstance.h"
#include "Enemies/Charger.h"
#include "Enemies/CrowBoss.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/GAS_PlayerState.h"
#include "Player/Player_HUD.h"
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
	Springarm->bUsePawnControlRotation = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));

	Camera->SetupAttachment(Springarm);
	
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ATest_Character::OnOverlap);
	SecondaryMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SecondaryMesh"));
	SecondaryMesh->SetupAttachment(GetMesh(), TEXT("WingSocket"));// Attach to socket

	MaxHealth = 10;
	Health = MaxHealth;
	RangedDamage = 5;
	MeleeDamage = 3;
	BioMass = 0;
	MaxBioMass = 400;
	
}

// Called when the game starts or when spawned
void ATest_Character::BeginPlay()
{
	Super::BeginPlay();
	SetHealth(GetMaxHealth());
	SetBioMass(0.f);
	UPlagued_Knight_GameInstance* GI = Cast<UPlagued_Knight_GameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (GI && GI->GetTargetLevel() == GetWorld()->GetMapName())
	{
		SetActorLocation(GI->GetSavedLocation());
		SetHealth(GI->GetSavedHealth());
		SetBioMass(GI->GetSavedBioMass());

		GI->ClearSavedData();
	}
	// Ensure InputActions is valid before proceeding
	ensure(InputActions != nullptr);

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("EnhancedInputLocalPlayerSubsystem is null"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController cast failed in BeginPlay"));
	}
	DashCooldown = 2.f;

	SaveGame("Slot_1", 1);
}

// Called every frame
void ATest_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
	if (!FMath::IsNearlyZero(GetActorLocation().X))
	{
		GetCharacterMovement()->bConstrainToPlane = true;
		GetCharacterMovement()->SetPlaneConstraintAxisSetting(EPlaneConstraintAxisSetting::X);
	}
	if (GetCharacterMovement()->IsMovingOnGround())
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
	
	
}
// Called to bind functionality to input
void ATest_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	ensure(EnhancedInputComponent != nullptr);
	ensure(InputActions != nullptr);  // Check again here just in case

		// Jumping
		EnhancedInputComponent->BindAction(InputActions->JumpAction, ETriggerEvent::Started, this, &ATest_Character::GASJump);
		EnhancedInputComponent->BindAction(InputActions->JumpAction, ETriggerEvent::Completed, this, &ATest_Character::GASStopJump);
		
		// Moving
		EnhancedInputComponent->BindAction(InputActions->MoveLeftAction, ETriggerEvent::Triggered, this, &ATest_Character::MoveLeft);
		EnhancedInputComponent->BindAction(InputActions->MoveLeftAction, ETriggerEvent::Completed, this, &ATest_Character::StopMoving);

		EnhancedInputComponent->BindAction(InputActions->MoveRightAction, ETriggerEvent::Triggered, this, &ATest_Character::MoveRight);
		EnhancedInputComponent->BindAction(InputActions->MoveRightAction, ETriggerEvent::Completed, this, &ATest_Character::StopMoving);

		EnhancedInputComponent->BindAction(InputActions->DropDownInput,ETriggerEvent::Started,this, &ATest_Character::DropDown);

		EnhancedInputComponent->BindAction(InputActions->RunInput, ETriggerEvent::Started, this, &ATest_Character::Run);
		EnhancedInputComponent->BindAction(InputActions->RunInput, ETriggerEvent::Completed, this, &ATest_Character::StopRun);
		//PowerUpInputs
		EnhancedInputComponent->BindAction(InputActions->DashAction, ETriggerEvent::Triggered, this, &ATest_Character::GAS_Dash);

		EnhancedInputComponent->BindAction(InputActions->WallLatchAction, ETriggerEvent::Ongoing, this, &ATest_Character::GASWallLatch);
		EnhancedInputComponent->BindAction(InputActions->WallLatchAction, ETriggerEvent::Completed, this, &ATest_Character::GASStopWallLatch);

		//Save
		EnhancedInputComponent->BindAction(InputActions->MenuInput, ETriggerEvent::Started, this, &ATest_Character::ToggleMenu);

		EnhancedInputComponent->BindAction(InputActions->RangedAttackInput, ETriggerEvent::Started, this, &ATest_Character::GAS_RangedAttack);
		EnhancedInputComponent->BindAction(InputActions->MeleeInput, ETriggerEvent::Started ,this, &ATest_Character::MeleeAttack);

	
}


void ATest_Character::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);
	
	bFinishJump = true;
	bMidJump = false;
	/*if (bIsRunning)
	{
		GetCharacterMovement()->MaxWalkSpeed = 1400.f;
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = 800.f;
	}*/

}

float ATest_Character::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator, AActor* DamageCauser)
{
	SetHealth(GetHealth() - DamageAmount);

	if (GetHealth() <= 0)
	{
		Dead();
		return 0;
	}
	// Clear any existing timer before setting a new one
	GetWorld()->GetTimerManager().ClearTimer(invincibilityframe);
	//GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	GetWorld()->GetTimerManager().SetTimer(invincibilityframe, FTimerDelegate::CreateLambda([this]()
		{


		}), 10.f, false);

	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}


void ATest_Character::OnMeleeHitNotify()
{

	UE_LOG(LogTemp, Warning, TEXT("Started collision check"));

	FVector Start = GetMesh()->GetSocketLocation(TEXT("Hitbox_Right_Hand"));
	FVector ForwardVector = GetActorForwardVector();
	FVector End = Start + (ForwardVector * 200.f);

	//DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1.0f, 0, 2.0f);
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
				if (Hit.GetActor() && Hit.GetActor()->Implements<UEnemyInterface>())
				{
					if (GetBioMass() <= MaxBioMass) {
						SetBioMass(GetBioMass() + 50);
					}
				}
				UGameplayStatics::ApplyDamage(HitActor, MeleeDamage, GetController(), this, nullptr);
			}
		}
	}

}

void ATest_Character::OnSublevelLoaded()
{
	UPlagued_Knight_GameInstance* GI = Cast<UPlagued_Knight_GameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (!GI) return;

	SetActorLocation(GI->GetSavedLocation());
	SetHealth(GI->GetSavedHealth());
	SetBioMass(GI->GetSavedBioMass());

	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);

	OnHealthChanged.Broadcast(GI->GetSavedHealth());
	OnEnergyChanged.Broadcast(GI->GetSavedBioMass());

	GI->ClearSavedData();

	UE_LOG(LogTemp, Log, TEXT("Restored character state after sublevel stream load."));
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

		check(AbilitySystemComponent);  // Must be valid
		FGameplayTag JumpTag = FGameplayTag::RequestGameplayTag(FName("Abilities.Double_Jump"));
		AbilitySystemComponent->TryActivateAbilitiesByTag(FGameplayTagContainer(JumpTag));
		
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
		FGameplayTag DashTag = FGameplayTag::RequestGameplayTag(FName("Abilities.Dash"));
		AbilitySystemComponent->TryActivateAbilitiesByTag(FGameplayTagContainer(DashTag));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AbilitySystemComponent is null in GAS_Dash"));
	}
		

	
}

void ATest_Character::GASWallLatch()
{
	if (AbilitySystemComponent && GA_Wall_Latch)
	{
		
		check(AbilitySystemComponent);
		FGameplayTag WallLatchTag = FGameplayTag::RequestGameplayTag(FName("Abilities.WallLatch"));
		AbilitySystemComponent->TryActivateAbilitiesByTag(FGameplayTagContainer(WallLatchTag));
	


	}
}

void ATest_Character::GASStopWallLatch()
{
	if (GA_Wall_Latch && AbilitySystemComponent)
	AbilitySystemComponent->AbilityLocalInputReleased(JumpAbilitySpec.InputID);
}

void ATest_Character::GAS_Space()
{
}

void ATest_Character::GAS_RangedAttack()
{

	if (AbilitySystemComponent && GA_Ranged_Attack && BioMass >= 100)
	{
		if (!bIsRangedAttacking) {
			bIsRangedAttacking = true;

			SetBioMass(GetBioMass() - 100);
		}
	}
}

void ATest_Character::ExecuteRangedAttack()
{

	SpawnLocation = GetMesh()->GetSocketLocation(TEXT("Hitbox_Right_Hand"));
	
	FGameplayTagContainer tags;
	tags.AddTag(FGameplayTag::RequestGameplayTag(FName("Abilities.Shoot")));
	AbilitySystemComponent->TryActivateAbilitiesByTag(tags);

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

	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	this->EnableInput(PlayerController);
}

void ATest_Character::PauseInput()
{
	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
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



float ATest_Character::GetAnimationDuration(UAnimMontage* Montage)
{
	return Montage->GetPlayLength();
}




void ATest_Character::MoveLeft(const FInputActionValue& Value)
{
	const FVector2D moveVector = Value.Get<FVector2D>();


	// Only respond if the stick is moved enough (ignore tiny noise)
	if (FMath::Abs(moveVector.X) > 0.5f)
	{
		
			// Moving left: face left (180 degrees yaw)
			//TargetSocketOffset = FVector(0.f, -300.f, 0.f); // Player at right
			SetActorRotation(FRotator(0.f, -90, 0.f));
		
			//Springarm->SocketOffset = TargetSocketOffset;
		// Move character along its forward vector (in sidescroller, usually X axis)
		const FVector directionVector = -GetActorForwardVector();
		AddMovementInput(directionVector, -FMath::Abs(moveVector.X)); // Always positive

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

void ATest_Character::MoveRight(const FInputActionValue& Value)
{
	const FVector2D moveVector = Value.Get<FVector2D>();


	// Only respond if the stick is moved enough (ignore tiny noise)
	if (FMath::Abs(moveVector.X) > 0.5f)
	{

		// Moving left: face left (180 degrees yaw)
		//TargetSocketOffset = FVector(0.f, 300.f, 0.f); // Player at right
		SetActorRotation(FRotator(0.f, 90, 0.f));

		//Springarm->SocketOffset = TargetSocketOffset;
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
	bIsMeleeAttacking = true;
	GetCharacterMovement()->StopActiveMovement();

	

	
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
		if (OtherActor && OtherActor != this && OtherActor && OtherActor->Implements<UInteractable>())
		{
			FString InteractionText = IInteractable::Execute_GetInteractibleText(OtherActor);
			UE_LOG(LogTemp, Log, TEXT("Interaction Text: %s"), *InteractionText);
			
			IInteractable::Execute_LoadText(OtherActor, InteractionText);
			IInteractable::Execute_PlayText(OtherActor);
		}

}

void ATest_Character::SaveGame(FString SlotName, int32 SlotNumber)
{
	USaveState::SaveGame(GetWorld(),SlotName, SlotNumber);
}

void ATest_Character::LoadGame(FString SlotName, int32 SlotNumber)
{
	USaveState::LoadGame(GetWorld(),SlotName, SlotNumber);
}
