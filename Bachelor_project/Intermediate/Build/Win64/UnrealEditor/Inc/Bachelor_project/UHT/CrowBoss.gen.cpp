// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/CrowBoss.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCrowBoss() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ACrowBoss();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ACrowBoss_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class ACrowBoss Function Collision
struct Z_Construct_UFunction_ACrowBoss_Collision_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CrowBoss.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACrowBoss_Collision_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACrowBoss, nullptr, "Collision", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_Collision_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACrowBoss_Collision_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ACrowBoss_Collision()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACrowBoss_Collision_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACrowBoss::execCollision)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Collision();
	P_NATIVE_END;
}
// End Class ACrowBoss Function Collision

// Begin Class ACrowBoss Function Death
struct Z_Construct_UFunction_ACrowBoss_Death_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CrowBoss.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACrowBoss_Death_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACrowBoss, nullptr, "Death", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_Death_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACrowBoss_Death_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ACrowBoss_Death()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACrowBoss_Death_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACrowBoss::execDeath)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Death();
	P_NATIVE_END;
}
// End Class ACrowBoss Function Death

// Begin Class ACrowBoss Function FeatherAttack
struct Z_Construct_UFunction_ACrowBoss_FeatherAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CrowBoss.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACrowBoss_FeatherAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACrowBoss, nullptr, "FeatherAttack", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_FeatherAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACrowBoss_FeatherAttack_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ACrowBoss_FeatherAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACrowBoss_FeatherAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACrowBoss::execFeatherAttack)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FeatherAttack();
	P_NATIVE_END;
}
// End Class ACrowBoss Function FeatherAttack

// Begin Class ACrowBoss Function GetAttackTarget
struct Z_Construct_UFunction_ACrowBoss_GetAttackTarget_Statics
{
	struct CrowBoss_eventGetAttackTarget_Parms
	{
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//AttackTarget\n" },
#endif
		{ "ModuleRelativePath", "Public/CrowBoss.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AttackTarget" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACrowBoss_GetAttackTarget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CrowBoss_eventGetAttackTarget_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACrowBoss_GetAttackTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACrowBoss_GetAttackTarget_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_GetAttackTarget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACrowBoss_GetAttackTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACrowBoss, nullptr, "GetAttackTarget", nullptr, nullptr, Z_Construct_UFunction_ACrowBoss_GetAttackTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_GetAttackTarget_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACrowBoss_GetAttackTarget_Statics::CrowBoss_eventGetAttackTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_GetAttackTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACrowBoss_GetAttackTarget_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACrowBoss_GetAttackTarget_Statics::CrowBoss_eventGetAttackTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACrowBoss_GetAttackTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACrowBoss_GetAttackTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACrowBoss::execGetAttackTarget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetAttackTarget();
	P_NATIVE_END;
}
// End Class ACrowBoss Function GetAttackTarget

// Begin Class ACrowBoss Function GetHealth
struct Z_Construct_UFunction_ACrowBoss_GetHealth_Statics
{
	struct CrowBoss_eventGetHealth_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Getters and setters\n//Health\n" },
#endif
		{ "ModuleRelativePath", "Public/CrowBoss.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Getters and setters\nHealth" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ACrowBoss_GetHealth_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CrowBoss_eventGetHealth_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACrowBoss_GetHealth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACrowBoss_GetHealth_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_GetHealth_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACrowBoss_GetHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACrowBoss, nullptr, "GetHealth", nullptr, nullptr, Z_Construct_UFunction_ACrowBoss_GetHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_GetHealth_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACrowBoss_GetHealth_Statics::CrowBoss_eventGetHealth_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_GetHealth_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACrowBoss_GetHealth_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACrowBoss_GetHealth_Statics::CrowBoss_eventGetHealth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACrowBoss_GetHealth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACrowBoss_GetHealth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACrowBoss::execGetHealth)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetHealth();
	P_NATIVE_END;
}
// End Class ACrowBoss Function GetHealth

// Begin Class ACrowBoss Function GetStamina
struct Z_Construct_UFunction_ACrowBoss_GetStamina_Statics
{
	struct CrowBoss_eventGetStamina_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Stamina\n" },
#endif
		{ "ModuleRelativePath", "Public/CrowBoss.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stamina" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ACrowBoss_GetStamina_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CrowBoss_eventGetStamina_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACrowBoss_GetStamina_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACrowBoss_GetStamina_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_GetStamina_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACrowBoss_GetStamina_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACrowBoss, nullptr, "GetStamina", nullptr, nullptr, Z_Construct_UFunction_ACrowBoss_GetStamina_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_GetStamina_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACrowBoss_GetStamina_Statics::CrowBoss_eventGetStamina_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_GetStamina_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACrowBoss_GetStamina_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACrowBoss_GetStamina_Statics::CrowBoss_eventGetStamina_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACrowBoss_GetStamina()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACrowBoss_GetStamina_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACrowBoss::execGetStamina)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetStamina();
	P_NATIVE_END;
}
// End Class ACrowBoss Function GetStamina

// Begin Class ACrowBoss Function MeleeAttack
struct Z_Construct_UFunction_ACrowBoss_MeleeAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CrowBoss.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACrowBoss_MeleeAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACrowBoss, nullptr, "MeleeAttack", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_MeleeAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACrowBoss_MeleeAttack_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ACrowBoss_MeleeAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACrowBoss_MeleeAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACrowBoss::execMeleeAttack)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->MeleeAttack();
	P_NATIVE_END;
}
// End Class ACrowBoss Function MeleeAttack

