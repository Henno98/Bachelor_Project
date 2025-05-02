// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Bachelor_project : ModuleRules
{
	public Bachelor_project(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "AIModule", "GameplayAbilities",
			"GameplayTasks", "GameplayTags", "UMG", "Slate", "SlateCore", "Niagara"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.AddRange(new string[]
			{
				"UnrealEd",
				"BlueprintGraph",
				"KismetCompiler",
				"EditorSubsystem",
				"PropertyEditor",
				"LevelEditor",
				"AssetTools",
			});
		}
	}
}
