// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/SmallCharger_BTService.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSmallCharger_BTService() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTService();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_USmallCharger_BTService();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_USmallCharger_BTService_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class USmallCharger_BTService
void USmallCharger_BTService::StaticRegisterNativesUSmallCharger_BTService()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USmallCharger_BTService);
UClass* Z_Construct_UClass_USmallCharger_BTService_NoRegister()
{
	return USmallCharger_BTService::StaticClass();
}
struct Z_Construct_UClass_USmallCharger_BTService_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "SmallCharger_BTService.h" },
		{ "ModuleRelativePath", "Public/SmallCharger_BTService.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USmallCharger_BTService>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_USmallCharger_BTService_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTService,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USmallCharger_BTService_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USmallCharger_BTService_Statics::ClassParams = {
	&USmallCharger_BTService::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USmallCharger_BTService_Statics::Class_MetaDataParams), Z_Construct_UClass_USmallCharger_BTService_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_USmallCharger_BTService()
{
	if (!Z_Registration_Info_UClass_USmallCharger_BTService.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USmallCharger_BTService.OuterSingleton, Z_Construct_UClass_USmallCharger_BTService_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USmallCharger_BTService.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<USmallCharger_BTService>()
{
	return USmallCharger_BTService::StaticClass();
}
USmallCharger_BTService::USmallCharger_BTService(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(USmallCharger_BTService);
USmallCharger_BTService::~USmallCharger_BTService() {}
// End Class USmallCharger_BTService

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_BTService_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USmallCharger_BTService, USmallCharger_BTService::StaticClass, TEXT("USmallCharger_BTService"), &Z_Registration_Info_UClass_USmallCharger_BTService, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USmallCharger_BTService), 3060648529U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_BTService_h_1498532798(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_BTService_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_BTService_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
