// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Text_Widget.generated.h"

/**
 * 
 */
UCLASS()
class BACHELOR_PROJECT_API UText_Widget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void NativeConstruct() override;
	UFUNCTION()
	void ConstructWidget();
	UFUNCTION()
	void UpdateWidget(const FString& newtext);
protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextBlock;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Variable")
	float WrapSize = 600;
	UPROPERTY(meta = (BindWidget))
	UImage* BackgroundImage;
};
