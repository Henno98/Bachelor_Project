// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicPlatform.generated.h"



class UStaticMeshComponent;
class UBoxComponent;
UCLASS()
class BACHELOR_PROJECT_API ABasicPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasicPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY()
	 UStaticMeshComponent* StaticMesh;
	 UPROPERTY()
	 UBoxComponent* Collider;
};
