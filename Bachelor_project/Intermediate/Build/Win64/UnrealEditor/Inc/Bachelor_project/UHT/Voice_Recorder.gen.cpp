// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Voice_Recorder.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoice_Recorder() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_AVoice_Recorder();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_AVoice_Recorder_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class AVoice_Recorder
void AVoice_Recorder::StaticRegisterNativesAVoice_Recorder()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVoice_Recorder);
UClass* Z_Construct_UClass_AVoice_Recorder_NoRegister()
{
	return AVoice_Recorder::StaticClass();
}
struct Z_Construct_UClass_AVoice_Recorder_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Voice_Recorder.h" },
		{ "ModuleRelativePath", "Public/Voice_Recorder.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoice_Recorder>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AVoice_Recorder_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVoice_Recorder_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AVoice_Recorder_Statics::ClassParams = {
	&AVoice_Recorder::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVoice_Recorder_Statics::Class_MetaDataParams), Z_Construct_UClass_AVoice_Recorder_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AVoice_Recorder()
{
	if (!Z_Registration_Info_UClass_AVoice_Recorder.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVoice_Recorder.OuterSingleton, Z_Construct_UClass_AVoice_Recorder_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AVoice_Recorder.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<AVoice_Recorder>()
{
	return AVoice_Recorder::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AVoice_Recorder);
AVoice_Recorder::~AVoice_Recorder() {}
// End Class AVoice_Recorder

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Voice_Recorder_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AVoice_Recorder, AVoice_Recorder::StaticClass, TEXT("AVoice_Recorder"), &Z_Registration_Info_UClass_AVoice_Recorder, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVoice_Recorder), 2741462584U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Voice_Recorder_h_319372821(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Voice_Recorder_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Voice_Recorder_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
