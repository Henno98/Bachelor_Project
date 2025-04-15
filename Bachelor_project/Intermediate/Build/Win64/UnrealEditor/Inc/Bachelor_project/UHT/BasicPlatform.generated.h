// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BasicPlatform.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef BACHELOR_PROJECT_BasicPlatform_generated_h
#error "BasicPlatform.generated.h already included, missing '#pragma once' in BasicPlatform.h"
#endif
#define BACHELOR_PROJECT_BasicPlatform_generated_h

#define FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BasicPlatform_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execLeftTriggerBox); \
	DECLARE_FUNCTION(execOnPlayerEnterTrigger);


#define FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BasicPlatform_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABasicPlatform(); \
	friend struct Z_Construct_UClass_ABasicPlatform_Statics; \
public: \
	DECLARE_CLASS(ABasicPlatform, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Bachelor_project"), NO_API) \
	DECLARE_SERIALIZER(ABasicPlatform)


#define FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BasicPlatform_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ABasicPlatform(ABasicPlatform&&); \
	ABasicPlatform(const ABasicPlatform&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABasicPlatform); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABasicPlatform); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABasicPlatform) \
	NO_API virtual ~ABasicPlatform();


#define FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BasicPlatform_h_11_PROLOG
#define FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BasicPlatform_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BasicPlatform_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BasicPlatform_h_14_INCLASS_NO_PURE_DECLS \
	FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BasicPlatform_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BACHELOR_PROJECT_API UClass* StaticClass<class ABasicPlatform>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_BasicPlatform_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
