// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSnake_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Snake;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Snake()
	{
		if (!Z_Registration_Info_UPackage__Script_Snake.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Snake",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xF8B5680B,
				0xBB901CFA,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Snake.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Snake.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Snake(Z_Construct_UPackage__Script_Snake, TEXT("/Script/Snake"), Z_Registration_Info_UPackage__Script_Snake, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xF8B5680B, 0xBB901CFA));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
