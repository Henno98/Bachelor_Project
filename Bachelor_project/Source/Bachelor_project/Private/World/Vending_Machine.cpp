// Fill out your copyright notice in the Description page of Project Settings.


#include "World/Vending_Machine.h"
#include "Components/BoxComponent.h"
#include "Player/SaveState.h"
#include "Player/Test_Character.h"

// Sets default values
AVending_Machine::AVending_Machine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Static Mesh"));
	SetRootComponent(SkeletalMesh);
	HitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hitbox"));
	HitBox->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void AVending_Machine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVending_Machine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FTimerHandle AutoSave;

}

void AVending_Machine::Save(AActor* Player)
{

}

void AVending_Machine::InteractableAction_Implementation()
{

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
	{
		ATest_Character* player = Cast<ATest_Character>(PC->GetPawn());

		if (player) {

			//Play saving anim
			player->SetHealth(player->GetMaxHealth());
			player->SetBioMass(player->GetMaxBioMass());
			//play refresh effect
			USaveState::SaveGame(GetWorld(), "Main_Save", 0);
			
		}
	}

	
}

//void AVending_Machine::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
//                                 UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	if (OtherActor->IsA<ATest_Character>())
//	{
//		ATest_Character* Player = Cast<ATest_Character>(OtherActor);
//		//Play saving anim
//
//
//		Player->SetHealth(Player->GetMaxHealth());
//		Player->SetBioMass(Player->GetMaxBioMass());
//		
//		//play refresh effect
//
//		//AutoSave when encountering the first time
//		if (FirstTime) {
//			
//			Player->SaveGame("Main_Save",0);
//			FirstTime = false;
//		}
//		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Auto save complete"));
//		//Player inputs save action to save
//
//
//	}
//
//}
//
//void AVending_Machine::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
//	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
//{
//	if (OtherActor->IsA<ATest_Character>())
//	{
//		ATest_Character* Player = Cast<ATest_Character>(OtherActor);
//		//Play saving anim
//	}
//
//}
//
