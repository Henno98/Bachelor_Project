// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KeyBindsWidget.h"
#include "Player_Stat_Widget.h"
#include "Recorder_Inventory_Widget.h"
#include "SaveSlotListWidget.h"
#include "Components/Overlay.h"
#include "Components/SizeBox.h"
#include "Components/VerticalBox.h"
#include "Main_Menu_Widget.generated.h"



UCLASS()
class BACHELOR_PROJECT_API UMain_Menu_Widget : public UUserWidget
{
	GENERATED_BODY()
protected:
	// Sets up the widget
	UFUNCTION()
	virtual void NativeConstruct() override;
	UPROPERTY(meta = (BindWidget))
	class UButton* Quit_Button;
	UPROPERTY(meta = (BindWidget))
	class UButton* Close_Button;
	UPROPERTY(meta = (BindWidget))
	class UButton* Mapping_Menu;
	UPROPERTY(meta = (BindWidget))
	class UButton* Load_Button;
	UPROPERTY(meta = (BindWidget))
	class UButton* Open_Inventory;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "SaveSlots")
	int32 MaxSlots = 3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UPlayer_Stat_Widget> PlayerStatsWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UKeyBindsWidget> KeybindsWidgetClass;
	UPROPERTY()
	class UKeyBindsWidget* Keybindwidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<USaveSlotListWidget> SaveSlotWidgetClass;
	UPROPERTY()
	USaveSlotListWidget* SaveSlotList;
	UPROPERTY()
	TArray<USaveSlotListWidget*> SaveSlotWidgets;

	UPROPERTY()
	URecorder_Inventory_Widget* RecorderWidget;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<URecorder_Inventory_Widget> RecorderWidgetClass;
	
	// Function to update the health bar
public:
	
	UPROPERTY(meta = (BindWidget))
	USizeBox* Container;
	
	UFUNCTION()
	void OnLoadClicked(const FString& slotname, int32 slotnumber);

	UFUNCTION()
	void OnMappingMenuClicked();
	UFUNCTION()
	void OnSaveClicked(const FString& SlotName, int32 SlotNumber);

	UFUNCTION()
	void OnQuitClicked();

	UFUNCTION()
	void OnCloseClicked();
	UFUNCTION()
	void OnOpenInventoryClicked();

	UFUNCTION()
	void CreateSaveSlotList();
	UFUNCTION()
	void CreateSaveSlotButton(const FString& slotname, int32 slotnumber);
	UFUNCTION()
	void OnPressedSave();
	UFUNCTION()
	void OnPresseedLoad();
};
