/**
 * ------------------------------------------------------------
 * Copyright Infinadeck 2022
 * Created by George Burger
 * Infinadeck Blueprint Library implementation file for use with Unreal Engine 4.
 * https://github.com/Infinadeck/InfinadeckUnrealPlugin
 * ------------------------------------------------------------
 */

#include "InfinadeckBlueprintBPLibrary.h"
#include "Core.h"
#include "InfinadeckSDK.h"

UInfinadeckBlueprintBPLibrary::UInfinadeckBlueprintBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

FVector UInfinadeckBlueprintBPLibrary::GetTreadmillMotion() {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	return FInfinadeckSDKModule::Get().GetTreadmillDirection();
}

FVector UInfinadeckBlueprintBPLibrary::GetRingPosition() {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	return FInfinadeckSDKModule::Get().GetRingPosition();
}

float UInfinadeckBlueprintBPLibrary::GetRingRadius() {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	return FInfinadeckSDKModule::Get().GetRingRadius();
}

bool UInfinadeckBlueprintBPLibrary::GetTreadmillRunState() {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	return FInfinadeckSDKModule::Get().GetTreadmillRunState();
}

void UInfinadeckBlueprintBPLibrary::SetTreadmillRunState(bool state) {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	FInfinadeckSDKModule::Get().SetTreadmillRunState(state);
}

bool UInfinadeckBlueprintBPLibrary::GetTreadmillPause() {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	return FInfinadeckSDKModule::Get().GetTreadmillPause();
}

void UInfinadeckBlueprintBPLibrary::SetTreadmillPause(bool brake) {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	FInfinadeckSDKModule::Get().SetTreadmillPause(brake);
}

void UInfinadeckBlueprintBPLibrary::SetTreadmillManualMotion(float x, float y) {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	FInfinadeckSDKModule::Get().SetTreadmillManualMotion(x, y);
}

void UInfinadeckBlueprintBPLibrary::StartTreadmillManualControl() {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	FInfinadeckSDKModule::Get().StartTreadmillManualControl();
}

void UInfinadeckBlueprintBPLibrary::StartTreadmillUserControl() {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	FInfinadeckSDKModule::Get().StartTreadmillUserControl();
}

void UInfinadeckBlueprintBPLibrary::StopTreadmill() {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	FInfinadeckSDKModule::Get().StopTreadmill();
}

FString UInfinadeckBlueprintBPLibrary::GetTreadmillID() {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	return FInfinadeckSDKModule::Get().GetTreadmillID();
}

FString UInfinadeckBlueprintBPLibrary::GetTreadmillModelNumber() {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	return FInfinadeckSDKModule::Get().GetTreadmillModelNumber();
}

FString UInfinadeckBlueprintBPLibrary::GetTreadmillDLLVersion() {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	return FInfinadeckSDKModule::Get().GetTreadmillDLLVersion();
}

bool UInfinadeckBlueprintBPLibrary::CheckConnection() {
	return FInfinadeckSDKModule::Get().CheckConnection();
}

FString UInfinadeckBlueprintBPLibrary::ConnectToTreadmill() {
	InfinadeckInitError e = FInfinadeckSDKModule::Get().ConnectToTreadmill();
	FString errorInfo = "";
	if (e == InfinadeckInitError_None) { errorInfo = "ERROR: INIT CONNECTION FAILED WITH NO ERROR"; }
	else if (e == InfinadeckInitError_Unknown) { errorInfo = "ERROR: UNKNOWN ERROR"; }
	else if (e == InfinadeckInitError_NoServer) { errorInfo = "ERROR: NO SERVER FOUND"; }
	else if (e == InfinadeckInitError_UpdateRequired) { errorInfo = "ERROR: GAME API UPDATE REQUIRED"; }
	else if (e == InfinadeckInitError_InterfaceVerificationFailed) { errorInfo = "ERROR: FAILED TO VERIFY INTERFACE"; }
	else if (e == InfinadeckInitError_ControllerVerificationFailed) { errorInfo = "ERROR: FAILED TO VERIFY CONTROLLER"; }
	else if (e == InfinadeckInitError_FailedInitialization) { errorInfo = "ERROR: FAILED TO INITIALIZE"; }
	else if (e == InfinadeckInitError_FailedHostResolution) { errorInfo = "ERROR: FAILED TO RESOLVE HOST"; }
	else if (e == InfinadeckInitError_FailedServerConnection) { errorInfo = "ERROR: FAILED TO CONNECT TO SERVER"; }
	else if (e == InfinadeckInitError_FailedServerSend) { errorInfo = "ERROR: FAILED TO SEND PACKET TO SERVER"; }
	else if (e == InfinadeckInitError_RuntimeOutOfDate) { errorInfo = "ERROR: RUNTIME OUT OF DATE"; }
	else { errorInfo = "ERROR: UNDOCUMENTED ERROR"; }
	return errorInfo;
}

bool UInfinadeckBlueprintBPLibrary::CheckRuntimeOpen() {
	return FInfinadeckSDKModule::Get().CheckRuntimeOpen();
}

float UInfinadeckBlueprintBPLibrary::GetFloorSpeedMagnitude() {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	return FInfinadeckSDKModule::Get().GetFloorSpeedMagnitude();
}

float UInfinadeckBlueprintBPLibrary::GetFloorSpeedAngle() {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	return FInfinadeckSDKModule::Get().GetFloorSpeedAngle();
}

FVector UInfinadeckBlueprintBPLibrary::GetUserPosition() {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	return FInfinadeckSDKModule::Get().GetUserPosition();
}

FQuat UInfinadeckBlueprintBPLibrary::GetUserRotation() {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	return FInfinadeckSDKModule::Get().GetUserRotation();
}

void UInfinadeckBlueprintBPLibrary::SetVirtualRing(bool enable) {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	FInfinadeckSDKModule::Get().SetVirtualRing(enable);
}

bool UInfinadeckBlueprintBPLibrary::GetVirtualRingEnabled() {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	return FInfinadeckSDKModule::Get().GetVirtualRingEnabled();
}

FQuat UInfinadeckBlueprintBPLibrary::GetReferenceDeviceAngleDifference() {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	return FInfinadeckSDKModule::Get().GetReferenceDeviceAngleDifference();
}

FString UInfinadeckBlueprintBPLibrary::InfinadeckJSONImport(FString CfgFileName, bool FreshStart) {
	return FInfinadeckSDKModule::Get().InfinadeckJSONImport(CfgFileName, FreshStart);
}

TArray< FString > UInfinadeckBlueprintBPLibrary::InfinadeckJSONRead(FString CfgFileName) {
	return FInfinadeckSDKModule::Get().InfinadeckJSONRead(CfgFileName);
}

bool UInfinadeckBlueprintBPLibrary::InfinadeckJSONWrite(FString CfgFileName, TArray< FString > DataString) {
	return FInfinadeckSDKModule::Get().InfinadeckJSONWrite(CfgFileName, DataString);
}