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
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UPlayer_Stat_Widget_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_USaveSlotListWidget_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UMG_API UClass* Z_Construct_UClass_UVerticalBox_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UMain_Menu_Widget Function CreateSaveSlotButton
struct Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotButton_Statics
{
	struct Main_Menu_Widget_eventCreateSaveSlotButton_Parms
	{
		FString slotname;
		int32 slotnumber;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Main_Menu_Widget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_slotname_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_slotname;
	static const UECodeGen_Private::FIntPropertyParams NewProp_slotnumber;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotButton_Statics::NewProp_slotname = { "slotname", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Main_Menu_Widget_eventCreateSaveSlotButton_Parms, slotname), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_slotname_MetaData), NewProp_slotname_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotButton_Statics::NewProp_slotnumber = { "slotnumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Main_Menu_Widget_eventCreateSaveSlotButton_Parms, slotnumber), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotButton_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotButton_Statics::NewProp_slotname,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotButton_Statics::NewProp_slotnumber,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotButton_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotButton_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMain_Menu_Widget, nullptr, "CreateSaveSlotButton", nullptr, nullptr, Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotButton_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotButton_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotButton_Statics::Main_Menu_Widget_eventCreateSaveSlotButton_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotButton_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotButton_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotButton_Statics::Main_Menu_Widget_eventCreateSaveSlotButton_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotButton()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotButton_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMain_Menu_Widget::execCreateSaveSlotButton)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_slotname);
	P_GET_PROPERTY(FIntProperty,Z_Param_slotnumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CreateSaveSlotButton(Z_Param_slotname,Z_Param_slotnumber);
	P_NATIVE_END;
}
// End Class UMain_Menu_Widget Function CreateSaveSlotButton

// Begin Class UMain_Menu_Widget Function CreateSaveSlotList
struct Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotList_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Main_Menu_Widget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMain_Menu_Widget, nullptr, "CreateSaveSlotList", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotList_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotList_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotList()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotList_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMain_Menu_Widget::execCreateSaveSlotList)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CreateSaveSlotList();
	P_NATIVE_END;
}
// End Class UMain_Menu_Widget Function CreateSaveSlotList

// Begin Class UMain_Menu_Widget Function NativeConstruct
struct Z_Construct_UFunction_UMain_Menu_Widget_NativeConstruct_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Sets up the widget\n" },
#endif
		{ "ModuleRelativePath", "Public/Main_Menu_Widget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets up the widget" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMain_Menu_Widget_NativeConstruct_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMain_Menu_Widget, nullptr, "NativeConstruct", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMain_Menu_Widget_NativeConstruct_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMain_Menu_Widget_NativeConstruct_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UMain_Menu_Widget_NativeConstruct()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMain_Menu_Widget_NativeConstruct_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMain_Menu_Widget::execNativeConstruct)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->NativeConstruct();
	P_NATIVE_END;
}
// End Class UMain_Menu_Widget Function NativeConstruct

// Begin Class UMain_Menu_Widget Function OnCloseClicked
struct Z_Construct_UFunction_UMain_Menu_Widget_OnCloseClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Main_Menu_Widget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMain_Menu_Widget_OnCloseClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMain_Menu_Widget, nullptr, "OnCloseClicked", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMain_Menu_Widget_OnCloseClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMain_Menu_Widget_OnCloseClicked_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UMain_Menu_Widget_OnCloseClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMain_Menu_Widget_OnCloseClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMain_Menu_Widget::execOnCloseClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnCloseClicked();
	P_NATIVE_END;
}
// End Class UMain_Menu_Widget Function OnCloseClicked

