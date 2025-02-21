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
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UGAS_Double_Jump_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpAbility_MetaData[] = {
		{ "ModuleRelativePath", "Public/GAS_PlayerState.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_JumpAbility;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGAS_PlayerState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AGAS_PlayerState_Statics::NewProp_JumpAbility = { "JumpAbility", nullptr, (EPropertyFlags)0x0014000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGAS_PlayerState, JumpAbility), Z_Construct_UClass_UClass, Z_Construct_UClass_UGAS_Double_Jump_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAbility_MetaData), NewProp_JumpAbility_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGAS_PlayerState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGAS_PlayerState_Statics::NewProp_JumpAbility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGAS_PlayerState_Statics::PropPointers) < 2048);
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
	Z_Construct_UClass_AGAS_PlayerState_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AGAS_PlayerState_Statics::PropPointers),
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
		{ Z_Construct_UClass_AGAS_PlayerState, AGAS_PlayerState::StaticClass, TEXT("AGAS_PlayerState"), &Z_Registration_Info_UClass_AGAS_PlayerState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGAS_PlayerState), 1624063117U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_GAS_PlayerState_h_448001025(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_GAS_PlayerState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_GAS_PlayerState_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
