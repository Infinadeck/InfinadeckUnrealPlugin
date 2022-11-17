/**
 * ------------------------------------------------------------
 * Copyright Infinadeck 2022
 * Created by George Burger
 * InfinadeckSDK InterOp implementation file for use with Unreal Engine 4.
 * https://github.com/Infinadeck/InfinadeckUnrealPlugin
 * ------------------------------------------------------------
 */

#include "InfinadeckSDK.h"
#include "Core.h"
#include "Math/UnitConversion.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "infinadeck.h"
#include <JsonObjectConverter.h>

#define LOCTEXT_NAMESPACE "FInfinadeckSDKModule"

static bool connection_attempted_ = false;

//returns the units being used by the engine
float GetUnrealUnits()
{
	float distanceUnitScale = 100.0;
	FString ValueReceived; //Get scale value from settings
	if (GConfig->GetString(TEXT("/Script/UnrealEd.EditorProjectAppearanceSettings"),
	                       TEXT("DistanceUnits"), ValueReceived, GEditorIni))
	{
		TOptional<EUnit> currentUnit = FUnitConversion::UnitFromString(*ValueReceived);
		if (!currentUnit.IsSet())
		{
			//set the unit if it is not already set
			currentUnit = EUnit::Centimeters;
		}
		switch (currentUnit.GetValue())
		{
			//sets the unit conversion factor based on what unit is connected
		case EUnit::Micrometers:
			distanceUnitScale = 1000000.0;
			break;
		case EUnit::Millimeters:
			distanceUnitScale = 1000.0;
			break;
		case EUnit::Centimeters:
			distanceUnitScale = 100.0;
			break;
		case EUnit::Meters:
			distanceUnitScale = 1.0;
			break;
		case EUnit::Kilometers:
			distanceUnitScale = 0.001;
			break;
		default:
			distanceUnitScale = 100.0;
		}
	}
	return distanceUnitScale; //return the unit scale
}

//returns the ring position after converting based on the unit scale
FVector FInfinadeckSDKModule::GetRingPosition()
{
	Infinadeck::Ring ring = Infinadeck::GetRing();
	float distanceUnitScale = GetUnrealUnits();
	FVector RingPosition = FVector(ring.x * distanceUnitScale, ring.y *
	               distanceUnitScale, ring.z * distanceUnitScale); //converts the values according to the unit scale
	return RingPosition;
}

//return the radius of the ring
float FInfinadeckSDKModule::GetRingRadius()
{
	Infinadeck::Ring ring = Infinadeck::GetRing();
	return (float)ring.r * GetUnrealUnits();
}

//return the current treadmill's serial number
FString FInfinadeckSDKModule::GetTreadmillID()
{
	Infinadeck::TreadmillInfo info = Infinadeck::GetTreadmillInfo();
	return (FString)info.id;
}

//return the current treadmill's model number
FString FInfinadeckSDKModule::GetTreadmillModelNumber()
{
	Infinadeck::TreadmillInfo info = Infinadeck::GetTreadmillInfo();
	return (FString)info.model_number;
}

//return the current treadmill's dll version
FString FInfinadeckSDKModule::GetTreadmillDLLVersion()
{
	Infinadeck::TreadmillInfo info = Infinadeck::GetTreadmillInfo();
	return (FString)info.treadmill_version;
}

//determines and returns the speed and direction that the treadmill is moving
FVector FInfinadeckSDKModule::GetTreadmillDirection()
{
	Infinadeck::SpeedVector2 vec = Infinadeck::GetFloorSpeeds();
	float distanceUnitScale = GetUnrealUnits();
	FVector TreadmillDirection =  FVector(vec.v[0] * distanceUnitScale, vec.v[1] * distanceUnitScale, 0);
	return TreadmillDirection;
}

//setter for the treadmill's state (running or not)
void FInfinadeckSDKModule::SetTreadmillRunState(bool state)
{
	Infinadeck::SetTreadmillRunState(state);
}

//getter for the treadmill's state (running or not)
bool FInfinadeckSDKModule::GetTreadmillRunState()
{
	return Infinadeck::GetTreadmillRunState();
}

