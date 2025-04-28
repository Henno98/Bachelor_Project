// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Enemies/CrowBoss_Projectile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef BACHELOR_PROJECT_CrowBoss_Projectile_generated_h
#error "CrowBoss_Projectile.generated.h already included, missing '#pragma once' in CrowBoss_Projectile.h"
#endif
#define BACHELOR_PROJECT_CrowBoss_Projectile_generated_h

#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowBoss_Projectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnHit);


#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowBoss_Projectile_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACrowBoss_Projectile(); \
	friend struct Z_Construct_UClass_ACrowBoss_Projectile_Statics; \
public: \
	DECLARE_CLASS(ACrowBoss_Projectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Bachelor_project"), NO_API) \
	DECLARE_SERIALIZER(ACrowBoss_Projectile)


#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowBoss_Projectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACrowBoss_Projectile(ACrowBoss_Projectile&&); \
	ACrowBoss_Projectile(const ACrowBoss_Projectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACrowBoss_Projectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACrowBoss_Projectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACrowBoss_Projectile) \
	NO_API virtual ~ACrowBoss_Projectile();


#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowBoss_Projectile_h_9_PROLOG
#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowBoss_Projectile_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowBoss_Projectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowBoss_Projectile_h_12_INCLASS_NO_PURE_DECLS \
	FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowBoss_Projectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BACHELOR_PROJECT_API UClass* StaticClass<class ACrowBoss_Projectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Enemies_CrowBoss_Projectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
