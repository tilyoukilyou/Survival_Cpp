// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Survival_Cpp : ModuleRules
{
	public Survival_Cpp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
