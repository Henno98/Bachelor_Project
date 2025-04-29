// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/World/BasicPlatform.h"
#include "Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBasicPlatform() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ABasicPlatform();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ABasicPlatform_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class ABasicPlatform Function LeftTriggerBox
struct Z_Construct_UFunction_ABasicPlatform_LeftTriggerBox_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Function to handle the end overlap event\n" },
#endif
		{ "ModuleRelativePath", "Public/World/BasicPlatform.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Function to handle the end overlap event" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABasicPlatform_LeftTriggerBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABasicPlatform, nullptr, "LeftTriggerBox", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABasicPlatform_LeftTriggerBox_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABasicPlatform_LeftTriggerBox_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ABasicPlatform_LeftTriggerBox()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABasicPlatform_LeftTriggerBox_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABasicPlatform::execLeftTriggerBox)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->LeftTriggerBox();
	P_NATIVE_END;
}
// End Class ABasicPlatform Function LeftTriggerBox

// Begin Class ABasicPlatform Function OnPlayerEnterTrigger
struct Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics
{
	struct BasicPlatform_eventOnPlayerEnterTrigger_Parms
	{
		UPrimitiveComponent* OverlappedComponent;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComp;
		int32 OtherBodyIndex;
		bool bFromSweep;
		FHitResult SweepResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// When the player enters the trigger, show tutorial text\n" },
#endif
		{ "ModuleRelativePath", "Public/World/BasicPlatform.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When the player enters the trigger, show tutorial text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static void NewProp_bFromSweep_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SweepResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BasicPlatform_eventOnPlayerEnterTrigger_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComponent_MetaData), NewProp_OverlappedComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BasicPlatform_eventOnPlayerEnterTrigger_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BasicPlatform_eventOnPlayerEnterTrigger_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BasicPlatform_eventOnPlayerEnterTrigger_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::NewProp_bFromSweep_SetBit(void* Obj)
{
	((BasicPlatform_eventOnPlayerEnterTrigger_Parms*)Obj)->bFromSweep = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BasicPlatform_eventOnPlayerEnterTrigger_Parms), &Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BasicPlatform_eventOnPlayerEnterTrigger_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SweepResult_MetaData), NewProp_SweepResult_MetaData) }; // 4100991306
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::NewProp_OverlappedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::NewProp_OtherBodyIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::NewProp_bFromSweep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::NewProp_SweepResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABasicPlatform, nullptr, "OnPlayerEnterTrigger", nullptr, nullptr, Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::PropPointers), sizeof(Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::BasicPlatform_eventOnPlayerEnterTrigger_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::BasicPlatform_eventOnPlayerEnterTrigger_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABasicPlatform::execOnPlayerEnterTrigger)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_GET_UBOOL(Z_Param_bFromSweep);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnPlayerEnterTrigger(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
	P_NATIVE_END;
}
// End Class ABasicPlatform Function OnPlayerEnterTrigger

// Begin Class ABasicPlatform
void ABasicPlatform::StaticRegisterNativesABasicPlatform()
{
	UClass* Class = ABasicPlatform::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "LeftTriggerBox", &ABasicPlatform::execLeftTriggerBox },
		{ "OnPlayerEnterTrigger", &ABasicPlatform::execOnPlayerEnterTrigger },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABasicPlatform);
UClass* Z_Construct_UClass_ABasicPlatform_NoRegister()
{
	return ABasicPlatform::StaticClass();
}
struct Z_Construct_UClass_ABasicPlatform_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "World/BasicPlatform.h" },
		{ "ModuleRelativePath", "Public/World/BasicPlatform.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TriggerBox_MetaData[] = {
		{ "Category", "BasicPlatform" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Trigger Volume component\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/World/BasicPlatform.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Trigger Volume component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TutorialText_MetaData[] = {
		{ "Category", "Tutorial" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Tutorial text to show when player enters the volume\n" },
#endif
		{ "ModuleRelativePath", "Public/World/BasicPlatform.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tutorial text to show when player enters the volume" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TriggerBox;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TutorialText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ABasicPlatform_LeftTriggerBox, "LeftTriggerBox" }, // 2290916888
		{ &Z_Construct_UFunction_ABasicPlatform_OnPlayerEnterTrigger, "OnPlayerEnterTrigger" }, // 3521328346
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABasicPlatform>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABasicPlatform_Statics::NewProp_TriggerBox = { "TriggerBox", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABasicPlatform, TriggerBox), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TriggerBox_MetaData), NewProp_TriggerBox_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ABasicPlatform_Statics::NewProp_TutorialText = { "TutorialText", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABasicPlatform, TutorialText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TutorialText_MetaData), NewProp_TutorialText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABasicPlatform_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABasicPlatform_Statics::NewProp_TriggerBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABasicPlatform_Statics::NewProp_TutorialText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABasicPlatform_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABasicPlatform_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABasicPlatform_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABasicPlatform_Statics::ClassParams = {
	&ABasicPlatform::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ABasicPlatform_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ABasicPlatform_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABasicPlatform_Statics::Class_MetaDataParams), Z_Construct_UClass_ABasicPlatform_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABasicPlatform()
{
	if (!Z_Registration_Info_UClass_ABasicPlatform.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABasicPlatform.OuterSingleton, Z_Construct_UClass_ABasicPlatform_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABasicPlatform.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<ABasicPlatform>()
{
	return ABasicPlatform::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABasicPlatform);
ABasicPlatform::~ABasicPlatform() {}
// End Class ABasicPlatform

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_World_BasicPlatform_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABasicPlatform, ABasicPlatform::StaticClass, TEXT("ABasicPlatform"), &Z_Registration_Info_UClass_ABasicPlatform, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABasicPlatform), 4017711234U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_World_BasicPlatform_h_1978518467(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_World_BasicPlatform_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_World_BasicPlatform_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
