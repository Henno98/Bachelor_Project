// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CrowBoss.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BACHELOR_PROJECT_CrowBoss_generated_h
#error "CrowBoss.generated.h already included, missing '#pragma once' in CrowBoss.h"
#endif
#define BACHELOR_PROJECT_CrowBoss_generated_h

#define FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowBoss_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDeath); \
	DECLARE_FUNCTION(execCollision); \
	DECLARE_FUNCTION(execSpecialAttack); \
	DECLARE_FUNCTION(execFeatherAttack); \
	DECLARE_FUNCTION(execMeleeAttack);


#define FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowBoss_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACrowBoss(); \
	friend struct Z_Construct_UClass_ACrowBoss_Statics; \
public: \
	DECLARE_CLASS(ACrowBoss, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Bachelor_project"), NO_API) \
	DECLARE_SERIALIZER(ACrowBoss)


#define FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowBoss_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACrowBoss(ACrowBoss&&); \
	ACrowBoss(const ACrowBoss&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACrowBoss); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACrowBoss); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACrowBoss) \
	NO_API virtual ~ACrowBoss();


#define FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowBoss_h_9_PROLOG
#define FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowBoss_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowBoss_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowBoss_h_12_INCLASS_NO_PURE_DECLS \
	FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowBoss_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BACHELOR_PROJECT_API UClass* StaticClass<class ACrowBoss>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_larss_Documents_Github_repositories_Inventory_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_CrowBoss_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
