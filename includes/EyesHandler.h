#pragma once
#include "Eye.h"
/// @brief Class to handle the eyes movement.
class EyesHandler
{
  public:
  EyesHandler() = delete;
  ~EyesHandler() = delete;
  static void MoveEyes(Eye::EYE_ID eyeIdentifier,uint16_t degrees);
  static bool Attach(pair<Eye::EYE_ID,uint8_t[2]> eyes[2]);
  static bool Dettach();
  /// @brief Returns true if the eyes handler can be used with the parameters of the constructor.
  /// @return 
  static bool IsAvailable();
  private:
  static const uint8_t NUM_OF_EYES = 2;
  static bool isAvailable;
  /// @brief Left eye is idx 0, right one is idx 1
  static Eye mEyes[NUM_OF_EYES];
};