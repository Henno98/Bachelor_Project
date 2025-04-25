// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "World/LevelStreamingActor.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef BACHELOR_PROJECT_LevelStreamingActor_generated_h
#error "LevelStreamingActor.generated.h already included, missing '#pragma once' in LevelStreamingActor.h"
#endif
#define BACHELOR_PROJECT_LevelStreamingActor_generated_h

#define FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_World_LevelStreamingActor_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOverlapEnds); \
	DECLARE_FUNCTION(execOverlapBegins);


#define FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_World_LevelStreamingActor_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALevelStreamingActor(); \
	friend struct Z_Construct_UClass_ALevelStreamingActor_Statics; \
public: \
	DECLARE_CLASS(ALevelStreamingActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Bachelor_project"), NO_API) \
	DECLARE_SERIALIZER(ALevelStreamingActor)


#define FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_World_LevelStreamingActor_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ALevelStreamingActor(ALevelStreamingActor&&); \
	ALevelStreamingActor(const ALevelStreamingActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALevelStreamingActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALevelStreamingActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALevelStreamingActor) \
	NO_API virtual ~ALevelStreamingActor();


#define FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_World_LevelStreamingActor_h_13_PROLOG
#define FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_World_LevelStreamingActor_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_World_LevelStreamingActor_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_World_LevelStreamingActor_h_16_INCLASS_NO_PURE_DECLS \
	FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_World_LevelStreamingActor_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BACHELOR_PROJECT_API UClass* StaticClass<class ALevelStreamingActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Bruker_Documents_GitHub_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_World_LevelStreamingActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
