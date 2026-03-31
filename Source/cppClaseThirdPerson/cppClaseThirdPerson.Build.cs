// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class cppClaseThirdPerson : ModuleRules
{
	public cppClaseThirdPerson(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"OnlineSubsystem",
    		"OnlineSubsystemUtils"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"cppClaseThirdPerson",
			"cppClaseThirdPerson/Variant_Platforming",
			"cppClaseThirdPerson/Variant_Platforming/Animation",
			"cppClaseThirdPerson/Variant_Combat",
			"cppClaseThirdPerson/Variant_Combat/AI",
			"cppClaseThirdPerson/Variant_Combat/Animation",
			"cppClaseThirdPerson/Variant_Combat/Gameplay",
			"cppClaseThirdPerson/Variant_Combat/Interfaces",
			"cppClaseThirdPerson/Variant_Combat/UI",
			"cppClaseThirdPerson/Variant_SideScrolling",
			"cppClaseThirdPerson/Variant_SideScrolling/AI",
			"cppClaseThirdPerson/Variant_SideScrolling/Gameplay",
			"cppClaseThirdPerson/Variant_SideScrolling/Interfaces",
			"cppClaseThirdPerson/Variant_SideScrolling/UI"
		});

		DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
