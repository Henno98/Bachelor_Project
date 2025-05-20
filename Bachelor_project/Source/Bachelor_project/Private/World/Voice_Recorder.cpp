// Fill out your copyright notice in the Description page of Project Settings.



#include "World/Voice_Recorder.h"

#include "Plagued_Knight_GameInstance.h"
#include "Internationalization/StringTableRegistry.h"
#include "Internationalization/StringTableCore.h"     // For FStringTable
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
    LineDelay = 4.f;
}


// Called when the game starts or when spawned
void AVoice_Recorder::BeginPlay()
{
	Super::BeginPlay();
    CurrentIndex = 0;
  
	
    LoadAllDialogueKeysFromTable();
}

// Called every frame
void AVoice_Recorder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVoice_Recorder::InteractableAction_Implementation()
{
    UE_LOG(LogTemp, Log, TEXT("[VoiceRecorder] InteractableAction triggered on Recorder ID: %d"), ID);

    UPlagued_Knight_GameInstance* GameInstance = Cast<UPlagued_Knight_GameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
    if (!GameInstance)
    {
        UE_LOG(LogTemp, Error, TEXT("[VoiceRecorder] No valid GameInstance found."));
        return;
    }

    if (!GameInstance->HasRecorder(ID))
    {
        UE_LOG(LogTemp, Log, TEXT("[VoiceRecorder] Recorder ID %d not found in inventory. Adding it."), ID);
        GameInstance->AddRecorder(ID, this);
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("[VoiceRecorder] Recorder ID %d found in inventory."), ID);
    }

    // Avoid re-triggering if it's already playing
    if (!GetWorldTimerManager().IsTimerActive(LinePlaybackTimer))
    {
        UE_LOG(LogTemp, Log, TEXT("[VoiceRecorder] Starting playback for Recorder ID %d"), ID);
        LoadAllDialogueKeysFromTable();
        CurrentIndex = 0;
        PlayNextLine();
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("[VoiceRecorder] Playback is already active for Recorder ID %d"), ID);
    }
            
}

void AVoice_Recorder::PlayNextLine()
{
    if (!DialogueKeys.IsValidIndex(CurrentIndex))
    {
        UE_LOG(LogTemp, Warning, TEXT("No more dialogue lines."));
        return;
    }

    FString Key = DialogueKeys[CurrentIndex];
    ShowDialogueLine(Key);
    // Get text from string table
    FText TextLine = FText::FromStringTable(StringTableName, FTextKey(Key));

    if (TextLine.IsEmpty())
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing key in String Table: %s"), *Key);
        return;
    }

    // Show text
    //UKismetSystemLibrary::PrintString(this, TextLine.ToString(), true, true, FLinearColor::Green, 3.f);

    // Play sound
    if (AudioClips.IsValidIndex(CurrentIndex) && AudioClips[CurrentIndex])
    {
        UGameplayStatics::PlaySound2D(this, AudioClips[CurrentIndex]);
    }

    ++CurrentIndex;
    // Check if there are more lines, if so, set a timer to play the next one
    if (DialogueKeys.IsValidIndex(CurrentIndex))
    {
        // Set a timer to call PlayNextLine() again after the specified delay
        GetWorldTimerManager().SetTimer(LinePlaybackTimer, this, &AVoice_Recorder::PlayNextLine, LineDelay, false);
    }
   
}

void AVoice_Recorder::ShowDialogueLine(const FString& Key)
{
    FText Text = FText::FromStringTable(StringTableName, FTextKey(Key));
    if (!Text.IsEmpty())
    {

        APlayerController* PC = GetWorld()->GetFirstPlayerController();
        if (PC)
        {

            APlayer_HUD* HUD = Cast<APlayer_HUD>(PC->GetHUD());
            if (HUD) {
                HUD->ShowText(Text.ToString());
            }
        }
    }
}
void AVoice_Recorder::LoadAllDialogueKeysFromTable()
{
    DialogueKeys.Empty();

    UE_LOG(LogTemp, Log, TEXT("Attempting to find String Table: %s"), *StringTableName.ToString());

    // Try to find the string table from the registry
    TSharedPtr<const FStringTable> Table = FStringTableRegistry::Get().FindStringTable(StringTableName);

    // Check if the table is valid and log accordingly
    if (Table.IsValid())
    {
        UE_LOG(LogTemp, Log, TEXT("Found String Table: %s"), *StringTableName.ToString());
        Table->EnumerateKeysAndSourceStrings([&](const FTextKey& Key, const FString& Source) -> bool
            {
                DialogueKeys.Add(Key.ToString());
                UE_LOG(LogTemp, Log, TEXT("Loaded Key: %s"), *Key.ToString()); // Log the key to check
                return true;
            });

        DialogueKeys.Sort(); // Optional, to maintain order
        UE_LOG(LogTemp, Log, TEXT("Loaded %d keys from String Table '%s'"), DialogueKeys.Num(), *StringTableName.ToString());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("String Table '%s' not found."), *StringTableName.ToString());
    }
}