// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/ASC_AbilitySystemComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeASC_AbilitySystemComponent() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UASC_AbilitySystemComponent();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UASC_AbilitySystemComponent_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UASC_AbilitySystemComponent
void UASC_AbilitySystemComponent::StaticRegisterNativesUASC_AbilitySystemComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UASC_AbilitySystemComponent);
UClass* Z_Construct_UClass_UASC_AbilitySystemComponent_NoRegister()
{
	return UASC_AbilitySystemComponent::StaticClass();
}
struct Z_Construct_UClass_UASC_AbilitySystemComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Object LOD Lighting Transform Sockets TextureStreaming Object LOD Lighting Transform Sockets TextureStreaming" },
		{ "IncludePath", "ASC_AbilitySystemComponent.h" },
		{ "ModuleRelativePath", "Public/ASC_AbilitySystemComponent.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UASC_AbilitySystemComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UASC_AbilitySystemComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAbilitySystemComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UASC_AbilitySystemComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UASC_AbilitySystemComponent_Statics::ClassParams = {
	&UASC_AbilitySystemComponent::StaticClass,
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
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UASC_AbilitySystemComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UASC_AbilitySystemComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UASC_AbilitySystemComponent()
{
	if (!Z_Registration_Info_UClass_UASC_AbilitySystemComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UASC_AbilitySystemComponent.OuterSingleton, Z_Construct_UClass_UASC_AbilitySystemComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UASC_AbilitySystemComponent.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UASC_AbilitySystemComponent>()
{
	return UASC_AbilitySystemComponent::StaticClass();
}
UASC_AbilitySystemComponent::UASC_AbilitySystemComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UASC_AbilitySystemComponent);
UASC_AbilitySystemComponent::~UASC_AbilitySystemComponent() {}
// End Class UASC_AbilitySystemComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_ASC_AbilitySystemComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UASC_AbilitySystemComponent, UASC_AbilitySystemComponent::StaticClass, TEXT("UASC_AbilitySystemComponent"), &Z_Registration_Info_UClass_UASC_AbilitySystemComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UASC_AbilitySystemComponent), 2170550821U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_ASC_AbilitySystemComponent_h_34058944(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_ASC_AbilitySystemComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_ASC_AbilitySystemComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
