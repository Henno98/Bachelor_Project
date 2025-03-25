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
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayEffect_NoRegister();
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
		{ "IncludePath", "GAS_Ranged_Attack.h" },
		{ "ModuleRelativePath", "Public/GAS_Ranged_Attack.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CooldownGameplayEffect_MetaData[] = {
		{ "Category", "Ability" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Cooldown effect applied when ability is used\n" },
#endif
		{ "ModuleRelativePath", "Public/GAS_Ranged_Attack.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cooldown effect applied when ability is used" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_CooldownGameplayEffect;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGAS_Ranged_Attack>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UGAS_Ranged_Attack_Statics::NewProp_CooldownGameplayEffect = { "CooldownGameplayEffect", nullptr, (EPropertyFlags)0x0024080000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGAS_Ranged_Attack, CooldownGameplayEffect), Z_Construct_UClass_UClass, Z_Construct_UClass_UGameplayEffect_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CooldownGameplayEffect_MetaData), NewProp_CooldownGameplayEffect_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGAS_Ranged_Attack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGAS_Ranged_Attack_Statics::NewProp_CooldownGameplayEffect,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGAS_Ranged_Attack_Statics::PropPointers) < 2048);
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
	Z_Construct_UClass_UGAS_Ranged_Attack_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UGAS_Ranged_Attack_Statics::PropPointers),
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
DEFINE_VTABLE_PTR_HELPER_CTOR(UGAS_Ranged_Attack);
UGAS_Ranged_Attack::~UGAS_Ranged_Attack() {}
// End Class UGAS_Ranged_Attack

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_GAS_Ranged_Attack_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGAS_Ranged_Attack, UGAS_Ranged_Attack::StaticClass, TEXT("UGAS_Ranged_Attack"), &Z_Registration_Info_UClass_UGAS_Ranged_Attack, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGAS_Ranged_Attack), 1875105676U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_GAS_Ranged_Attack_h_2155247767(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_GAS_Ranged_Attack_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_GAS_Ranged_Attack_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
