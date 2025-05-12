// Fill out your copyright notice in the Description page of Project Settings.



#include "World/Voice_Recorder.h"
#include "Internationalization/StringTableRegistry.h"
#include "Internationalization/StringTableCore.h"     // For FStringTable
#include "Internationalization/StringTableRegistry.h" // For FStringTableRegistry
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
    if (!TextLines.IsValidIndex(CurrentLineIndex))
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid CurrentLineIndex: %d"), CurrentLineIndex);
        GetWorldTimerManager().ClearTimer(LinePlaybackTimer);
        return;
    }

    FText CurrentLine = TextLines[CurrentLineIndex];
    UE_LOG(LogTemp, Log, TEXT("Displaying line index: %d | Text: %s"), CurrentLineIndex, *CurrentLine.ToString());

    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (PC)
    {
        UKismetSystemLibrary::PrintString(this, CurrentLine.ToString(), true, true, FLinearColor::Green, 2.f);

        APlayer_HUD* PlayerHUD = Cast<APlayer_HUD>(PC->GetHUD());
        if (PlayerHUD)
        {
            PlayerHUD->ShowText(CurrentLine.ToString());
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("PlayerHUD is null."));
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController not found."));
    }

    if (AudioClips.IsValidIndex(CurrentLineIndex) && AudioClips[CurrentLineIndex])
    {
        UGameplayStatics::PlaySound2D(this, AudioClips[CurrentLineIndex]);
        UE_LOG(LogTemp, Log, TEXT("Playing audio clip at index %d"), CurrentLineIndex);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No valid audio clip at index %d"), CurrentLineIndex);
    }

    CurrentLineIndex++;

    if (TextLines.IsValidIndex(CurrentLineIndex))
    {
        GetWorldTimerManager().SetTimer(LinePlaybackTimer, this, &AVoice_Recorder::DisplayNextLine, 4.f, false);
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("Finished playing all lines."));
        GetWorldTimerManager().ClearTimer(LinePlaybackTimer);
    }
}
void AVoice_Recorder::LoadText_Implementation(const FString& FilePath)
{
    TextLines.Empty();

    const int32 MaxLines = 1; // Prevent infinite loop
    int32 Index = 0;

    while (Index < MaxLines)
    {
        FString Key = FString::Printf(TEXT("Line_%d"), Index);
        FText RetrievedText = FText::FromStringTable(StringTableName, Key);

        if (RetrievedText.ToString() == Key)
        {
            UE_LOG(LogTemp, Log, TEXT("End of string table reached or missing key at index %d (key: %s)"), Index, *Key);
            break;
        }

        TextLines.Add(RetrievedText);
        UE_LOG(LogTemp, Log, TEXT("Loaded line %d: %s"), Index, *RetrievedText.ToString());
        Index++;
    }

    if (Index == MaxLines)
    {
        UE_LOG(LogTemp, Warning, TEXT("Reached max line count (%d). Possible malformed or infinite string table."), MaxLines);
    }

    CurrentLineIndex = 0;

    UE_LOG(LogTemp, Log, TEXT("Loaded %d lines from String Table '%s'"), TextLines.Num(), *StringTableName.ToString());
}

void AVoice_Recorder::PlayText_Implementation()
{
    if (TextLines.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("No text loaded. Cannot start playback."));
        return;
    }

    CurrentLineIndex = 0;
    UE_LOG(LogTemp, Log, TEXT("Starting playback of %d lines."), TextLines.Num());

    GetWorldTimerManager().SetTimer(LinePlaybackTimer, this, &AVoice_Recorder::DisplayNextLine, 1.5f, false);
}
TArray<FString> AVoice_Recorder::GetAllStringTableKeys(FName InTableName)
{
    TArray<FString> Keys;

    TSharedPtr<const FStringTable> Table = FStringTableRegistry::Get().FindStringTable(InTableName);
    if (Table.IsValid())
    {
        UE_LOG(LogTemp, Log, TEXT("Found string table: %s"), *InTableName.ToString());

        Table->EnumerateKeysAndSourceStrings(([&](const FTextKey& Key, const FString& SourceString) -> bool
            {
                FString KeyStr = Key.ToString();
                Keys.Add(KeyStr);
                UE_LOG(LogTemp, Log, TEXT("Found key: %s | Source: %s"), *KeyStr, *SourceString);
                return true;
            }));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("String table '%s' not found."), *InTableName.ToString());
    }

    return Keys;
}