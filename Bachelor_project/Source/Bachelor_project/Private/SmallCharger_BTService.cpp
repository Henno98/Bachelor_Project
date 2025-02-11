// Fill out your copyright notice in the Description page of Project Settings.


#include "SmallCharger_BTService.h"
#include "SmallCharger_AIController.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/Animation/AnimSingleNodeInstance.h"
#include "BehaviorTree/BlackboardComponent.h"



void USmallCharger_BTService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	ASmallCharger_AIController* smallcharger_ai_controller = Cast<ASmallCharger_AIController>(OwnerComp.GetOwner());

	/*if (smallcharger_ai_controller != nullptr) {

		float currentDistance = FVector::Distance(smallcharger_ai_controller->GetNavAgentLocation(), smallcharger_ai_controller->smallCharger_target_location);

		float percentageToTarget = currentDistance / smallcharger_ai_controller->initialDistance * 100.0f;

		USkeletalMeshComponent* skelComponent = Cast<USkeletalMeshComponent>(smallcharger_ai_controller->GetCharacter()->GetMesh());*/

		/*if (skelComponent != nullptr) {

			if (OwnerComp.GetBlackboardComponent()->GetValueAsBool("SeenOwner") == true)
			{
				if (OwnerComp.GetBlackboardComponent()->GetValueAsBool("Closed_To_Owner"))
				{
					skelComponent->GetSingleNodeInstance()->SetBlendSpacePosition(FVector::ZeroVector);

				}
				else if (OwnerComp.GetBlackboardComponent()->GetValueAsBool("Run_To_Owner"))
				{
					skelComponent->GetSingleNodeInstance()->SetBlendSpacePosition(FVector(100, 0, 0));
				}
			}
			else
			{
				FVector blendParameter(percentageToTarget, 0.0f, 0.0f);

				skelComponent->GetSingleNodeInstance()->SetBlendSpacePosition(blendParameter);
			}


		}*/

	//}


}
