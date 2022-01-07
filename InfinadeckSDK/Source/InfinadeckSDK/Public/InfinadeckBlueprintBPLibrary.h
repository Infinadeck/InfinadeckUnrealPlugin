/**
 * ------------------------------------------------------------
 * Infinadeck Blueprint Library header file for use with Unreal Engine 4.
 * https://github.com/Infinadeck/InfinadeckUnrealPlugin
 * Created by George Burger @ Infinadeck, 2019-2022
 * Attribution required.
 * ------------------------------------------------------------
 */

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "InfinadeckBlueprintBPLibrary.generated.h"
/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class INFINADECKSDK_API UInfinadeckBlueprintBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
		
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get X and Y Movement Data from Treadmill", Keywords = "Infinadeck Treadmill Locomotion Movement Omnidirectional"), Category = "Infinadeck")
	static FVector GetTreadmillMotion();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get position of treadmill ring", Keywords = "Infinadeck Treadmill Locomotion Ring Omnidirectional"), Category = "Infinadeck")	
	static FVector GetRingPosition();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get radius of treadmill ring", Keywords = "Infinadeck Treadmill Locomotion Ring Radius Omnidirectional"), Category = "Infinadeck")
	static float GetRingRadius();
  
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Check if treadmill is running", Keywords = "Infinadeck Treadmill Control VR Locomotion Omnidirectional"), Category = "Infinadeck")
	static bool GetTreadmillRunState();
 
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set treadmill to run", Keywords = "Infinadeck Treadmill Locomotion Control VR Omnidirectional"), Category = "Infinadeck")
	static void SetTreadmillRunState(bool state);
  
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Check if treadmill is paused", Keywords = "Infinadeck Treadmill Locomotion Control VR Omnidirectional"), Category = "Infinadeck")  
	static bool GetTreadmillPause();
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Pause treadmill motion", Keywords = "Infinadeck Treadmill Locomotion Control VR Omnidirectional"), Category = "Infinadeck")
	static void SetTreadmillPause(bool brake);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set User Position and rotation", Keywords = "Infinadeck Treadmill Locomotion Control VR Omnidirectional"), Category = "Infinadeck")
	static void SetTreadmillUserPositionRotation(FVector position, FQuat quaternion);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Treadmill Manual Direction", Keywords = "Infinadeck Treadmill Locomotion Control VR Omnidirectional"), Category = "Infinadeck")
	static void SetTreadmillManualMotion(float x, float y);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Start the treadmill in User Control mode", Keywords = "Infinadeck Treadmill Locomotion Control VR Omnidirectional"), Category = "Infinadeck")
	static void StartTreadmillUserControl();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Start the treadmill in Manual Control mode", Keywords = "Infinadeck Treadmill Locomotion Control VR Omnidirectional"), Category = "Infinadeck")
	static void StartTreadmillManualControl();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Stop the treadmill", Keywords = "Infinadeck Treadmill Locomotion Control VR Omnidirectional"), Category = "Infinadeck")
	static void StopTreadmill();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get the treadmill ID", Keywords = "Infinadeck Treadmill Locomotion Control VR Omnidirectional"), Category = "Infinadeck")
	static FString GetTreadmillID();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get the treadmill model number", Keywords = "Infinadeck Treadmill Locomotion Control VR Omnidirectional"), Category = "Infinadeck")
	static FString GetTreadmillModelNumber();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get the treadmill DLL version", Keywords = "Infinadeck Treadmill Locomotion Control VR Omnidirectional"), Category = "Infinadeck")
	static FString GetTreadmillDLLVersion();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Import JSON File (Infinadeck)", Keywords = "Infinadeck Treadmill Data Json Omnidirectional"), Category = "Infinadeck")
	static FString InfinadeckJSONImport(FString CfgFileName);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Read JSON File (Infinadeck)", Keywords = "Infinadeck Treadmill Data Json Omnidirectional"), Category = "Infinadeck")
	static TArray< FString > InfinadeckJSONRead(FString CfgFileName);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Write JSON File (Infinadeck)", Keywords = "Infinadeck Treadmill Data Json Omnidirectional"), Category = "Infinadeck")
	static bool InfinadeckJSONWrite(FString CfgFileName, TArray< FString > DataString);
};
