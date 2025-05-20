#include "Enemies/MeleePlant_AIController.h"
#include "Perception/PawnSensingComponent.h"
#include "Player/Test_Character.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include <Enemies/MeleePlant.h>

AMeleePlant_AIController::AMeleePlant_AIController()
{
	MeleePlant_PerceptionComponent = CreateDefaultSubobject<UPawnSensingComponent>("PawnSensing");
	MeleePlant_PerceptionComponent->SetPeripheralVisionAngle(90.0f);
	MeleePlant_PerceptionComponent->SightRadius = 400.0f;
}

void AMeleePlant_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (MeleePlant_PerceptionComponent)
	{
		MeleePlant_PerceptionComponent->OnSeePawn.AddDynamic(this, &AMeleePlant_AIController::OnEnemySeeItsTarget);
	}
}

void AMeleePlant_AIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Player)
	{
		AMeleePlant* MeleePlant = Cast<AMeleePlant>(GetPawn());
		if (!MeleePlant) return;

		const float Distance = FVector::Dist(GetPawn()->GetActorLocation(), Player->GetActorLocation());

		if (Distance <= MeleePlant->AttackRange)
		{
			if (bCanAttack)
			{
				PerformAttack();
				bCanAttack = false;

				// Attack cooldown timer
				GetWorld()->GetTimerManager().SetTimer(AttackCooldownTimer, this, &AMeleePlant_AIController::ResetAttack, 2.0f, false);
			}
		}
	}
}

void AMeleePlant_AIController::OnEnemySeeItsTarget(APawn* SensedPawn)
{
	if (SensedPawn && SensedPawn->IsA<ATest_Character>())
	{
		const FVector PlayerLocation = SensedPawn->GetActorLocation();
		const FVector PlantLocation = GetPawn()->GetActorLocation();
		const float VerticalDistance = FMath::Abs(PlayerLocation.Z - PlantLocation.Z);

		/*if (VerticalDistance > 100.f)
		{
			UE_LOG(LogTemp, Warning, TEXT("Player too high - ignoring."));
			return;
		}*/

		Player = SensedPawn;
	}
}

void AMeleePlant_AIController::PerformAttack()
{
	if (!Player) return;

	AMeleePlant* MeleePlant = Cast<AMeleePlant>(GetPawn());
	if (MeleePlant)
	{
		MeleePlant->PerformMeleeAttack();
	}

	UE_LOG(LogTemp, Warning, TEXT("MeleePlant attacks!"));
	DrawDebugString(GetWorld(), GetPawn()->GetActorLocation() + FVector(0, 0, 100), TEXT("ATTACK!"), nullptr, FColor::Red, 1.0f);

	FVector Start = MeleePlant->GetMesh()->GetSocketLocation("BiteSocket") + FVector(0.f, 0.f, 50.f);;
	FVector ForwardVector = MeleePlant->GetActorForwardVector();
	FVector End = Start + ForwardVector * MeleePlant->AttackRange + FVector(0.f, 0.f, 20.f);
	DrawDebugSphere(GetWorld(), End, 100.f, 12, FColor::Red, false, 1.0f);

}

void AMeleePlant_AIController::ResetAttack()
{
	bCanAttack = true;
}
