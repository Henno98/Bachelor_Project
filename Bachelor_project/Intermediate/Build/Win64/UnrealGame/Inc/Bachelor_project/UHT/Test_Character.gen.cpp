// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Player/Test_Character.h"
#include "EnhancedInput/Public/InputActionValue.h"
#include "Runtime/Engine/Classes/Engine/HitResult.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTest_Character() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_APlayer_HUD_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_Aprojectile_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ATest_Character();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ATest_Character_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UGAS_Dash_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UGAS_Double_Jump_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UGAS_Ranged_Attack_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UGAS_Wall_Latch_NoRegister();
BACHELOR_PROJECT_API UFunction* Z_Construct_UDelegateFunction_Bachelor_project_OnHealthChangedSignature__DelegateSignature();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UAnimationAsset_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
ENHANCEDINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FInputActionValue();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemInterface_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Delegate FOnHealthChangedSignature
struct Z_Construct_UDelegateFunction_Bachelor_project_OnHealthChangedSignature__DelegateSignature_Statics
{
	struct _Script_Bachelor_project_eventOnHealthChangedSignature_Parms
	{
		int32 NewHealth;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_NewHealth;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_Bachelor_project_OnHealthChangedSignature__DelegateSignature_Statics::NewProp_NewHealth = { "NewHealth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Bachelor_project_eventOnHealthChangedSignature_Parms, NewHealth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Bachelor_project_OnHealthChangedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Bachelor_project_OnHealthChangedSignature__DelegateSignature_Statics::NewProp_NewHealth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Bachelor_project_OnHealthChangedSignature__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Bachelor_project_OnHealthChangedSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Bachelor_project, nullptr, "OnHealthChangedSignature__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_Bachelor_project_OnHealthChangedSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Bachelor_project_OnHealthChangedSignature__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Bachelor_project_OnHealthChangedSignature__DelegateSignature_Statics::_Script_Bachelor_project_eventOnHealthChangedSignature_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Bachelor_project_OnHealthChangedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Bachelor_project_OnHealthChangedSignature__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_Bachelor_project_OnHealthChangedSignature__DelegateSignature_Statics::_Script_Bachelor_project_eventOnHealthChangedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Bachelor_project_OnHealthChangedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Bachelor_project_OnHealthChangedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnHealthChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& OnHealthChangedSignature, int32 NewHealth)
{
	struct _Script_Bachelor_project_eventOnHealthChangedSignature_Parms
	{
		int32 NewHealth;
	};
	_Script_Bachelor_project_eventOnHealthChangedSignature_Parms Parms;
	Parms.NewHealth=NewHealth;
	OnHealthChangedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnHealthChangedSignature

// Begin Class ATest_Character Function EndMeleeAttack
struct Z_Construct_UFunction_ATest_Character_EndMeleeAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATest_Character_EndMeleeAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATest_Character, nullptr, "EndMeleeAttack", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATest_Character_EndMeleeAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATest_Character_EndMeleeAttack_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ATest_Character_EndMeleeAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATest_Character_EndMeleeAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATest_Character::execEndMeleeAttack)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EndMeleeAttack();
	P_NATIVE_END;
}
// End Class ATest_Character Function EndMeleeAttack

// Begin Class ATest_Character Function LoadGame
struct Z_Construct_UFunction_ATest_Character_LoadGame_Statics
{
	struct Test_Character_eventLoadGame_Parms
	{
		FString slotname;
		int32 slotnumber;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_slotname;
	static const UECodeGen_Private::FIntPropertyParams NewProp_slotnumber;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATest_Character_LoadGame_Statics::NewProp_slotname = { "slotname", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Test_Character_eventLoadGame_Parms, slotname), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ATest_Character_LoadGame_Statics::NewProp_slotnumber = { "slotnumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Test_Character_eventLoadGame_Parms, slotnumber), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATest_Character_LoadGame_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATest_Character_LoadGame_Statics::NewProp_slotname,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATest_Character_LoadGame_Statics::NewProp_slotnumber,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATest_Character_LoadGame_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATest_Character_LoadGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATest_Character, nullptr, "LoadGame", nullptr, nullptr, Z_Construct_UFunction_ATest_Character_LoadGame_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATest_Character_LoadGame_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATest_Character_LoadGame_Statics::Test_Character_eventLoadGame_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATest_Character_LoadGame_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATest_Character_LoadGame_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATest_Character_LoadGame_Statics::Test_Character_eventLoadGame_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATest_Character_LoadGame()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATest_Character_LoadGame_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATest_Character::execLoadGame)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_slotname);
	P_GET_PROPERTY(FIntProperty,Z_Param_slotnumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->LoadGame(Z_Param_slotname,Z_Param_slotnumber);
	P_NATIVE_END;
}
// End Class ATest_Character Function LoadGame

// Begin Class ATest_Character Function MeleeAttack
struct Z_Construct_UFunction_ATest_Character_MeleeAttack_Statics
{
	struct Test_Character_eventMeleeAttack_Parms
	{
		FInputActionValue Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATest_Character_MeleeAttack_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Test_Character_eventMeleeAttack_Parms, Value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATest_Character_MeleeAttack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATest_Character_MeleeAttack_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATest_Character_MeleeAttack_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATest_Character_MeleeAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATest_Character, nullptr, "MeleeAttack", nullptr, nullptr, Z_Construct_UFunction_ATest_Character_MeleeAttack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATest_Character_MeleeAttack_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATest_Character_MeleeAttack_Statics::Test_Character_eventMeleeAttack_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATest_Character_MeleeAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATest_Character_MeleeAttack_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATest_Character_MeleeAttack_Statics::Test_Character_eventMeleeAttack_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATest_Character_MeleeAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATest_Character_MeleeAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATest_Character::execMeleeAttack)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->MeleeAttack(Z_Param_Out_Value);
	P_NATIVE_END;
}
// End Class ATest_Character Function MeleeAttack

// Begin Class ATest_Character Function Move
struct Z_Construct_UFunction_ATest_Character_Move_Statics
{
	struct Test_Character_eventMove_Parms
	{
		FInputActionValue Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATest_Character_Move_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Test_Character_eventMove_Parms, Value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATest_Character_Move_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATest_Character_Move_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATest_Character_Move_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATest_Character_Move_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATest_Character, nullptr, "Move", nullptr, nullptr, Z_Construct_UFunction_ATest_Character_Move_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATest_Character_Move_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATest_Character_Move_Statics::Test_Character_eventMove_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATest_Character_Move_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATest_Character_Move_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATest_Character_Move_Statics::Test_Character_eventMove_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATest_Character_Move()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATest_Character_Move_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATest_Character::execMove)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Move(Z_Param_Out_Value);
	P_NATIVE_END;
}
// End Class ATest_Character Function Move

// Begin Class ATest_Character Function OnOverlap
struct Z_Construct_UFunction_ATest_Character_OnOverlap_Statics
{
	struct Test_Character_eventOnOverlap_Parms
	{
		UPrimitiveComponent* OverlappedComponent;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComponent;
		int32 OtherBodyIndex;
		bool bFromSweep;
		FHitResult SweepResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComponent;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static void NewProp_bFromSweep_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SweepResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Test_Character_eventOnOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComponent_MetaData), NewProp_OverlappedComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Test_Character_eventOnOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::NewProp_OtherComponent = { "OtherComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Test_Character_eventOnOverlap_Parms, OtherComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComponent_MetaData), NewProp_OtherComponent_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Test_Character_eventOnOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::NewProp_bFromSweep_SetBit(void* Obj)
{
	((Test_Character_eventOnOverlap_Parms*)Obj)->bFromSweep = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Test_Character_eventOnOverlap_Parms), &Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Test_Character_eventOnOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SweepResult_MetaData), NewProp_SweepResult_MetaData) }; // 4100991306
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::NewProp_OverlappedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::NewProp_OtherComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::NewProp_OtherBodyIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::NewProp_bFromSweep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::NewProp_SweepResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATest_Character, nullptr, "OnOverlap", nullptr, nullptr, Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::Test_Character_eventOnOverlap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::Test_Character_eventOnOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATest_Character_OnOverlap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATest_Character_OnOverlap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATest_Character::execOnOverlap)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComponent);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_GET_UBOOL(Z_Param_bFromSweep);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComponent,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
	P_NATIVE_END;
}
// End Class ATest_Character Function OnOverlap

