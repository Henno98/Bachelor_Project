// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/BTTask_Movement_SmallCharger.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTTask_Movement_SmallCharger() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UBTTask_Movement_SmallCharger();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UBTTask_Movement_SmallCharger_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UBTTask_Movement_SmallCharger
void UBTTask_Movement_SmallCharger::StaticRegisterNativesUBTTask_Movement_SmallCharger()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTTask_Movement_SmallCharger);
UClass* Z_Construct_UClass_UBTTask_Movement_SmallCharger_NoRegister()
{
	return UBTTask_Movement_SmallCharger::StaticClass();
}
struct Z_Construct_UClass_UBTTask_Movement_SmallCharger_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BTTask_Movement_SmallCharger.h" },
		{ "ModuleRelativePath", "Public/BTTask_Movement_SmallCharger.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTTask_Movement_SmallCharger>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UBTTask_Movement_SmallCharger_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_Movement_SmallCharger_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTTask_Movement_SmallCharger_Statics::ClassParams = {
	&UBTTask_Movement_SmallCharger::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_Movement_SmallCharger_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTTask_Movement_SmallCharger_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBTTask_Movement_SmallCharger()
{
	if (!Z_Registration_Info_UClass_UBTTask_Movement_SmallCharger.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTTask_Movement_SmallCharger.OuterSingleton, Z_Construct_UClass_UBTTask_Movement_SmallCharger_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBTTask_Movement_SmallCharger.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UBTTask_Movement_SmallCharger>()
{
	return UBTTask_Movement_SmallCharger::StaticClass();
}
UBTTask_Movement_SmallCharger::UBTTask_Movement_SmallCharger(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBTTask_Movement_SmallCharger);
UBTTask_Movement_SmallCharger::~UBTTask_Movement_SmallCharger() {}
// End Class UBTTask_Movement_SmallCharger

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BTTask_Movement_SmallCharger_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBTTask_Movement_SmallCharger, UBTTask_Movement_SmallCharger::StaticClass, TEXT("UBTTask_Movement_SmallCharger"), &Z_Registration_Info_UClass_UBTTask_Movement_SmallCharger, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTTask_Movement_SmallCharger), 1774378512U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BTTask_Movement_SmallCharger_h_503136818(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BTTask_Movement_SmallCharger_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BTTask_Movement_SmallCharger_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
