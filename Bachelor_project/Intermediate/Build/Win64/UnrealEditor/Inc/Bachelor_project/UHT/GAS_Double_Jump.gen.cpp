// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/GAS_Double_Jump.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGAS_Double_Jump() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UGAS_Double_Jump();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UGAS_Double_Jump_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UGAS_Double_Jump
void UGAS_Double_Jump::StaticRegisterNativesUGAS_Double_Jump()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGAS_Double_Jump);
UClass* Z_Construct_UClass_UGAS_Double_Jump_NoRegister()
{
	return UGAS_Double_Jump::StaticClass();
}
struct Z_Construct_UClass_UGAS_Double_Jump_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "GAS_Double_Jump.h" },
		{ "ModuleRelativePath", "Public/GAS_Double_Jump.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGAS_Double_Jump>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UGAS_Double_Jump_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameplayAbility,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGAS_Double_Jump_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGAS_Double_Jump_Statics::ClassParams = {
	&UGAS_Double_Jump::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGAS_Double_Jump_Statics::Class_MetaDataParams), Z_Construct_UClass_UGAS_Double_Jump_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGAS_Double_Jump()
{
	if (!Z_Registration_Info_UClass_UGAS_Double_Jump.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGAS_Double_Jump.OuterSingleton, Z_Construct_UClass_UGAS_Double_Jump_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGAS_Double_Jump.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UGAS_Double_Jump>()
{
	return UGAS_Double_Jump::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGAS_Double_Jump);
UGAS_Double_Jump::~UGAS_Double_Jump() {}
// End Class UGAS_Double_Jump

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_GAS_Double_Jump_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGAS_Double_Jump, UGAS_Double_Jump::StaticClass, TEXT("UGAS_Double_Jump"), &Z_Registration_Info_UClass_UGAS_Double_Jump, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGAS_Double_Jump), 1658724324U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_GAS_Double_Jump_h_2594121344(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_GAS_Double_Jump_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_GAS_Double_Jump_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
