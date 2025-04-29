// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Player/GAS_Dash.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGAS_Dash() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UGAS_Dash();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UGAS_Dash_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UGAS_Dash
void UGAS_Dash::StaticRegisterNativesUGAS_Dash()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGAS_Dash);
UClass* Z_Construct_UClass_UGAS_Dash_NoRegister()
{
	return UGAS_Dash::StaticClass();
}
struct Z_Construct_UClass_UGAS_Dash_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Player/GAS_Dash.h" },
		{ "ModuleRelativePath", "Public/Player/GAS_Dash.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGAS_Dash>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UGAS_Dash_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameplayAbility,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGAS_Dash_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGAS_Dash_Statics::ClassParams = {
	&UGAS_Dash::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGAS_Dash_Statics::Class_MetaDataParams), Z_Construct_UClass_UGAS_Dash_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGAS_Dash()
{
	if (!Z_Registration_Info_UClass_UGAS_Dash.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGAS_Dash.OuterSingleton, Z_Construct_UClass_UGAS_Dash_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGAS_Dash.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UGAS_Dash>()
{
	return UGAS_Dash::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGAS_Dash);
UGAS_Dash::~UGAS_Dash() {}
// End Class UGAS_Dash

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_GAS_Dash_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGAS_Dash, UGAS_Dash::StaticClass, TEXT("UGAS_Dash"), &Z_Registration_Info_UClass_UGAS_Dash, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGAS_Dash), 3467796411U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_GAS_Dash_h_3937503283(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_GAS_Dash_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_GAS_Dash_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
