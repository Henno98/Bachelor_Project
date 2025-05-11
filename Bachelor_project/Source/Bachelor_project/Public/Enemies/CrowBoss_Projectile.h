// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "CrowBoss_Projectile.generated.h"

UCLASS()
class BACHELOR_PROJECT_API ACrowBoss_Projectile : public AActor
{
	GENERATED_BODY()
	

public:
    // Sets default values for this actor's properties
    ACrowBoss_Projectile();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
    UStaticMeshComponent* Mesh;
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Collision")
    UCapsuleComponent* Collider;
    UPROPERTY(VisibleAnywhere)
    class UProjectileMovementComponent* ProjectileMovement;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Damage;
    FVector TargetLocation;
    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	void DestroyActor();
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    FRotator LookAt(FVector target);
};

