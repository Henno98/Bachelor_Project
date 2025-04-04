// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Player_Stat_Widget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayer_Stat_Widget() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UPlayer_Stat_Widget();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UPlayer_Stat_Widget_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
UMG_API UClass* Z_Construct_UClass_UPanelWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UPlayer_Stat_Widget
void UPlayer_Stat_Widget::StaticRegisterNativesUPlayer_Stat_Widget()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPlayer_Stat_Widget);
UClass* Z_Construct_UClass_UPlayer_Stat_Widget_NoRegister()
{
	return UPlayer_Stat_Widget::StaticClass();
}
struct Z_Construct_UClass_UPlayer_Stat_Widget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Player_Stat_Widget.h" },
		{ "ModuleRelativePath", "Public/Player_Stat_Widget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealthBarPanel_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Reference to the canvas panel where health images will be added\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player_Stat_Widget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference to the canvas panel where health images will be added" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealthPointImage_MetaData[] = {
		{ "Category", "HealthBar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Reference to the image used for a single health point\n" },
#endif
		{ "ModuleRelativePath", "Public/Player_Stat_Widget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference to the image used for a single health point" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[] = {
		{ "Category", "HealthBar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Maximum health (for example, set to 10)\n" },
#endif
		{ "ModuleRelativePath", "Public/Player_Stat_Widget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum health (for example, set to 10)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealthBarPanel;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealthPointImage;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxHealth;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlayer_Stat_Widget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPlayer_Stat_Widget_Statics::NewProp_HealthBarPanel = { "HealthBarPanel", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayer_Stat_Widget, HealthBarPanel), Z_Construct_UClass_UPanelWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealthBarPanel_MetaData), NewProp_HealthBarPanel_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPlayer_Stat_Widget_Statics::NewProp_HealthPointImage = { "HealthPointImage", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayer_Stat_Widget, HealthPointImage), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealthPointImage_MetaData), NewProp_HealthPointImage_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UPlayer_Stat_Widget_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayer_Stat_Widget, MaxHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxHealth_MetaData), NewProp_MaxHealth_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPlayer_Stat_Widget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayer_Stat_Widget_Statics::NewProp_HealthBarPanel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayer_Stat_Widget_Statics::NewProp_HealthPointImage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayer_Stat_Widget_Statics::NewProp_MaxHealth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayer_Stat_Widget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UPlayer_Stat_Widget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayer_Stat_Widget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPlayer_Stat_Widget_Statics::ClassParams = {
	&UPlayer_Stat_Widget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UPlayer_Stat_Widget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UPlayer_Stat_Widget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayer_Stat_Widget_Statics::Class_MetaDataParams), Z_Construct_UClass_UPlayer_Stat_Widget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPlayer_Stat_Widget()
{
	if (!Z_Registration_Info_UClass_UPlayer_Stat_Widget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPlayer_Stat_Widget.OuterSingleton, Z_Construct_UClass_UPlayer_Stat_Widget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPlayer_Stat_Widget.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UPlayer_Stat_Widget>()
{
	return UPlayer_Stat_Widget::StaticClass();
}
UPlayer_Stat_Widget::UPlayer_Stat_Widget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPlayer_Stat_Widget);
UPlayer_Stat_Widget::~UPlayer_Stat_Widget() {}
// End Class UPlayer_Stat_Widget

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Stat_Widget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPlayer_Stat_Widget, UPlayer_Stat_Widget::StaticClass, TEXT("UPlayer_Stat_Widget"), &Z_Registration_Info_UClass_UPlayer_Stat_Widget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPlayer_Stat_Widget), 955313217U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Stat_Widget_h_2731608061(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Stat_Widget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Stat_Widget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
