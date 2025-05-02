// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "projectile.generated.h"

UCLASS()
class BACHELOR_PROJECT_API Aprojectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aprojectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "staticmesh")
	UStaticMeshComponent* staticmesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "staticmesh")
	USphereComponent* collider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targeting")
	float lifetime = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targeting")
	FVector TargetLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targeting")
	FVector CurrentLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targeting")
	FVector Velocity;
	UFUNCTION()
	void Travel(float deltatime);
	UFUNCTION()
	void SetPosition(FVector position);
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Collider data")
	float Size{5.f};

	UFUNCTION()
	void DestroyActor();

	float Timer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collider data")
	int Damage;

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	int GetDamage() { return Damage; }
	void SetDamage(int newdamage) { Damage = newdamage; }

	AActor* Owner;
	AActor* GetSpawner() { return Owner; }
};
