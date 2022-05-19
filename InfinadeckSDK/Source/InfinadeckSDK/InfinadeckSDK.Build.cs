/**
 * ------------------------------------------------------------
 * Copyright Infinadeck 2022
 * Created by George Burger
 * InfinadeckSDK Build file for use with Unreal Engine 4.
 * https://github.com/Infinadeck/InfinadeckUnrealPlugin
 * ------------------------------------------------------------
 */

using UnrealBuildTool;
using System.IO;
using System;

public class InfinadeckSDK : ModuleRules
{
    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../Source/ThirdParty/")); }
    }

    public InfinadeckSDK(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
				// ... add public include paths required here ...
			}
            );

        PrivateIncludePaths.AddRange(
            new string[] {
				// ... add other private include paths required here ...
			}
            );

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "Core",
                "Projects",
                "Json",
                "JsonUtilities",
				// ... add other public dependencies that you statically link with here ...
			}
            );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
				// ... add private dependencies that you statically link with here ...	
			}
            );

        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
				// ... add any modules that your module loads dynamically here ...
			}
            );

        PublicAdditionalLibraries.Add(Path.Combine(Path.Combine(ThirdPartyPath, "Infinadeck", "lib"),
                (Target.Platform == UnrealTargetPlatform.Win64) ? "Win64" : "Win32",
                "InfinadeckAPI.lib"));
        PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "Infinadeck", "include"));

        RuntimeDependencies.Add("$(TargetOutputDir)/Library.dll",
            Path.Combine(
                Path.Combine(ThirdPartyPath, "Infinadeck", "lib"),
                (Target.Platform == UnrealTargetPlatform.Win64) ? "Win64" : "Win32",
                "Library.dll"
            )
        );

        PublicDelayLoadDLLs.Add("InfinadeckAPI.dll");
        RuntimeDependencies.Add("$(TargetOutputDir)/InfinadeckAPI.dll",
            Path.Combine(
                Path.Combine(ThirdPartyPath, "Infinadeck", "lib"),
                (Target.Platform == UnrealTargetPlatform.Win64) ? "Win64" : "Win32",
                "InfinadeckAPI.dll"
            )
        );
    }
}