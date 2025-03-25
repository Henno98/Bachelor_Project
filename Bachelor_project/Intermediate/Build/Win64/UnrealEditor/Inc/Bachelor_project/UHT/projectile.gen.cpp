// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bachelor_project/Public/projectile.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeprojectile() {}

// Begin Cross Module References
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_Aprojectile();
BACHELOR_PROJECT_API UClass* Z_Construct_UClass_Aprojectile_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Bachelor_project();
// End Cross Module References

// Begin Class Aprojectile Function SetPosition
struct Z_Construct_UFunction_Aprojectile_SetPosition_Statics
{
	struct projectile_eventSetPosition_Parms
	{
		FVector position;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/projectile.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_position;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_Aprojectile_SetPosition_Statics::NewProp_position = { "position", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(projectile_eventSetPosition_Parms, position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_Aprojectile_SetPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Aprojectile_SetPosition_Statics::NewProp_position,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_Aprojectile_SetPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_Aprojectile_SetPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_Aprojectile, nullptr, "SetPosition", nullptr, nullptr, Z_Construct_UFunction_Aprojectile_SetPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_Aprojectile_SetPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_Aprojectile_SetPosition_Statics::projectile_eventSetPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_Aprojectile_SetPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_Aprojectile_SetPosition_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_Aprojectile_SetPosition_Statics::projectile_eventSetPosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_Aprojectile_SetPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_Aprojectile_SetPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(Aprojectile::execSetPosition)
{
	P_GET_STRUCT(FVector,Z_Param_position);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPosition(Z_Param_position);
	P_NATIVE_END;
}
// End Class Aprojectile Function SetPosition

// Begin Class Aprojectile Function Travel
struct Z_Construct_UFunction_Aprojectile_Travel_Statics
{
	struct projectile_eventTravel_Parms
	{
		float deltatime;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/projectile.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_deltatime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_Aprojectile_Travel_Statics::NewProp_deltatime = { "deltatime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(projectile_eventTravel_Parms, deltatime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_Aprojectile_Travel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Aprojectile_Travel_Statics::NewProp_deltatime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_Aprojectile_Travel_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_Aprojectile_Travel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_Aprojectile, nullptr, "Travel", nullptr, nullptr, Z_Construct_UFunction_Aprojectile_Travel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_Aprojectile_Travel_Statics::PropPointers), sizeof(Z_Construct_UFunction_Aprojectile_Travel_Statics::projectile_eventTravel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_Aprojectile_Travel_Statics::Function_MetaDataParams), Z_Construct_UFunction_Aprojectile_Travel_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_Aprojectile_Travel_Statics::projectile_eventTravel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_Aprojectile_Travel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_Aprojectile_Travel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(Aprojectile::execTravel)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_deltatime);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Travel(Z_Param_deltatime);
	P_NATIVE_END;
}
// End Class Aprojectile Function Travel

// Begin Class Aprojectile
void Aprojectile::StaticRegisterNativesAprojectile()
{
	UClass* Class = Aprojectile::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SetPosition", &Aprojectile::execSetPosition },
		{ "Travel", &Aprojectile::execTravel },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(Aprojectile);
UClass* Z_Construct_UClass_Aprojectile_NoRegister()
{
	return Aprojectile::StaticClass();
}
struct Z_Construct_UClass_Aprojectile_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "projectile.h" },
		{ "ModuleRelativePath", "Public/projectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_staticmesh_MetaData[] = {
		{ "Category", "staticmesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/projectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_collider_MetaData[] = {
		{ "Category", "staticmesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/projectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_lifetime_MetaData[] = {
		{ "Category", "staticmesh" },
		{ "ModuleRelativePath", "Public/projectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetLocation_MetaData[] = {
		{ "Category", "staticmesh" },
		{ "ModuleRelativePath", "Public/projectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentLocation_MetaData[] = {
		{ "Category", "staticmesh" },
		{ "ModuleRelativePath", "Public/projectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Velocity_MetaData[] = {
		{ "Category", "staticmesh" },
		{ "ModuleRelativePath", "Public/projectile.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_staticmesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_collider;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_lifetime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Velocity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_Aprojectile_SetPosition, "SetPosition" }, // 2196613535
		{ &Z_Construct_UFunction_Aprojectile_Travel, "Travel" }, // 350465836
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<Aprojectile>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_Aprojectile_Statics::NewProp_staticmesh = { "staticmesh", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Aprojectile, staticmesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_staticmesh_MetaData), NewProp_staticmesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_Aprojectile_Statics::NewProp_collider = { "collider", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Aprojectile, collider), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_collider_MetaData), NewProp_collider_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_Aprojectile_Statics::NewProp_lifetime = { "lifetime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Aprojectile, lifetime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_lifetime_MetaData), NewProp_lifetime_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_Aprojectile_Statics::NewProp_TargetLocation = { "TargetLocation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Aprojectile, TargetLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetLocation_MetaData), NewProp_TargetLocation_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_Aprojectile_Statics::NewProp_CurrentLocation = { "CurrentLocation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Aprojectile, CurrentLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentLocation_MetaData), NewProp_CurrentLocation_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_Aprojectile_Statics::NewProp_Velocity = { "Velocity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Aprojectile, Velocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Velocity_MetaData), NewProp_Velocity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_Aprojectile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aprojectile_Statics::NewProp_staticmesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aprojectile_Statics::NewProp_collider,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aprojectile_Statics::NewProp_lifetime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aprojectile_Statics::NewProp_TargetLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aprojectile_Statics::NewProp_CurrentLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aprojectile_Statics::NewProp_Velocity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_Aprojectile_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_Aprojectile_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Bachelor_project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_Aprojectile_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_Aprojectile_Statics::ClassParams = {
	&Aprojectile::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_Aprojectile_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_Aprojectile_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_Aprojectile_Statics::Class_MetaDataParams), Z_Construct_UClass_Aprojectile_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_Aprojectile()
{
	if (!Z_Registration_Info_UClass_Aprojectile.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_Aprojectile.OuterSingleton, Z_Construct_UClass_Aprojectile_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_Aprojectile.OuterSingleton;
}
template<> BACHELOR_PROJECT_API UClass* StaticClass<Aprojectile>()
{
	return Aprojectile::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(Aprojectile);
Aprojectile::~Aprojectile() {}
// End Class Aprojectile

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_jacob_Documents_GitHubMain_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_projectile_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_Aprojectile, Aprojectile::StaticClass, TEXT("Aprojectile"), &Z_Registration_Info_UClass_Aprojectile, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(Aprojectile), 2182678116U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jacob_Documents_GitHubMain_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_projectile_h_1936810097(TEXT("/Script/Bachelor_project"),
	Z_CompiledInDeferFile_FID_Users_jacob_Documents_GitHubMain_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_projectile_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_jacob_Documents_GitHubMain_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_projectile_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
