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
    Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
    Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
    SetRootComponent(Mesh);
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
       
        // Increase the line index for the next time
        CurrentLineIndex++;

        // Get the player controller
        APlayerController* PC = GetWorld()->GetFirstPlayerController();
        if (PC)
        {
            FText CurrentLine = TextLines[CurrentLineIndex];
            UKismetSystemLibrary::PrintString(this, CurrentLine.ToString(), true, true, FLinearColor::Green, 2.f);
           
            // Get the player's HUD
            APlayer_HUD* PlayerHUD = Cast<APlayer_HUD>(PC->GetHUD());
            if (PlayerHUD)
            {
                // Display the current line on the HUD
                PlayerHUD->ShowText(CurrentLine.ToString());
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


void AVoice_Recorder::LoadText_Implementation(const FString& FilePath)
{
    TextLines.Empty();

    // Simulate loading sequential lines from a String Table
    int32 Index = 0;
    while (true)
    {
        FString Key = FString::Printf(TEXT("Line_%d"), Index);
        FText RetrievedText = FText::FromStringTable(StringTableName, Key);

        // If the key doesn't exist, the retrieved text equals the key
        if (RetrievedText.ToString() == Key)
        {
            break;
        }

        TextLines.Add(RetrievedText);
        Index++;
    }

    CurrentLineIndex = 0;

    UE_LOG(LogTemp, Log, TEXT("Loaded %d lines from String Table '%s'"), TextLines.Num(), *StringTableName.ToString());
    
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

int32 AVoice_Recorder::GetID_Implementation()
{
    return RecorderID;
}

void AVoice_Recorder::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

