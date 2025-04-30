// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Text_Widget.h"

void UText_Widget::NativeConstruct()
{
	Super::NativeConstruct();

	ConstructWidget();

}

void UText_Widget::ConstructWidget()
{
	if (TextBlock)
	{
		
		TextBlock->SetWrapTextAt(WrapSize);
	}
	if (BackgroundImage)
	{


	}
}

void UText_Widget::UpdateWidget(const FString& newtext)
{
	if (TextBlock)
	{

		TextBlock->SetText(FText::FromString(newtext));
	}
}


