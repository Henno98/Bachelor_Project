// Fill out your copyright notice in the Description page of Project Settings.


#include "projectile.h"

#include "SmallCharger.h"
#include "Test_Character.h"
#include "Test_Enemy.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
Aprojectile::Aprojectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	SetRootComponent(collider);
	collider->SetRelativeScale3D(FVector(Size));
	collider->OnComponentBeginOverlap.AddDynamic(this, &Aprojectile::OnOverlap);
	//collider->SetWorldScale3D(FVector(0.5f));
	staticmesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("staticmesh"));
	staticmesh->SetupAttachment(RootComponent);
	staticmesh->SetRelativeScale3D(FVector(0.5f));
	//collider->IgnoreActorWhenMoving(GetOwner(),true);

}
// Called when the game starts or when spawned
void Aprojectile::BeginPlay()
{
	Super::BeginPlay();
	//SetActorLocation(CurrentLocation);
	lifetime = FMath::RandRange(5, 10);
	
}
// Called every frame
void Aprojectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Travel(DeltaTime);
	
	Timer += DeltaTime;
	if (Timer > lifetime) {
		DestroyActor();
	}

}

void Aprojectile::Travel(float deltatime)
{

	CurrentLocation = GetActorLocation();
	CurrentLocation += Velocity*deltatime;
	SetActorLocation(CurrentLocation);

}

void Aprojectile::SetPosition(FVector position)
{
	CurrentLocation = position;
}

void Aprojectile::DestroyActor()
{
	    SetActorHiddenInGame(true);
		SetActorEnableCollision(false);
		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Destroyed projectile", true);

}

void Aprojectile::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if (OtherActor != GetOwner()) {
		if (OtherActor->IsA<ASmallCharger>())
		{
			//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, TEXT("Hit a Charger"));
			if (OtherComponent->IsA<UBoxComponent>()) {
				ASmallCharger* charger = Cast<ASmallCharger>(OtherActor);
				charger->Destroy();
				this->DestroyActor();
				//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Orange, TEXT("Hit Charger"));
			}
		}
		if (OtherActor->IsA<ATest_Character>())
		{
			if (OtherComponent->IsA<UCapsuleComponent>()) {
				//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, TEXT("Hit a test character"));

				ATest_Character* player = Cast<ATest_Character>(OtherActor);
				ATest_Enemy* owner = Cast<ATest_Enemy>(GetOwner());
				int damage = owner->GetDamage();
				player->Hit(damage);
				//player->LaunchCharacter(player->GetActorForwardVector().GetSafeNormal() * -100.f, false, false);
				GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("Player took damage"));
				this->DestroyActor();
			}
		}
		if (OtherActor->IsA<ATest_Enemy>())
		{
			//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, TEXT("Hit a test_Enemy"));
			if (OtherComponent->IsA<UBoxComponent>()) {

				ATest_Enemy* enemy = Cast<ATest_Enemy>(OtherActor);
				ATest_Character* owner = Cast<ATest_Character>(GetOwner());
				int damage = owner->GetRangedDamage();
				enemy->OnHit(damage);
				GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("Enemy took damage"));
				this->DestroyActor();
			}
		}
		
	}
}

