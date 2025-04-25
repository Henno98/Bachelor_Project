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
	
}

// Called when the game starts or when spawned
void ABasicPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABasicPlatform::OnPlayerEnterTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->IsA(ATest_Character::StaticClass()))
	{
		// Assuming you have a reference to your HUD to show the tutorial text
		APlayer_HUD* HUD = Cast<APlayer_HUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
		if (HUD)
		{
			HUD->ShowTutorialText(TutorialText); // Display the tutorial text
			// In OnPlayerEnterTrigger:
			
			GetWorld()->GetTimerManager().SetTimer(TutorialTextTimerHandle, this, &ABasicPlatform::LeftTriggerBox, 5.0f, false);
		}
	}

}

void ABasicPlatform::LeftTriggerBox()
{
	
		// Clear the tutorial text
		APlayer_HUD* HUD = Cast<APlayer_HUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
		if (HUD)
		{
			HUD->ClearText();  // Call function to clear the text in HUD
		}
	

}


