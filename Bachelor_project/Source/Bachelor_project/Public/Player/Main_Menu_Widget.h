// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player_Stat_Widget.h"
#include "SaveSlotListWidget.h"
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
	class UButton* Load_Button;
	UPROPERTY(meta = (BindWidget))
	class UButton* Save_Button;
	UPROPERTY(meta = (BindWidget))
	class UButton* Quit_Button;
	UPROPERTY(meta = (BindWidget))
	class UButton* Close_Button;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UPlayer_Stat_Widget> PlayerStatsWidgetClass;

	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<USaveSlotListWidget> SaveSlotWidgetClass;
	// Function to update the health bar
public:

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* SlotListContainer;
	UFUNCTION()
	void OnLoadClicked(const FString& slotname, int32 slotnumber);

	UFUNCTION()
	void OnSaveClicked(const FString& slotname, int32 slotnumber);

	UFUNCTION()
	void OnQuitClicked();

	UFUNCTION()
	void OnCloseClicked();


	UFUNCTION()
	void CreateSaveSlotList();
	UFUNCTION()
	void CreateSaveSlotButton(const FString& slotname, int32 slotnumber);
	UFUNCTION()
	void OnPressedSave();
	UFUNCTION()
	void OnPresseedLoad();
};
