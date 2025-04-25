// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Charger_AIController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCharger_AIController() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTreeComponent_NoRegister();
AIMODULE_API UClass* Z_Construct_UClass_UBlackboardComponent_NoRegister();
AIMODULE_API UClass* Z_Construct_UClass_UPawnSensingComponent_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ACharger_AIController();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ACharger_AIController_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_AWandering_Target_Point_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class ACharger_AIController Function OnSeenPawn
struct Z_Construct_UFunction_ACharger_AIController_OnSeenPawn_Statics
{
	struct Charger_AIController_eventOnSeenPawn_Parms
	{
		APawn* SeenPawn;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Charger_AIController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SeenPawn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACharger_AIController_OnSeenPawn_Statics::NewProp_SeenPawn = { "SeenPawn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Charger_AIController_eventOnSeenPawn_Parms, SeenPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACharger_AIController_OnSeenPawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACharger_AIController_OnSeenPawn_Statics::NewProp_SeenPawn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACharger_AIController_OnSeenPawn_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACharger_AIController_OnSeenPawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACharger_AIController, nullptr, "OnSeenPawn", nullptr, nullptr, Z_Construct_UFunction_ACharger_AIController_OnSeenPawn_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACharger_AIController_OnSeenPawn_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACharger_AIController_OnSeenPawn_Statics::Charger_AIController_eventOnSeenPawn_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACharger_AIController_OnSeenPawn_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACharger_AIController_OnSeenPawn_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACharger_AIController_OnSeenPawn_Statics::Charger_AIController_eventOnSeenPawn_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACharger_AIController_OnSeenPawn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACharger_AIController_OnSeenPawn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACharger_AIController::execOnSeenPawn)
{
	P_GET_OBJECT(APawn,Z_Param_SeenPawn);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnSeenPawn(Z_Param_SeenPawn);
	P_NATIVE_END;
}
// End Class ACharger_AIController Function OnSeenPawn

// Begin Class ACharger_AIController
void ACharger_AIController::StaticRegisterNativesACharger_AIController()
{
	UClass* Class = ACharger_AIController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnSeenPawn", &ACharger_AIController::execOnSeenPawn },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACharger_AIController);
UClass* Z_Construct_UClass_ACharger_AIController_NoRegister()
{
	return ACharger_AIController::StaticClass();
}
struct Z_Construct_UClass_ACharger_AIController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Charger_AIController.h" },
		{ "ModuleRelativePath", "Public/Charger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Charger_BT_MetaData[] = {
		{ "Category", "Charger_AIController" },
		{ "ModuleRelativePath", "Public/Charger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Charger_BTC_MetaData[] = {
		{ "Category", "Charger_AIController" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Charger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Charger_BBC_MetaData[] = {
		{ "Category", "Charger_AIController" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Charger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialDistance_MetaData[] = {
		{ "Category", "AI Movement" },
		{ "ModuleRelativePath", "Public/Charger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Player_MetaData[] = {
		{ "ModuleRelativePath", "Public/Charger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Charger_PerceptionComponent_MetaData[] = {
		{ "Category", "Charger_AIController" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Charger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChargingDistance_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "Public/Charger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChargingSpeed_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "Public/Charger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NormalSpeed_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "Public/Charger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChargeCooldown_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "Public/Charger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChargeOvershootDistance_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "Public/Charger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WanderRadius_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "Public/Charger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WanderingPoint_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "Public/Charger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentCooldownTime_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "Public/Charger_AIController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Charger_BT;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Charger_BTC;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Charger_BBC;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InitialDistance;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Player;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Charger_PerceptionComponent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ChargingDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ChargingSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NormalSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ChargeCooldown;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ChargeOvershootDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WanderRadius;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WanderingPoint_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_WanderingPoint;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentCooldownTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ACharger_AIController_OnSeenPawn, "OnSeenPawn" }, // 1808354766
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACharger_AIController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACharger_AIController_Statics::NewProp_Charger_BT = { "Charger_BT", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharger_AIController, Charger_BT), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Charger_BT_MetaData), NewProp_Charger_BT_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACharger_AIController_Statics::NewProp_Charger_BTC = { "Charger_BTC", nullptr, (EPropertyFlags)0x0040000000090009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharger_AIController, Charger_BTC), Z_Construct_UClass_UBehaviorTreeComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Charger_BTC_MetaData), NewProp_Charger_BTC_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACharger_AIController_Statics::NewProp_Charger_BBC = { "Charger_BBC", nullptr, (EPropertyFlags)0x0040000000090009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharger_AIController, Charger_BBC), Z_Construct_UClass_UBlackboardComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Charger_BBC_MetaData), NewProp_Charger_BBC_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACharger_AIController_Statics::NewProp_InitialDistance = { "InitialDistance", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharger_AIController, InitialDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialDistance_MetaData), NewProp_InitialDistance_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACharger_AIController_Statics::NewProp_Player = { "Player", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharger_AIController, Player), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Player_MetaData), NewProp_Player_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACharger_AIController_Statics::NewProp_Charger_PerceptionComponent = { "Charger_PerceptionComponent", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharger_AIController, Charger_PerceptionComponent), Z_Construct_UClass_UPawnSensingComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Charger_PerceptionComponent_MetaData), NewProp_Charger_PerceptionComponent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACharger_AIController_Statics::NewProp_ChargingDistance = { "ChargingDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharger_AIController, ChargingDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChargingDistance_MetaData), NewProp_ChargingDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACharger_AIController_Statics::NewProp_ChargingSpeed = { "ChargingSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharger_AIController, ChargingSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChargingSpeed_MetaData), NewProp_ChargingSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACharger_AIController_Statics::NewProp_NormalSpeed = { "NormalSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharger_AIController, NormalSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NormalSpeed_MetaData), NewProp_NormalSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACharger_AIController_Statics::NewProp_ChargeCooldown = { "ChargeCooldown", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharger_AIController, ChargeCooldown), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChargeCooldown_MetaData), NewProp_ChargeCooldown_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACharger_AIController_Statics::NewProp_ChargeOvershootDistance = { "ChargeOvershootDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharger_AIController, ChargeOvershootDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChargeOvershootDistance_MetaData), NewProp_ChargeOvershootDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACharger_AIController_Statics::NewProp_WanderRadius = { "WanderRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharger_AIController, WanderRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WanderRadius_MetaData), NewProp_WanderRadius_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACharger_AIController_Statics::NewProp_WanderingPoint_Inner = { "WanderingPoint", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AWandering_Target_Point_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ACharger_AIController_Statics::NewProp_WanderingPoint = { "WanderingPoint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharger_AIController, WanderingPoint), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WanderingPoint_MetaData), NewProp_WanderingPoint_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACharger_AIController_Statics::NewProp_CurrentCooldownTime = { "CurrentCooldownTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharger_AIController, CurrentCooldownTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentCooldownTime_MetaData), NewProp_CurrentCooldownTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACharger_AIController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharger_AIController_Statics::NewProp_Charger_BT,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharger_AIController_Statics::NewProp_Charger_BTC,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharger_AIController_Statics::NewProp_Charger_BBC,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharger_AIController_Statics::NewProp_InitialDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharger_AIController_Statics::NewProp_Player,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharger_AIController_Statics::NewProp_Charger_PerceptionComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharger_AIController_Statics::NewProp_ChargingDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharger_AIController_Statics::NewProp_ChargingSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharger_AIController_Statics::NewProp_NormalSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharger_AIController_Statics::NewProp_ChargeCooldown,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharger_AIController_Statics::NewProp_ChargeOvershootDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharger_AIController_Statics::NewProp_WanderRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharger_AIController_Statics::NewProp_WanderingPoint_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharger_AIController_Statics::NewProp_WanderingPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharger_AIController_Statics::NewProp_CurrentCooldownTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACharger_AIController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACharger_AIController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACharger_AIController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACharger_AIController_Statics::ClassParams = {
	&ACharger_AIController::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ACharger_AIController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ACharger_AIController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACharger_AIController_Statics::Class_MetaDataParams), Z_Construct_UClass_ACharger_AIController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACharger_AIController()
{
	if (!Z_Registration_Info_UClass_ACharger_AIController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACharger_AIController.OuterSingleton, Z_Construct_UClass_ACharger_AIController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACharger_AIController.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<ACharger_AIController>()
{
	return ACharger_AIController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACharger_AIController);
ACharger_AIController::~ACharger_AIController() {}
// End Class ACharger_AIController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Charger_AIController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACharger_AIController, ACharger_AIController::StaticClass, TEXT("ACharger_AIController"), &Z_Registration_Info_UClass_ACharger_AIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACharger_AIController), 257865108U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Charger_AIController_h_3640625367(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Charger_AIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Charger_AIController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
