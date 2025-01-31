// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/SaveState.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSaveState() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_USaveState();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_USaveState_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_USaveGame();
ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class USaveState
void USaveState::StaticRegisterNativesUSaveState()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USaveState);
UClass* Z_Construct_UClass_USaveState_NoRegister()
{
	return USaveState::StaticClass();
}
struct Z_Construct_UClass_USaveState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "SaveState.h" },
		{ "ModuleRelativePath", "Public/SaveState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerName_MetaData[] = {
		{ "Category", "Basic" },
		{ "ModuleRelativePath", "Public/SaveState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SaveSlotName_MetaData[] = {
		{ "Category", "Basic" },
		{ "ModuleRelativePath", "Public/SaveState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UserIndex_MetaData[] = {
		{ "Category", "Basic" },
		{ "ModuleRelativePath", "Public/SaveState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerLocation_MetaData[] = {
		{ "Category", "Basic" },
		{ "ModuleRelativePath", "Public/SaveState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasDoubleJumpPowerUp_MetaData[] = {
		{ "ModuleRelativePath", "Public/SaveState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasWallLatchPowerUp_MetaData[] = {
		{ "ModuleRelativePath", "Public/SaveState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedWorld_MetaData[] = {
		{ "ModuleRelativePath", "Public/SaveState.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_PlayerName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SaveSlotName;
	static const UECodeGen_Private::FUInt32PropertyParams NewProp_UserIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlayerLocation;
	static void NewProp_bHasDoubleJumpPowerUp_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasDoubleJumpPowerUp;
	static void NewProp_bHasWallLatchPowerUp_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasWallLatchPowerUp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SavedWorld;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USaveState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_USaveState_Statics::NewProp_PlayerName = { "PlayerName", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USaveState, PlayerName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerName_MetaData), NewProp_PlayerName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_USaveState_Statics::NewProp_SaveSlotName = { "SaveSlotName", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USaveState, SaveSlotName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SaveSlotName_MetaData), NewProp_SaveSlotName_MetaData) };
const UECodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_USaveState_Statics::NewProp_UserIndex = { "UserIndex", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USaveState, UserIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UserIndex_MetaData), NewProp_UserIndex_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USaveState_Statics::NewProp_PlayerLocation = { "PlayerLocation", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USaveState, PlayerLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerLocation_MetaData), NewProp_PlayerLocation_MetaData) };
void Z_Construct_UClass_USaveState_Statics::NewProp_bHasDoubleJumpPowerUp_SetBit(void* Obj)
{
	((USaveState*)Obj)->bHasDoubleJumpPowerUp = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USaveState_Statics::NewProp_bHasDoubleJumpPowerUp = { "bHasDoubleJumpPowerUp", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USaveState), &Z_Construct_UClass_USaveState_Statics::NewProp_bHasDoubleJumpPowerUp_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasDoubleJumpPowerUp_MetaData), NewProp_bHasDoubleJumpPowerUp_MetaData) };
void Z_Construct_UClass_USaveState_Statics::NewProp_bHasWallLatchPowerUp_SetBit(void* Obj)
{
	((USaveState*)Obj)->bHasWallLatchPowerUp = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USaveState_Statics::NewProp_bHasWallLatchPowerUp = { "bHasWallLatchPowerUp", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USaveState), &Z_Construct_UClass_USaveState_Statics::NewProp_bHasWallLatchPowerUp_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasWallLatchPowerUp_MetaData), NewProp_bHasWallLatchPowerUp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USaveState_Statics::NewProp_SavedWorld = { "SavedWorld", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USaveState, SavedWorld), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedWorld_MetaData), NewProp_SavedWorld_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USaveState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveState_Statics::NewProp_PlayerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveState_Statics::NewProp_SaveSlotName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveState_Statics::NewProp_UserIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveState_Statics::NewProp_PlayerLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveState_Statics::NewProp_bHasDoubleJumpPowerUp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveState_Statics::NewProp_bHasWallLatchPowerUp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveState_Statics::NewProp_SavedWorld,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USaveState_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_USaveState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USaveGame,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USaveState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USaveState_Statics::ClassParams = {
	&USaveState::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_USaveState_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_USaveState_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USaveState_Statics::Class_MetaDataParams), Z_Construct_UClass_USaveState_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_USaveState()
{
	if (!Z_Registration_Info_UClass_USaveState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USaveState.OuterSingleton, Z_Construct_UClass_USaveState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USaveState.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<USaveState>()
{
	return USaveState::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(USaveState);
USaveState::~USaveState() {}
// End Class USaveState

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SaveState_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USaveState, USaveState::StaticClass, TEXT("USaveState"), &Z_Registration_Info_UClass_USaveState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USaveState), 1223445571U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SaveState_h_571385131(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SaveState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SaveState_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
