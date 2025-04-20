// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player_Stat_Widget.h"
#include "Blueprint/UserWidget.h"
#include "Main_Menu_Widget.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API UMain_Menu_Widget : public UUserWidget
{
	GENERATED_BODY()
protected:
	// Sets up the widget
	UFUNCTION()
	virtual void NativeConstruct() override;
	UPROPERTY(meta = (BindWidget))
	class UButton* Load_Button;
	UPROPERTY(meta = (BindWidget))
	class UButton* Save_Button;
	UPROPERTY(meta = (BindWidget))
	class UButton* Quit_Button;
	UPROPERTY(meta = (BindWidget))
	class UButton* Close_Button;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UPlayer_Stat_Widget> PlayerStatsWidgetClass;

	// Function to update the health bar
public:
	UFUNCTION()
	void OnLoadClicked();

	UFUNCTION()
	void OnSaveClicked();

	UFUNCTION()
	void OnQuitClicked();

	UFUNCTION()
	void OnCloseClicked();
};
