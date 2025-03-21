// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/SmallCharger.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSmallCharger() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ASmallCharger();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ASmallCharger_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class ASmallCharger
void ASmallCharger::StaticRegisterNativesASmallCharger()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASmallCharger);
UClass* Z_Construct_UClass_ASmallCharger_NoRegister()
{
	return ASmallCharger::StaticClass();
}
struct Z_Construct_UClass_ASmallCharger_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "SmallCharger.h" },
		{ "ModuleRelativePath", "Public/SmallCharger.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASmallCharger>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ASmallCharger_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASmallCharger_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASmallCharger_Statics::ClassParams = {
	&ASmallCharger::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASmallCharger_Statics::Class_MetaDataParams), Z_Construct_UClass_ASmallCharger_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASmallCharger()
{
	if (!Z_Registration_Info_UClass_ASmallCharger.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASmallCharger.OuterSingleton, Z_Construct_UClass_ASmallCharger_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASmallCharger.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<ASmallCharger>()
{
	return ASmallCharger::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASmallCharger);
ASmallCharger::~ASmallCharger() {}
// End Class ASmallCharger

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASmallCharger, ASmallCharger::StaticClass, TEXT("ASmallCharger"), &Z_Registration_Info_UClass_ASmallCharger, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASmallCharger), 4172007752U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_h_1277093096(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
