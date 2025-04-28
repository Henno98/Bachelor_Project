// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Enemies/Charger_WanderingTask.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCharger_WanderingTask() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UCharger_WanderingTask();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UCharger_WanderingTask_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UCharger_WanderingTask
void UCharger_WanderingTask::StaticRegisterNativesUCharger_WanderingTask()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCharger_WanderingTask);
UClass* Z_Construct_UClass_UCharger_WanderingTask_NoRegister()
{
	return UCharger_WanderingTask::StaticClass();
}
struct Z_Construct_UClass_UCharger_WanderingTask_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Enemies/Charger_WanderingTask.h" },
		{ "ModuleRelativePath", "Public/Enemies/Charger_WanderingTask.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WanderRadius_MetaData[] = {
		{ "Category", "Wander" },
		{ "ModuleRelativePath", "Public/Enemies/Charger_WanderingTask.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UseControllerWanderRadius_MetaData[] = {
		{ "Category", "Wander" },
		{ "ModuleRelativePath", "Public/Enemies/Charger_WanderingTask.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WanderRadius;
	static void NewProp_UseControllerWanderRadius_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_UseControllerWanderRadius;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCharger_WanderingTask>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCharger_WanderingTask_Statics::NewProp_WanderRadius = { "WanderRadius", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCharger_WanderingTask, WanderRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WanderRadius_MetaData), NewProp_WanderRadius_MetaData) };
void Z_Construct_UClass_UCharger_WanderingTask_Statics::NewProp_UseControllerWanderRadius_SetBit(void* Obj)
{
	((UCharger_WanderingTask*)Obj)->UseControllerWanderRadius = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCharger_WanderingTask_Statics::NewProp_UseControllerWanderRadius = { "UseControllerWanderRadius", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCharger_WanderingTask), &Z_Construct_UClass_UCharger_WanderingTask_Statics::NewProp_UseControllerWanderRadius_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UseControllerWanderRadius_MetaData), NewProp_UseControllerWanderRadius_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCharger_WanderingTask_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCharger_WanderingTask_Statics::NewProp_WanderRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCharger_WanderingTask_Statics::NewProp_UseControllerWanderRadius,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCharger_WanderingTask_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCharger_WanderingTask_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCharger_WanderingTask_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCharger_WanderingTask_Statics::ClassParams = {
	&UCharger_WanderingTask::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCharger_WanderingTask_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCharger_WanderingTask_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCharger_WanderingTask_Statics::Class_MetaDataParams), Z_Construct_UClass_UCharger_WanderingTask_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCharger_WanderingTask()
{
	if (!Z_Registration_Info_UClass_UCharger_WanderingTask.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCharger_WanderingTask.OuterSingleton, Z_Construct_UClass_UCharger_WanderingTask_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCharger_WanderingTask.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UCharger_WanderingTask>()
{
	return UCharger_WanderingTask::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCharger_WanderingTask);
UCharger_WanderingTask::~UCharger_WanderingTask() {}
// End Class UCharger_WanderingTask

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_Charger_WanderingTask_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCharger_WanderingTask, UCharger_WanderingTask::StaticClass, TEXT("UCharger_WanderingTask"), &Z_Registration_Info_UClass_UCharger_WanderingTask, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCharger_WanderingTask), 3083145279U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_Charger_WanderingTask_h_2929727931(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_Charger_WanderingTask_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_Charger_WanderingTask_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
