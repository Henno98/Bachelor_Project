// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Power_WallLatch.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePower_WallLatch() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UPower_WallLatch();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UPower_WallLatch_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UPowerUpController();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UPower_WallLatch
void UPower_WallLatch::StaticRegisterNativesUPower_WallLatch()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPower_WallLatch);
UClass* Z_Construct_UClass_UPower_WallLatch_NoRegister()
{
	return UPower_WallLatch::StaticClass();
}
struct Z_Construct_UClass_UPower_WallLatch_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Power_WallLatch.h" },
		{ "ModuleRelativePath", "Public/Power_WallLatch.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallCheckDistance_MetaData[] = {
		{ "ModuleRelativePath", "Public/Power_WallLatch.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WallCheckDistance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPower_WallLatch>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPower_WallLatch_Statics::NewProp_WallCheckDistance = { "WallCheckDistance", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPower_WallLatch, WallCheckDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallCheckDistance_MetaData), NewProp_WallCheckDistance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPower_WallLatch_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPower_WallLatch_Statics::NewProp_WallCheckDistance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPower_WallLatch_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UPower_WallLatch_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPowerUpController,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPower_WallLatch_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPower_WallLatch_Statics::ClassParams = {
	&UPower_WallLatch::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UPower_WallLatch_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UPower_WallLatch_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPower_WallLatch_Statics::Class_MetaDataParams), Z_Construct_UClass_UPower_WallLatch_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPower_WallLatch()
{
	if (!Z_Registration_Info_UClass_UPower_WallLatch.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPower_WallLatch.OuterSingleton, Z_Construct_UClass_UPower_WallLatch_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPower_WallLatch.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UPower_WallLatch>()
{
	return UPower_WallLatch::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPower_WallLatch);
UPower_WallLatch::~UPower_WallLatch() {}
// End Class UPower_WallLatch

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Power_WallLatch_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPower_WallLatch, UPower_WallLatch::StaticClass, TEXT("UPower_WallLatch"), &Z_Registration_Info_UClass_UPower_WallLatch, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPower_WallLatch), 690420167U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Power_WallLatch_h_665643638(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Power_WallLatch_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Power_WallLatch_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
