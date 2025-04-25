// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Enemies/CrowTask_MeleeAttack.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCrowTask_MeleeAttack() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UCrowTask_MeleeAttack();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UCrowTask_MeleeAttack_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UCrowTask_MeleeAttack
void UCrowTask_MeleeAttack::StaticRegisterNativesUCrowTask_MeleeAttack()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCrowTask_MeleeAttack);
UClass* Z_Construct_UClass_UCrowTask_MeleeAttack_NoRegister()
{
	return UCrowTask_MeleeAttack::StaticClass();
}
struct Z_Construct_UClass_UCrowTask_MeleeAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Enemies/CrowTask_MeleeAttack.h" },
		{ "ModuleRelativePath", "Public/Enemies/CrowTask_MeleeAttack.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCrowTask_MeleeAttack>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCrowTask_MeleeAttack_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCrowTask_MeleeAttack_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCrowTask_MeleeAttack_Statics::ClassParams = {
	&UCrowTask_MeleeAttack::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCrowTask_MeleeAttack_Statics::Class_MetaDataParams), Z_Construct_UClass_UCrowTask_MeleeAttack_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCrowTask_MeleeAttack()
{
	if (!Z_Registration_Info_UClass_UCrowTask_MeleeAttack.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCrowTask_MeleeAttack.OuterSingleton, Z_Construct_UClass_UCrowTask_MeleeAttack_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCrowTask_MeleeAttack.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UCrowTask_MeleeAttack>()
{
	return UCrowTask_MeleeAttack::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCrowTask_MeleeAttack);
UCrowTask_MeleeAttack::~UCrowTask_MeleeAttack() {}
// End Class UCrowTask_MeleeAttack

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowTask_MeleeAttack_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCrowTask_MeleeAttack, UCrowTask_MeleeAttack::StaticClass, TEXT("UCrowTask_MeleeAttack"), &Z_Registration_Info_UClass_UCrowTask_MeleeAttack, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCrowTask_MeleeAttack), 3880831048U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowTask_MeleeAttack_h_4049899113(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowTask_MeleeAttack_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowTask_MeleeAttack_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
