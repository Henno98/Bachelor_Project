// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Player_HUD.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayer_HUD() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_APlayer_HUD();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_APlayer_HUD_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UMain_Menu_Widget_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UPlayer_Stat_Widget_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AHUD();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class APlayer_HUD Function ClearText
struct Z_Construct_UFunction_APlayer_HUD_ClearText_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player_HUD.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayer_HUD_ClearText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayer_HUD, nullptr, "ClearText", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayer_HUD_ClearText_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayer_HUD_ClearText_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlayer_HUD_ClearText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayer_HUD_ClearText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayer_HUD::execClearText)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearText();
	P_NATIVE_END;
}
// End Class APlayer_HUD Function ClearText

// Begin Class APlayer_HUD Function ShowTutorialText
struct Z_Construct_UFunction_APlayer_HUD_ShowTutorialText_Statics
{
	struct Player_HUD_eventShowTutorialText_Parms
	{
		FString Text;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Show tutorial text on the screen\n" },
#endif
		{ "ModuleRelativePath", "Public/Player_HUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Show tutorial text on the screen" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Text;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_APlayer_HUD_ShowTutorialText_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Player_HUD_eventShowTutorialText_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayer_HUD_ShowTutorialText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayer_HUD_ShowTutorialText_Statics::NewProp_Text,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayer_HUD_ShowTutorialText_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayer_HUD_ShowTutorialText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayer_HUD, nullptr, "ShowTutorialText", nullptr, nullptr, Z_Construct_UFunction_APlayer_HUD_ShowTutorialText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayer_HUD_ShowTutorialText_Statics::PropPointers), sizeof(Z_Construct_UFunction_APlayer_HUD_ShowTutorialText_Statics::Player_HUD_eventShowTutorialText_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayer_HUD_ShowTutorialText_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayer_HUD_ShowTutorialText_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_APlayer_HUD_ShowTutorialText_Statics::Player_HUD_eventShowTutorialText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APlayer_HUD_ShowTutorialText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayer_HUD_ShowTutorialText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayer_HUD::execShowTutorialText)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Text);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowTutorialText(Z_Param_Text);
	P_NATIVE_END;
}
// End Class APlayer_HUD Function ShowTutorialText

// Begin Class APlayer_HUD
void APlayer_HUD::StaticRegisterNativesAPlayer_HUD()
{
	UClass* Class = APlayer_HUD::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClearText", &APlayer_HUD::execClearText },
		{ "ShowTutorialText", &APlayer_HUD::execShowTutorialText },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APlayer_HUD);
UClass* Z_Construct_UClass_APlayer_HUD_NoRegister()
{
	return APlayer_HUD::StaticClass();
}
struct Z_Construct_UClass_APlayer_HUD_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "Player_HUD.h" },
		{ "ModuleRelativePath", "Public/Player_HUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MainMenuWidgetClass_MetaData[] = {
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Widget classes (set these in the Blueprint/Details panel)\n" },
#endif
		{ "ModuleRelativePath", "Public/Player_HUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Widget classes (set these in the Blueprint/Details panel)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StatWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/Player_HUD.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Main_Menu_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Widget instances\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player_HUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Widget instances" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Player_Stat_Widget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player_HUD.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_MainMenuWidgetClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_StatWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Main_Menu;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Player_Stat_Widget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_APlayer_HUD_ClearText, "ClearText" }, // 5867220
		{ &Z_Construct_UFunction_APlayer_HUD_ShowTutorialText, "ShowTutorialText" }, // 3157519329
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlayer_HUD>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_APlayer_HUD_Statics::NewProp_MainMenuWidgetClass = { "MainMenuWidgetClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayer_HUD, MainMenuWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UMain_Menu_Widget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MainMenuWidgetClass_MetaData), NewProp_MainMenuWidgetClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_APlayer_HUD_Statics::NewProp_StatWidgetClass = { "StatWidgetClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayer_HUD, StatWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UPlayer_Stat_Widget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StatWidgetClass_MetaData), NewProp_StatWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayer_HUD_Statics::NewProp_Main_Menu = { "Main_Menu", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayer_HUD, Main_Menu), Z_Construct_UClass_UMain_Menu_Widget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Main_Menu_MetaData), NewProp_Main_Menu_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayer_HUD_Statics::NewProp_Player_Stat_Widget = { "Player_Stat_Widget", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayer_HUD, Player_Stat_Widget), Z_Construct_UClass_UPlayer_Stat_Widget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Player_Stat_Widget_MetaData), NewProp_Player_Stat_Widget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APlayer_HUD_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayer_HUD_Statics::NewProp_MainMenuWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayer_HUD_Statics::NewProp_StatWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayer_HUD_Statics::NewProp_Main_Menu,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayer_HUD_Statics::NewProp_Player_Stat_Widget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlayer_HUD_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_APlayer_HUD_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AHUD,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlayer_HUD_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APlayer_HUD_Statics::ClassParams = {
	&APlayer_HUD::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_APlayer_HUD_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_APlayer_HUD_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APlayer_HUD_Statics::Class_MetaDataParams), Z_Construct_UClass_APlayer_HUD_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APlayer_HUD()
{
	if (!Z_Registration_Info_UClass_APlayer_HUD.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APlayer_HUD.OuterSingleton, Z_Construct_UClass_APlayer_HUD_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APlayer_HUD.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<APlayer_HUD>()
{
	return APlayer_HUD::StaticClass();
}
APlayer_HUD::APlayer_HUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(APlayer_HUD);
APlayer_HUD::~APlayer_HUD() {}
// End Class APlayer_HUD

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_HUD_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APlayer_HUD, APlayer_HUD::StaticClass, TEXT("APlayer_HUD"), &Z_Registration_Info_UClass_APlayer_HUD, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APlayer_HUD), 2820616357U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_HUD_h_3787832724(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_HUD_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_HUD_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
