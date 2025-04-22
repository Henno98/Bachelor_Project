// Fill out your copyright notice in the Description page of Project Settings.


#include "Main_Menu_Widget.h"

#include "SaveSlotListWidget.h"
#include "SaveState.h"
#include "Test_Character.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMain_Menu_Widget::NativeConstruct()
{// Setup main buttons
    if (Load_Button)
        Load_Button->OnClicked.AddDynamic(this,&UMain_Menu_Widget)

    if (Quit_Button)
        Quit_Button->OnClicked.AddDynamic(this, &UMain_Menu_Widget::OnQuitClicked);

    if (Close_Button)
        Close_Button->OnClicked.AddDynamic(this, &UMain_Menu_Widget::OnCloseClicked);

    CreateSaveSlotList();

}
void UMain_Menu_Widget::OnLoadClicked(const FString& SlotName, int32 SlotNumber)
{
    ATest_Character* Player = Cast<ATest_Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    if (Player)
    {
        Player->LoadGame(SlotName, SlotNumber);
    }
}

void UMain_Menu_Widget::OnSaveClicked(const FString& SlotName, int32 SlotNumber)
{
    ATest_Character* Player = Cast<ATest_Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    if (Player)
    {
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
    const int32 MaxSlots = 3; // Arbitrary max slot count
    for (int32 i = 0; i < MaxSlots; ++i)
    {
        FString SlotName = FString::Printf(TEXT("Slot_%d"), i);

        CreateSaveSlotButton(SlotName, i); // Always create it
        if (!UGameplayStatics::DoesSaveGameExist(SlotName, i)) {
            OnSaveClicked(SlotName, i);
        }
    }

    
}

void UMain_Menu_Widget::CreateSaveSlotButton(const FString& slotname, int32 slotnumber)
{


    if (!SaveSlotWidgetClass || !SlotListContainer) return;
USaveSlotListWidget* Entry = CreateWidget<USaveSlotListWidget>(GetWorld(), SaveSlotWidgetClass);
    if (!Entry) return;

    Entry->SlotName = slotname;
    Entry->SlotIndex = slotnumber;
    Entry->ParentMenu = this;

    SlotListContainer->AddChild(Entry);
}

void UMain_Menu_Widget::OnPressedSave()
{
    
}

void UMain_Menu_Widget::OnPresseedLoad()
{
}
