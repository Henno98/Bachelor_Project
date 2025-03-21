// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MoveToPlayer_SmallCharger.h"
#include "SmallCharger_AIController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetStringLibrary.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UBTTask_MoveToPlayer_SmallCharger::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type result = EBTNodeResult::Failed;
	UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent();
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "Seen Player");
	if (AActor* player = Cast<AActor>(BB->GetValueAsObject("Player")))
	{
		FVector Direction = (player->GetActorLocation() - OwnerComp.GetOwner()->GetActorLocation()).GetSafeNormal();

		float OvershootDistance = 200.f;
		FVector TargetLocation = player->GetActorLocation() + Direction * OvershootDistance;

		TargetLocation.Z = OwnerComp.GetOwner()->GetActorLocation().Z;
		BB->SetValueAsVector("TargetLocation", FVector(TargetLocation.X, TargetLocation.Y, OwnerComp.GetOwner()->GetActorLocation().Z));
		FString Message = UKismetStringLibrary::Conv_VectorToString(FVector(TargetLocation.X, TargetLocation.Y, OwnerComp.GetOwner()->GetActorLocation().Z));
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, Message);
		result = EBTNodeResult::Succeeded;
	}
	return result;
}


//EBTNodeResult::Type UBTTask_MoveToPlayer_SmallCharger::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
//{
//	Super::ExecuteTask(OwnerComp, NodeMemory);
//	
//	UBlackboardComponent* AI_smallcharger_BBC = Cast<UBlackboardComponent>(OwnerComp.GetBlackboardComponent());
//	if (!AI_smallcharger_BBC) return EBTNodeResult::Failed;
//
//	ASmallCharger_AIController* AI_smallcharger_controller = Cast<ASmallCharger_AIController>(OwnerComp.GetAIOwner());
//	if (!AI_smallcharger_controller) return EBTNodeResult::Failed;
//	
//
//
//	FVector LastSeenLocation = AI_smallcharger_BBC->GetValueAsVector("LastSeenLocation");
//	FVector AI_Location = AI_smallcharger_controller->GetPawn()->GetActorLocation();
//
//	// Ignore the Z-axis and only move on X and Y
//	FVector ChargeDirection = (FVector(LastSeenLocation.X, LastSeenLocation.Y, AI_Location.Z) - AI_Location).GetSafeNormal();
//	FVector ChargeTargetLocation = FVector(LastSeenLocation.X, LastSeenLocation.Y, AI_Location.Z) + (ChargeDirection * 600.0f);
//
//
//	// Move AI to extended charge location
//	AI_smallcharger_controller->MoveToLocation(ChargeTargetLocation, 5.0f, true, true, false, true, 0, true);
//
//	
//	ACharacter* AICharacter = Cast<ACharacter>(AI_smallcharger_controller->GetPawn());
//	if (AICharacter)
//	{
//		AICharacter->GetCharacterMovement()->MaxWalkSpeed = 1200.0f;
//	}
//
//	return EBTNodeResult::InProgress;
//}
//
//
//void UBTTask_MoveToPlayer_SmallCharger::OnTaskFinished(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTNodeResult::Type TaskResult)
//{
//	Super::OnTaskFinished(OwnerComp, NodeMemory, TaskResult);
//
//	ASmallCharger_AIController* AI_smallcharger_controller = Cast<ASmallCharger_AIController>(OwnerComp.GetAIOwner());
//	UBlackboardComponent* AI_smallcharger_BBC = Cast<UBlackboardComponent>(OwnerComp.GetBlackboardComponent());
//
//	if (!AI_smallcharger_controller || !AI_smallcharger_BBC) return;
//
//	// Reset speed to normal
//	ACharacter* AICharacter = Cast<ACharacter>(AI_smallcharger_controller->GetPawn());
//	if (AICharacter)
//	{
//		AICharacter->GetCharacterMovement()->MaxWalkSpeed = 300.0f; // Normal speed
//	}
//
//	// Check if the player is still nearby
//	AActor* PlayerPawn = Cast<AActor>(AI_smallcharger_BBC->GetValueAsObject("Player"));
//
//	if (AICharacter && PlayerPawn)
//	{
//		float DistanceToPlayer = FVector::Distance(AICharacter->GetActorLocation(), PlayerPawn->GetActorLocation());
//
//		if (DistanceToPlayer < 600.0f)
//		{
//			AI_smallcharger_BBC->SetValueAsBool("SeenPlayer", true);
//			UE_LOG(LogTemp, Warning, TEXT("Player is still close, recharging"));
//			
//		}
//		else
//		{
//				AI_smallcharger_BBC->SetValueAsBool("SeenPlayer", false);
//			UE_LOG(LogTemp, Warning, TEXT("Player moved away, stopping charge"));
//			
//		}
//		
//	}
//}



