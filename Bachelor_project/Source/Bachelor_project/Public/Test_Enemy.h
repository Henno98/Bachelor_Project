// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Test_Enemy.generated.h"

class UStaticMeshComponent;
class UBoxComponent;
UCLASS()
class BACHELOR_PROJECT_API ATest_Enemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATest_Enemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void Walk(float deltatime);
	
	void Look();
	void Attack();
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Variables")
	float LookDistance{300.f};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	float WalkDistance{400.f};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	float WalkSpeed{ 200.f };
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	float AttackRange{200.f};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	float AttackSpeed{1.f};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	bool bSeesPlayer{false};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	bool bHasAttacked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FVector Position;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticMesh")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collider")
	UBoxComponent* Collider;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float Timer{ 0.f };

};