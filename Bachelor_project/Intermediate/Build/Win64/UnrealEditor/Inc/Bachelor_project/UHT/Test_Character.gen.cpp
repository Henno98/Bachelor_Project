// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Test_Character.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTest_Character() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_Aprojectile_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ATest_Character();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ATest_Character_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UGAS_Double_Jump_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UGAS_Wall_Latch_NoRegister();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_UPowerUpController_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemInterface_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class ATest_Character Function LoadGame
struct Z_Construct_UFunction_ATest_Character_LoadGame_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATest_Character_LoadGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATest_Character, nullptr, "LoadGame", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATest_Character_LoadGame_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATest_Character_LoadGame_Statics::Function_MetaDataParams) };
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
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->LoadGame();
	P_NATIVE_END;
}
// End Class ATest_Character Function LoadGame

// Begin Class ATest_Character Function SaveGame
struct Z_Construct_UFunction_ATest_Character_SaveGame_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATest_Character_SaveGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATest_Character, nullptr, "SaveGame", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATest_Character_SaveGame_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATest_Character_SaveGame_Statics::Function_MetaDataParams) };
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
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SaveGame();
	P_NATIVE_END;
}
// End Class ATest_Character Function SaveGame

// Begin Class ATest_Character
void ATest_Character::StaticRegisterNativesATest_Character()
{
	UClass* Class = ATest_Character::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "LoadGame", &ATest_Character::execLoadGame },
		{ "SaveGame", &ATest_Character::execSaveGame },
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
		{ "IncludePath", "Test_Character.h" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DashAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoubleJumpAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallLatchAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SaveAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LoadAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RangedAttackInput_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Springarm_MetaData[] = {
		{ "Category", "Test_Character" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HurtBox_MetaData[] = {
		{ "Category", "Hurtbox" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HurtVisibility_MetaData[] = {
		{ "Category", "Hurtbox" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "Category", "Test_Character" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoubleJumpPowerUp_MetaData[] = {
		{ "Category", "PowerUps" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallLatchPowerUp_MetaData[] = {
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasDoubleJumpPowerUp_MetaData[] = {
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasWallLatchPowerUp_MetaData[] = {
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RangedAttackClass_MetaData[] = {
		{ "Category", "Projectile class" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DashCooldown_MetaData[] = {
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpVelocity_MetaData[] = {
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilitySystemComponent_MetaData[] = {
		{ "Category", "Test_Character" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GA_Double_Jump_MetaData[] = {
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpAbilityTag_MetaData[] = {
		{ "Category", "GASGameplayAbility" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GA_Wall_Latch_MetaData[] = {
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallLatchAbilityTag_MetaData[] = {
		{ "Category", "GASGameplayAbility" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DashAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DoubleJumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WallLatchAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SaveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LoadAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RangedAttackInput;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Springarm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HurtBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HurtVisibility;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DoubleJumpPowerUp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WallLatchPowerUp;
	static void NewProp_bHasDoubleJumpPowerUp_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasDoubleJumpPowerUp;
	static void NewProp_bHasWallLatchPowerUp_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasWallLatchPowerUp;
	static const UECodeGen_Private::FClassPropertyParams NewProp_RangedAttackClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DashCooldown;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_JumpVelocity;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AbilitySystemComponent;
	static const UECodeGen_Private::FClassPropertyParams NewProp_GA_Double_Jump;
	static const UECodeGen_Private::FStructPropertyParams NewProp_JumpAbilityTag;
	static const UECodeGen_Private::FClassPropertyParams NewProp_GA_Wall_Latch;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WallLatchAbilityTag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ATest_Character_LoadGame, "LoadGame" }, // 3777754426
		{ &Z_Construct_UFunction_ATest_Character_SaveGame, "SaveGame" }, // 122556343
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATest_Character>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultMappingContext_MetaData), NewProp_DefaultMappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAction_MetaData), NewProp_JumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_DashAction = { "DashAction", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, DashAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DashAction_MetaData), NewProp_DashAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_DoubleJumpAction = { "DoubleJumpAction", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, DoubleJumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoubleJumpAction_MetaData), NewProp_DoubleJumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_WallLatchAction = { "WallLatchAction", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, WallLatchAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallLatchAction_MetaData), NewProp_WallLatchAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_SaveAction = { "SaveAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, SaveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SaveAction_MetaData), NewProp_SaveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_LoadAction = { "LoadAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, LoadAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoadAction_MetaData), NewProp_LoadAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_RangedAttackInput = { "RangedAttackInput", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, RangedAttackInput), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RangedAttackInput_MetaData), NewProp_RangedAttackInput_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_Springarm = { "Springarm", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, Springarm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Springarm_MetaData), NewProp_Springarm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_HurtBox = { "HurtBox", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, HurtBox), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HurtBox_MetaData), NewProp_HurtBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_HurtVisibility = { "HurtVisibility", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, HurtVisibility), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HurtVisibility_MetaData), NewProp_HurtVisibility_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x002008000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_DoubleJumpPowerUp = { "DoubleJumpPowerUp", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, DoubleJumpPowerUp), Z_Construct_UClass_UPowerUpController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoubleJumpPowerUp_MetaData), NewProp_DoubleJumpPowerUp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_WallLatchPowerUp = { "WallLatchPowerUp", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, WallLatchPowerUp), Z_Construct_UClass_UPowerUpController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallLatchPowerUp_MetaData), NewProp_WallLatchPowerUp_MetaData) };
void Z_Construct_UClass_ATest_Character_Statics::NewProp_bHasDoubleJumpPowerUp_SetBit(void* Obj)
{
	((ATest_Character*)Obj)->bHasDoubleJumpPowerUp = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_bHasDoubleJumpPowerUp = { "bHasDoubleJumpPowerUp", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ATest_Character), &Z_Construct_UClass_ATest_Character_Statics::NewProp_bHasDoubleJumpPowerUp_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasDoubleJumpPowerUp_MetaData), NewProp_bHasDoubleJumpPowerUp_MetaData) };
void Z_Construct_UClass_ATest_Character_Statics::NewProp_bHasWallLatchPowerUp_SetBit(void* Obj)
{
	((ATest_Character*)Obj)->bHasWallLatchPowerUp = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_bHasWallLatchPowerUp = { "bHasWallLatchPowerUp", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ATest_Character), &Z_Construct_UClass_ATest_Character_Statics::NewProp_bHasWallLatchPowerUp_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasWallLatchPowerUp_MetaData), NewProp_bHasWallLatchPowerUp_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_RangedAttackClass = { "RangedAttackClass", nullptr, (EPropertyFlags)0x0024080000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, RangedAttackClass), Z_Construct_UClass_UClass, Z_Construct_UClass_Aprojectile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RangedAttackClass_MetaData), NewProp_RangedAttackClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_DashCooldown = { "DashCooldown", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, DashCooldown), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DashCooldown_MetaData), NewProp_DashCooldown_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_JumpVelocity = { "JumpVelocity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, JumpVelocity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpVelocity_MetaData), NewProp_JumpVelocity_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_AbilitySystemComponent = { "AbilitySystemComponent", nullptr, (EPropertyFlags)0x0124080000080009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, AbilitySystemComponent), Z_Construct_UClass_UAbilitySystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilitySystemComponent_MetaData), NewProp_AbilitySystemComponent_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_GA_Double_Jump = { "GA_Double_Jump", nullptr, (EPropertyFlags)0x0014000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, GA_Double_Jump), Z_Construct_UClass_UClass, Z_Construct_UClass_UGAS_Double_Jump_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GA_Double_Jump_MetaData), NewProp_GA_Double_Jump_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_JumpAbilityTag = { "JumpAbilityTag", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, JumpAbilityTag), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAbilityTag_MetaData), NewProp_JumpAbilityTag_MetaData) }; // 3352185621
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_GA_Wall_Latch = { "GA_Wall_Latch", nullptr, (EPropertyFlags)0x0014000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, GA_Wall_Latch), Z_Construct_UClass_UClass, Z_Construct_UClass_UGAS_Wall_Latch_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GA_Wall_Latch_MetaData), NewProp_GA_Wall_Latch_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_WallLatchAbilityTag = { "WallLatchAbilityTag", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, WallLatchAbilityTag), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallLatchAbilityTag_MetaData), NewProp_WallLatchAbilityTag_MetaData) }; // 3352185621
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATest_Character_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_DefaultMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_JumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_DashAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_DoubleJumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_WallLatchAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_SaveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_LoadAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_RangedAttackInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_Springarm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_HurtBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_HurtVisibility,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_Camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_DoubleJumpPowerUp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_WallLatchPowerUp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_bHasDoubleJumpPowerUp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_bHasWallLatchPowerUp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_RangedAttackClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_DashCooldown,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_JumpVelocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_AbilitySystemComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_GA_Double_Jump,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_JumpAbilityTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_GA_Wall_Latch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_WallLatchAbilityTag,
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
struct Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Test_Character_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATest_Character, ATest_Character::StaticClass, TEXT("ATest_Character"), &Z_Registration_Info_UClass_ATest_Character, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATest_Character), 3262331132U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Test_Character_h_185438794(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Test_Character_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Test_Character_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
