// Fill out your copyright notice in the Description page of Project Settings.


#include "Vending_Machine.h"

#include "Test_Character.h"
#include "Components/BoxComponent.h"

// Sets default values
AVending_Machine::AVending_Machine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SetRootComponent(StaticMesh);
	HitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hitbox"));
	HitBox->SetupAttachment(RootComponent);
	HitBox->OnComponentBeginOverlap.AddDynamic(this, &AVending_Machine::OnOverlap);
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

}

void AVending_Machine::Save(AActor* Player)
{

}

void AVending_Machine::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                 UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA<ATest_Character>())
	{
		ATest_Character* Player = Cast<ATest_Character>(OtherActor);
		//Play saving anim

		//AutoSave when encountering the first time
		if (FirstTime) {
			Player->SaveGame();
		}
		//Player inputs save action to save
	}
	else return;


}

