// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/AIController_SmallCharger.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAIController_SmallCharger() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
AIMODULE_API UClass* Z_Construct_UClass_UPawnSensingComponent_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_AAIController_SmallCharger();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_AAIController_SmallCharger_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class AAIController_SmallCharger Function OnEnemySeenItsOwner
struct Z_Construct_UFunction_AAIController_SmallCharger_OnEnemySeenItsOwner_Statics
{
	struct AIController_SmallCharger_eventOnEnemySeenItsOwner_Parms
	{
		APawn* SensedPawn;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AIController_SmallCharger.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SensedPawn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AAIController_SmallCharger_OnEnemySeenItsOwner_Statics::NewProp_SensedPawn = { "SensedPawn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AIController_SmallCharger_eventOnEnemySeenItsOwner_Parms, SensedPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AAIController_SmallCharger_OnEnemySeenItsOwner_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAIController_SmallCharger_OnEnemySeenItsOwner_Statics::NewProp_SensedPawn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AAIController_SmallCharger_OnEnemySeenItsOwner_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AAIController_SmallCharger_OnEnemySeenItsOwner_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AAIController_SmallCharger, nullptr, "OnEnemySeenItsOwner", nullptr, nullptr, Z_Construct_UFunction_AAIController_SmallCharger_OnEnemySeenItsOwner_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AAIController_SmallCharger_OnEnemySeenItsOwner_Statics::PropPointers), sizeof(Z_Construct_UFunction_AAIController_SmallCharger_OnEnemySeenItsOwner_Statics::AIController_SmallCharger_eventOnEnemySeenItsOwner_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AAIController_SmallCharger_OnEnemySeenItsOwner_Statics::Function_MetaDataParams), Z_Construct_UFunction_AAIController_SmallCharger_OnEnemySeenItsOwner_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AAIController_SmallCharger_OnEnemySeenItsOwner_Statics::AIController_SmallCharger_eventOnEnemySeenItsOwner_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AAIController_SmallCharger_OnEnemySeenItsOwner()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AAIController_SmallCharger_OnEnemySeenItsOwner_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AAIController_SmallCharger::execOnEnemySeenItsOwner)
{
	P_GET_OBJECT(APawn,Z_Param_SensedPawn);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnEnemySeenItsOwner(Z_Param_SensedPawn);
	P_NATIVE_END;
}
// End Class AAIController_SmallCharger Function OnEnemySeenItsOwner

// Begin Class AAIController_SmallCharger
void AAIController_SmallCharger::StaticRegisterNativesAAIController_SmallCharger()
{
	UClass* Class = AAIController_SmallCharger::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnEnemySeenItsOwner", &AAIController_SmallCharger::execOnEnemySeenItsOwner },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAIController_SmallCharger);
UClass* Z_Construct_UClass_AAIController_SmallCharger_NoRegister()
{
	return AAIController_SmallCharger::StaticClass();
}
struct Z_Construct_UClass_AAIController_SmallCharger_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "AIController_SmallCharger.h" },
		{ "ModuleRelativePath", "Public/AIController_SmallCharger.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SmallCharger_BT_MetaData[] = {
		{ "Category", "AIController_SmallCharger" },
		{ "ModuleRelativePath", "Public/AIController_SmallCharger.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SmallCharger_PercetionComponent_MetaData[] = {
		{ "Category", "AIController_SmallCharger" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/AIController_SmallCharger.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SmallCharger_BT;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SmallCharger_PercetionComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AAIController_SmallCharger_OnEnemySeenItsOwner, "OnEnemySeenItsOwner" }, // 3072103081
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAIController_SmallCharger>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAIController_SmallCharger_Statics::NewProp_SmallCharger_BT = { "SmallCharger_BT", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAIController_SmallCharger, SmallCharger_BT), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SmallCharger_BT_MetaData), NewProp_SmallCharger_BT_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAIController_SmallCharger_Statics::NewProp_SmallCharger_PercetionComponent = { "SmallCharger_PercetionComponent", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAIController_SmallCharger, SmallCharger_PercetionComponent), Z_Construct_UClass_UPawnSensingComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SmallCharger_PercetionComponent_MetaData), NewProp_SmallCharger_PercetionComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAIController_SmallCharger_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAIController_SmallCharger_Statics::NewProp_SmallCharger_BT,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAIController_SmallCharger_Statics::NewProp_SmallCharger_PercetionComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAIController_SmallCharger_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AAIController_SmallCharger_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAIController_SmallCharger_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AAIController_SmallCharger_Statics::ClassParams = {
	&AAIController_SmallCharger::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AAIController_SmallCharger_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AAIController_SmallCharger_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAIController_SmallCharger_Statics::Class_MetaDataParams), Z_Construct_UClass_AAIController_SmallCharger_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AAIController_SmallCharger()
{
	if (!Z_Registration_Info_UClass_AAIController_SmallCharger.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAIController_SmallCharger.OuterSingleton, Z_Construct_UClass_AAIController_SmallCharger_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AAIController_SmallCharger.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<AAIController_SmallCharger>()
{
	return AAIController_SmallCharger::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AAIController_SmallCharger);
AAIController_SmallCharger::~AAIController_SmallCharger() {}
// End Class AAIController_SmallCharger

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_AIController_SmallCharger_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AAIController_SmallCharger, AAIController_SmallCharger::StaticClass, TEXT("AAIController_SmallCharger"), &Z_Registration_Info_UClass_AAIController_SmallCharger, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAIController_SmallCharger), 3708130909U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_AIController_SmallCharger_h_1696807344(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_AIController_SmallCharger_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_AIController_SmallCharger_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
