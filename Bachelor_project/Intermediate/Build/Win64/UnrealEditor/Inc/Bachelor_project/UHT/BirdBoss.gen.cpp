// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Enemies/BirdBoss.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBirdBoss() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ABirdBoss();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ABirdBoss_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class ABirdBoss
void ABirdBoss::StaticRegisterNativesABirdBoss()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABirdBoss);
UClass* Z_Construct_UClass_ABirdBoss_NoRegister()
{
	return ABirdBoss::StaticClass();
}
struct Z_Construct_UClass_ABirdBoss_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Enemies/BirdBoss.h" },
		{ "ModuleRelativePath", "Public/Enemies/BirdBoss.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackRange_MetaData[] = {
		{ "Category", "AttackRange" },
		{ "ModuleRelativePath", "Public/Enemies/BirdBoss.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackRange;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABirdBoss>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABirdBoss_Statics::NewProp_AttackRange = { "AttackRange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABirdBoss, AttackRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackRange_MetaData), NewProp_AttackRange_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABirdBoss_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABirdBoss_Statics::NewProp_AttackRange,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABirdBoss_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABirdBoss_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABirdBoss_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABirdBoss_Statics::ClassParams = {
	&ABirdBoss::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ABirdBoss_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ABirdBoss_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABirdBoss_Statics::Class_MetaDataParams), Z_Construct_UClass_ABirdBoss_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABirdBoss()
{
	if (!Z_Registration_Info_UClass_ABirdBoss.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABirdBoss.OuterSingleton, Z_Construct_UClass_ABirdBoss_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABirdBoss.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<ABirdBoss>()
{
	return ABirdBoss::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABirdBoss);
ABirdBoss::~ABirdBoss() {}
// End Class ABirdBoss

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_BirdBoss_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABirdBoss, ABirdBoss::StaticClass, TEXT("ABirdBoss"), &Z_Registration_Info_UClass_ABirdBoss, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABirdBoss), 2932543430U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_BirdBoss_h_958134655(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_BirdBoss_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_BirdBoss_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