// Begin Class ATest_Character Function SaveGame
struct Z_Construct_UFunction_ATest_Character_SaveGame_Statics
{
	struct Test_Character_eventSaveGame_Parms
	{
		FString slotname;
		int32 slotnumber;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_slotname;
	static const UECodeGen_Private::FIntPropertyParams NewProp_slotnumber;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATest_Character_SaveGame_Statics::NewProp_slotname = { "slotname", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Test_Character_eventSaveGame_Parms, slotname), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ATest_Character_SaveGame_Statics::NewProp_slotnumber = { "slotnumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Test_Character_eventSaveGame_Parms, slotnumber), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATest_Character_SaveGame_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATest_Character_SaveGame_Statics::NewProp_slotname,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATest_Character_SaveGame_Statics::NewProp_slotnumber,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATest_Character_SaveGame_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATest_Character_SaveGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATest_Character, nullptr, "SaveGame", nullptr, nullptr, Z_Construct_UFunction_ATest_Character_SaveGame_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATest_Character_SaveGame_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATest_Character_SaveGame_Statics::Test_Character_eventSaveGame_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATest_Character_SaveGame_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATest_Character_SaveGame_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATest_Character_SaveGame_Statics::Test_Character_eventSaveGame_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATest_Character_SaveGame()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATest_Character_SaveGame_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATest_Character::execSaveGame)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_slotname);
	P_GET_PROPERTY(FIntProperty,Z_Param_slotnumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SaveGame(Z_Param_slotname,Z_Param_slotnumber);
	P_NATIVE_END;
}
// End Class ATest_Character Function SaveGame

// Begin Class ATest_Character Function StopMoving
struct Z_Construct_UFunction_ATest_Character_StopMoving_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATest_Character_StopMoving_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATest_Character, nullptr, "StopMoving", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATest_Character_StopMoving_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATest_Character_StopMoving_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ATest_Character_StopMoving()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATest_Character_StopMoving_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATest_Character::execStopMoving)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopMoving();
	P_NATIVE_END;
}
// End Class ATest_Character Function StopMoving

// Begin Class ATest_Character
void ATest_Character::StaticRegisterNativesATest_Character()
{
	UClass* Class = ATest_Character::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "EndMeleeAttack", &ATest_Character::execEndMeleeAttack },
		{ "LoadGame", &ATest_Character::execLoadGame },
		{ "MeleeAttack", &ATest_Character::execMeleeAttack },
		{ "Move", &ATest_Character::execMove },
		{ "OnOverlap", &ATest_Character::execOnOverlap },
		{ "SaveGame", &ATest_Character::execSaveGame },
		{ "StopMoving", &ATest_Character::execStopMoving },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATest_Character);
