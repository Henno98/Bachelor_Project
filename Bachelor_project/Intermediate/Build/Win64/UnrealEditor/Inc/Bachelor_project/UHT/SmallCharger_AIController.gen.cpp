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
AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTreeComponent_NoRegister();
AIMODULE_API UClass* Z_Construct_UClass_UBlackboardComponent_NoRegister();
AIMODULE_API UClass* Z_Construct_UClass_UPawnSensingComponent_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ASmallCharger_AIController();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ASmallCharger_AIController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class ASmallCharger_AIController Function OnSeenPawn
struct Z_Construct_UFunction_ASmallCharger_AIController_OnSeenPawn_Statics
{
	struct SmallCharger_AIController_eventOnSeenPawn_Parms
	{
		APawn* SeenPawn;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SmallCharger_AIController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SeenPawn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASmallCharger_AIController_OnSeenPawn_Statics::NewProp_SeenPawn = { "SeenPawn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SmallCharger_AIController_eventOnSeenPawn_Parms, SeenPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASmallCharger_AIController_OnSeenPawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASmallCharger_AIController_OnSeenPawn_Statics::NewProp_SeenPawn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASmallCharger_AIController_OnSeenPawn_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASmallCharger_AIController_OnSeenPawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASmallCharger_AIController, nullptr, "OnSeenPawn", nullptr, nullptr, Z_Construct_UFunction_ASmallCharger_AIController_OnSeenPawn_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASmallCharger_AIController_OnSeenPawn_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASmallCharger_AIController_OnSeenPawn_Statics::SmallCharger_AIController_eventOnSeenPawn_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASmallCharger_AIController_OnSeenPawn_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASmallCharger_AIController_OnSeenPawn_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASmallCharger_AIController_OnSeenPawn_Statics::SmallCharger_AIController_eventOnSeenPawn_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASmallCharger_AIController_OnSeenPawn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASmallCharger_AIController_OnSeenPawn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASmallCharger_AIController::execOnSeenPawn)
{
	P_GET_OBJECT(APawn,Z_Param_SeenPawn);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnSeenPawn(Z_Param_SeenPawn);
	P_NATIVE_END;
}
// End Class ASmallCharger_AIController Function OnSeenPawn

// Begin Class ASmallCharger_AIController
void ASmallCharger_AIController::StaticRegisterNativesASmallCharger_AIController()
{
	UClass* Class = ASmallCharger_AIController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnSeenPawn", &ASmallCharger_AIController::execOnSeenPawn },
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
		{ "Comment", "/**\n *\n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "SmallCharger_AIController.h" },
		{ "ModuleRelativePath", "Public/SmallCharger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SmallCharger_BT_MetaData[] = {
		{ "Category", "SmallCharger_AIController" },
		{ "ModuleRelativePath", "Public/SmallCharger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SmallCharger_BTC_MetaData[] = {
		{ "Category", "SmallCharger_AIController" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SmallCharger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SmallCharger_BBC_MetaData[] = {
		{ "Category", "SmallCharger_AIController" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SmallCharger_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SmallCharger_PerceptionComponent_MetaData[] = {
		{ "Category", "SmallCharger_AIController" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SmallCharger_AIController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SmallCharger_BT;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SmallCharger_BTC;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SmallCharger_BBC;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SmallCharger_PerceptionComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ASmallCharger_AIController_OnSeenPawn, "OnSeenPawn" }, // 3939285132
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASmallCharger_AIController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASmallCharger_AIController_Statics::NewProp_SmallCharger_BT = { "SmallCharger_BT", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASmallCharger_AIController, SmallCharger_BT), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SmallCharger_BT_MetaData), NewProp_SmallCharger_BT_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASmallCharger_AIController_Statics::NewProp_SmallCharger_BTC = { "SmallCharger_BTC", nullptr, (EPropertyFlags)0x0040000000090009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASmallCharger_AIController, SmallCharger_BTC), Z_Construct_UClass_UBehaviorTreeComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SmallCharger_BTC_MetaData), NewProp_SmallCharger_BTC_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASmallCharger_AIController_Statics::NewProp_SmallCharger_BBC = { "SmallCharger_BBC", nullptr, (EPropertyFlags)0x0040000000090009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASmallCharger_AIController, SmallCharger_BBC), Z_Construct_UClass_UBlackboardComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SmallCharger_BBC_MetaData), NewProp_SmallCharger_BBC_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASmallCharger_AIController_Statics::NewProp_SmallCharger_PerceptionComponent = { "SmallCharger_PerceptionComponent", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASmallCharger_AIController, SmallCharger_PerceptionComponent), Z_Construct_UClass_UPawnSensingComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SmallCharger_PerceptionComponent_MetaData), NewProp_SmallCharger_PerceptionComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASmallCharger_AIController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASmallCharger_AIController_Statics::NewProp_SmallCharger_BT,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASmallCharger_AIController_Statics::NewProp_SmallCharger_BTC,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASmallCharger_AIController_Statics::NewProp_SmallCharger_BBC,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASmallCharger_AIController_Statics::NewProp_SmallCharger_PerceptionComponent,
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
struct Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_AIController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASmallCharger_AIController, ASmallCharger_AIController::StaticClass, TEXT("ASmallCharger_AIController"), &Z_Registration_Info_UClass_ASmallCharger_AIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASmallCharger_AIController), 895574674U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_AIController_h_1374316505(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_AIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_AIController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
