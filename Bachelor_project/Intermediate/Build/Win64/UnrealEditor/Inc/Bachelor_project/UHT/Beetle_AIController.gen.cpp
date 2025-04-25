// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Beetle_AIController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBeetle_AIController() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
AIMODULE_API UClass* Z_Construct_UClass_UPawnSensingComponent_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ABeetle_AIController();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ABeetle_AIController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class ABeetle_AIController Function OnEnemySeeItsTarget
struct Z_Construct_UFunction_ABeetle_AIController_OnEnemySeeItsTarget_Statics
{
	struct Beetle_AIController_eventOnEnemySeeItsTarget_Parms
	{
		APawn* SensedPawn;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Beetle_AIController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SensedPawn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABeetle_AIController_OnEnemySeeItsTarget_Statics::NewProp_SensedPawn = { "SensedPawn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Beetle_AIController_eventOnEnemySeeItsTarget_Parms, SensedPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABeetle_AIController_OnEnemySeeItsTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABeetle_AIController_OnEnemySeeItsTarget_Statics::NewProp_SensedPawn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABeetle_AIController_OnEnemySeeItsTarget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABeetle_AIController_OnEnemySeeItsTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABeetle_AIController, nullptr, "OnEnemySeeItsTarget", nullptr, nullptr, Z_Construct_UFunction_ABeetle_AIController_OnEnemySeeItsTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABeetle_AIController_OnEnemySeeItsTarget_Statics::PropPointers), sizeof(Z_Construct_UFunction_ABeetle_AIController_OnEnemySeeItsTarget_Statics::Beetle_AIController_eventOnEnemySeeItsTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABeetle_AIController_OnEnemySeeItsTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABeetle_AIController_OnEnemySeeItsTarget_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ABeetle_AIController_OnEnemySeeItsTarget_Statics::Beetle_AIController_eventOnEnemySeeItsTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ABeetle_AIController_OnEnemySeeItsTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABeetle_AIController_OnEnemySeeItsTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABeetle_AIController::execOnEnemySeeItsTarget)
{
	P_GET_OBJECT(APawn,Z_Param_SensedPawn);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnEnemySeeItsTarget(Z_Param_SensedPawn);
	P_NATIVE_END;
}
// End Class ABeetle_AIController Function OnEnemySeeItsTarget

// Begin Class ABeetle_AIController
void ABeetle_AIController::StaticRegisterNativesABeetle_AIController()
{
	UClass* Class = ABeetle_AIController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnEnemySeeItsTarget", &ABeetle_AIController::execOnEnemySeeItsTarget },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABeetle_AIController);
UClass* Z_Construct_UClass_ABeetle_AIController_NoRegister()
{
	return ABeetle_AIController::StaticClass();
}
struct Z_Construct_UClass_ABeetle_AIController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Beetle_AIController.h" },
		{ "ModuleRelativePath", "Public/Beetle_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Beetle_BT_MetaData[] = {
		{ "Category", "Beetle_AIController" },
		{ "ModuleRelativePath", "Public/Beetle_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Beetle_PerceptionComponent_MetaData[] = {
		{ "Category", "Beetle_AIController" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Beetle_AIController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Beetle_BT;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Beetle_PerceptionComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ABeetle_AIController_OnEnemySeeItsTarget, "OnEnemySeeItsTarget" }, // 1491726807
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABeetle_AIController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABeetle_AIController_Statics::NewProp_Beetle_BT = { "Beetle_BT", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABeetle_AIController, Beetle_BT), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Beetle_BT_MetaData), NewProp_Beetle_BT_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABeetle_AIController_Statics::NewProp_Beetle_PerceptionComponent = { "Beetle_PerceptionComponent", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABeetle_AIController, Beetle_PerceptionComponent), Z_Construct_UClass_UPawnSensingComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Beetle_PerceptionComponent_MetaData), NewProp_Beetle_PerceptionComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABeetle_AIController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeetle_AIController_Statics::NewProp_Beetle_BT,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeetle_AIController_Statics::NewProp_Beetle_PerceptionComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABeetle_AIController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABeetle_AIController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABeetle_AIController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABeetle_AIController_Statics::ClassParams = {
	&ABeetle_AIController::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ABeetle_AIController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ABeetle_AIController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABeetle_AIController_Statics::Class_MetaDataParams), Z_Construct_UClass_ABeetle_AIController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABeetle_AIController()
{
	if (!Z_Registration_Info_UClass_ABeetle_AIController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABeetle_AIController.OuterSingleton, Z_Construct_UClass_ABeetle_AIController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABeetle_AIController.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<ABeetle_AIController>()
{
	return ABeetle_AIController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABeetle_AIController);
ABeetle_AIController::~ABeetle_AIController() {}
// End Class ABeetle_AIController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Beetle_AIController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABeetle_AIController, ABeetle_AIController::StaticClass, TEXT("ABeetle_AIController"), &Z_Registration_Info_UClass_ABeetle_AIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABeetle_AIController), 190310270U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Beetle_AIController_h_496311948(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Beetle_AIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Beetle_AIController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
