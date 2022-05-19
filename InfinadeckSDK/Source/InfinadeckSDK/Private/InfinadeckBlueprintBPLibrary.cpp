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
  FInfinadeckSDKModule::Get().SetTreadmillManualMotion(x,y); 
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

FString UInfinadeckBlueprintBPLibrary::InfinadeckJSONImport(FString CfgFileName) {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	return FInfinadeckSDKModule::Get().InfinadeckJSONImport(CfgFileName);
}

TArray< FString > UInfinadeckBlueprintBPLibrary::InfinadeckJSONRead(FString CfgFileName) {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	return FInfinadeckSDKModule::Get().InfinadeckJSONRead(CfgFileName);
}

bool UInfinadeckBlueprintBPLibrary::InfinadeckJSONWrite(FString CfgFileName, TArray< FString > DataString) {
	if (!FInfinadeckSDKModule::Get().CheckConnection()) {
		FInfinadeckSDKModule::Get().ConnectToTreadmill();
	}
	return FInfinadeckSDKModule::Get().InfinadeckJSONWrite(CfgFileName, DataString);
}