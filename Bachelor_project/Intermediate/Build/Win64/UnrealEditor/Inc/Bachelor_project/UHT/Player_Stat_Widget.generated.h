// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Player/Player_Stat_Widget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BACHELOR_PROJECT_Player_Stat_Widget_generated_h
#error "Player_Stat_Widget.generated.h already included, missing '#pragma once' in Player_Stat_Widget.h"
#endif
#define BACHELOR_PROJECT_Player_Stat_Widget_generated_h

#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Player_Stat_Widget_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUpdateTutorialText); \
	DECLARE_FUNCTION(execUpdateBioMass); \
	DECLARE_FUNCTION(execUpdateHealth); \
	DECLARE_FUNCTION(execNativeConstruct);


#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Player_Stat_Widget_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPlayer_Stat_Widget(); \
	friend struct Z_Construct_UClass_UPlayer_Stat_Widget_Statics; \
public: \
	DECLARE_CLASS(UPlayer_Stat_Widget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Bachelor_project"), NO_API) \
	DECLARE_SERIALIZER(UPlayer_Stat_Widget)


#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Player_Stat_Widget_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPlayer_Stat_Widget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UPlayer_Stat_Widget(UPlayer_Stat_Widget&&); \
	UPlayer_Stat_Widget(const UPlayer_Stat_Widget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPlayer_Stat_Widget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPlayer_Stat_Widget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPlayer_Stat_Widget) \
	NO_API virtual ~UPlayer_Stat_Widget();


#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Player_Stat_Widget_h_13_PROLOG
#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Player_Stat_Widget_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Player_Stat_Widget_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Player_Stat_Widget_h_16_INCLASS_NO_PURE_DECLS \
	FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Player_Stat_Widget_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BACHELOR_PROJECT_API UClass* StaticClass<class UPlayer_Stat_Widget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Player_Stat_Widget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
