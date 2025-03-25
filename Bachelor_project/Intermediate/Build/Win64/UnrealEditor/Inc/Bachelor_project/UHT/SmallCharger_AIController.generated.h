// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SmallCharger_AIController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APawn;
#ifdef BACHELOR_PROJECT_SmallCharger_AIController_generated_h
#error "SmallCharger_AIController.generated.h already included, missing '#pragma once' in SmallCharger_AIController.h"
#endif
#define BACHELOR_PROJECT_SmallCharger_AIController_generated_h

#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_AIController_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnSeenPawn);


#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_AIController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASmallCharger_AIController(); \
	friend struct Z_Construct_UClass_ASmallCharger_AIController_Statics; \
public: \
	DECLARE_CLASS(ASmallCharger_AIController, AAIController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Bachelor_project"), NO_API) \
	DECLARE_SERIALIZER(ASmallCharger_AIController)


#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_AIController_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ASmallCharger_AIController(ASmallCharger_AIController&&); \
	ASmallCharger_AIController(const ASmallCharger_AIController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASmallCharger_AIController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASmallCharger_AIController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASmallCharger_AIController) \
	NO_API virtual ~ASmallCharger_AIController();


#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_AIController_h_12_PROLOG
#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_AIController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_AIController_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_AIController_h_15_INCLASS_NO_PURE_DECLS \
	FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_AIController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BACHELOR_PROJECT_API UClass* StaticClass<class ASmallCharger_AIController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_SmallCharger_AIController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
