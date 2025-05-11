// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/VRI_Button_Widget.h"

void UVRI_Button_Widget::NativeConstruct()
{

    Super::NativeConstruct();

    if (PlayButton)
    {
        PlayButton->OnClicked.Clear();

        PlayButton->OnClicked.AddDynamic(this, &UVRI_Button_Widget::HandleButtonClicked);
    }
    SetIsFocusable(true);
}
void UVRI_Button_Widget::HandleButtonClicked()
{
    OnRecorderClicked.Broadcast(RecorderID);
}