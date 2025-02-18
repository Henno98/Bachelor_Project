// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/GAS_PlayerState.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGAS_PlayerState() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_AGAS_PlayerState();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_AGAS_PlayerState_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerState();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemInterface_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class AGAS_PlayerState
void AGAS_PlayerState::StaticRegisterNativesAGAS_PlayerState()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGAS_PlayerState);
UClass* Z_Construct_UClass_AGAS_PlayerState_NoRegister()
{
	return AGAS_PlayerState::StaticClass();
}
struct Z_Construct_UClass_AGAS_PlayerState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GAS_PlayerState.h" },
		{ "ModuleRelativePath", "Public/GAS_PlayerState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGAS_PlayerState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AGAS_PlayerState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerState,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGAS_PlayerState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AGAS_PlayerState_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UAbilitySystemInterface_NoRegister, (int32)VTABLE_OFFSET(AGAS_PlayerState, IAbilitySystemInterface), false },  // 2272790346
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGAS_PlayerState_Statics::ClassParams = {
	&AGAS_PlayerState::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	UE_ARRAY_COUNT(InterfaceParams),
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGAS_PlayerState_Statics::Class_MetaDataParams), Z_Construct_UClass_AGAS_PlayerState_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGAS_PlayerState()
{
	if (!Z_Registration_Info_UClass_AGAS_PlayerState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGAS_PlayerState.OuterSingleton, Z_Construct_UClass_AGAS_PlayerState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGAS_PlayerState.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<AGAS_PlayerState>()
{
	return AGAS_PlayerState::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGAS_PlayerState);
AGAS_PlayerState::~AGAS_PlayerState() {}
// End Class AGAS_PlayerState

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_GAS_PlayerState_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGAS_PlayerState, AGAS_PlayerState::StaticClass, TEXT("AGAS_PlayerState"), &Z_Registration_Info_UClass_AGAS_PlayerState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGAS_PlayerState), 469054284U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_GAS_PlayerState_h_3830253972(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_GAS_PlayerState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_GAS_PlayerState_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
