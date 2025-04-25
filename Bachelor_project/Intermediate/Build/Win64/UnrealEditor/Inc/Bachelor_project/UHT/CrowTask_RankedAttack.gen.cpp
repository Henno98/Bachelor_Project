// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/CrowTask_RankedAttack.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCrowTask_RankedAttack() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTNode();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UCrowTask_RankedAttack();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UCrowTask_RankedAttack_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UCrowTask_RankedAttack
void UCrowTask_RankedAttack::StaticRegisterNativesUCrowTask_RankedAttack()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCrowTask_RankedAttack);
UClass* Z_Construct_UClass_UCrowTask_RankedAttack_NoRegister()
{
	return UCrowTask_RankedAttack::StaticClass();
}
struct Z_Construct_UClass_UCrowTask_RankedAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "CrowTask_RankedAttack.h" },
		{ "ModuleRelativePath", "Public/CrowTask_RankedAttack.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCrowTask_RankedAttack>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCrowTask_RankedAttack_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTNode,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCrowTask_RankedAttack_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCrowTask_RankedAttack_Statics::ClassParams = {
	&UCrowTask_RankedAttack::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCrowTask_RankedAttack_Statics::Class_MetaDataParams), Z_Construct_UClass_UCrowTask_RankedAttack_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCrowTask_RankedAttack()
{
	if (!Z_Registration_Info_UClass_UCrowTask_RankedAttack.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCrowTask_RankedAttack.OuterSingleton, Z_Construct_UClass_UCrowTask_RankedAttack_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCrowTask_RankedAttack.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UCrowTask_RankedAttack>()
{
	return UCrowTask_RankedAttack::StaticClass();
}
UCrowTask_RankedAttack::UCrowTask_RankedAttack(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCrowTask_RankedAttack);
UCrowTask_RankedAttack::~UCrowTask_RankedAttack() {}
// End Class UCrowTask_RankedAttack

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowTask_RankedAttack_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCrowTask_RankedAttack, UCrowTask_RankedAttack::StaticClass, TEXT("UCrowTask_RankedAttack"), &Z_Registration_Info_UClass_UCrowTask_RankedAttack, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCrowTask_RankedAttack), 3726472958U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowTask_RankedAttack_h_587164569(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowTask_RankedAttack_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowTask_RankedAttack_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
