/**
 * ------------------------------------------------------------
 * Copyright Infinadeck 2022
 * Created by George Burger
 * InfinadeckAPI.dll InterOp header file for use with C++ Applications.
 * https://github.com/Infinadeck/InfinadeckSDK
 * ------------------------------------------------------------
 */

#ifndef INFINADECK_H_
#define INFINADECK_H_

#include <cstdint>

#define API_VERSION_MAJOR 2
#define API_VERSION_MINOR 2
#define API_VERSION_BUILD 0

#define INFINADECK_SERIAL_NUMBER_MAX_LENGTH 40

/// @brief The different results from initialization
enum InfinadeckInitError {
  InfinadeckInitError_None,
  InfinadeckInitError_Unknown,
  InfinadeckInitError_NoServer,
  InfinadeckInitError_UpdateRequired,
  InfinadeckInitError_InterfaceVerificationFailed,
  InfinadeckInitError_ControllerVerificationFailed,
  InfinadeckInitError_FailedInitialization,
  InfinadeckInitError_FailedHostResolution,
  InfinadeckInitError_FailedServerConnection,
  InfinadeckInitError_FailedServerSend,
  InfinadeckInitError_RuntimeOutOfDate
};

namespace Infinadeck {
  
  /// @brief Contains a 2-axis speed value
  struct SpeedVector2 {
    double v[2];
  };

  /// @brief Represents the position and radius of the virtual ring
  struct Ring {
    double x;
    double y;
    double z;
    double r;
  };

  /// @brief Various strings describing a treadmill on the network
  struct TreadmillInfo {
    char id[32];
    char model_number[32];
    char treadmill_version[32];
  };

  /// @brief Represents a 3-axis point
  struct PositionVector3 {
      double x;
      double y;
      double z;
  };

  /// @brief Represents a rotation represented as a quaternion
  struct QuaternionVector4 {
      double w;
      double x;
      double y;
      double z;
  };

  /// @brief Combines a user's 3-axis position and rotation
  struct UserPositionRotation {
      PositionVector3 position;
      QuaternionVector4 quaternion;
  };

  /// @brief Represents various numerical data points for a treadmill on the network
  struct DiagnosticInfo {
      SpeedVector2 service_distance;
      SpeedVector2 total_distance;
      double service_hours;
      double total_hours;
  };

}
#if defined( _WIN32 )
#define API_CALLTYPE __cdecl
#else
#define API_CALLTYPE 
#endif

#ifdef INFINADECK_API_EXPORTS  
#define INFINADECK_API extern "C" __declspec(dllexport)   
#else  
#define INFINADECK_API extern "C" __declspec(dllimport)   
#endif  

namespace Infinadeck {

  /// @brief Get the current floor speed in each axis
  /// 
  /// @return The speed in the X and Y axis, in m/s
  INFINADECK_API SpeedVector2 API_CALLTYPE GetFloorSpeeds();

  /// @brief Treating the floor velocity as a vector, get the magnitude
  /// 
  /// @return The magnitude of the floor velocity, in m/s
  INFINADECK_API double API_CALLTYPE GetFloorSpeedMagnitude();


  /// @brief Treating the floor velocity as a vector, get the direction
  /// 
  /// @return The direction of the floor velocity, in radians
  INFINADECK_API double API_CALLTYPE GetFloorSpeedAngle();

  /// @brief Set the manual speed in the X and Y axis
  /// 
  /// @details The treadmill can be operated in manual mode, with the speed in the X and Y axis set by the user. This
  ///          be done using the on-screen joystick in the desktop application, or by using this function. In the event
  ///          that both the on-screen joystick and this function are used simultaneously, the on-screen joystick takes
  ///          priority.
  /// 
  /// @param[in] x,y The velocity sent to each axis, in m/s
  INFINADECK_API void API_CALLTYPE SetManualSpeeds(double x, double y);

  /// @brief Start the treadmill using user tracking
  ///
  /// @details The treadmill's primary method of operation is by moving the floor in response to user motion, to keep
  ///          the user in the center. This function will start the treadmill in this mode, if it is currently possible
  ///          to do so. If the treadmill is not in the correct state, or it is already in any active mode, this will
  ///          have no effect.
  INFINADECK_API void API_CALLTYPE StartTreadmillUserControl();

  /// @brief Check if there is an active connection to Infinadeck Runtime
  /// 
  /// @return whether connection is active or not
  INFINADECK_API bool API_CALLTYPE CheckConnection();

