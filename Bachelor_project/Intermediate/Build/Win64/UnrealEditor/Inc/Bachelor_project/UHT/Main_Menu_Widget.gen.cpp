// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Main_Menu_Widget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMain_Menu_Widget() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UMain_Menu_Widget();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UMain_Menu_Widget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UMain_Menu_Widget
void UMain_Menu_Widget::StaticRegisterNativesUMain_Menu_Widget()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMain_Menu_Widget);
UClass* Z_Construct_UClass_UMain_Menu_Widget_NoRegister()
{
	return UMain_Menu_Widget::StaticClass();
}
struct Z_Construct_UClass_UMain_Menu_Widget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Main_Menu_Widget.h" },
		{ "ModuleRelativePath", "Public/Main_Menu_Widget.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMain_Menu_Widget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UMain_Menu_Widget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMain_Menu_Widget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMain_Menu_Widget_Statics::ClassParams = {
	&UMain_Menu_Widget::StaticClass,
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
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMain_Menu_Widget_Statics::Class_MetaDataParams), Z_Construct_UClass_UMain_Menu_Widget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMain_Menu_Widget()
{
	if (!Z_Registration_Info_UClass_UMain_Menu_Widget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMain_Menu_Widget.OuterSingleton, Z_Construct_UClass_UMain_Menu_Widget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMain_Menu_Widget.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UMain_Menu_Widget>()
{
	return UMain_Menu_Widget::StaticClass();
}
UMain_Menu_Widget::UMain_Menu_Widget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMain_Menu_Widget);
UMain_Menu_Widget::~UMain_Menu_Widget() {}
// End Class UMain_Menu_Widget

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Main_Menu_Widget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMain_Menu_Widget, UMain_Menu_Widget::StaticClass, TEXT("UMain_Menu_Widget"), &Z_Registration_Info_UClass_UMain_Menu_Widget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMain_Menu_Widget), 1362887497U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Main_Menu_Widget_h_3026345340(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Main_Menu_Widget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Main_Menu_Widget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
