// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Wandering_Target_Point.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWandering_Target_Point() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_AWandering_Target_Point();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_AWandering_Target_Point_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ATargetPoint();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class AWandering_Target_Point
void AWandering_Target_Point::StaticRegisterNativesAWandering_Target_Point()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWandering_Target_Point);
UClass* Z_Construct_UClass_AWandering_Target_Point_NoRegister()
{
	return AWandering_Target_Point::StaticClass();
}
struct Z_Construct_UClass_AWandering_Target_Point_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Wandering_Target_Point.h" },
		{ "ModuleRelativePath", "Public/Wandering_Target_Point.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWandering_Target_Point>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AWandering_Target_Point_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ATargetPoint,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWandering_Target_Point_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AWandering_Target_Point_Statics::ClassParams = {
	&AWandering_Target_Point::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWandering_Target_Point_Statics::Class_MetaDataParams), Z_Construct_UClass_AWandering_Target_Point_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AWandering_Target_Point()
{
	if (!Z_Registration_Info_UClass_AWandering_Target_Point.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWandering_Target_Point.OuterSingleton, Z_Construct_UClass_AWandering_Target_Point_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AWandering_Target_Point.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<AWandering_Target_Point>()
{
	return AWandering_Target_Point::StaticClass();
}
AWandering_Target_Point::AWandering_Target_Point(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AWandering_Target_Point);
AWandering_Target_Point::~AWandering_Target_Point() {}
// End Class AWandering_Target_Point

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Wandering_Target_Point_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AWandering_Target_Point, AWandering_Target_Point::StaticClass, TEXT("AWandering_Target_Point"), &Z_Registration_Info_UClass_AWandering_Target_Point, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWandering_Target_Point), 2741939911U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Wandering_Target_Point_h_167334379(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Wandering_Target_Point_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Wandering_Target_Point_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
