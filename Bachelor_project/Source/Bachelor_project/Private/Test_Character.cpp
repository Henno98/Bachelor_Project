// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "InputActionValue.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GAS_PlayerState.h"
#include "SaveState.h"
#include "Test_Enemy.h"


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

	HurtBox = CreateDefaultSubobject<USphereComponent>(TEXT("HurtBox"));
	HurtBox->SetupAttachment(RootComponent); // or to RootComponent initially
	HurtBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	HurtBox->SetGenerateOverlapEvents(false);
	HurtBox->SetHiddenInGame(false); // Optional
	HurtBox->OnComponentBeginOverlap.AddDynamic(this, &ATest_Character::OnOverlap);
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
	SaveGame();
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	DashCooldown = 2.f;


}
void ATest_Character::SaveGame()
{
	if (bCanSave) {
		if (USaveState* SaveGameInstance = Cast<USaveState>(UGameplayStatics::CreateSaveGameObject(USaveState::StaticClass())))
		{
			// Set data on the savegame object.
			SaveGameInstance->PlayerName = TEXT("PlayerOne");
			SaveGameInstance->PlayerLocation = this->GetActorLocation();
			SaveGameInstance->SavedWorld = GetWorld();
			SaveGameInstance->Health = Health;
			SaveGameInstance->BioMass = BioMass;
			// Save the data immediately.
			if (UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("Slot 1"), 0))
			{
				// Save succeeded.

			}
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
			SetHealth(SaveGameInstance->Health);
			BioMass = SaveGameInstance->BioMass;
			OnHealthChanged.Broadcast(Health);
			OnEnergyChanged.Broadcast(BioMass);
		
		}
	}
}
// Called every frame
void ATest_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetBioMass() <= MaxBioMass) {
		SetBioMass(GetBioMass()+1);
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

		EnhancedInputComponent->BindAction(WallLatchAction, ETriggerEvent::Ongoing, this, &ATest_Character::GASWallLatch);
		EnhancedInputComponent->BindAction(WallLatchAction, ETriggerEvent::Completed, this, &ATest_Character::GASStopWallLatch);

		//Save
		EnhancedInputComponent->BindAction(SaveAction, ETriggerEvent::Started, this, &ATest_Character::SaveGame);
		EnhancedInputComponent->BindAction(LoadAction, ETriggerEvent::Started, this, &ATest_Character::LoadGame);
		EnhancedInputComponent->BindAction(MenuInput, ETriggerEvent::Triggered, this, &ATest_Character::ToggleMenu);

		EnhancedInputComponent->BindAction(RangedAttackInput, ETriggerEvent::Started, this, &ATest_Character::GAS_RangedAttack);
		EnhancedInputComponent->BindAction(MeleeInput, ETriggerEvent::Started, this, &ATest_Character::MeleeAttack);

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
	if (AbilitySystemComponent && GA_Double_Jump)
	{
	
		FGameplayTagContainer jumpGameTagContainer;
		jumpGameTagContainer.AddTag(FGameplayTag::RequestGameplayTag(FName("Abilities.Double_Jump")));
		AbilitySystemComponent->TryActivateAbilitiesByTag(jumpGameTagContainer);


	}

}

void ATest_Character::GASStopJump()
{
	if (GetVelocity().Z > 0)
	{

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
	
	if (bSingleHit)
	{
		if (IsValid(HitResult.GetActor()))
		{
			if (HitResult.GetActor()->GetFName().ToString().Contains(FString("Platform")) == true)
			{

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

void ATest_Character::ToggleMenu()
{
	if (PlayerHUD)
	{
		PlayerHUD->ToggleMenu();
	}
}




void ATest_Character::Move(const FInputActionValue& Value)
{
	const FVector2D moveVector = Value.Get<FVector2D>();
	const FRotator moveRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
	if (MoveAnim)
	{

		GetMesh()->PlayAnimation(MoveAnim, true);
	}
	if (moveVector.X > 0.05f ) {
		 SetActorRotation(FRotator(0.f,90.f,0.f));
		const FVector directionVector = moveRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(directionVector, moveVector.X);

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

void ATest_Character::MeleeAttack(const FInputActionValue& Value)
{
	FTimerHandle AttackTimer;

	if (MeleeAnim)
	{
		GetMesh()->PlayAnimation(MeleeAnim, false);

		// Example condition: check if the socket exists before proceeding
		if (GetMesh()->DoesSocketExist(TEXT("Hitbox_Right_Hand")))
		{
			if (HurtBox) {
				/*FTransform SocketTransform = GetMesh()->GetSocketTransform(TEXT("Hitbox_Right_Hand"));
				HurtBox->SetWorldTransform(SocketTransform);*/
				HurtBox->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("Hitbox_Right_Hand"));
				HurtBox->SetSphereRadius(200.f); // Adjust radius as needed
				HurtBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
				HurtBox->SetGenerateOverlapEvents(true);

				FVector Location = HurtBox->GetComponentLocation();
				UE_LOG(LogTemp, Warning, TEXT("HurtBox location: %s"), *Location.ToString());

				float AnimDuration = MeleeAnim->GetPlayLength();
				GetWorldTimerManager().SetTimer(AttackTimer, this, &ATest_Character::EndMeleeAttack, AnimDuration, false);
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Socket 'Hitbox_Right_Hand' does not exist on the mesh!"));
		}
	}

	


}

void ATest_Character::EndMeleeAttack()
{
	// Optional: Detach the HurtBox or disable its collision
	HurtBox->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
	HurtBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
void ATest_Character::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		
			// Handle the overlap event here
			UE_LOG(LogTemp, Warning, TEXT("Hit"));
			ATest_Enemy* enemy = Cast<ATest_Enemy>(OtherActor);
			enemy->OnHit(MeleeDamage);
		
	}

}