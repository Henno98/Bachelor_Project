// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "VRI_Button_Widget.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRecorderClicked, int32, RecorderID);
/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API UVRI_Button_Widget : public UUserWidget
{
	GENERATED_BODY()

public:
    UPROPERTY(meta = (BindWidget))
    UButton* PlayButton;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* TitleText;

    UPROPERTY(BlueprintAssignable, Category = "Recorder")
    FOnRecorderClicked OnRecorderClicked;

    void SetRecorderID(int32 ID) { RecorderID = ID; }
    int32 GetRecorderID() const { return RecorderID; }

    void SetText(FString InText) { TitleText->SetText(FText::FromString(InText)); }

protected:
    virtual void NativeConstruct() override;

private:
    int32 RecorderID;

    UFUNCTION()
    void HandleButtonClicked();
};
