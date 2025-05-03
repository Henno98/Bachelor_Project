// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/Main_Menu_Widget.h"
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
   // CreateSaveSlotList();
    FTimerHandle TimerHandle;
    GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	if (Close_Button)
    {
        GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([this]()
            {
                if (Close_Button)
                {
                    Close_Button->SetKeyboardFocus();
                }
            }), 0.1f, false);
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
    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (PC && KeybindsWidgetClass)
    {
        if (!Keybindwidget)
        {
            Keybindwidget = CreateWidget<UKeyBindsWidget>(GetWorld(), KeybindsWidgetClass);
        }

        if (Keybindwidget)
        {
            if (!KeyBindsContainer->HasChild(Keybindwidget))
            {
                KeyBindsContainer->AddChild(Keybindwidget);
            }
            else
            {
                KeyBindsContainer->ClearChildren(); // Hides/removes it
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

void UMain_Menu_Widget::CreateSaveSlotList()
{
    if (SlotListContainer->GetChildrenCount() == 0)
    {
        SlotListContainer->ClearChildren();
        SaveSlotWidgets.Empty();

        for (int32 i = 0; i < MaxSlots; ++i)
        {
            FString SlotName = FString::Printf(TEXT("Slot_%d"), i);

            CreateSaveSlotButton(SlotName, i);

            if (!UGameplayStatics::DoesSaveGameExist(SlotName, i)) {
                OnSaveClicked(SlotName, i);
            }
        }
    }
    else
    {
        // Remove all slot widgets from container
        SlotListContainer->ClearChildren();
        SaveSlotWidgets.Empty();
    }
}

void UMain_Menu_Widget::CreateSaveSlotButton(const FString& slotname, int32 slotnumber)
{

    if (!SaveSlotWidgetClass || !SlotListContainer) return;

    USaveSlotListWidget* NewSlotWidget = CreateWidget<USaveSlotListWidget>(GetWorld(), SaveSlotWidgetClass);
    if (!NewSlotWidget) return;

    NewSlotWidget->SlotName = slotname;
    NewSlotWidget->SlotIndex = slotnumber;
    NewSlotWidget->ParentMenu = this;

    SlotListContainer->AddChild(NewSlotWidget);
    SaveSlotWidgets.Add(NewSlotWidget);
}

void UMain_Menu_Widget::OnPressedSave()
{
    
}

void UMain_Menu_Widget::OnPresseedLoad()
{
}
