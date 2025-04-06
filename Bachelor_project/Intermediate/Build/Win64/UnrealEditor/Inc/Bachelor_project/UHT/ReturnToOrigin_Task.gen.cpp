// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/ReturnToOrigin_Task.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReturnToOrigin_Task() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UReturnToOrigin_Task();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UReturnToOrigin_Task_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UReturnToOrigin_Task
void UReturnToOrigin_Task::StaticRegisterNativesUReturnToOrigin_Task()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UReturnToOrigin_Task);
UClass* Z_Construct_UClass_UReturnToOrigin_Task_NoRegister()
{
	return UReturnToOrigin_Task::StaticClass();
}
struct Z_Construct_UClass_UReturnToOrigin_Task_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "ReturnToOrigin_Task.h" },
		{ "ModuleRelativePath", "Public/ReturnToOrigin_Task.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DiveSpeed_MetaData[] = {
		{ "Category", "Dive" },
		{ "ModuleRelativePath", "Public/ReturnToOrigin_Task.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DiveSpeed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UReturnToOrigin_Task>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UReturnToOrigin_Task_Statics::NewProp_DiveSpeed = { "DiveSpeed", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UReturnToOrigin_Task, DiveSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DiveSpeed_MetaData), NewProp_DiveSpeed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UReturnToOrigin_Task_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReturnToOrigin_Task_Statics::NewProp_DiveSpeed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UReturnToOrigin_Task_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UReturnToOrigin_Task_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UReturnToOrigin_Task_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UReturnToOrigin_Task_Statics::ClassParams = {
	&UReturnToOrigin_Task::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UReturnToOrigin_Task_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UReturnToOrigin_Task_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UReturnToOrigin_Task_Statics::Class_MetaDataParams), Z_Construct_UClass_UReturnToOrigin_Task_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UReturnToOrigin_Task()
{
	if (!Z_Registration_Info_UClass_UReturnToOrigin_Task.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UReturnToOrigin_Task.OuterSingleton, Z_Construct_UClass_UReturnToOrigin_Task_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UReturnToOrigin_Task.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UReturnToOrigin_Task>()
{
	return UReturnToOrigin_Task::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UReturnToOrigin_Task);
UReturnToOrigin_Task::~UReturnToOrigin_Task() {}
// End Class UReturnToOrigin_Task

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_ReturnToOrigin_Task_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UReturnToOrigin_Task, UReturnToOrigin_Task::StaticClass, TEXT("UReturnToOrigin_Task"), &Z_Registration_Info_UClass_UReturnToOrigin_Task, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UReturnToOrigin_Task), 338789147U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_ReturnToOrigin_Task_h_3156377169(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_ReturnToOrigin_Task_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_ReturnToOrigin_Task_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
