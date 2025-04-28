// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Player/GAS_Wall_Latch.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGAS_Wall_Latch() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UGAS_Wall_Latch();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UGAS_Wall_Latch_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UGAS_Wall_Latch
void UGAS_Wall_Latch::StaticRegisterNativesUGAS_Wall_Latch()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGAS_Wall_Latch);
UClass* Z_Construct_UClass_UGAS_Wall_Latch_NoRegister()
{
	return UGAS_Wall_Latch::StaticClass();
}
struct Z_Construct_UClass_UGAS_Wall_Latch_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Player/GAS_Wall_Latch.h" },
		{ "ModuleRelativePath", "Public/Player/GAS_Wall_Latch.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGAS_Wall_Latch>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UGAS_Wall_Latch_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameplayAbility,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGAS_Wall_Latch_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGAS_Wall_Latch_Statics::ClassParams = {
	&UGAS_Wall_Latch::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGAS_Wall_Latch_Statics::Class_MetaDataParams), Z_Construct_UClass_UGAS_Wall_Latch_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGAS_Wall_Latch()
{
	if (!Z_Registration_Info_UClass_UGAS_Wall_Latch.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGAS_Wall_Latch.OuterSingleton, Z_Construct_UClass_UGAS_Wall_Latch_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGAS_Wall_Latch.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UGAS_Wall_Latch>()
{
	return UGAS_Wall_Latch::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGAS_Wall_Latch);
UGAS_Wall_Latch::~UGAS_Wall_Latch() {}
// End Class UGAS_Wall_Latch

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_GAS_Wall_Latch_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGAS_Wall_Latch, UGAS_Wall_Latch::StaticClass, TEXT("UGAS_Wall_Latch"), &Z_Registration_Info_UClass_UGAS_Wall_Latch, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGAS_Wall_Latch), 3946962976U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_GAS_Wall_Latch_h_838452850(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_GAS_Wall_Latch_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_GAS_Wall_Latch_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
