// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelStreamingActor.h"

#include "Test_Character.h"

// Sets default values
ALevelStreamingActor::ALevelStreamingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OverlapVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapVolume"));
	SetRootComponent(OverlapVolume);
	OverlapVolume->OnComponentBeginOverlap.AddUniqueDynamic(this, &ALevelStreamingActor::OverlapBegins);
	OverlapVolume->OnComponentEndOverlap.AddUniqueDynamic(this, &ALevelStreamingActor::OverlapEnds);
}

// Called when the game starts or when spawned
void ALevelStreamingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALevelStreamingActor::OverlapBegins(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);

	if (OtherActor == MyCharacter)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Overlapped actor found"));
		if ( LevelToLoad != " ") {
			//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Level to load found"));

			FLatentActionInfo LatentInfo;
			UGameplayStatics::LoadStreamLevel(this, LevelToLoad, true, true, LatentInfo);
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Level not found"));

		}
	}
}

void ALevelStreamingActor::OverlapEnds(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	if (OtherActor == MyCharacter)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Overlapped actor left collision zone"));

		if (LevelToUnLoad != "") {
			//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Level should unload"));

			FLatentActionInfo LatentInfo;
			UGameplayStatics::UnloadStreamLevel(this, LevelToLoad, LatentInfo,false);
		}
	}
}

// Called every frame
void ALevelStreamingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

