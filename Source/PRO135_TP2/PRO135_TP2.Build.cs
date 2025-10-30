// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PRO135_TP2 : ModuleRules
{
	public PRO135_TP2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
		});

		PrivateDependencyModuleNames.AddRange(new string[] { "AIModule" });
	}
}
