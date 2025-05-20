// Fill out your copyright notice in the Description page of Project Settings.


#include "World/HiddenRoom.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AHiddenRoom::AHiddenRoom()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	SetRootComponent(TriggerBox);
	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerBox->SetCollisionObjectType(ECC_WorldDynamic);
	TriggerBox->SetCollisionResponseToAllChannels(ECR_Ignore);
	TriggerBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	// You can assign these manually in editor
	RoomOpen = CreateDefaultSubobject<USceneComponent>(TEXT("RoomOpen"));
	RoomOpen->SetupAttachment(RootComponent);

	RoomHidden = CreateDefaultSubobject<USceneComponent>(TEXT("RoomHidden"));
	RoomHidden->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AHiddenRoom::BeginPlay()
{
	Super::BeginPlay();
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AHiddenRoom::OnBoxBeginOverlap);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &AHiddenRoom::OnBoxEndOverlap);
}

// Called every frame
void AHiddenRoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHiddenRoom::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor == UGameplayStatics::GetPlayerCharacter(this, 0))
	{
		if (RoomOpen) RoomOpen->SetVisibility(true, true);
		if (RoomHidden) RoomHidden->SetVisibility(false, true);
	}
}

void AHiddenRoom::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor == UGameplayStatics::GetPlayerCharacter(this, 0))
	{
		if (RoomOpen) RoomOpen->SetVisibility(false, true);
		if (RoomHidden) RoomHidden->SetVisibility(true, true);
	}
}

