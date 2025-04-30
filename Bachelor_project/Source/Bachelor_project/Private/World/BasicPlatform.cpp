// Fill out your copyright notice in the Description page of Project Settings.



#include "World/BasicPlatform.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/Test_Character.h"

// Sets default values
ABasicPlatform::ABasicPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create and initialize the Trigger Box component
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	RootComponent = TriggerBox;
	TriggerBox->SetGenerateOverlapEvents(true);
	TriggerBox->SetBoxExtent(FVector(200.0f, 200.0f, 100.0f)); // Adjust size as needed
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ABasicPlatform::OnPlayerEnterTrigger);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &ABasicPlatform::LeftTriggerBox);

}

// Called when the game starts or when spawned
void ABasicPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABasicPlatform::OnPlayerEnterTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//if (bHasoverlapped) return;


	if (OtherActor->IsA<ATest_Character>()) {
		APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
		if (PC)
		{
			APlayer_HUD* HUD = Cast<APlayer_HUD>(PC->GetHUD());
			if (HUD)
			{
				bHasoverlapped = true;
				HUD->ShowText(TutorialText);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("HUD is null or not of type APlayer_HUD"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("PlayerController not found"));
		}
	}

}

void ABasicPlatform::LeftTriggerBox(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
//if (!bHasoverlapped) return;


	if (OtherActor->IsA<ATest_Character>()) {
		UE_LOG(LogTemp, Warning, TEXT("LeftTriggerBox triggered by: %s"), *OtherActor->GetName());
		APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
		if (PC)
		{
			APlayer_HUD* HUD = Cast<APlayer_HUD>(PC->GetHUD());
			if (HUD)
			{
				HUD->HideText();
				bHasoverlapped = false;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("HUD is null or not of type APlayer_HUD"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("PlayerController not found"));
		}
	}

}


