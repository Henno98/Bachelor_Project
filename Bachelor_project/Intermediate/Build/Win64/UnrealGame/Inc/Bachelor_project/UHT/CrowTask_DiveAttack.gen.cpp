// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Enemies/CrowTask_DiveAttack.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCrowTask_DiveAttack() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
AIMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FBlackboardKeySelector();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UCrowTask_DiveAttack();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UCrowTask_DiveAttack_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UCrowTask_DiveAttack
void UCrowTask_DiveAttack::StaticRegisterNativesUCrowTask_DiveAttack()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCrowTask_DiveAttack);
UClass* Z_Construct_UClass_UCrowTask_DiveAttack_NoRegister()
{
	return UCrowTask_DiveAttack::StaticClass();
}
struct Z_Construct_UClass_UCrowTask_DiveAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Enemies/CrowTask_DiveAttack.h" },
		{ "ModuleRelativePath", "Public/Enemies/CrowTask_DiveAttack.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetLocationKey_MetaData[] = {
		{ "Category", "Blackboard" },
		{ "ModuleRelativePath", "Public/Enemies/CrowTask_DiveAttack.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DiveSpeed_MetaData[] = {
		{ "Category", "Dive" },
		{ "ModuleRelativePath", "Public/Enemies/CrowTask_DiveAttack.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GroundZ_MetaData[] = {
		{ "Category", "Dive" },
		{ "ModuleRelativePath", "Public/Enemies/CrowTask_DiveAttack.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetLocationKey;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DiveSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GroundZ;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCrowTask_DiveAttack>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCrowTask_DiveAttack_Statics::NewProp_TargetLocationKey = { "TargetLocationKey", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCrowTask_DiveAttack, TargetLocationKey), Z_Construct_UScriptStruct_FBlackboardKeySelector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetLocationKey_MetaData), NewProp_TargetLocationKey_MetaData) }; // 3940742986
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCrowTask_DiveAttack_Statics::NewProp_DiveSpeed = { "DiveSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCrowTask_DiveAttack, DiveSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DiveSpeed_MetaData), NewProp_DiveSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCrowTask_DiveAttack_Statics::NewProp_GroundZ = { "GroundZ", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCrowTask_DiveAttack, GroundZ), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GroundZ_MetaData), NewProp_GroundZ_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCrowTask_DiveAttack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCrowTask_DiveAttack_Statics::NewProp_TargetLocationKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCrowTask_DiveAttack_Statics::NewProp_DiveSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCrowTask_DiveAttack_Statics::NewProp_GroundZ,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCrowTask_DiveAttack_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCrowTask_DiveAttack_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCrowTask_DiveAttack_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCrowTask_DiveAttack_Statics::ClassParams = {
	&UCrowTask_DiveAttack::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCrowTask_DiveAttack_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCrowTask_DiveAttack_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCrowTask_DiveAttack_Statics::Class_MetaDataParams), Z_Construct_UClass_UCrowTask_DiveAttack_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCrowTask_DiveAttack()
{
	if (!Z_Registration_Info_UClass_UCrowTask_DiveAttack.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCrowTask_DiveAttack.OuterSingleton, Z_Construct_UClass_UCrowTask_DiveAttack_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCrowTask_DiveAttack.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UCrowTask_DiveAttack>()
{
	return UCrowTask_DiveAttack::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCrowTask_DiveAttack);
UCrowTask_DiveAttack::~UCrowTask_DiveAttack() {}
// End Class UCrowTask_DiveAttack

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowTask_DiveAttack_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCrowTask_DiveAttack, UCrowTask_DiveAttack::StaticClass, TEXT("UCrowTask_DiveAttack"), &Z_Registration_Info_UClass_UCrowTask_DiveAttack, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCrowTask_DiveAttack), 2562450315U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowTask_DiveAttack_h_829700343(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowTask_DiveAttack_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowTask_DiveAttack_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
