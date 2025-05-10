// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/Main_Menu_Widget.h"

#include "Plagued_Knight_GameInstance.h"
#include "Player/Test_Character.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMain_Menu_Widget::NativeConstruct()
{// Setup main buttons
    Super::NativeConstruct();

    if (Quit_Button) {
        Quit_Button->OnClicked.Clear();
        Quit_Button->OnClicked.AddDynamic(this, &UMain_Menu_Widget::OnQuitClicked);
    }
    if (Close_Button) {
        Close_Button->OnClicked.Clear();
        Close_Button->OnClicked.AddDynamic(this, &UMain_Menu_Widget::OnCloseClicked);
    }
    if (Mapping_Menu)
    {
        Mapping_Menu->OnClicked.Clear();
        Mapping_Menu->OnClicked.AddDynamic(this, &UMain_Menu_Widget::OnMappingMenuClicked);
    }
    if (Load_Button)
    {
        Load_Button->OnClicked.Clear();
        Load_Button->OnClicked.AddDynamic(this, &UMain_Menu_Widget::CreateSaveSlotList);

    }
    if (Open_Inventory)
    {
        Open_Inventory->OnClicked.Clear();
        Open_Inventory->OnClicked.AddDynamic(this, &UMain_Menu_Widget::OnOpenInventoryClicked);

    }

}
void UMain_Menu_Widget::OnLoadClicked(const FString& SlotName, int32 SlotNumber)
{
    ATest_Character* Player = Cast<ATest_Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    if (Player)
    {
        Player->LoadGame(SlotName, SlotNumber);
    }
}

void UMain_Menu_Widget::OnMappingMenuClicked()
{
    Container->ClearChildren();
    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (PC && KeybindsWidgetClass)
    {
        if (!Keybindwidget)
        {
            Keybindwidget = CreateWidget<UKeyBindsWidget>(GetWorld(), KeybindsWidgetClass);
        }

        if (Keybindwidget)
        {
            if (!Container->HasChild(Keybindwidget))
            {
                Container->AddChild(Keybindwidget);
            }
            else
            {
                Container->ClearChildren(); // Hides/removes it
            }
        }
    }
}


void UMain_Menu_Widget::OnSaveClicked(const FString& SlotName, int32 SlotNumber)
{

    ATest_Character* Player = Cast<ATest_Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    if (Player) {
        Player->SaveGame(SlotName, SlotNumber);
    }
}

void UMain_Menu_Widget::OnQuitClicked()
{
    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
    if (PlayerController)
    {
        PlayerController->ConsoleCommand("quit");
    }
}

void UMain_Menu_Widget::OnCloseClicked()
{
		
        RemoveFromParent(); // Closes the menu

        APlayerController* PC = GetWorld()->GetFirstPlayerController();
        if (PC)
        {
            PC->bShowMouseCursor = false;
            PC->SetInputMode(FInputModeGameOnly());
            PC->SetPause(false);
            if (PlayerStatsWidgetClass)
            {
                UPlayer_Stat_Widget* StatsWidget = CreateWidget<UPlayer_Stat_Widget>(GetWorld(), PlayerStatsWidgetClass);
                if (StatsWidget)
                {
                    StatsWidget->AddToViewport();
                }
            }
        }
    


}

void UMain_Menu_Widget::OnOpenInventoryClicked()
{
    Container->ClearChildren();
    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (PC && RecorderWidgetClass)
    {
        UE_LOG(LogTemp, Log, TEXT("Attempting to create or toggle the Recorder Widget."));

        if (!RecorderWidget)
        {
            UE_LOG(LogTemp, Log, TEXT("RecorderWidget does not exist, creating it."));
            RecorderWidget = CreateWidget<URecorder_Inventory_Widget>(GetWorld(), RecorderWidgetClass);
        }

        if (RecorderWidget)
        {
            if (!Container->HasChild(RecorderWidget)) {
                UE_LOG(LogTemp, Log, TEXT("RecorderWidget is not a child of InventoryContainer. Adding it."));

                UPlagued_Knight_GameInstance* GI = Cast<UPlagued_Knight_GameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
                if (GI)
                {
                    UE_LOG(LogTemp, Log, TEXT("GameInstance found, populating the inventory."));

                    // Use the inventory from the GameInstance to populate the widget
                    RecorderWidget->PopulateInventory(GI->GetRecorderInventory());
                    Container->AddChild(RecorderWidget);

                    UE_LOG(LogTemp, Log, TEXT("RecorderWidget added to InventoryContainer."));
                }
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("Failed to cast to GameInstance, cannot populate inventory."));
                }
            }
            else
            {
                UE_LOG(LogTemp, Log, TEXT("RecorderWidget already a child of InventoryContainer. Removing it."));
                Container->ClearChildren();
            }
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Either PC is null or RecorderWidgetClass is not set."));
    }

}

void UMain_Menu_Widget::CreateSaveSlotList()
{
    Container->ClearChildren();
    if (!SaveSlotWidgetClass || !Container) return;  // Ensure the necessary references exist

    // Create the Vertical Box to hold the slots
    UVerticalBox* SlotListPanel = NewObject<UVerticalBox>(this);
    if (!SlotListPanel) return;

    for (int32 i = 0; i < MaxSlots; ++i)
    {
        FString SlotName = FString::Printf(TEXT("Slot_%d"), i);

        // Create the SaveSlotWidget
        USaveSlotListWidget* NewSlotWidget = CreateWidget<USaveSlotListWidget>(GetWorld(), SaveSlotWidgetClass);
        if (!NewSlotWidget) continue;

        // Initialize the widget with necessary data
        NewSlotWidget->SlotName = SlotName;
        NewSlotWidget->SlotIndex = i;
        NewSlotWidget->ParentMenu = this;

        // Add the widget to the Vertical Box
        SlotListPanel->AddChildToVerticalBox(NewSlotWidget);

        // Optional: Log widget creation
        UE_LOG(LogTemp, Log, TEXT("Created SaveSlotListWidget for Slot: %s (Index: %d)"), *SlotName, i);
    }

    // Add the Vertical Box to the Container (e.g., a SizeBox or another panel)
    Container->AddChild(SlotListPanel);

}

void UMain_Menu_Widget::CreateSaveSlotButton(const FString& slotname, int32 slotnumber)
{

   
}

void UMain_Menu_Widget::OnPressedSave()
{
    
}

void UMain_Menu_Widget::OnPresseedLoad()
{
}