// Begin Class UMain_Menu_Widget Function OnLoadClicked
struct Z_Construct_UFunction_UMain_Menu_Widget_OnLoadClicked_Statics
{
	struct Main_Menu_Widget_eventOnLoadClicked_Parms
	{
		FString slotname;
		int32 slotnumber;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Main_Menu_Widget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_slotname_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_slotname;
	static const UECodeGen_Private::FIntPropertyParams NewProp_slotnumber;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMain_Menu_Widget_OnLoadClicked_Statics::NewProp_slotname = { "slotname", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Main_Menu_Widget_eventOnLoadClicked_Parms, slotname), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_slotname_MetaData), NewProp_slotname_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMain_Menu_Widget_OnLoadClicked_Statics::NewProp_slotnumber = { "slotnumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Main_Menu_Widget_eventOnLoadClicked_Parms, slotnumber), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMain_Menu_Widget_OnLoadClicked_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMain_Menu_Widget_OnLoadClicked_Statics::NewProp_slotname,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMain_Menu_Widget_OnLoadClicked_Statics::NewProp_slotnumber,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMain_Menu_Widget_OnLoadClicked_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMain_Menu_Widget_OnLoadClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMain_Menu_Widget, nullptr, "OnLoadClicked", nullptr, nullptr, Z_Construct_UFunction_UMain_Menu_Widget_OnLoadClicked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMain_Menu_Widget_OnLoadClicked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMain_Menu_Widget_OnLoadClicked_Statics::Main_Menu_Widget_eventOnLoadClicked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMain_Menu_Widget_OnLoadClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMain_Menu_Widget_OnLoadClicked_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMain_Menu_Widget_OnLoadClicked_Statics::Main_Menu_Widget_eventOnLoadClicked_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMain_Menu_Widget_OnLoadClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMain_Menu_Widget_OnLoadClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMain_Menu_Widget::execOnLoadClicked)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_slotname);
	P_GET_PROPERTY(FIntProperty,Z_Param_slotnumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnLoadClicked(Z_Param_slotname,Z_Param_slotnumber);
	P_NATIVE_END;
}
// End Class UMain_Menu_Widget Function OnLoadClicked

// Begin Class UMain_Menu_Widget Function OnQuitClicked
struct Z_Construct_UFunction_UMain_Menu_Widget_OnQuitClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Main_Menu_Widget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMain_Menu_Widget_OnQuitClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMain_Menu_Widget, nullptr, "OnQuitClicked", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMain_Menu_Widget_OnQuitClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMain_Menu_Widget_OnQuitClicked_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UMain_Menu_Widget_OnQuitClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMain_Menu_Widget_OnQuitClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMain_Menu_Widget::execOnQuitClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnQuitClicked();
	P_NATIVE_END;
}
// End Class UMain_Menu_Widget Function OnQuitClicked

// Begin Class UMain_Menu_Widget Function OnSaveClicked
struct Z_Construct_UFunction_UMain_Menu_Widget_OnSaveClicked_Statics
{
	struct Main_Menu_Widget_eventOnSaveClicked_Parms
	{
		FString slotname;
		int32 slotnumber;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Main_Menu_Widget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_slotname_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_slotname;
	static const UECodeGen_Private::FIntPropertyParams NewProp_slotnumber;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMain_Menu_Widget_OnSaveClicked_Statics::NewProp_slotname = { "slotname", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Main_Menu_Widget_eventOnSaveClicked_Parms, slotname), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_slotname_MetaData), NewProp_slotname_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMain_Menu_Widget_OnSaveClicked_Statics::NewProp_slotnumber = { "slotnumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Main_Menu_Widget_eventOnSaveClicked_Parms, slotnumber), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMain_Menu_Widget_OnSaveClicked_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMain_Menu_Widget_OnSaveClicked_Statics::NewProp_slotname,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMain_Menu_Widget_OnSaveClicked_Statics::NewProp_slotnumber,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMain_Menu_Widget_OnSaveClicked_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMain_Menu_Widget_OnSaveClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMain_Menu_Widget, nullptr, "OnSaveClicked", nullptr, nullptr, Z_Construct_UFunction_UMain_Menu_Widget_OnSaveClicked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMain_Menu_Widget_OnSaveClicked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMain_Menu_Widget_OnSaveClicked_Statics::Main_Menu_Widget_eventOnSaveClicked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMain_Menu_Widget_OnSaveClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMain_Menu_Widget_OnSaveClicked_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMain_Menu_Widget_OnSaveClicked_Statics::Main_Menu_Widget_eventOnSaveClicked_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMain_Menu_Widget_OnSaveClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMain_Menu_Widget_OnSaveClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMain_Menu_Widget::execOnSaveClicked)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_slotname);
	P_GET_PROPERTY(FIntProperty,Z_Param_slotnumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnSaveClicked(Z_Param_slotname,Z_Param_slotnumber);
	P_NATIVE_END;
}
// End Class UMain_Menu_Widget Function OnSaveClicked

// Begin Class UMain_Menu_Widget
void UMain_Menu_Widget::StaticRegisterNativesUMain_Menu_Widget()
{
	UClass* Class = UMain_Menu_Widget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CreateSaveSlotButton", &UMain_Menu_Widget::execCreateSaveSlotButton },
		{ "CreateSaveSlotList", &UMain_Menu_Widget::execCreateSaveSlotList },
		{ "NativeConstruct", &UMain_Menu_Widget::execNativeConstruct },
		{ "OnCloseClicked", &UMain_Menu_Widget::execOnCloseClicked },
		{ "OnLoadClicked", &UMain_Menu_Widget::execOnLoadClicked },
		{ "OnQuitClicked", &UMain_Menu_Widget::execOnQuitClicked },
		{ "OnSaveClicked", &UMain_Menu_Widget::execOnSaveClicked },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Load_Button_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Main_Menu_Widget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Save_Button_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Main_Menu_Widget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quit_Button_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Main_Menu_Widget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Close_Button_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Main_Menu_Widget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerStatsWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/Main_Menu_Widget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SaveSlotWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/Main_Menu_Widget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotListContainer_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Main_Menu_Widget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Load_Button;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Save_Button;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Quit_Button;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Close_Button;
	static const UECodeGen_Private::FClassPropertyParams NewProp_PlayerStatsWidgetClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_SaveSlotWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotListContainer;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotButton, "CreateSaveSlotButton" }, // 4228846798
		{ &Z_Construct_UFunction_UMain_Menu_Widget_CreateSaveSlotList, "CreateSaveSlotList" }, // 355030159
		{ &Z_Construct_UFunction_UMain_Menu_Widget_NativeConstruct, "NativeConstruct" }, // 3331562393
		{ &Z_Construct_UFunction_UMain_Menu_Widget_OnCloseClicked, "OnCloseClicked" }, // 1656000231
		{ &Z_Construct_UFunction_UMain_Menu_Widget_OnLoadClicked, "OnLoadClicked" }, // 2211213334
		{ &Z_Construct_UFunction_UMain_Menu_Widget_OnQuitClicked, "OnQuitClicked" }, // 3447004408
		{ &Z_Construct_UFunction_UMain_Menu_Widget_OnSaveClicked, "OnSaveClicked" }, // 3815834577
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMain_Menu_Widget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMain_Menu_Widget_Statics::NewProp_Load_Button = { "Load_Button", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMain_Menu_Widget, Load_Button), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Load_Button_MetaData), NewProp_Load_Button_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMain_Menu_Widget_Statics::NewProp_Save_Button = { "Save_Button", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMain_Menu_Widget, Save_Button), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Save_Button_MetaData), NewProp_Save_Button_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMain_Menu_Widget_Statics::NewProp_Quit_Button = { "Quit_Button", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMain_Menu_Widget, Quit_Button), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quit_Button_MetaData), NewProp_Quit_Button_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMain_Menu_Widget_Statics::NewProp_Close_Button = { "Close_Button", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMain_Menu_Widget, Close_Button), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Close_Button_MetaData), NewProp_Close_Button_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UMain_Menu_Widget_Statics::NewProp_PlayerStatsWidgetClass = { "PlayerStatsWidgetClass", nullptr, (EPropertyFlags)0x0024080000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMain_Menu_Widget, PlayerStatsWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UPlayer_Stat_Widget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerStatsWidgetClass_MetaData), NewProp_PlayerStatsWidgetClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UMain_Menu_Widget_Statics::NewProp_SaveSlotWidgetClass = { "SaveSlotWidgetClass", nullptr, (EPropertyFlags)0x0024080000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMain_Menu_Widget, SaveSlotWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_USaveSlotListWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SaveSlotWidgetClass_MetaData), NewProp_SaveSlotWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMain_Menu_Widget_Statics::NewProp_SlotListContainer = { "SlotListContainer", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMain_Menu_Widget, SlotListContainer), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotListContainer_MetaData), NewProp_SlotListContainer_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMain_Menu_Widget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMain_Menu_Widget_Statics::NewProp_Load_Button,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMain_Menu_Widget_Statics::NewProp_Save_Button,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMain_Menu_Widget_Statics::NewProp_Quit_Button,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMain_Menu_Widget_Statics::NewProp_Close_Button,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMain_Menu_Widget_Statics::NewProp_PlayerStatsWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMain_Menu_Widget_Statics::NewProp_SaveSlotWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMain_Menu_Widget_Statics::NewProp_SlotListContainer,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMain_Menu_Widget_Statics::PropPointers) < 2048);
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
	FuncInfo,
	Z_Construct_UClass_UMain_Menu_Widget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UMain_Menu_Widget_Statics::PropPointers),
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
		{ Z_Construct_UClass_UMain_Menu_Widget, UMain_Menu_Widget::StaticClass, TEXT("UMain_Menu_Widget"), &Z_Registration_Info_UClass_UMain_Menu_Widget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMain_Menu_Widget), 1568516837U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Main_Menu_Widget_h_770157522(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Main_Menu_Widget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Main_Menu_Widget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
