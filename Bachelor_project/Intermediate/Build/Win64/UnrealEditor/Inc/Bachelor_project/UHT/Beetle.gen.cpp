// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Enemies/Beetle.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBeetle() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ABeetle();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ABeetle_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class ABeetle
void ABeetle::StaticRegisterNativesABeetle()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABeetle);
UClass* Z_Construct_UClass_ABeetle_NoRegister()
{
	return ABeetle::StaticClass();
}
struct Z_Construct_UClass_ABeetle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Enemies/Beetle.h" },
		{ "ModuleRelativePath", "Public/Enemies/Beetle.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABeetle>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABeetle_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABeetle_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABeetle_Statics::ClassParams = {
	&ABeetle::StaticClass,
	"Game",
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABeetle_Statics::Class_MetaDataParams), Z_Construct_UClass_ABeetle_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABeetle()
{
	if (!Z_Registration_Info_UClass_ABeetle.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABeetle.OuterSingleton, Z_Construct_UClass_ABeetle_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABeetle.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<ABeetle>()
{
	return ABeetle::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABeetle);
ABeetle::~ABeetle() {}
// End Class ABeetle

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_Beetle_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABeetle, ABeetle::StaticClass, TEXT("ABeetle"), &Z_Registration_Info_UClass_ABeetle, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABeetle), 730285536U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_Beetle_h_631474656(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_Beetle_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_Beetle_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
