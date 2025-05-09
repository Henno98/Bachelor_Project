// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BACHELOR_PROJECT_API IInteractable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactible")
	bool GetIsInteractible() const;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactible")
	FString GetInteractibleText()const;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactible")
	void LoadText(const FString& FilePath);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactible")
	void PlayText();
	/*
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactible")

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactible")

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactible")

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactible")*/

};
