// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UMGClientCPP : ModuleRules
{
	public UMGClientCPP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
