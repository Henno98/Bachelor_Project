// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Enemies/CrowBoss_AIController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCrowBoss_AIController() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTreeComponent_NoRegister();
AIMODULE_API UClass* Z_Construct_UClass_UBlackboardComponent_NoRegister();
AIMODULE_API UClass* Z_Construct_UClass_UPawnSensingComponent_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ACrowBoss_AIController();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ACrowBoss_AIController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class ACrowBoss_AIController Function OnSeenPawn
struct Z_Construct_UFunction_ACrowBoss_AIController_OnSeenPawn_Statics
{
	struct CrowBoss_AIController_eventOnSeenPawn_Parms
	{
		APawn* SeenPawn;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Enemies/CrowBoss_AIController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SeenPawn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACrowBoss_AIController_OnSeenPawn_Statics::NewProp_SeenPawn = { "SeenPawn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CrowBoss_AIController_eventOnSeenPawn_Parms, SeenPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACrowBoss_AIController_OnSeenPawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACrowBoss_AIController_OnSeenPawn_Statics::NewProp_SeenPawn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_AIController_OnSeenPawn_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACrowBoss_AIController_OnSeenPawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACrowBoss_AIController, nullptr, "OnSeenPawn", nullptr, nullptr, Z_Construct_UFunction_ACrowBoss_AIController_OnSeenPawn_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_AIController_OnSeenPawn_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACrowBoss_AIController_OnSeenPawn_Statics::CrowBoss_AIController_eventOnSeenPawn_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACrowBoss_AIController_OnSeenPawn_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACrowBoss_AIController_OnSeenPawn_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACrowBoss_AIController_OnSeenPawn_Statics::CrowBoss_AIController_eventOnSeenPawn_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACrowBoss_AIController_OnSeenPawn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACrowBoss_AIController_OnSeenPawn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACrowBoss_AIController::execOnSeenPawn)
{
	P_GET_OBJECT(APawn,Z_Param_SeenPawn);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnSeenPawn(Z_Param_SeenPawn);
	P_NATIVE_END;
}
// End Class ACrowBoss_AIController Function OnSeenPawn

// Begin Class ACrowBoss_AIController
void ACrowBoss_AIController::StaticRegisterNativesACrowBoss_AIController()
{
	UClass* Class = ACrowBoss_AIController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnSeenPawn", &ACrowBoss_AIController::execOnSeenPawn },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACrowBoss_AIController);
UClass* Z_Construct_UClass_ACrowBoss_AIController_NoRegister()
{
	return ACrowBoss_AIController::StaticClass();
}
struct Z_Construct_UClass_ACrowBoss_AIController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Enemies/CrowBoss_AIController.h" },
		{ "ModuleRelativePath", "Public/Enemies/CrowBoss_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CrowBoss_BT_MetaData[] = {
		{ "Category", "CrowBoss_AIController" },
		{ "ModuleRelativePath", "Public/Enemies/CrowBoss_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CrowBoss_BTC_MetaData[] = {
		{ "Category", "CrowBoss_AIController" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Enemies/CrowBoss_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CrowBoss_BBC_MetaData[] = {
		{ "Category", "CrowBoss_AIController" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Enemies/CrowBoss_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Player_MetaData[] = {
		{ "ModuleRelativePath", "Public/Enemies/CrowBoss_AIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CrowBoss_PerceptionComponent_MetaData[] = {
		{ "Category", "CrowBoss_AIController" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Enemies/CrowBoss_AIController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CrowBoss_BT;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CrowBoss_BTC;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CrowBoss_BBC;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Player;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CrowBoss_PerceptionComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ACrowBoss_AIController_OnSeenPawn, "OnSeenPawn" }, // 3143085149
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACrowBoss_AIController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACrowBoss_AIController_Statics::NewProp_CrowBoss_BT = { "CrowBoss_BT", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACrowBoss_AIController, CrowBoss_BT), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CrowBoss_BT_MetaData), NewProp_CrowBoss_BT_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACrowBoss_AIController_Statics::NewProp_CrowBoss_BTC = { "CrowBoss_BTC", nullptr, (EPropertyFlags)0x0040000000090009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACrowBoss_AIController, CrowBoss_BTC), Z_Construct_UClass_UBehaviorTreeComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CrowBoss_BTC_MetaData), NewProp_CrowBoss_BTC_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACrowBoss_AIController_Statics::NewProp_CrowBoss_BBC = { "CrowBoss_BBC", nullptr, (EPropertyFlags)0x0040000000090009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACrowBoss_AIController, CrowBoss_BBC), Z_Construct_UClass_UBlackboardComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CrowBoss_BBC_MetaData), NewProp_CrowBoss_BBC_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACrowBoss_AIController_Statics::NewProp_Player = { "Player", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACrowBoss_AIController, Player), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Player_MetaData), NewProp_Player_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACrowBoss_AIController_Statics::NewProp_CrowBoss_PerceptionComponent = { "CrowBoss_PerceptionComponent", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACrowBoss_AIController, CrowBoss_PerceptionComponent), Z_Construct_UClass_UPawnSensingComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CrowBoss_PerceptionComponent_MetaData), NewProp_CrowBoss_PerceptionComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACrowBoss_AIController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowBoss_AIController_Statics::NewProp_CrowBoss_BT,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowBoss_AIController_Statics::NewProp_CrowBoss_BTC,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowBoss_AIController_Statics::NewProp_CrowBoss_BBC,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowBoss_AIController_Statics::NewProp_Player,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrowBoss_AIController_Statics::NewProp_CrowBoss_PerceptionComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACrowBoss_AIController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACrowBoss_AIController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACrowBoss_AIController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACrowBoss_AIController_Statics::ClassParams = {
	&ACrowBoss_AIController::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ACrowBoss_AIController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ACrowBoss_AIController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACrowBoss_AIController_Statics::Class_MetaDataParams), Z_Construct_UClass_ACrowBoss_AIController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACrowBoss_AIController()
{
	if (!Z_Registration_Info_UClass_ACrowBoss_AIController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACrowBoss_AIController.OuterSingleton, Z_Construct_UClass_ACrowBoss_AIController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACrowBoss_AIController.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<ACrowBoss_AIController>()
{
	return ACrowBoss_AIController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACrowBoss_AIController);
ACrowBoss_AIController::~ACrowBoss_AIController() {}
// End Class ACrowBoss_AIController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowBoss_AIController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACrowBoss_AIController, ACrowBoss_AIController::StaticClass, TEXT("ACrowBoss_AIController"), &Z_Registration_Info_UClass_ACrowBoss_AIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACrowBoss_AIController), 3364194676U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowBoss_AIController_h_2352265286(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowBoss_AIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowBoss_AIController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
