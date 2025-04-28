// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Player/Main_Menu_Widget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BACHELOR_PROJECT_Main_Menu_Widget_generated_h
#error "Main_Menu_Widget.generated.h already included, missing '#pragma once' in Main_Menu_Widget.h"
#endif
#define BACHELOR_PROJECT_Main_Menu_Widget_generated_h

#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Main_Menu_Widget_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnPresseedLoad); \
	DECLARE_FUNCTION(execOnPressedSave); \
	DECLARE_FUNCTION(execCreateSaveSlotButton); \
	DECLARE_FUNCTION(execCreateSaveSlotList); \
	DECLARE_FUNCTION(execOnCloseClicked); \
	DECLARE_FUNCTION(execOnQuitClicked); \
	DECLARE_FUNCTION(execOnSaveClicked); \
	DECLARE_FUNCTION(execOnLoadClicked); \
	DECLARE_FUNCTION(execNativeConstruct);


#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Main_Menu_Widget_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMain_Menu_Widget(); \
	friend struct Z_Construct_UClass_UMain_Menu_Widget_Statics; \
public: \
	DECLARE_CLASS(UMain_Menu_Widget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Bachelor_project"), NO_API) \
	DECLARE_SERIALIZER(UMain_Menu_Widget)


#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Main_Menu_Widget_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMain_Menu_Widget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMain_Menu_Widget(UMain_Menu_Widget&&); \
	UMain_Menu_Widget(const UMain_Menu_Widget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMain_Menu_Widget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMain_Menu_Widget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMain_Menu_Widget) \
	NO_API virtual ~UMain_Menu_Widget();


#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Main_Menu_Widget_h_13_PROLOG
#define FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Main_Menu_Widget_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Main_Menu_Widget_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Main_Menu_Widget_h_16_INCLASS_NO_PURE_DECLS \
	FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Main_Menu_Widget_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BACHELOR_PROJECT_API UClass* StaticClass<class UMain_Menu_Widget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Bachelor_Bachelor_Project_Bachelor_project_Source_Bachelor_project_Public_Player_Main_Menu_Widget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
