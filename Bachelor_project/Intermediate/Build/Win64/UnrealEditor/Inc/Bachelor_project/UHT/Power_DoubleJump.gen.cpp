// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Power_DoubleJump.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePower_DoubleJump() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UPower_DoubleJump();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UPower_DoubleJump_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UPowerUpController();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UPower_DoubleJump
void UPower_DoubleJump::StaticRegisterNativesUPower_DoubleJump()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPower_DoubleJump);
UClass* Z_Construct_UClass_UPower_DoubleJump_NoRegister()
{
	return UPower_DoubleJump::StaticClass();
}
struct Z_Construct_UClass_UPower_DoubleJump_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Power_DoubleJump.h" },
		{ "ModuleRelativePath", "Public/Power_DoubleJump.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPower_DoubleJump>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UPower_DoubleJump_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPowerUpController,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPower_DoubleJump_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPower_DoubleJump_Statics::ClassParams = {
	&UPower_DoubleJump::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPower_DoubleJump_Statics::Class_MetaDataParams), Z_Construct_UClass_UPower_DoubleJump_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPower_DoubleJump()
{
	if (!Z_Registration_Info_UClass_UPower_DoubleJump.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPower_DoubleJump.OuterSingleton, Z_Construct_UClass_UPower_DoubleJump_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPower_DoubleJump.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UPower_DoubleJump>()
{
	return UPower_DoubleJump::StaticClass();
}
UPower_DoubleJump::UPower_DoubleJump(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPower_DoubleJump);
UPower_DoubleJump::~UPower_DoubleJump() {}
// End Class UPower_DoubleJump

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Power_DoubleJump_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPower_DoubleJump, UPower_DoubleJump::StaticClass, TEXT("UPower_DoubleJump"), &Z_Registration_Info_UClass_UPower_DoubleJump, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPower_DoubleJump), 1210804822U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Power_DoubleJump_h_2714401809(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Power_DoubleJump_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Power_DoubleJump_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
