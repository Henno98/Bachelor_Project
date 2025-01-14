// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/Test_Enemy.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTest_Enemy() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ATest_Enemy();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_ATest_Enemy_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class ATest_Enemy
void ATest_Enemy::StaticRegisterNativesATest_Enemy()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATest_Enemy);
UClass* Z_Construct_UClass_ATest_Enemy_NoRegister()
{
	return ATest_Enemy::StaticClass();
}
struct Z_Construct_UClass_ATest_Enemy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Test_Enemy.h" },
		{ "ModuleRelativePath", "Public/Test_Enemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookDistance_MetaData[] = {
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/Test_Enemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkDistance_MetaData[] = {
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/Test_Enemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkSpeed_MetaData[] = {
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/Test_Enemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackRange_MetaData[] = {
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/Test_Enemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackSpeed_MetaData[] = {
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/Test_Enemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSeesPlayer_MetaData[] = {
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/Test_Enemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasAttacked_MetaData[] = {
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/Test_Enemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[] = {
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/Test_Enemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StaticMesh_MetaData[] = {
		{ "Category", "StaticMesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Test_Enemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Collider_MetaData[] = {
		{ "Category", "Collider" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Test_Enemy.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LookDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackSpeed;
	static void NewProp_bSeesPlayer_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSeesPlayer;
	static void NewProp_bHasAttacked_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasAttacked;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StaticMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Collider;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATest_Enemy>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATest_Enemy_Statics::NewProp_LookDistance = { "LookDistance", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Enemy, LookDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookDistance_MetaData), NewProp_LookDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATest_Enemy_Statics::NewProp_WalkDistance = { "WalkDistance", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Enemy, WalkDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkDistance_MetaData), NewProp_WalkDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATest_Enemy_Statics::NewProp_WalkSpeed = { "WalkSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Enemy, WalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkSpeed_MetaData), NewProp_WalkSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATest_Enemy_Statics::NewProp_AttackRange = { "AttackRange", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Enemy, AttackRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackRange_MetaData), NewProp_AttackRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATest_Enemy_Statics::NewProp_AttackSpeed = { "AttackSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Enemy, AttackSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackSpeed_MetaData), NewProp_AttackSpeed_MetaData) };
void Z_Construct_UClass_ATest_Enemy_Statics::NewProp_bSeesPlayer_SetBit(void* Obj)
{
	((ATest_Enemy*)Obj)->bSeesPlayer = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATest_Enemy_Statics::NewProp_bSeesPlayer = { "bSeesPlayer", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ATest_Enemy), &Z_Construct_UClass_ATest_Enemy_Statics::NewProp_bSeesPlayer_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSeesPlayer_MetaData), NewProp_bSeesPlayer_MetaData) };
void Z_Construct_UClass_ATest_Enemy_Statics::NewProp_bHasAttacked_SetBit(void* Obj)
{
	((ATest_Enemy*)Obj)->bHasAttacked = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATest_Enemy_Statics::NewProp_bHasAttacked = { "bHasAttacked", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ATest_Enemy), &Z_Construct_UClass_ATest_Enemy_Statics::NewProp_bHasAttacked_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasAttacked_MetaData), NewProp_bHasAttacked_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATest_Enemy_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Enemy, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Position_MetaData), NewProp_Position_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Enemy_Statics::NewProp_StaticMesh = { "StaticMesh", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Enemy, StaticMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StaticMesh_MetaData), NewProp_StaticMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATest_Enemy_Statics::NewProp_Collider = { "Collider", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATest_Enemy, Collider), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Collider_MetaData), NewProp_Collider_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATest_Enemy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Enemy_Statics::NewProp_LookDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Enemy_Statics::NewProp_WalkDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Enemy_Statics::NewProp_WalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Enemy_Statics::NewProp_AttackRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Enemy_Statics::NewProp_AttackSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Enemy_Statics::NewProp_bSeesPlayer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Enemy_Statics::NewProp_bHasAttacked,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Enemy_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Enemy_Statics::NewProp_StaticMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATest_Enemy_Statics::NewProp_Collider,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATest_Enemy_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ATest_Enemy_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATest_Enemy_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATest_Enemy_Statics::ClassParams = {
	&ATest_Enemy::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ATest_Enemy_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ATest_Enemy_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATest_Enemy_Statics::Class_MetaDataParams), Z_Construct_UClass_ATest_Enemy_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATest_Enemy()
{
	if (!Z_Registration_Info_UClass_ATest_Enemy.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATest_Enemy.OuterSingleton, Z_Construct_UClass_ATest_Enemy_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATest_Enemy.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<ATest_Enemy>()
{
	return ATest_Enemy::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATest_Enemy);
ATest_Enemy::~ATest_Enemy() {}
// End Class ATest_Enemy

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Test_Enemy_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATest_Enemy, ATest_Enemy::StaticClass, TEXT("ATest_Enemy"), &Z_Registration_Info_UClass_ATest_Enemy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATest_Enemy), 2621004894U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Test_Enemy_h_2433133859(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Test_Enemy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Test_Enemy_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
