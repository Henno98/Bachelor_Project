// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/CrowBoss_Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"


ACrowBoss_Projectile::ACrowBoss_Projectile()
{
    PrimaryActorTick.bCanEverTick = false;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;
    Mesh->SetSimulatePhysics(false);
    Mesh->SetNotifyRigidBodyCollision(true);
    Mesh->OnComponentHit.AddDynamic(this, &ACrowBoss_Projectile::OnHit);

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->InitialSpeed = 1200.0f;
    ProjectileMovement->MaxSpeed = 1200.0f;
    ProjectileMovement->bRotationFollowsVelocity = true;
    ProjectileMovement->ProjectileGravityScale = 0.0f;
}

// Called when the game starts or when spawned
void ACrowBoss_Projectile::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void ACrowBoss_Projectile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void ACrowBoss_Projectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
    FVector NormalImpulse, const FHitResult& Hit)
{
}