  /// @brief Gets the position and size of the virtual ring
  /// 
  /// @details The ring on the treadmill frame is available in the VR world space. This function will retrieve the
  ///          current position of the ring in 3D space, as well as the radius of the ring. In order to be accurate,
  ///          the center position must be correctly calibrated.
  /// 
  /// @return Struct containing position and radius of the ring in VR
  INFINADECK_API Ring API_CALLTYPE GetRing();

  /// @brief Set the treadmill to run in either tracked or manual mode
  /// 
  /// @param[in] state `true` if using tracking mode, `false` if using manual mode
  INFINADECK_API void SetTreadmillRunState(bool state);

  /// @brief Start the treadmill in manual mode
  /// 
  /// @details The treadmill can be operated in manual mode, with the speed in the X and Y axis set by the user. This 
  ///          function will start the treadmill in this mode, if it is currently possible to do so. If the treadmill
  ///          is not in the correct state, or it is already in any active mode, this will have no effect.
  INFINADECK_API void StartTreadmillManualControl();

  /// @brief Stop the treadmill if it is moving
  ///
  /// @details If the treadmill is currently in motion, this function will stop it and put it in a state where it is
  ///          ready to receive another start command. If the treadmill is already stopped, this will have no effect.
  INFINADECK_API void StopTreadmill();

  /// @brief Gets whether the treadmill is currently is motion
  /// 
  /// @return whether the treadmill is currently moving or not
  INFINADECK_API bool API_CALLTYPE GetTreadmillRunState();

  /// @brief Get the serial number of the currently connected treadmill
  /// 
  /// @param[out] string Buffer containing the serial number
  /// @param[in] length Size of the given buffer
  INFINADECK_API void API_CALLTYPE GetTreadmillSerialNumber(char* string, int length);

  /// @brief Get the current treadmill's serial number, model number, and firmware version
  /// 
  /// @return struct containing the serial number, model number, and firmware version
  INFINADECK_API TreadmillInfo API_CALLTYPE GetTreadmillInfo();

  /// @brief Get the user's current position and rotation in the tracking space
  /// 
  /// @return Struct containing the user's current position and rotation
  INFINADECK_API UserPositionRotation API_CALLTYPE GetUserPositionRotation();

  /// @brief Get diagnostic information about the currently connected treadmill
  /// 
  /// @return struct information about the currently connected treadmill
  INFINADECK_API DiagnosticInfo API_CALLTYPE GetDiagnostics();

  /// @brief Currently does nothing
  INFINADECK_API void API_CALLTYPE SetTreadmillPause(bool enable);

  /// @brief Currently does nothing
  INFINADECK_API bool API_CALLTYPE GetTreadmillPauseState();

  /// @brief Currently does nothing
  INFINADECK_API void API_CALLTYPE SetVirtualRing(bool enable);

  /// @brief Currently does nothing
  INFINADECK_API bool API_CALLTYPE GetVirtualRingEnabled();

  /// @brief Get the difference between the angles of the reference tracking device and floor speed
  /// 
  /// @details The difference in the angle between the treadmill and the reference device (parallel to the plane of the
  ///          treadmill) may be useful for several purposes, most notably mapping the user's motion onto a virtual 
  ///          trackpad for moving in VR applications that don't natively support Infinadeck.
  /// 
  /// @return Quaternion representing the differential rotation
  INFINADECK_API QuaternionVector4 API_CALLTYPE GetReferenceDeviceAngleDifference();

  /// @brief Should not be called by the user
  INFINADECK_API uint32_t API_CALLTYPE InitInternal(InfinadeckInitError* inError);
  
  /// @brief Get a detailed text description of the most recent error during initialization
  /// 
  /// @param[out] buffer String buffer containing the error description
  /// @param[in] buffer_size The size of the given buffer
  INFINADECK_API void API_CALLTYPE GetLastInitErrorDescription(char* buffer, int buffer_size);

  /// @brief Initializes API and connects to Runtime
  /// @param[in] err Error description, set to `InfinadeckInitError_None` if successful
  inline void InitInfinadeckConnection(InfinadeckInitError* err) {
    *err = InfinadeckInitError_None;
    InitInternal(err);
  }

  /// @brief Should not be called by user 
  INFINADECK_API uint32_t API_CALLTYPE DeInitInternal();

  /// @brief Shuts down the API and closes connection to the Runtime
  inline void DeInitInfinadeckConnection() {
    DeInitInternal();
  }
}
#endif
