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
UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UPlayer_Stat_Widget Function NativeConstruct
struct Z_Construct_UFunction_UPlayer_Stat_Widget_NativeConstruct_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Sets up the widget\n" },
#endif
		{ "ModuleRelativePath", "Public/Player_Stat_Widget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets up the widget" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlayer_Stat_Widget_NativeConstruct_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPlayer_Stat_Widget, nullptr, "NativeConstruct", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayer_Stat_Widget_NativeConstruct_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlayer_Stat_Widget_NativeConstruct_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UPlayer_Stat_Widget_NativeConstruct()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlayer_Stat_Widget_NativeConstruct_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlayer_Stat_Widget::execNativeConstruct)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->NativeConstruct();
	P_NATIVE_END;
}
// End Class UPlayer_Stat_Widget Function NativeConstruct

// Begin Class UPlayer_Stat_Widget Function UpdateBioMass
struct Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateBioMass_Statics
{
	struct Player_Stat_Widget_eventUpdateBioMass_Parms
	{
		int32 currenthealth;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player_Stat_Widget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_currenthealth;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateBioMass_Statics::NewProp_currenthealth = { "currenthealth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Player_Stat_Widget_eventUpdateBioMass_Parms, currenthealth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateBioMass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateBioMass_Statics::NewProp_currenthealth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateBioMass_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateBioMass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPlayer_Stat_Widget, nullptr, "UpdateBioMass", nullptr, nullptr, Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateBioMass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateBioMass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateBioMass_Statics::Player_Stat_Widget_eventUpdateBioMass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateBioMass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateBioMass_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateBioMass_Statics::Player_Stat_Widget_eventUpdateBioMass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateBioMass()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateBioMass_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlayer_Stat_Widget::execUpdateBioMass)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_currenthealth);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateBioMass(Z_Param_currenthealth);
	P_NATIVE_END;
}
// End Class UPlayer_Stat_Widget Function UpdateBioMass

// Begin Class UPlayer_Stat_Widget Function UpdateHealth
struct Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateHealth_Statics
{
	struct Player_Stat_Widget_eventUpdateHealth_Parms
	{
		int32 currenthealth;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Function to update the health bar\n" },
#endif
		{ "ModuleRelativePath", "Public/Player_Stat_Widget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Function to update the health bar" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_currenthealth;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateHealth_Statics::NewProp_currenthealth = { "currenthealth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Player_Stat_Widget_eventUpdateHealth_Parms, currenthealth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateHealth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateHealth_Statics::NewProp_currenthealth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateHealth_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPlayer_Stat_Widget, nullptr, "UpdateHealth", nullptr, nullptr, Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateHealth_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateHealth_Statics::Player_Stat_Widget_eventUpdateHealth_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateHealth_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateHealth_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateHealth_Statics::Player_Stat_Widget_eventUpdateHealth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateHealth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateHealth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlayer_Stat_Widget::execUpdateHealth)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_currenthealth);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateHealth(Z_Param_currenthealth);
	P_NATIVE_END;
}
// End Class UPlayer_Stat_Widget Function UpdateHealth

// Begin Class UPlayer_Stat_Widget Function UpdateTutorialText
struct Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateTutorialText_Statics
{
	struct Player_Stat_Widget_eventUpdateTutorialText_Parms
	{
		FString newtext;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player_Stat_Widget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_newtext_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_newtext;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateTutorialText_Statics::NewProp_newtext = { "newtext", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Player_Stat_Widget_eventUpdateTutorialText_Parms, newtext), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_newtext_MetaData), NewProp_newtext_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateTutorialText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateTutorialText_Statics::NewProp_newtext,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateTutorialText_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateTutorialText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPlayer_Stat_Widget, nullptr, "UpdateTutorialText", nullptr, nullptr, Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateTutorialText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateTutorialText_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateTutorialText_Statics::Player_Stat_Widget_eventUpdateTutorialText_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateTutorialText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateTutorialText_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateTutorialText_Statics::Player_Stat_Widget_eventUpdateTutorialText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateTutorialText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateTutorialText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPlayer_Stat_Widget::execUpdateTutorialText)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_newtext);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateTutorialText(Z_Param_newtext);
	P_NATIVE_END;
}
// End Class UPlayer_Stat_Widget Function UpdateTutorialText

// Begin Class UPlayer_Stat_Widget
void UPlayer_Stat_Widget::StaticRegisterNativesUPlayer_Stat_Widget()
{
	UClass* Class = UPlayer_Stat_Widget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "NativeConstruct", &UPlayer_Stat_Widget::execNativeConstruct },
		{ "UpdateBioMass", &UPlayer_Stat_Widget::execUpdateBioMass },
		{ "UpdateHealth", &UPlayer_Stat_Widget::execUpdateHealth },
		{ "UpdateTutorialText", &UPlayer_Stat_Widget::execUpdateTutorialText },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnergyBar_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player_Stat_Widget.h" },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BioMassImage_MetaData[] = {
		{ "Category", "EnergyBar" },
		{ "ModuleRelativePath", "Public/Player_Stat_Widget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TutorialTextBlock_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player_Stat_Widget.h" },
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
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EnergyBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealthPointImage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BioMassImage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TutorialTextBlock;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxHealth;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPlayer_Stat_Widget_NativeConstruct, "NativeConstruct" }, // 3782668698
		{ &Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateBioMass, "UpdateBioMass" }, // 2670450259
		{ &Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateHealth, "UpdateHealth" }, // 1883232996
		{ &Z_Construct_UFunction_UPlayer_Stat_Widget_UpdateTutorialText, "UpdateTutorialText" }, // 291221697
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlayer_Stat_Widget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPlayer_Stat_Widget_Statics::NewProp_HealthBarPanel = { "HealthBarPanel", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayer_Stat_Widget, HealthBarPanel), Z_Construct_UClass_UPanelWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealthBarPanel_MetaData), NewProp_HealthBarPanel_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPlayer_Stat_Widget_Statics::NewProp_EnergyBar = { "EnergyBar", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayer_Stat_Widget, EnergyBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnergyBar_MetaData), NewProp_EnergyBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPlayer_Stat_Widget_Statics::NewProp_HealthPointImage = { "HealthPointImage", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayer_Stat_Widget, HealthPointImage), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealthPointImage_MetaData), NewProp_HealthPointImage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPlayer_Stat_Widget_Statics::NewProp_BioMassImage = { "BioMassImage", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayer_Stat_Widget, BioMassImage), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BioMassImage_MetaData), NewProp_BioMassImage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPlayer_Stat_Widget_Statics::NewProp_TutorialTextBlock = { "TutorialTextBlock", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayer_Stat_Widget, TutorialTextBlock), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TutorialTextBlock_MetaData), NewProp_TutorialTextBlock_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UPlayer_Stat_Widget_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayer_Stat_Widget, MaxHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxHealth_MetaData), NewProp_MaxHealth_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPlayer_Stat_Widget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayer_Stat_Widget_Statics::NewProp_HealthBarPanel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayer_Stat_Widget_Statics::NewProp_EnergyBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayer_Stat_Widget_Statics::NewProp_HealthPointImage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayer_Stat_Widget_Statics::NewProp_BioMassImage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayer_Stat_Widget_Statics::NewProp_TutorialTextBlock,
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
	FuncInfo,
	Z_Construct_UClass_UPlayer_Stat_Widget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
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
struct Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Stat_Widget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPlayer_Stat_Widget, UPlayer_Stat_Widget::StaticClass, TEXT("UPlayer_Stat_Widget"), &Z_Registration_Info_UClass_UPlayer_Stat_Widget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPlayer_Stat_Widget), 2255735141U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Stat_Widget_h_2255979364(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Stat_Widget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Stat_Widget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
