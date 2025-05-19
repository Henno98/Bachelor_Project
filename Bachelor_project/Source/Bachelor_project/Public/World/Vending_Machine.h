// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "GameFramework/Actor.h"
#include "Vending_Machine.generated.h"

UCLASS()
class BACHELOR_PROJECT_API AVending_Machine : public AActor,public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVending_Machine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Basic attributes")
	class USkeletalMeshComponent* SkeletalMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic attributes")
	class UBoxComponent* HitBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic attributes")

	int ID;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void Save(AActor* Player);
	virtual bool GetIsInteractible_Implementation() const override { return  true; };
	virtual int32 GetID_Implementation() override { return ID; };
	virtual void InteractableAction_Implementation() override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Basic attributes")
	bool FirstTime =true;
};
