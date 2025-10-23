/**
 * ------------------------------------------------------------
 * Copyright Infinadeck 2022
 * Created by George Burger
 * InfinadeckSDK InterOp header file for use with Unreal Engine 4.
 * https://github.com/Infinadeck/InfinadeckUnrealPlugin
 * ------------------------------------------------------------
 */

#pragma once

#include "Modules/ModuleManager.h"
#include "infinadeck.h"

class INFINADECKSDK_API FInfinadeckSDKModule : public IModuleInterface
{
public:
	bool CheckRuntimeOpen();
	FVector GetRingPosition();
	FVector GetTreadmillDirection();
	float GetRingRadius();
	void SetTreadmillRunState(bool state);
	void StartTreadmillUserControl();
	void StartTreadmillManualControl();
	void StopTreadmill();
	bool GetTreadmillPause();
	void SetTreadmillPause(bool brake);
	bool GetTreadmillRunState();
	InfinadeckInitError ConnectToTreadmill();
	bool CheckConnection();
	FString GetTreadmillID();
	FString GetTreadmillModelNumber();
	FString GetTreadmillDLLVersion();
	void SetTreadmillManualMotion(double x, double y);
	float GetFloorSpeedMagnitude();
	float GetFloorSpeedAngle();
	FVector GetUserPosition();
	FQuat GetUserRotation();
	void SetVirtualRing(bool enable);
	bool GetVirtualRingEnabled();
	FQuat GetReferenceDeviceAngleDifference();
	FString InfinadeckJSONImport(FString CfgFileName, bool FreshStart);
	TArray< FString > InfinadeckJSONRead(FString CfgFileName);
	bool InfinadeckJSONWrite(FString CfgFileName, TArray< FString > DataString);
	
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static FInfinadeckSDKModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FInfinadeckSDKModule>("InfinadeckSDK");
	}

private:
	/** Handle to the test dll we will load */
	void* ExampleLibraryHandle = nullptr;
	bool run_once_ = false;
};
