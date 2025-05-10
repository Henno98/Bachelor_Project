#include "Enemies/CrowBoss_AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Enemies/CrowBoss.h"
#include "Perception/PawnSensingComponent.h"
#include "Player/Test_Character.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY_STATIC(LogCrowBossAI, Log, All);

ACrowBoss_AIController::ACrowBoss_AIController()
{
    CrowBoss_PerceptionComponent = CreateDefaultSubobject<UPawnSensingComponent>("CrowBoss Perception Component");
    CrowBoss_BBC = CreateDefaultSubobject<UBlackboardComponent>("BlackBoardComp");
    CrowBoss_BTC = CreateDefaultSubobject<UBehaviorTreeComponent>("CrowBoss Behavior Tree Component");
}

void ACrowBoss_AIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    if (CrowBoss_BT != nullptr)
    {
        UE_LOG(LogCrowBossAI, Log, TEXT("CrowBoss AI Possessed Pawn: %s"), *InPawn->GetName());

        CrowBoss_BBC->InitializeBlackboard(*CrowBoss_BT->BlackboardAsset);
        CrowBoss_BTC->StartTree(*CrowBoss_BT);
        CrowBoss_BBC->SetValueAsVector("OriginalPosition", GetPawn()->GetActorLocation());
        CrowBoss_PerceptionComponent->OnSeePawn.AddDynamic(this, &ACrowBoss_AIController::OnSeenPawn);
    }
}

void ACrowBoss_AIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    APawn* Crow = GetPawn();
    if (!Crow) return;
    ACrowBoss* CrowBoss = Cast<ACrowBoss>(Crow);
    if (!CrowBoss) return;

    bool bIsAttacking = CrowBoss_BBC->GetValueAsBool("IsAttacking");
    if (bIsAttacking)
    {
        UE_LOG(LogCrowBossAI, Verbose, TEXT("CrowBoss is attacking; skipping movement."));
        return;
    }

    if (Player)
    {
        CrowBoss->SetIsPatrolling(true);

        FVector PlayerLocation = Player->GetActorLocation();
        FVector CrowLocation = Crow->GetActorLocation();
        float Distance = FVector::Dist(PlayerLocation, CrowLocation);
        CrowBoss_BBC->SetValueAsFloat("DistanceToPlayer", Distance);
        if (Distance > CrowBoss->GetVisionRange())
        {
            UE_LOG(LogCrowBossAI, Warning, TEXT("Player is out of range. Stopping pursuit."));
            Player = nullptr;
            CrowBoss_BBC->SetValueAsObject("Player", nullptr);
            CrowBoss_BBC->SetValueAsBool("SeenPlayer", false);
            return;
        }

        FVector TargetLocation = PlayerLocation + FVector(0.f, 0.f, 300.f);
        FVector DirectionToTarget = TargetLocation - CrowLocation;
        float DistanceToTarget = DirectionToTarget.Size();
        DirectionToTarget = DirectionToTarget.GetSafeNormal();
        float MovementSpeed = FMath::Clamp(DistanceToTarget / 500.f, 0.1f, 1.0f);

        Crow->AddMovementInput(FVector(DirectionToTarget.X, DirectionToTarget.Y, 0), MovementSpeed);
    
            CrowBoss_BBC->SetValueAsBool("SeenPlayer", true);
        
            /*FRotator LookAt = (PlayerLocation - CrowLocation).Rotation();
            Crow->SetActorRotation(FMath::RInterpTo(Crow->GetActorRotation(), LookAt, DeltaTime, 5.0f));
        */
            FRotator FullLookAt = (PlayerLocation - CrowLocation).Rotation();

            // Horizontal-only look direction (no pitch)
            FVector FlatDirection = FVector(PlayerLocation.X, PlayerLocation.Y, CrowLocation.Z) - CrowLocation;
            FRotator HorizontalLookAt = FlatDirection.Rotation();

            //0.3 = 30% tilt
            float BlendFactor = 0.3f;
            FRotator BlendedLookAt;
            BlendedLookAt.Pitch = FMath::Lerp(HorizontalLookAt.Pitch, FullLookAt.Pitch, BlendFactor);
            BlendedLookAt.Yaw = FMath::Lerp(HorizontalLookAt.Yaw, FullLookAt.Yaw, BlendFactor);
            BlendedLookAt.Roll = 0.f;

            Crow->SetActorRotation(FMath::RInterpTo(Crow->GetActorRotation(), BlendedLookAt, DeltaTime, 5.0f));
    }
    else
    {
        CrowBoss_BBC->SetValueAsBool("SeenPlayer", false);
    }
}

void ACrowBoss_AIController::OnSeenPawn(APawn* SeenPawn)
{
    if (!SeenPawn) return;
    ACrowBoss* CrowBoss = Cast<ACrowBoss>(GetPawn());
    if (!CrowBoss) return;

    if (SeenPawn->IsA<ATest_Character>())
    {
        Player = SeenPawn;
        CrowBoss_BBC->SetValueAsObject("Player", SeenPawn);
        CrowBoss_BBC->SetValueAsBool("SeenPlayer", true);
        UE_LOG(LogCrowBossAI, Log, TEXT("CrowBoss spotted the player: %s"), *SeenPawn->GetName());
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("Player Seen!"));
    }
}
