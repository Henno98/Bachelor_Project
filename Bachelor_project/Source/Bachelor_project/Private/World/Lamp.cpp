// Fill out your copyright notice in the Description page of Project Settings.


#include "World/Lamp.h"
// Sets default values
ALamp::ALamp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// Create Mesh Component
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	SetRootComponent(MeshComp);

	// Point Light
	PointLightComp = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComp"));
	PointLightComp->SetupAttachment(MeshComp);
	PointLightComp->SetIntensity(3000.0f); // Default intensity

	// Timeline
	FlickerTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("FlickerTimeline"));
}

// Called when the game starts or when spawned
void ALamp::BeginPlay()
{
	Super::BeginPlay();
	if (FlickerCurve && FlickerTimeline)
	{
		// Bind timeline function
		FOnTimelineFloat UpdateFunction;
		UpdateFunction.BindUFunction(this, FName("OnTimelineUpdate"));

		FlickerTimeline->AddInterpFloat(FlickerCurve, UpdateFunction);
		FlickerTimeline->SetLooping(true);
		FlickerTimeline->PlayFromStart();
	}
	
}


// Called every frame
void ALamp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (FlickerTimeline)
	{
		FlickerTimeline->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, nullptr);
	}
}

void ALamp::OnTimelineUpdate(float Value)
{
	if (PointLightComp)
	{
		PointLightComp->SetIntensity(Value * 3000.0f);
	}
}