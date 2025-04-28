// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Enemies/CrowMovement_Task.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCrowMovement_Task() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UCrowMovement_Task();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UCrowMovement_Task_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UCrowMovement_Task
void UCrowMovement_Task::StaticRegisterNativesUCrowMovement_Task()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCrowMovement_Task);
UClass* Z_Construct_UClass_UCrowMovement_Task_NoRegister()
{
	return UCrowMovement_Task::StaticClass();
}
struct Z_Construct_UClass_UCrowMovement_Task_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Enemies/CrowMovement_Task.h" },
		{ "ModuleRelativePath", "Public/Enemies/CrowMovement_Task.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCrowMovement_Task>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCrowMovement_Task_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCrowMovement_Task_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCrowMovement_Task_Statics::ClassParams = {
	&UCrowMovement_Task::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCrowMovement_Task_Statics::Class_MetaDataParams), Z_Construct_UClass_UCrowMovement_Task_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCrowMovement_Task()
{
	if (!Z_Registration_Info_UClass_UCrowMovement_Task.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCrowMovement_Task.OuterSingleton, Z_Construct_UClass_UCrowMovement_Task_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCrowMovement_Task.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UCrowMovement_Task>()
{
	return UCrowMovement_Task::StaticClass();
}
UCrowMovement_Task::UCrowMovement_Task(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCrowMovement_Task);
UCrowMovement_Task::~UCrowMovement_Task() {}
// End Class UCrowMovement_Task

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowMovement_Task_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCrowMovement_Task, UCrowMovement_Task::StaticClass, TEXT("UCrowMovement_Task"), &Z_Registration_Info_UClass_UCrowMovement_Task, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCrowMovement_Task), 1196743107U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowMovement_Task_h_3298902794(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowMovement_Task_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowMovement_Task_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
