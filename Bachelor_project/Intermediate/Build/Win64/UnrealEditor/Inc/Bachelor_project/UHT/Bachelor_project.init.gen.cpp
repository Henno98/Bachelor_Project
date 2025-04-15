// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBachelor_project_init() {}
	BACHELOR_PROJECT_API UFunction* Z_Construct_UDelegateFunction_Bachelor_project_OnHealthChangedSignature__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Bachelor_project;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Bachelor_project()
	{
		if (!Z_Registration_Info_UPackage__Script_Bachelor_project.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_Bachelor_project_OnHealthChangedSignature__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Bachelor_project",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xA7A7D218,
				0x06DA3DF1,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Bachelor_project.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Bachelor_project.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Bachelor_project(Z_Construct_UPackage__Script_Bachelor_project, TEXT("/Script/Bachelor_project"), Z_Registration_Info_UPackage__Script_Bachelor_project, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xA7A7D218, 0x06DA3DF1));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