// Get last seen location of the player
	//FVector LastSeenLocation = AI_smallcharger_BBC->GetValueAsVector("LastSeenLocation");
	// Calculate charge direction (AI moves past the last seen location)
	//FVector AI_Location = AI_smallcharger_controller->GetPawn()->GetActorLocation();
	//FVector ChargeDirection = (LastSeenLocation - AI_Location).GetSafeNormal(); // Normalize direction

	//FVector ChargeTargetLocation = LastSeenLocation + (ChargeDirection * 600.0f);


//if (PlayerPawn)
	//{
		//float DistanceToPlayer = FVector::Distance(AICharacter->GetActorLocation(), PlayerPawn->GetActorLocation());


		//// If the player is still close, charge again
		//if (DistanceToPlayer < 600.0f) // Adjust range as needed
		//{
		//	// Set AI state for charging again
		//	AI_smallcharger_BBC->SetValueAsBool("Run_To_Player", true);
		//	AI_smallcharger_BBC->SetValueAsBool("Closed_To_Player", false);

		//	UE_LOG(LogTemp, Warning, TEXT("DistanceToPlayer < 600"));
		//}
		//else
		//{
		//	AI_smallcharger_BBC->SetValueAsBool("Run_To_Player", false);
		//	AI_smallcharger_BBC->SetValueAsBool("Closed_To_Player", true);
		//	UE_LOG(LogTemp, Warning, TEXT("DistanceToPlayer else"));
		//}
	//}






//void UBTTask_MoveToPlayer_SmallCharger::OnTaskFinished(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTNodeResult::Type TaskResult)
//{
//	Super::OnTaskFinished(OwnerComp, NodeMemory, TaskResult);
//
//	ASmallCharger_AIController* AI_smallcharger_controller = Cast<ASmallCharger_AIController>(OwnerComp.GetAIOwner());
//	UBlackboardComponent* AI_smallcharger_BBC = Cast<UBlackboardComponent>(OwnerComp.GetBlackboardComponent());
//
//	if (!AI_smallcharger_controller || !AI_smallcharger_BBC) return;
//
//	// Stop movement after charge
//	AI_smallcharger_controller->StopMovement();
//
//	// Reset speed to normal
//	ACharacter* AICharacter = Cast<ACharacter>(AI_smallcharger_controller->GetPawn());
//	if (AICharacter)
//	{
//		AICharacter->GetCharacterMovement()->MaxWalkSpeed = 300.0f; // Normal speed
//	}
//
//	// Check if the player is still nearby
//	AActor* PlayerPawn = Cast<AActor>(AI_smallcharger_BBC->GetValueAsObject("Player"));
//	if (PlayerPawn)
//	{
//		float DistanceToPlayer = FVector::Distance(AICharacter->GetActorLocation(), PlayerPawn->GetActorLocation());
//
//		// If the player is still close, charge again
//		if (DistanceToPlayer < 600.0f) // Adjust range as needed
//		{
//			AI_smallcharger_BBC->SetValueAsBool("Run_To_Player", true); // Trigger another charge
//		}
//		else
//		{
//			AI_smallcharger_BBC->SetValueAsBool("Run_To_Player", false);
//			AI_smallcharger_BBC->SetValueAsBool("Closed_To_Player", true);
//		}
//	}
//}







//MOVE TO PLAYER


//EBTNodeResult::Type UBTTask_MoveToPlayer_SmallCharger::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
//{
//	UBlackboardComponent* AI_smallcharger_BBC = Cast<UBlackboardComponent>(OwnerComp.GetBlackboardComponent());
//	AI_smallcharger_BBC->SetValueAsBool("Closed_To_Player", false);
//	AI_smallcharger_BBC->SetValueAsBool("Run_To_Player", true);
//
//	
//	
//	
//
//
//	return Super::ExecuteTask(OwnerComp, NodeMemory);
//}
//
//void UBTTask_MoveToPlayer_SmallCharger::OnTaskFinished(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTNodeResult::Type TaskResult)
//{
//	Super::OnTaskFinished(OwnerComp, NodeMemory, TaskResult);
//
//	ASmallCharger_AIController* AI_smallcharger_controller = Cast<ASmallCharger_AIController>(OwnerComp.GetAIOwner());
//	UBlackboardComponent* AI_smallcharger_BBC = Cast<UBlackboardComponent>(OwnerComp.GetBlackboardComponent());
//
//	AActor* player_pawn = Cast<AActor>(AI_smallcharger_BBC->GetValueAsObject("Player"));
//
//	float distance = FVector::Distance(AI_smallcharger_controller->GetNavAgentLocation(), FVector(player_pawn->GetActorLocation().X, player_pawn->GetActorLocation().Y, AI_smallcharger_controller->GetNavAgentLocation().Z));
//
//	if (distance < 400.0f)
//	{
//		AI_smallcharger_controller->StopMovement();
//		AI_smallcharger_BBC->SetValueAsBool("Run_To_Player", false);
//		AI_smallcharger_BBC->SetValueAsBool("Closed_To_Player", true);
//
//	}
//	
//
//}
