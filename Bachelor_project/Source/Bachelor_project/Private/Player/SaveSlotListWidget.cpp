// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/SaveSlotListWidget.h"
#include "Player/Main_menu_Widget.h"
void USaveSlotListWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (Button) {
        Button->OnClicked.Clear();
        Button->OnClicked.AddDynamic(this, &USaveSlotListWidget::HandleLoadClicked);
    }
    if (SlotNameText) {
     
        SlotNameText->SetText(FText::FromString(SlotName));
    }
    SetIsFocusable(true);
}

void USaveSlotListWidget::HandleLoadClicked()
{
    if (ParentMenu) 
    {
        ParentMenu->OnLoadClicked(SlotName, SlotIndex);
    }
}

void USaveSlotListWidget::HandleSaveClicked()
{
    if (ParentMenu) 
    {
        ParentMenu->OnSaveClicked(SlotName, SlotIndex);
    }
}

void USaveSlotListWidget::SetSave()
{
    if (Button)
        Button->OnClicked.AddDynamic(this, &USaveSlotListWidget::HandleLoadClicked);
}

void USaveSlotListWidget::SetLoad()
{
    if (Button)
        Button->OnClicked.AddDynamic(this, &USaveSlotListWidget::HandleSaveClicked);
}
