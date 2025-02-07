// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AIController_SmallCharger.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APawn;
#ifdef BACHELOR_PROJECT_AIController_SmallCharger_generated_h
#error "AIController_SmallCharger.generated.h already included, missing '#pragma once' in AIController_SmallCharger.h"
#endif
#define BACHELOR_PROJECT_AIController_SmallCharger_generated_h

#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_AIController_SmallCharger_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnEnemySeenItsOwner);


#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_AIController_SmallCharger_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAIController_SmallCharger(); \
	friend struct Z_Construct_UClass_AAIController_SmallCharger_Statics; \
public: \
	DECLARE_CLASS(AAIController_SmallCharger, AAIController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Bachelor_project"), NO_API) \
	DECLARE_SERIALIZER(AAIController_SmallCharger)


#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_AIController_SmallCharger_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AAIController_SmallCharger(AAIController_SmallCharger&&); \
	AAIController_SmallCharger(const AAIController_SmallCharger&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAIController_SmallCharger); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAIController_SmallCharger); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAIController_SmallCharger) \
	NO_API virtual ~AAIController_SmallCharger();


#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_AIController_SmallCharger_h_12_PROLOG
#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_AIController_SmallCharger_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_AIController_SmallCharger_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_AIController_SmallCharger_h_15_INCLASS_NO_PURE_DECLS \
	FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_AIController_SmallCharger_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BACHELOR_PROJECT_API UClass* StaticClass<class AAIController_SmallCharger>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_AIController_SmallCharger_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
