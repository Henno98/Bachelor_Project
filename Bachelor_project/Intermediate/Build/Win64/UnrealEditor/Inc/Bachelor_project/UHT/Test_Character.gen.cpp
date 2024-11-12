// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Test_Character.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTest_Character() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ATest_Character();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ATest_Character_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class ATest_Character
void ATest_Character::StaticRegisterNativesATest_Character()
{
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Springarm_MetaData[] = {
		{ "Category", "Test_Character" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "Category", "Test_Character" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpVelocity_MetaData[] = {
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/Test_Character.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Springarm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_JumpVelocity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATest_Character>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultMappingContext_MetaData), NewProp_DefaultMappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAction_MetaData), NewProp_JumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_Springarm = { "Springarm", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, Springarm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Springarm_MetaData), NewProp_Springarm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x002008000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATest_Character_Statics::NewProp_JumpVelocity = { "JumpVelocity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Character, JumpVelocity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpVelocity_MetaData), NewProp_JumpVelocity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATest_Character_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_DefaultMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_JumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_Springarm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_Camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Character_Statics::NewProp_JumpVelocity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATest_Character_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ATest_Character_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATest_Character_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATest_Character_Statics::ClassParams = {
	&ATest_Character::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ATest_Character_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ATest_Character_Statics::PropPointers),
	0,
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
		{ Z_Construct_UClass_ATest_Character, ATest_Character::StaticClass, TEXT("ATest_Character"), &Z_Registration_Info_UClass_ATest_Character, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATest_Character), 253460047U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Test_Character_h_1559033161(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Test_Character_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Test_Character_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
