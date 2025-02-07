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
		{ "MeleeAttack", &ACrowBoss::execMeleeAttack },
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
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Health;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MovementSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackDamage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Stamina;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ACrowBoss_Collision, "Collision" }, // 3645622983
		{ &Z_Construct_UFunction_ACrowBoss_Death, "Death" }, // 954907251
		{ &Z_Construct_UFunction_ACrowBoss_FeatherAttack, "FeatherAttack" }, // 1829571562
		{ &Z_Construct_UFunction_ACrowBoss_MeleeAttack, "MeleeAttack" }, // 3856112775
		{ &Z_Construct_UFunction_ACrowBoss_SpecialAttack, "SpecialAttack" }, // 1261300828
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACrowBoss>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACrowBoss_Statics::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACrowBoss, Health), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Health_MetaData), NewProp_Health_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACrowBoss_Statics::NewProp_MovementSpeed = { "MovementSpeed", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACrowBoss, MovementSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovementSpeed_MetaData), NewProp_MovementSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACrowBoss_Statics::NewProp_AttackDamage = { "AttackDamage", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACrowBoss, AttackDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackDamage_MetaData), NewProp_AttackDamage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACrowBoss_Statics::NewProp_Stamina = { "Stamina", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACrowBoss, Stamina), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Stamina_MetaData), NewProp_Stamina_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACrowBoss_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowBoss_Statics::NewProp_Health,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowBoss_Statics::NewProp_MovementSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowBoss_Statics::NewProp_AttackDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowBoss_Statics::NewProp_Stamina,
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
		{ Z_Construct_UClass_ACrowBoss, ACrowBoss::StaticClass, TEXT("ACrowBoss"), &Z_Registration_Info_UClass_ACrowBoss, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACrowBoss), 906079142U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowBoss_h_1693233655(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowBoss_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowBoss_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
