/**
 * ------------------------------------------------------------
 * InfinadeckSDK InterOp header file for use with Unreal Engine 4.
 * https://github.com/Infinadeck/InfinadeckUnrealPlugin
 * Created by George Burger @ Infinadeck, 2019-2022
 * Attribution required.
 * ------------------------------------------------------------
 */

#pragma once

#include "Modules/ModuleManager.h"
#include "infinadeck.h"

class INFINADECKSDK_API FInfinadeckSDKModule : public IModuleInterface
{
public:
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
	inline void SetUserPosition(float x, float y);
	inline void SetUserRotation(float w, float x, float y, float z);
	inline void SetTreadmillManualMotion(double x, double y);
	inline FString InfinadeckJSONImport(FString CfgFileName);
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
