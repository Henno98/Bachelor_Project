// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/SmallCharger_AIController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSmallCharger_AIController() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
AIMODULE_API UClass* Z_Construct_UClass_UPawnSensingComponent_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ASmallCharger_AIController();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ASmallCharger_AIController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class ASmallCharger_AIController Function OnEnemySeenItsOwner
struct Z_Construct_UFunction_ASmallCharger_AIController_OnEnemySeenItsOwner_Statics
{
	struct SmallCharger_AIController_eventOnEnemySeenItsOwner_Parms
	{
		APawn* SensedPawn;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SmallCharger_AIController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SensedPawn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASmallCharger_AIController_OnEnemySeenItsOwner_Statics::NewProp_SensedPawn = { "SensedPawn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SmallCharger_AIController_eventOnEnemySeenItsOwner_Parms, SensedPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASmallCharger_AIController_OnEnemySeenItsOwner_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASmallCharger_AIController_OnEnemySeenItsOwner_Statics::NewProp_SensedPawn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASmallCharger_AIController_OnEnemySeenItsOwner_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASmallCharger_AIController_OnEnemySeenItsOwner_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASmallCharger_AIController, nullptr, "OnEnemySeenItsOwner", nullptr, nullptr, Z_Construct_UFunction_ASmallCharger_AIController_OnEnemySeenItsOwner_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASmallCharger_AIController_OnEnemySeenItsOwner_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASmallCharger_AIController_OnEnemySeenItsOwner_Statics::SmallCharger_AIController_eventOnEnemySeenItsOwner_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASmallCharger_AIController_OnEnemySeenItsOwner_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASmallCharger_AIController_OnEnemySeenItsOwner_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASmallCharger_AIController_OnEnemySeenItsOwner_Statics::SmallCharger_AIController_eventOnEnemySeenItsOwner_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASmallCharger_AIController_OnEnemySeenItsOwner()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASmallCharger_AIController_OnEnemySeenItsOwner_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASmallCharger_AIController::execOnEnemySeenItsOwner)
{
	P_GET_OBJECT(APawn,Z_Param_SensedPawn);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnEnemySeenItsOwner(Z_Param_SensedPawn);
	P_NATIVE_END;
}
// End Class ASmallCharger_AIController Function OnEnemySeenItsOwner

// Begin Class ASmallCharger_AIController
void ASmallCharger_AIController::StaticRegisterNativesASmallCharger_AIController()
{
	UClass* Class = ASmallCharger_AIController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnEnemySeenItsOwner", &ASmallCharger_AIController::execOnEnemySeenItsOwner },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASmallCharger_AIController);
UClass* Z_Construct_UClass_ASmallCharger_AIController_NoRegister()
{
	return ASmallCharger_AIController::StaticClass();
}
struct Z_Construct_UClass_ASmallCharger_AIController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "SmallCharger_AIController.h" },
		{ "ModuleRelativePath", "Public/SmallCharger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SmallCharger_BT_MetaData[] = {
		{ "Category", "SmallCharger_AIController" },
		{ "ModuleRelativePath", "Public/SmallCharger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SmallCharger_PercetionComponent_MetaData[] = {
		{ "Category", "SmallCharger_AIController" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SmallCharger_AIController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SmallCharger_BT;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SmallCharger_PercetionComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ASmallCharger_AIController_OnEnemySeenItsOwner, "OnEnemySeenItsOwner" }, // 2289082881
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASmallCharger_AIController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASmallCharger_AIController_Statics::NewProp_SmallCharger_BT = { "SmallCharger_BT", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASmallCharger_AIController, SmallCharger_BT), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SmallCharger_BT_MetaData), NewProp_SmallCharger_BT_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASmallCharger_AIController_Statics::NewProp_SmallCharger_PercetionComponent = { "SmallCharger_PercetionComponent", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASmallCharger_AIController, SmallCharger_PercetionComponent), Z_Construct_UClass_UPawnSensingComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SmallCharger_PercetionComponent_MetaData), NewProp_SmallCharger_PercetionComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASmallCharger_AIController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASmallCharger_AIController_Statics::NewProp_SmallCharger_BT,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASmallCharger_AIController_Statics::NewProp_SmallCharger_PercetionComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASmallCharger_AIController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ASmallCharger_AIController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASmallCharger_AIController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASmallCharger_AIController_Statics::ClassParams = {
	&ASmallCharger_AIController::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ASmallCharger_AIController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ASmallCharger_AIController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASmallCharger_AIController_Statics::Class_MetaDataParams), Z_Construct_UClass_ASmallCharger_AIController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASmallCharger_AIController()
{
	if (!Z_Registration_Info_UClass_ASmallCharger_AIController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASmallCharger_AIController.OuterSingleton, Z_Construct_UClass_ASmallCharger_AIController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASmallCharger_AIController.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<ASmallCharger_AIController>()
{
	return ASmallCharger_AIController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASmallCharger_AIController);
ASmallCharger_AIController::~ASmallCharger_AIController() {}
// End Class ASmallCharger_AIController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_AIController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASmallCharger_AIController, ASmallCharger_AIController::StaticClass, TEXT("ASmallCharger_AIController"), &Z_Registration_Info_UClass_ASmallCharger_AIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASmallCharger_AIController), 974345042U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_AIController_h_72111363(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_AIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_AIController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
