// Fill out your copyright notice in the Description page of Project Settings.



#include "World/Voice_Recorder.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Player/Player_HUD.h"


// Sets default values
AVoice_Recorder::AVoice_Recorder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
    SetRootComponent(Collider);
    Collider->OnComponentBeginOverlap.AddDynamic(this, &AVoice_Recorder::OnOverlap);
}

// Called when the game starts or when spawned
void AVoice_Recorder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVoice_Recorder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AVoice_Recorder::DisplayNextLine()
{
    if (CurrentLineIndex < TextLines.Num())
    {
        // Get the current line
        FString Currentline = TextLines[CurrentLineIndex];

        // Debug print to the screen (optional for testing purposes)
        UKismetSystemLibrary::PrintString(this, Currentline, true, true, FLinearColor::Green, 2.f);

        // Increase the line index for the next time
        CurrentLineIndex++;

        // Get the player controller
        APlayerController* PC = GetWorld()->GetFirstPlayerController();
        if (PC)
        {
            // Get the player's HUD
            APlayer_HUD* PlayerHUD = Cast<APlayer_HUD>(PC->GetHUD());
            if (PlayerHUD)
            {
                // Display the current line on the HUD
                PlayerHUD->ShowText(Currentline);
            }
        }  // Play matching audio
        if (AudioClips.IsValidIndex(CurrentLineIndex) && AudioClips[CurrentLineIndex])
        {
            UGameplayStatics::PlaySound2D(this, AudioClips[CurrentLineIndex]);
        }
        GetWorldTimerManager().SetTimer(LinePlaybackTimer, this, &AVoice_Recorder::DisplayNextLine, 4.f, false);
    }
    else
    {
        GetWorldTimerManager().ClearTimer(LinePlaybackTimer);
        UE_LOG(LogTemp, Log, TEXT("Finished playing text file."));
    }
}

bool AVoice_Recorder::GetIsInteractible_Implementation() const
{
	 return true;;
}

FString AVoice_Recorder::GetInteractibleText_Implementation() const
{
    return TextFilePath;
}

void AVoice_Recorder::LoadText_Implementation(const FString& FilePath)
{
    FString FullPath = FPaths::ProjectContentDir() + FilePath;

    if (FPaths::FileExists(FullPath))
    {
        FFileHelper::LoadFileToStringArray(TextLines, *FullPath);
        CurrentLineIndex = 0;

        UE_LOG(LogTemp, Log, TEXT("Loaded %d lines from file: %s"), TextLines.Num(), *FullPath);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("File not found: %s"), *FullPath);
    }

    
}

void AVoice_Recorder::PlayText_Implementation() 
{
    if (TextLines.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("No text loaded."));
        return;
    }

    GetWorldTimerManager().SetTimer(LinePlaybackTimer, this, &AVoice_Recorder::DisplayNextLine, 1.5f, false);

   
}

void AVoice_Recorder::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

