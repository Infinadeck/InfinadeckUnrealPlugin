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
	inline bool CheckRuntimeOpen();
	inline FVector GetRingPosition();
	inline FVector GetTreadmillDirection();
	inline float GetRingRadius();
	inline void SetTreadmillRunState(bool state);
	inline void StartTreadmillUserControl();
	inline void StartTreadmillManualControl();
	inline void StopTreadmill();
	inline bool GetTreadmillPause();
	inline void SetTreadmillPause(bool brake);
	inline bool GetTreadmillRunState();
	inline InfinadeckInitError ConnectToTreadmill();
	inline bool CheckConnection();
	inline FString GetTreadmillID();
	inline FString GetTreadmillModelNumber();
	inline FString GetTreadmillDLLVersion();
	inline void SetTreadmillManualMotion(double x, double y);
	inline float GetFloorSpeedMagnitude();
	inline float GetFloorSpeedAngle();
	inline FVector GetUserPosition();
	inline FQuat GetUserRotation();
	inline void SetVirtualRing(bool enable);
	inline bool GetVirtualRingEnabled();
	inline FQuat GetReferenceDeviceAngleDifference();
	inline FString InfinadeckJSONImport(FString CfgFileName, bool FreshStart);
	inline TArray< FString > InfinadeckJSONRead(FString CfgFileName);
	inline bool InfinadeckJSONWrite(FString CfgFileName, TArray< FString > DataString);
	
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static inline FInfinadeckSDKModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FInfinadeckSDKModule>("InfinadeckSDK");
	}

private:
	/** Handle to the test dll we will load */
	void* ExampleLibraryHandle = nullptr;
	bool run_once_ = false;
};
