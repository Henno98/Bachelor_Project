// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/GAS_Ranged_Attack.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGAS_Ranged_Attack() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UGAS_Ranged_Attack();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UGAS_Ranged_Attack_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UGAS_Ranged_Attack
void UGAS_Ranged_Attack::StaticRegisterNativesUGAS_Ranged_Attack()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGAS_Ranged_Attack);
UClass* Z_Construct_UClass_UGAS_Ranged_Attack_NoRegister()
{
	return UGAS_Ranged_Attack::StaticClass();
}
struct Z_Construct_UClass_UGAS_Ranged_Attack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "GAS_Ranged_Attack.h" },
		{ "ModuleRelativePath", "Public/GAS_Ranged_Attack.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGAS_Ranged_Attack>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UGAS_Ranged_Attack_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameplayAbility,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGAS_Ranged_Attack_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGAS_Ranged_Attack_Statics::ClassParams = {
	&UGAS_Ranged_Attack::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGAS_Ranged_Attack_Statics::Class_MetaDataParams), Z_Construct_UClass_UGAS_Ranged_Attack_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGAS_Ranged_Attack()
{
	if (!Z_Registration_Info_UClass_UGAS_Ranged_Attack.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGAS_Ranged_Attack.OuterSingleton, Z_Construct_UClass_UGAS_Ranged_Attack_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGAS_Ranged_Attack.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UGAS_Ranged_Attack>()
{
	return UGAS_Ranged_Attack::StaticClass();
}
UGAS_Ranged_Attack::UGAS_Ranged_Attack(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGAS_Ranged_Attack);
UGAS_Ranged_Attack::~UGAS_Ranged_Attack() {}
// End Class UGAS_Ranged_Attack

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_GAS_Ranged_Attack_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGAS_Ranged_Attack, UGAS_Ranged_Attack::StaticClass, TEXT("UGAS_Ranged_Attack"), &Z_Registration_Info_UClass_UGAS_Ranged_Attack, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGAS_Ranged_Attack), 917152388U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_GAS_Ranged_Attack_h_514053410(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_GAS_Ranged_Attack_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_GAS_Ranged_Attack_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