// Begin Class ACrowBoss Function SetAttackTarget
struct Z_Construct_UFunction_ACrowBoss_SetAttackTarget_Statics
{
	struct CrowBoss_eventSetAttackTarget_Parms
	{
		AActor* newtarget;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CrowBoss.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_newtarget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACrowBoss_SetAttackTarget_Statics::NewProp_newtarget = { "newtarget", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CrowBoss_eventSetAttackTarget_Parms, newtarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACrowBoss_SetAttackTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACrowBoss_SetAttackTarget_Statics::NewProp_newtarget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_SetAttackTarget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACrowBoss_SetAttackTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACrowBoss, nullptr, "SetAttackTarget", nullptr, nullptr, Z_Construct_UFunction_ACrowBoss_SetAttackTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_SetAttackTarget_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACrowBoss_SetAttackTarget_Statics::CrowBoss_eventSetAttackTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_SetAttackTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACrowBoss_SetAttackTarget_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACrowBoss_SetAttackTarget_Statics::CrowBoss_eventSetAttackTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACrowBoss_SetAttackTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACrowBoss_SetAttackTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACrowBoss::execSetAttackTarget)
{
	P_GET_OBJECT(AActor,Z_Param_newtarget);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAttackTarget(Z_Param_newtarget);
	P_NATIVE_END;
}
// End Class ACrowBoss Function SetAttackTarget

// Begin Class ACrowBoss Function SetHealth
struct Z_Construct_UFunction_ACrowBoss_SetHealth_Statics
{
	struct CrowBoss_eventSetHealth_Parms
	{
		int32 newHealth;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CrowBoss.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_newHealth;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ACrowBoss_SetHealth_Statics::NewProp_newHealth = { "newHealth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CrowBoss_eventSetHealth_Parms, newHealth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACrowBoss_SetHealth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACrowBoss_SetHealth_Statics::NewProp_newHealth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_SetHealth_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACrowBoss_SetHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACrowBoss, nullptr, "SetHealth", nullptr, nullptr, Z_Construct_UFunction_ACrowBoss_SetHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_SetHealth_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACrowBoss_SetHealth_Statics::CrowBoss_eventSetHealth_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_SetHealth_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACrowBoss_SetHealth_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACrowBoss_SetHealth_Statics::CrowBoss_eventSetHealth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACrowBoss_SetHealth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACrowBoss_SetHealth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACrowBoss::execSetHealth)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_newHealth);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetHealth(Z_Param_newHealth);
	P_NATIVE_END;
}
// End Class ACrowBoss Function SetHealth

// Begin Class ACrowBoss Function SetStamina
struct Z_Construct_UFunction_ACrowBoss_SetStamina_Statics
{
	struct CrowBoss_eventSetStamina_Parms
	{
		float newstamina;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CrowBoss.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_newstamina;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ACrowBoss_SetStamina_Statics::NewProp_newstamina = { "newstamina", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CrowBoss_eventSetStamina_Parms, newstamina), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACrowBoss_SetStamina_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACrowBoss_SetStamina_Statics::NewProp_newstamina,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_SetStamina_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACrowBoss_SetStamina_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACrowBoss, nullptr, "SetStamina", nullptr, nullptr, Z_Construct_UFunction_ACrowBoss_SetStamina_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_SetStamina_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACrowBoss_SetStamina_Statics::CrowBoss_eventSetStamina_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_SetStamina_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACrowBoss_SetStamina_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACrowBoss_SetStamina_Statics::CrowBoss_eventSetStamina_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACrowBoss_SetStamina()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACrowBoss_SetStamina_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACrowBoss::execSetStamina)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_newstamina);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetStamina(Z_Param_newstamina);
	P_NATIVE_END;
}
// End Class ACrowBoss Function SetStamina

// Begin Class ACrowBoss Function SpecialAttack
struct Z_Construct_UFunction_ACrowBoss_SpecialAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CrowBoss.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACrowBoss_SpecialAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACrowBoss, nullptr, "SpecialAttack", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_SpecialAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACrowBoss_SpecialAttack_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ACrowBoss_SpecialAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACrowBoss_SpecialAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACrowBoss::execSpecialAttack)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpecialAttack();
	P_NATIVE_END;
}
// End Class ACrowBoss Function SpecialAttack

// Begin Class ACrowBoss
void ACrowBoss::StaticRegisterNativesACrowBoss()
{
	UClass* Class = ACrowBoss::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Collision", &ACrowBoss::execCollision },
		{ "Death", &ACrowBoss::execDeath },
		{ "FeatherAttack", &ACrowBoss::execFeatherAttack },
		{ "GetAttackTarget", &ACrowBoss::execGetAttackTarget },
		{ "GetHealth", &ACrowBoss::execGetHealth },
		{ "GetStamina", &ACrowBoss::execGetStamina },
		{ "MeleeAttack", &ACrowBoss::execMeleeAttack },
		{ "SetAttackTarget", &ACrowBoss::execSetAttackTarget },
		{ "SetHealth", &ACrowBoss::execSetHealth },
		{ "SetStamina", &ACrowBoss::execSetStamina },
		{ "SpecialAttack", &ACrowBoss::execSpecialAttack },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACrowBoss);
UClass* Z_Construct_UClass_ACrowBoss_NoRegister()
{
	return ACrowBoss::StaticClass();
}
struct Z_Construct_UClass_ACrowBoss_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "CrowBoss.h" },
		{ "ModuleRelativePath", "Public/CrowBoss.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[] = {
		{ "ModuleRelativePath", "Public/CrowBoss.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovementSpeed_MetaData[] = {
		{ "ModuleRelativePath", "Public/CrowBoss.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackDamage_MetaData[] = {
		{ "ModuleRelativePath", "Public/CrowBoss.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Stamina_MetaData[] = {
		{ "ModuleRelativePath", "Public/CrowBoss.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "ModuleRelativePath", "Public/CrowBoss.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Health;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MovementSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackDamage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Stamina;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ACrowBoss_Collision, "Collision" }, // 3645622983
		{ &Z_Construct_UFunction_ACrowBoss_Death, "Death" }, // 954907251
		{ &Z_Construct_UFunction_ACrowBoss_FeatherAttack, "FeatherAttack" }, // 1829571562
		{ &Z_Construct_UFunction_ACrowBoss_GetAttackTarget, "GetAttackTarget" }, // 3252934748
		{ &Z_Construct_UFunction_ACrowBoss_GetHealth, "GetHealth" }, // 3288902430
		{ &Z_Construct_UFunction_ACrowBoss_GetStamina, "GetStamina" }, // 1204102312
		{ &Z_Construct_UFunction_ACrowBoss_MeleeAttack, "MeleeAttack" }, // 3856112775
		{ &Z_Construct_UFunction_ACrowBoss_SetAttackTarget, "SetAttackTarget" }, // 1667406052
		{ &Z_Construct_UFunction_ACrowBoss_SetHealth, "SetHealth" }, // 4246206456
		{ &Z_Construct_UFunction_ACrowBoss_SetStamina, "SetStamina" }, // 618671020
		{ &Z_Construct_UFunction_ACrowBoss_SpecialAttack, "SpecialAttack" }, // 1261300828
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACrowBoss>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ACrowBoss_Statics::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACrowBoss, Health), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Health_MetaData), NewProp_Health_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACrowBoss_Statics::NewProp_MovementSpeed = { "MovementSpeed", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACrowBoss, MovementSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovementSpeed_MetaData), NewProp_MovementSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACrowBoss_Statics::NewProp_AttackDamage = { "AttackDamage", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACrowBoss, AttackDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackDamage_MetaData), NewProp_AttackDamage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACrowBoss_Statics::NewProp_Stamina = { "Stamina", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACrowBoss, Stamina), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Stamina_MetaData), NewProp_Stamina_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACrowBoss_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACrowBoss, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACrowBoss_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowBoss_Statics::NewProp_Health,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowBoss_Statics::NewProp_MovementSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowBoss_Statics::NewProp_AttackDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowBoss_Statics::NewProp_Stamina,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowBoss_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACrowBoss_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACrowBoss_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACrowBoss_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACrowBoss_Statics::ClassParams = {
	&ACrowBoss::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ACrowBoss_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ACrowBoss_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACrowBoss_Statics::Class_MetaDataParams), Z_Construct_UClass_ACrowBoss_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACrowBoss()
{
	if (!Z_Registration_Info_UClass_ACrowBoss.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACrowBoss.OuterSingleton, Z_Construct_UClass_ACrowBoss_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACrowBoss.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<ACrowBoss>()
{
	return ACrowBoss::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACrowBoss);
ACrowBoss::~ACrowBoss() {}
// End Class ACrowBoss

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowBoss_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACrowBoss, ACrowBoss::StaticClass, TEXT("ACrowBoss"), &Z_Registration_Info_UClass_ACrowBoss, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACrowBoss), 2220190915U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowBoss_h_957867169(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowBoss_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowBoss_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
