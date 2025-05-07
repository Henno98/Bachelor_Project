// Fill out your copyright notice in the Description page of Project Settings.


#include "Plagued_Knight_GameInstance.h"

void UPlagued_Knight_GameInstance::StoreSavedData(const FVector& Loc, float Health, float BioMass, FName Level)
{
    SavedLocation = Loc;
    SavedHealth = Health;
    SavedBioMass = BioMass;
    TargetLevel = Level;
}

FVector UPlagued_Knight_GameInstance::GetSavedLocation() const
{
    return SavedLocation;
}

float UPlagued_Knight_GameInstance::GetSavedHealth() const
{
    return SavedHealth;
}

float UPlagued_Knight_GameInstance::GetSavedBioMass() const
{
    return SavedBioMass;
}

FName UPlagued_Knight_GameInstance::GetTargetLevel() const
{
    return TargetLevel;
}

FString UPlagued_Knight_GameInstance::GetCurrentSubLevelName() const
{
    return CurrentSubLevel;
}

int32 UPlagued_Knight_GameInstance::GetGlobalProgress() const
{
    return GlobalProgress;
}

void UPlagued_Knight_GameInstance::ClearSavedData()
{
    SavedLocation = FVector::ZeroVector;
    SavedHealth = 0.0f;
    SavedBioMass = 0.0f;
    TargetLevel = NAME_None;
}
