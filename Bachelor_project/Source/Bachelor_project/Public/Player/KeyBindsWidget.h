// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Blueprint/UserWidget.h"
#include "KeyBindsWidget.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API UKeyBindsWidget : public UUserWidget
{
	GENERATED_BODY()
	bool bWaitingForKey;
	void UpdateKeyBindDisplay();
	void RebindKey(UInputAction* Action, FKey NewKey);
	
};
