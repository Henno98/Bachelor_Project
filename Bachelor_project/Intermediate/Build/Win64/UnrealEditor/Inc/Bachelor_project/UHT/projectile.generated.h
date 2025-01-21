// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "projectile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BACHELOR_PROJECT_projectile_generated_h
#error "projectile.generated.h already included, missing '#pragma once' in projectile.h"
#endif
#define BACHELOR_PROJECT_projectile_generated_h

#define FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_projectile_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetPosition); \
	DECLARE_FUNCTION(execTravel);


#define FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_projectile_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAprojectile(); \
	friend struct Z_Construct_UClass_Aprojectile_Statics; \
public: \
	DECLARE_CLASS(Aprojectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Bachelor_project"), NO_API) \
	DECLARE_SERIALIZER(Aprojectile)


#define FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_projectile_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	Aprojectile(Aprojectile&&); \
	Aprojectile(const Aprojectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, Aprojectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(Aprojectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(Aprojectile) \
	NO_API virtual ~Aprojectile();


#define FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_projectile_h_10_PROLOG
#define FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_projectile_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_projectile_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_projectile_h_13_INCLASS_NO_PURE_DECLS \
	FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_projectile_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BACHELOR_PROJECT_API UClass* StaticClass<class Aprojectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_projectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
