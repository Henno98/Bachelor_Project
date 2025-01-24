// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/BasicPlatform.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBasicPlatform() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ABasicPlatform();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ABasicPlatform_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class ABasicPlatform
void ABasicPlatform::StaticRegisterNativesABasicPlatform()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABasicPlatform);
UClass* Z_Construct_UClass_ABasicPlatform_NoRegister()
{
	return ABasicPlatform::StaticClass();
}
struct Z_Construct_UClass_ABasicPlatform_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "BasicPlatform.h" },
		{ "ModuleRelativePath", "Public/BasicPlatform.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StaticMesh_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BasicPlatform.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Collider_MetaData[] = {
		{ "Category", "Collider" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BasicPlatform.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StaticMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Collider;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABasicPlatform>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABasicPlatform_Statics::NewProp_StaticMesh = { "StaticMesh", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABasicPlatform, StaticMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StaticMesh_MetaData), NewProp_StaticMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABasicPlatform_Statics::NewProp_Collider = { "Collider", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABasicPlatform, Collider), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Collider_MetaData), NewProp_Collider_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABasicPlatform_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABasicPlatform_Statics::NewProp_StaticMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABasicPlatform_Statics::NewProp_Collider,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABasicPlatform_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABasicPlatform_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABasicPlatform_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABasicPlatform_Statics::ClassParams = {
	&ABasicPlatform::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ABasicPlatform_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ABasicPlatform_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABasicPlatform_Statics::Class_MetaDataParams), Z_Construct_UClass_ABasicPlatform_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABasicPlatform()
{
	if (!Z_Registration_Info_UClass_ABasicPlatform.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABasicPlatform.OuterSingleton, Z_Construct_UClass_ABasicPlatform_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABasicPlatform.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<ABasicPlatform>()
{
	return ABasicPlatform::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABasicPlatform);
ABasicPlatform::~ABasicPlatform() {}
// End Class ABasicPlatform

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_jacob_Documents_GitHubMain_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BasicPlatform_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABasicPlatform, ABasicPlatform::StaticClass, TEXT("ABasicPlatform"), &Z_Registration_Info_UClass_ABasicPlatform, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABasicPlatform), 1020359016U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jacob_Documents_GitHubMain_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BasicPlatform_h_2502319971(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_jacob_Documents_GitHubMain_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BasicPlatform_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_jacob_Documents_GitHubMain_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BasicPlatform_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
