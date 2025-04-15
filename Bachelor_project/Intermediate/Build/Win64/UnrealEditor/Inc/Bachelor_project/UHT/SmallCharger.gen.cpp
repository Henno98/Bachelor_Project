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
AIMODULE_API UClass* Z_Construct_UClass_UPawnSensingComponent_NoRegister();
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SmallCharger_PerceptionComponent_MetaData[] = {
		{ "Category", "AI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SmallCharger.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SmallCharger_PerceptionComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASmallCharger>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASmallCharger_Statics::NewProp_SmallCharger_PerceptionComponent = { "SmallCharger_PerceptionComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASmallCharger, SmallCharger_PerceptionComponent), Z_Construct_UClass_UPawnSensingComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SmallCharger_PerceptionComponent_MetaData), NewProp_SmallCharger_PerceptionComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASmallCharger_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASmallCharger_Statics::NewProp_SmallCharger_PerceptionComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASmallCharger_Statics::PropPointers) < 2048);
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
	Z_Construct_UClass_ASmallCharger_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ASmallCharger_Statics::PropPointers),
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
struct Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASmallCharger, ASmallCharger::StaticClass, TEXT("ASmallCharger"), &Z_Registration_Info_UClass_ASmallCharger, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASmallCharger), 528490175U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_h_3902491993(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
