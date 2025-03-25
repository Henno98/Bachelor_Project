// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/PowerUpController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePowerUpController() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UPowerUpController();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UPowerUpController_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class UPowerUpController Function Activate
struct Z_Construct_UFunction_UPowerUpController_Activate_Statics
{
	struct PowerUpController_eventActivate_Parms
	{
		AActor* Player;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "PowerUp" },
		{ "ModuleRelativePath", "Public/PowerUpController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Player;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPowerUpController_Activate_Statics::NewProp_Player = { "Player", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PowerUpController_eventActivate_Parms, Player), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPowerUpController_Activate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPowerUpController_Activate_Statics::NewProp_Player,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPowerUpController_Activate_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPowerUpController_Activate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPowerUpController, nullptr, "Activate", nullptr, nullptr, Z_Construct_UFunction_UPowerUpController_Activate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPowerUpController_Activate_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPowerUpController_Activate_Statics::PowerUpController_eventActivate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPowerUpController_Activate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPowerUpController_Activate_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UPowerUpController_Activate_Statics::PowerUpController_eventActivate_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPowerUpController_Activate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPowerUpController_Activate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPowerUpController::execActivate)
{
	P_GET_OBJECT(AActor,Z_Param_Player);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Activate(Z_Param_Player);
	P_NATIVE_END;
}
// End Class UPowerUpController Function Activate

// Begin Class UPowerUpController
void UPowerUpController::StaticRegisterNativesUPowerUpController()
{
	UClass* Class = UPowerUpController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Activate", &UPowerUpController::execActivate },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPowerUpController);
UClass* Z_Construct_UClass_UPowerUpController_NoRegister()
{
	return UPowerUpController::StaticClass();
}
struct Z_Construct_UClass_UPowerUpController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "PowerUpController.h" },
		{ "ModuleRelativePath", "Public/PowerUpController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsActivated_MetaData[] = {
		{ "Category", "PowerUp" },
		{ "ModuleRelativePath", "Public/PowerUpController.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bIsActivated_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsActivated;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPowerUpController_Activate, "Activate" }, // 4172503704
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPowerUpController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UPowerUpController_Statics::NewProp_bIsActivated_SetBit(void* Obj)
{
	((UPowerUpController*)Obj)->bIsActivated = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPowerUpController_Statics::NewProp_bIsActivated = { "bIsActivated", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPowerUpController), &Z_Construct_UClass_UPowerUpController_Statics::NewProp_bIsActivated_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsActivated_MetaData), NewProp_bIsActivated_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPowerUpController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPowerUpController_Statics::NewProp_bIsActivated,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPowerUpController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UPowerUpController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPowerUpController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPowerUpController_Statics::ClassParams = {
	&UPowerUpController::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UPowerUpController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UPowerUpController_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPowerUpController_Statics::Class_MetaDataParams), Z_Construct_UClass_UPowerUpController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPowerUpController()
{
	if (!Z_Registration_Info_UClass_UPowerUpController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPowerUpController.OuterSingleton, Z_Construct_UClass_UPowerUpController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPowerUpController.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<UPowerUpController>()
{
	return UPowerUpController::StaticClass();
}
UPowerUpController::UPowerUpController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPowerUpController);
UPowerUpController::~UPowerUpController() {}
// End Class UPowerUpController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_PowerUpController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPowerUpController, UPowerUpController::StaticClass, TEXT("UPowerUpController"), &Z_Registration_Info_UClass_UPowerUpController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPowerUpController), 4034072285U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_PowerUpController_h_2924775876(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_PowerUpController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_PowerUpController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
