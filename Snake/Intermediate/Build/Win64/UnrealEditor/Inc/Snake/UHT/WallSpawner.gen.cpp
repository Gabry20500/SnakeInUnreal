// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Snake/Public/WallSpawner.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWallSpawner() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	SNAKE_API UClass* Z_Construct_UClass_AWallSpawner();
	SNAKE_API UClass* Z_Construct_UClass_AWallSpawner_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Snake();
// End Cross Module References
	void AWallSpawner::StaticRegisterNativesAWallSpawner()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWallSpawner);
	UClass* Z_Construct_UClass_AWallSpawner_NoRegister()
	{
		return AWallSpawner::StaticClass();
	}
	struct Z_Construct_UClass_AWallSpawner_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWallSpawner_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Snake,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWallSpawner_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWallSpawner_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "WallSpawner.h" },
		{ "ModuleRelativePath", "Public/WallSpawner.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWallSpawner_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWallSpawner>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AWallSpawner_Statics::ClassParams = {
		&AWallSpawner::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWallSpawner_Statics::Class_MetaDataParams), Z_Construct_UClass_AWallSpawner_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AWallSpawner()
	{
		if (!Z_Registration_Info_UClass_AWallSpawner.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWallSpawner.OuterSingleton, Z_Construct_UClass_AWallSpawner_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AWallSpawner.OuterSingleton;
	}
	template<> SNAKE_API UClass* StaticClass<AWallSpawner>()
	{
		return AWallSpawner::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWallSpawner);
	AWallSpawner::~AWallSpawner() {}
	struct Z_CompiledInDeferFile_FID_Users_Horizoners_TO_D00_Desktop_SnakeInUnreal_Snake_Source_Snake_Public_WallSpawner_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Horizoners_TO_D00_Desktop_SnakeInUnreal_Snake_Source_Snake_Public_WallSpawner_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AWallSpawner, AWallSpawner::StaticClass, TEXT("AWallSpawner"), &Z_Registration_Info_UClass_AWallSpawner, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWallSpawner), 1081356445U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Horizoners_TO_D00_Desktop_SnakeInUnreal_Snake_Source_Snake_Public_WallSpawner_h_3979022591(TEXT("/Script/Snake"),
		Z_CompiledInDeferFile_FID_Users_Horizoners_TO_D00_Desktop_SnakeInUnreal_Snake_Source_Snake_Public_WallSpawner_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Horizoners_TO_D00_Desktop_SnakeInUnreal_Snake_Source_Snake_Public_WallSpawner_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
