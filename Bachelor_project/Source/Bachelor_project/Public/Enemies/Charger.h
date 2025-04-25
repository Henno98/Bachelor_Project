// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Charger.generated.h"

UCLASS()
class BACHELOR_PROJECT_API ACharger : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int Damage;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void Destroy();
	void OnHit(int Damage);
	int GetHealth() { return Health; }
	void SetHealth(int newhealth){Health = newhealth;}
	int GetDamage() { return Damage; }
};