//getter for the treadmill's break
bool FInfinadeckSDKModule::GetTreadmillPause()
{
	return Infinadeck::GetTreadmillPauseState();
}

//turns the brake on or off
void FInfinadeckSDKModule::SetTreadmillPause(bool brake)
{
	Infinadeck::SetTreadmillPause(brake);
}

// Starts the treadmill in User Mode
void FInfinadeckSDKModule::StartTreadmillUserControl()
{
	Infinadeck::StartTreadmillUserControl();
}

// Starts the treadmill in Manual Mode
void FInfinadeckSDKModule::StartTreadmillManualControl()
{
	Infinadeck::StartTreadmillManualControl();
}

// Stop the treadmill
void FInfinadeckSDKModule::StopTreadmill()
{
	Infinadeck::StopTreadmill();
}

//checks the connection to the treadmill and client
bool FInfinadeckSDKModule::CheckConnection()
{
	return Infinadeck::CheckConnection();
}

//attempt a connection to the treadmill using the client.js program
InfinadeckInitError FInfinadeckSDKModule::ConnectToTreadmill()
{
	InfinadeckInitError e = InfinadeckInitError_FailedServerConnection;
	Infinadeck::InitInfinadeckConnection(&e);
	return e;
}

void FInfinadeckSDKModule::SetTreadmillManualMotion(double x, double y)
{
	Infinadeck::SetManualSpeeds(x, y);
}

void FInfinadeckSDKModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("InfinadeckSDK")->GetBaseDir();
	// Add on the relative location of the third party dll and load it
	FString LibraryPath;
#if PLATFORM_WINDOWS
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/Infinadeck/lib/Win64/InfinadeckAPI.dll"));
#elif PLATFORM_MAC
  LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/InfinadeckSDKLibrary/Mac/Release/libExampleLibrary.dylib"));
#endif // PLATFORM_WINDOWS
	ExampleLibraryHandle = !LibraryPath.IsEmpty()
		                       ? FPlatformProcess::GetDllHandle(
			                       *LibraryPath)
		                       : nullptr;
	if (ExampleLibraryHandle)
	{
		// Call the test function in the third party library that opens a message box
	}
	else
	{
		//FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError",
		//                                              "Failed to load Infinadeck third party library"));
	}
}

//bool FInfinadeckSDKModule::run_once_ = false;
void FInfinadeckSDKModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	// Free the dll handle
	FPlatformProcess::FreeDllHandle(ExampleLibraryHandle);
	ExampleLibraryHandle = nullptr;
}

FString FInfinadeckSDKModule::InfinadeckJSONImport(FString CfgFileName)
{
	IFileManager& FileManager = IFileManager::Get();

	FString JsonString;
	if (!FileManager.FileExists(*CfgFileName)) { 
		UE_LOG(LogTemp, Warning, TEXT("FInfinadeckSDKModule::InfinadeckJSONImport() unable to import configuration file %s - generating empty"), *CfgFileName);
		FString EmptyString;
		FFileHelper::SaveStringToFile(EmptyString, *CfgFileName);
	}
	FFileHelper::LoadFileToString(JsonString, *CfgFileName);
	return JsonString;
}

TArray< FString > FInfinadeckSDKModule::InfinadeckJSONRead(FString CfgFileName)
{
	IFileManager& FileManager = IFileManager::Get();

	TArray< FString > JsonStringA;
	if (!FFileHelper::LoadFileToStringArray(JsonStringA, *CfgFileName))
	{
		UE_LOG(LogTemp, Warning, TEXT("FInfinadeckSDKModule::InfinadeckJSONRead() unable to read configuration file %s - using defaults"), *CfgFileName);
	}
	return JsonStringA;
}

bool FInfinadeckSDKModule::InfinadeckJSONWrite(FString CfgFileName, TArray< FString > DataString)
{
	IFileManager& FileManager = IFileManager::Get();

	if (!FFileHelper::SaveStringArrayToFile(DataString, *CfgFileName))
	{
		UE_LOG(LogTemp, Warning, TEXT("FInfinadeckSDKModule::InfinadeckJSONWrite() unable to write configuration file %s - using defaults"), *CfgFileName);
		return false;
	}
	return true;
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FInfinadeckSDKModule, InfinadeckSDK)
