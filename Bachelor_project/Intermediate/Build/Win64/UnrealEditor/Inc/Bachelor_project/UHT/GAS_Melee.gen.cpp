// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Player/GAS_Melee.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGAS_Melee() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UGAS_Melee();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UGAS_Melee_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UGAS_Melee
void UGAS_Melee::StaticRegisterNativesUGAS_Melee()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGAS_Melee);
UClass* Z_Construct_UClass_UGAS_Melee_NoRegister()
{
	return UGAS_Melee::StaticClass();
}
struct Z_Construct_UClass_UGAS_Melee_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Player/GAS_Melee.h" },
		{ "ModuleRelativePath", "Public/Player/GAS_Melee.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGAS_Melee>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UGAS_Melee_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameplayAbility,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGAS_Melee_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGAS_Melee_Statics::ClassParams = {
	&UGAS_Melee::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGAS_Melee_Statics::Class_MetaDataParams), Z_Construct_UClass_UGAS_Melee_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UGAS_Melee()
{
	if (!Z_Registration_Info_UClass_UGAS_Melee.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGAS_Melee.OuterSingleton, Z_Construct_UClass_UGAS_Melee_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGAS_Melee.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UGAS_Melee>()
{
	return UGAS_Melee::StaticClass();
}
UGAS_Melee::UGAS_Melee(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UGAS_Melee);
UGAS_Melee::~UGAS_Melee() {}
// End Class UGAS_Melee

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_GAS_Melee_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGAS_Melee, UGAS_Melee::StaticClass, TEXT("UGAS_Melee"), &Z_Registration_Info_UClass_UGAS_Melee, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGAS_Melee), 258392916U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_GAS_Melee_h_3973867894(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_GAS_Melee_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_GAS_Melee_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
