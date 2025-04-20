// Fill out your copyright notice in the Description page of Project Settings.


#include "Main_Menu_Widget.h"
#include "SaveState.h"
#include "Test_Character.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMain_Menu_Widget::NativeConstruct()
{
    if (Load_Button)
        Load_Button->OnClicked.AddDynamic(this, &UMain_Menu_Widget::OnLoadClicked);

    if (Save_Button)
        Save_Button->OnClicked.AddDynamic(this, &UMain_Menu_Widget::OnSaveClicked);

    if (Quit_Button)
        Quit_Button->OnClicked.AddDynamic(this, &UMain_Menu_Widget::OnQuitClicked);

    if (Close_Button)
        Close_Button->OnClicked.AddDynamic(this, &UMain_Menu_Widget::OnCloseClicked);

}
void UMain_Menu_Widget::OnLoadClicked()
{
  
    
            // Example: Move the player to the saved location
    ATest_Character* Player = Cast<ATest_Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

            if (Player)
            {
                Player->LoadGame();
            }

             
   
}

void UMain_Menu_Widget::OnSaveClicked()
{
    // Save game logic placeholder
    UE_LOG(LogTemp, Warning, TEXT("Save game clicked!"));
    ATest_Character* Player = Cast<ATest_Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

    if (Player)
    {
        Player->SaveGame();
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
