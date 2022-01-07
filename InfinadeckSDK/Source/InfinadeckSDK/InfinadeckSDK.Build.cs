using UnrealBuildTool;
using System.IO;
using System;

/**
 * ------------------------------------------------------------
 * InfinadeckSDK Build file for use with Unreal Engine 4.
 * https://github.com/Infinadeck/InfinadeckUnrealPlugin
 * Created by George Burger @ Infinadeck, 2019-2022
 * Attribution required.
 * ------------------------------------------------------------
 */

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
        PublicDelayLoadDLLs.Add("InfinadeckAPI.dll");
        RuntimeDependencies.Add("$(TargetOutputDir)/InfinadeckAPI.dll",
            Path.Combine(
                Path.Combine(ThirdPartyPath, "Infinadeck", "lib"),
                (Target.Platform == UnrealTargetPlatform.Win64) ? "Win64" : "Win32",
                "InfinadeckAPI.dll"
            )
        );
    }

    public string GetRuntimeDllDependencyPath()
    {
        return Path.Combine(Path.Combine(ThirdPartyPath, "Infinadeck", "lib"),
            (Target.Platform == UnrealTargetPlatform.Win64) ? "Win64" : "Win32",
            "InfinadeckAPI.dll");
    }

    public bool LoadInfinadeckLib(ReadOnlyTargetRules Target)
    {
        bool isLibrarySupported = false;

        if ((Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32))
        {
            isLibrarySupported = true;

            PublicAdditionalLibraries.Add(Path.Combine(Path.Combine(ThirdPartyPath, "Infinadeck", "lib"),
                (Target.Platform == UnrealTargetPlatform.Win64) ? "Win64" : "Win32",
                "InfinadeckAPI.lib"));

            PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "Infinadeck", "include"));
        }
        return isLibrarySupported;
    }
}