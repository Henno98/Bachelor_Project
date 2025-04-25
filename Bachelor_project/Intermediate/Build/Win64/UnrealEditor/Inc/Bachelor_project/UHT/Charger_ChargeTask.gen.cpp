// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Charger_ChargeTask.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCharger_ChargeTask() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UCharger_ChargeTask();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UCharger_ChargeTask_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UCharger_ChargeTask
void UCharger_ChargeTask::StaticRegisterNativesUCharger_ChargeTask()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCharger_ChargeTask);
UClass* Z_Construct_UClass_UCharger_ChargeTask_NoRegister()
{
	return UCharger_ChargeTask::StaticClass();
}
struct Z_Construct_UClass_UCharger_ChargeTask_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Charger_ChargeTask.h" },
		{ "ModuleRelativePath", "Public/Charger_ChargeTask.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChargeSpeedMultiplier_MetaData[] = {
		{ "Category", "Charge" },
		{ "ModuleRelativePath", "Public/Charger_ChargeTask.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxChargeTime_MetaData[] = {
		{ "Category", "Charge" },
		{ "ModuleRelativePath", "Public/Charger_ChargeTask.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ChargeSpeedMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxChargeTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCharger_ChargeTask>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCharger_ChargeTask_Statics::NewProp_ChargeSpeedMultiplier = { "ChargeSpeedMultiplier", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCharger_ChargeTask, ChargeSpeedMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChargeSpeedMultiplier_MetaData), NewProp_ChargeSpeedMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCharger_ChargeTask_Statics::NewProp_MaxChargeTime = { "MaxChargeTime", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCharger_ChargeTask, MaxChargeTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxChargeTime_MetaData), NewProp_MaxChargeTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCharger_ChargeTask_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCharger_ChargeTask_Statics::NewProp_ChargeSpeedMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCharger_ChargeTask_Statics::NewProp_MaxChargeTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCharger_ChargeTask_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCharger_ChargeTask_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCharger_ChargeTask_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCharger_ChargeTask_Statics::ClassParams = {
	&UCharger_ChargeTask::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCharger_ChargeTask_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCharger_ChargeTask_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCharger_ChargeTask_Statics::Class_MetaDataParams), Z_Construct_UClass_UCharger_ChargeTask_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCharger_ChargeTask()
{
	if (!Z_Registration_Info_UClass_UCharger_ChargeTask.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCharger_ChargeTask.OuterSingleton, Z_Construct_UClass_UCharger_ChargeTask_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCharger_ChargeTask.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UCharger_ChargeTask>()
{
	return UCharger_ChargeTask::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCharger_ChargeTask);
UCharger_ChargeTask::~UCharger_ChargeTask() {}
// End Class UCharger_ChargeTask

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Charger_ChargeTask_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCharger_ChargeTask, UCharger_ChargeTask::StaticClass, TEXT("UCharger_ChargeTask"), &Z_Registration_Info_UClass_UCharger_ChargeTask, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCharger_ChargeTask), 1271383927U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Charger_ChargeTask_h_675084687(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Charger_ChargeTask_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Charger_ChargeTask_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