UClass* Z_Construct_UClass_ATest_Character_NoRegister()
{
	return ATest_Character::StaticClass();
}
struct Z_Construct_UClass_ATest_Character_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Player/Test_Character.h" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnHealthChanged_MetaData[] = {
		{ "Category", "Events" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnEnergyChanged_MetaData[] = {
		{ "Category", "Events" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IdleAnim_MetaData[] = {
		{ "Category", "Animations" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Animations\n" },
#endif
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Animations" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeleeAnim_MetaData[] = {
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RangedAttackAnim_MetaData[] = {
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeathAnim_MetaData[] = {
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAnim_MetaData[] = {
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DashAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoubleJumpAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallLatchAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SaveAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LoadAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RangedAttackInput_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DropDownInput_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeleeInput_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MenuInput_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Springarm_MetaData[] = {
		{ "Category", "Test_Character" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//default components\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "default components" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HurtBox_MetaData[] = {
		{ "Category", "Hurtbox" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "Category", "Test_Character" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RangedAttackClass_MetaData[] = {
		{ "Category", "Projectile class" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsDashing_MetaData[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Animation/State flags\n" },
#endif
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Animation/State flags" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasDoubleJumped_MetaData[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsRunning_MetaData[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsMeleeAttacking_MetaData[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsRangedAttacking_MetaData[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DashCooldown_MetaData[] = {
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpVelocity_MetaData[] = {
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BulletSize_MetaData[] = {
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilitySystemComponent_MetaData[] = {
		{ "Category", "Test_Character" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[] = {
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[] = {
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxBioMass_MetaData[] = {
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BioMass_MetaData[] = {
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeleeDamage_MetaData[] = {
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RangedDamage_MetaData[] = {
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanSave_MetaData[] = {
		{ "Category", "Save" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GA_Double_Jump_MetaData[] = {
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpAbilityTag_MetaData[] = {
		{ "Category", "GASGameplayAbility" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GA_Wall_Latch_MetaData[] = {
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallLatchAbilityTag_MetaData[] = {
		{ "Category", "GASGameplayAbility" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GA_Dash_MetaData[] = {
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DashAbilityTag_MetaData[] = {
		{ "Category", "GASGameplayAbility" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GA_Ranged_Attack_MetaData[] = {
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RangedAttackAbilityTag_MetaData[] = {
		{ "Category", "GASGameplayAbility" },
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerHUD_MetaData[] = {
		{ "ModuleRelativePath", "Public/Player/Test_Character.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnHealthChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnEnergyChanged;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IdleAnim;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MeleeAnim;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RangedAttackAnim;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DeathAnim;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAnim;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DashAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DoubleJumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WallLatchAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SaveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LoadAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RangedAttackInput;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DropDownInput;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MeleeInput;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MenuInput;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Springarm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HurtBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static const UECodeGen_Private::FClassPropertyParams NewProp_RangedAttackClass;
	static void NewProp_bIsDashing_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsDashing;
	static void NewProp_bHasDoubleJumped_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasDoubleJumped;
	static void NewProp_bIsRunning_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsRunning;
	static void NewProp_bIsMeleeAttacking_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsMeleeAttacking;
	static void NewProp_bIsRangedAttacking_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsRangedAttacking;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DashCooldown;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_JumpVelocity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BulletSize;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AbilitySystemComponent;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxHealth;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Health;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxBioMass;
	static const UECodeGen_Private::FIntPropertyParams NewProp_BioMass;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MeleeDamage;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RangedDamage;
	static void NewProp_bCanSave_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanSave;
	static const UECodeGen_Private::FClassPropertyParams NewProp_GA_Double_Jump;
	static const UECodeGen_Private::FStructPropertyParams NewProp_JumpAbilityTag;
	static const UECodeGen_Private::FClassPropertyParams NewProp_GA_Wall_Latch;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WallLatchAbilityTag;
	static const UECodeGen_Private::FClassPropertyParams NewProp_GA_Dash;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DashAbilityTag;
	static const UECodeGen_Private::FClassPropertyParams NewProp_GA_Ranged_Attack;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RangedAttackAbilityTag;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerHUD;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ATest_Character_EndMeleeAttack, "EndMeleeAttack" }, // 1671132607
		{ &Z_Construct_UFunction_ATest_Character_LoadGame, "LoadGame" }, // 2594519604
		{ &Z_Construct_UFunction_ATest_Character_MeleeAttack, "MeleeAttack" }, // 4190055688
		{ &Z_Construct_UFunction_ATest_Character_Move, "Move" }, // 2151626114
		{ &Z_Construct_UFunction_ATest_Character_OnOverlap, "OnOverlap" }, // 3240729512
		{ &Z_Construct_UFunction_ATest_Character_SaveGame, "SaveGame" }, // 3123011433
		{ &Z_Construct_UFunction_ATest_Character_StopMoving, "StopMoving" }, // 1498487510
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATest_Character>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_OnHealthChanged = { "OnHealthChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, OnHealthChanged), Z_Construct_UDelegateFunction_Bachelor_project_OnHealthChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnHealthChanged_MetaData), NewProp_OnHealthChanged_MetaData) }; // 109266755
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_OnEnergyChanged = { "OnEnergyChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, OnEnergyChanged), Z_Construct_UDelegateFunction_Bachelor_project_OnHealthChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnEnergyChanged_MetaData), NewProp_OnEnergyChanged_MetaData) }; // 109266755
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_IdleAnim = { "IdleAnim", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, IdleAnim), Z_Construct_UClass_UAnimationAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IdleAnim_MetaData), NewProp_IdleAnim_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_MeleeAnim = { "MeleeAnim", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, MeleeAnim), Z_Construct_UClass_UAnimationAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeleeAnim_MetaData), NewProp_MeleeAnim_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_RangedAttackAnim = { "RangedAttackAnim", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, RangedAttackAnim), Z_Construct_UClass_UAnimationAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RangedAttackAnim_MetaData), NewProp_RangedAttackAnim_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_DeathAnim = { "DeathAnim", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, DeathAnim), Z_Construct_UClass_UAnimationAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeathAnim_MetaData), NewProp_DeathAnim_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_MoveAnim = { "MoveAnim", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, MoveAnim), Z_Construct_UClass_UAnimationAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAnim_MetaData), NewProp_MoveAnim_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultMappingContext_MetaData), NewProp_DefaultMappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAction_MetaData), NewProp_JumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_DashAction = { "DashAction", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, DashAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DashAction_MetaData), NewProp_DashAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_DoubleJumpAction = { "DoubleJumpAction", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, DoubleJumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoubleJumpAction_MetaData), NewProp_DoubleJumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_WallLatchAction = { "WallLatchAction", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, WallLatchAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallLatchAction_MetaData), NewProp_WallLatchAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_SaveAction = { "SaveAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, SaveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SaveAction_MetaData), NewProp_SaveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_LoadAction = { "LoadAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, LoadAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoadAction_MetaData), NewProp_LoadAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_RangedAttackInput = { "RangedAttackInput", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, RangedAttackInput), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RangedAttackInput_MetaData), NewProp_RangedAttackInput_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_DropDownInput = { "DropDownInput", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, DropDownInput), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DropDownInput_MetaData), NewProp_DropDownInput_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_MeleeInput = { "MeleeInput", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, MeleeInput), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeleeInput_MetaData), NewProp_MeleeInput_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_MenuInput = { "MenuInput", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, MenuInput), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MenuInput_MetaData), NewProp_MenuInput_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_Springarm = { "Springarm", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, Springarm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Springarm_MetaData), NewProp_Springarm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_HurtBox = { "HurtBox", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, HurtBox), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HurtBox_MetaData), NewProp_HurtBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x001000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_RangedAttackClass = { "RangedAttackClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, RangedAttackClass), Z_Construct_UClass_UClass, Z_Construct_UClass_Aprojectile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RangedAttackClass_MetaData), NewProp_RangedAttackClass_MetaData) };
void Z_Construct_UClass_ATest_Character_Statics::NewProp_bIsDashing_SetBit(void* Obj)
{
	((ATest_Character*)Obj)->bIsDashing = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_bIsDashing = { "bIsDashing", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ATest_Character), &Z_Construct_UClass_ATest_Character_Statics::NewProp_bIsDashing_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsDashing_MetaData), NewProp_bIsDashing_MetaData) };
void Z_Construct_UClass_ATest_Character_Statics::NewProp_bHasDoubleJumped_SetBit(void* Obj)
{
	((ATest_Character*)Obj)->bHasDoubleJumped = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_bHasDoubleJumped = { "bHasDoubleJumped", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ATest_Character), &Z_Construct_UClass_ATest_Character_Statics::NewProp_bHasDoubleJumped_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasDoubleJumped_MetaData), NewProp_bHasDoubleJumped_MetaData) };
void Z_Construct_UClass_ATest_Character_Statics::NewProp_bIsRunning_SetBit(void* Obj)
{
	((ATest_Character*)Obj)->bIsRunning = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_bIsRunning = { "bIsRunning", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ATest_Character), &Z_Construct_UClass_ATest_Character_Statics::NewProp_bIsRunning_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsRunning_MetaData), NewProp_bIsRunning_MetaData) };
void Z_Construct_UClass_ATest_Character_Statics::NewProp_bIsMeleeAttacking_SetBit(void* Obj)
{
	((ATest_Character*)Obj)->bIsMeleeAttacking = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_bIsMeleeAttacking = { "bIsMeleeAttacking", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ATest_Character), &Z_Construct_UClass_ATest_Character_Statics::NewProp_bIsMeleeAttacking_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsMeleeAttacking_MetaData), NewProp_bIsMeleeAttacking_MetaData) };
void Z_Construct_UClass_ATest_Character_Statics::NewProp_bIsRangedAttacking_SetBit(void* Obj)
{
	((ATest_Character*)Obj)->bIsRangedAttacking = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_bIsRangedAttacking = { "bIsRangedAttacking", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ATest_Character), &Z_Construct_UClass_ATest_Character_Statics::NewProp_bIsRangedAttacking_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsRangedAttacking_MetaData), NewProp_bIsRangedAttacking_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_DashCooldown = { "DashCooldown", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, DashCooldown), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DashCooldown_MetaData), NewProp_DashCooldown_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_JumpVelocity = { "JumpVelocity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, JumpVelocity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpVelocity_MetaData), NewProp_JumpVelocity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_BulletSize = { "BulletSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, BulletSize), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BulletSize_MetaData), NewProp_BulletSize_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_AbilitySystemComponent = { "AbilitySystemComponent", nullptr, (EPropertyFlags)0x0124080000080009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, AbilitySystemComponent), Z_Construct_UClass_UAbilitySystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilitySystemComponent_MetaData), NewProp_AbilitySystemComponent_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, MaxHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxHealth_MetaData), NewProp_MaxHealth_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, Health), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Health_MetaData), NewProp_Health_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_MaxBioMass = { "MaxBioMass", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, MaxBioMass), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxBioMass_MetaData), NewProp_MaxBioMass_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_BioMass = { "BioMass", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, BioMass), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BioMass_MetaData), NewProp_BioMass_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_MeleeDamage = { "MeleeDamage", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, MeleeDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeleeDamage_MetaData), NewProp_MeleeDamage_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_RangedDamage = { "RangedDamage", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, RangedDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RangedDamage_MetaData), NewProp_RangedDamage_MetaData) };
void Z_Construct_UClass_ATest_Character_Statics::NewProp_bCanSave_SetBit(void* Obj)
{
	((ATest_Character*)Obj)->bCanSave = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_bCanSave = { "bCanSave", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ATest_Character), &Z_Construct_UClass_ATest_Character_Statics::NewProp_bCanSave_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanSave_MetaData), NewProp_bCanSave_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_GA_Double_Jump = { "GA_Double_Jump", nullptr, (EPropertyFlags)0x0014000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, GA_Double_Jump), Z_Construct_UClass_UClass, Z_Construct_UClass_UGAS_Double_Jump_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GA_Double_Jump_MetaData), NewProp_GA_Double_Jump_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_JumpAbilityTag = { "JumpAbilityTag", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, JumpAbilityTag), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAbilityTag_MetaData), NewProp_JumpAbilityTag_MetaData) }; // 3352185621
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_GA_Wall_Latch = { "GA_Wall_Latch", nullptr, (EPropertyFlags)0x0014000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, GA_Wall_Latch), Z_Construct_UClass_UClass, Z_Construct_UClass_UGAS_Wall_Latch_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GA_Wall_Latch_MetaData), NewProp_GA_Wall_Latch_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_WallLatchAbilityTag = { "WallLatchAbilityTag", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, WallLatchAbilityTag), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallLatchAbilityTag_MetaData), NewProp_WallLatchAbilityTag_MetaData) }; // 3352185621
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_GA_Dash = { "GA_Dash", nullptr, (EPropertyFlags)0x0014000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, GA_Dash), Z_Construct_UClass_UClass, Z_Construct_UClass_UGAS_Dash_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GA_Dash_MetaData), NewProp_GA_Dash_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_DashAbilityTag = { "DashAbilityTag", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, DashAbilityTag), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DashAbilityTag_MetaData), NewProp_DashAbilityTag_MetaData) }; // 3352185621
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_GA_Ranged_Attack = { "GA_Ranged_Attack", nullptr, (EPropertyFlags)0x0014000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, GA_Ranged_Attack), Z_Construct_UClass_UClass, Z_Construct_UClass_UGAS_Ranged_Attack_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GA_Ranged_Attack_MetaData), NewProp_GA_Ranged_Attack_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_RangedAttackAbilityTag = { "RangedAttackAbilityTag", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, RangedAttackAbilityTag), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RangedAttackAbilityTag_MetaData), NewProp_RangedAttackAbilityTag_MetaData) }; // 3352185621
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_PlayerHUD = { "PlayerHUD", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, PlayerHUD), Z_Construct_UClass_APlayer_HUD_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerHUD_MetaData), NewProp_PlayerHUD_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATest_Character_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_OnHealthChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_OnEnergyChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_IdleAnim,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_MeleeAnim,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_RangedAttackAnim,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_DeathAnim,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_MoveAnim,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_DefaultMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_JumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_DashAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_DoubleJumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_WallLatchAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_SaveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_LoadAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_RangedAttackInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_DropDownInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_MeleeInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_MenuInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_Springarm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_HurtBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_Camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_RangedAttackClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_bIsDashing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_bHasDoubleJumped,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_bIsRunning,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_bIsMeleeAttacking,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_bIsRangedAttacking,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_DashCooldown,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_JumpVelocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_BulletSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_AbilitySystemComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_MaxHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_Health,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_MaxBioMass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_BioMass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_MeleeDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_RangedDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_bCanSave,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_GA_Double_Jump,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_JumpAbilityTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_GA_Wall_Latch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_WallLatchAbilityTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_GA_Dash,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_DashAbilityTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_GA_Ranged_Attack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_RangedAttackAbilityTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_PlayerHUD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATest_Character_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ATest_Character_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATest_Character_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ATest_Character_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UAbilitySystemInterface_NoRegister, (int32)VTABLE_OFFSET(ATest_Character, IAbilitySystemInterface), false },  // 2272790346
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATest_Character_Statics::ClassParams = {
	&ATest_Character::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ATest_Character_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ATest_Character_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATest_Character_Statics::Class_MetaDataParams), Z_Construct_UClass_ATest_Character_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATest_Character()
{
	if (!Z_Registration_Info_UClass_ATest_Character.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATest_Character.OuterSingleton, Z_Construct_UClass_ATest_Character_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATest_Character.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<ATest_Character>()
{
	return ATest_Character::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATest_Character);
ATest_Character::~ATest_Character() {}
// End Class ATest_Character

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Test_Character_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATest_Character, ATest_Character::StaticClass, TEXT("ATest_Character"), &Z_Registration_Info_UClass_ATest_Character, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATest_Character), 2813734662U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Test_Character_h_1796160921(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Test_Character_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Test_Character_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
