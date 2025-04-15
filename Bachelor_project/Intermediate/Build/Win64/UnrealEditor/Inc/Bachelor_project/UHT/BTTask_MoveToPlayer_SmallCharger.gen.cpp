// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/BTTask_MoveToPlayer_SmallCharger.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTTask_MoveToPlayer_SmallCharger() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UBTTask_MoveToPlayer_SmallCharger();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UBTTask_MoveToPlayer_SmallCharger_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UBTTask_MoveToPlayer_SmallCharger
void UBTTask_MoveToPlayer_SmallCharger::StaticRegisterNativesUBTTask_MoveToPlayer_SmallCharger()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTTask_MoveToPlayer_SmallCharger);
UClass* Z_Construct_UClass_UBTTask_MoveToPlayer_SmallCharger_NoRegister()
{
	return UBTTask_MoveToPlayer_SmallCharger::StaticClass();
}
struct Z_Construct_UClass_UBTTask_MoveToPlayer_SmallCharger_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BTTask_MoveToPlayer_SmallCharger.h" },
		{ "ModuleRelativePath", "Public/BTTask_MoveToPlayer_SmallCharger.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTTask_MoveToPlayer_SmallCharger>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UBTTask_MoveToPlayer_SmallCharger_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_MoveToPlayer_SmallCharger_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTTask_MoveToPlayer_SmallCharger_Statics::ClassParams = {
	&UBTTask_MoveToPlayer_SmallCharger::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_MoveToPlayer_SmallCharger_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTTask_MoveToPlayer_SmallCharger_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBTTask_MoveToPlayer_SmallCharger()
{
	if (!Z_Registration_Info_UClass_UBTTask_MoveToPlayer_SmallCharger.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTTask_MoveToPlayer_SmallCharger.OuterSingleton, Z_Construct_UClass_UBTTask_MoveToPlayer_SmallCharger_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBTTask_MoveToPlayer_SmallCharger.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UBTTask_MoveToPlayer_SmallCharger>()
{
	return UBTTask_MoveToPlayer_SmallCharger::StaticClass();
}
UBTTask_MoveToPlayer_SmallCharger::UBTTask_MoveToPlayer_SmallCharger(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBTTask_MoveToPlayer_SmallCharger);
UBTTask_MoveToPlayer_SmallCharger::~UBTTask_MoveToPlayer_SmallCharger() {}
// End Class UBTTask_MoveToPlayer_SmallCharger

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BTTask_MoveToPlayer_SmallCharger_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBTTask_MoveToPlayer_SmallCharger, UBTTask_MoveToPlayer_SmallCharger::StaticClass, TEXT("UBTTask_MoveToPlayer_SmallCharger"), &Z_Registration_Info_UClass_UBTTask_MoveToPlayer_SmallCharger, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTTask_MoveToPlayer_SmallCharger), 1099547002U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BTTask_MoveToPlayer_SmallCharger_h_305531859(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BTTask_MoveToPlayer_SmallCharger_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BTTask_MoveToPlayer_SmallCharger_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
