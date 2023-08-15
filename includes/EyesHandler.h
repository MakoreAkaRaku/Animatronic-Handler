#pragma once
#include "Eye.h"
/// @brief Class to handle the servo movement.
class EyesHandler
{
  public:
  EyesHandler() = delete;
  ~EyesHandler() = delete;
  void MoveEyes(Eye::EYE_ID eyeIdentifier,uint16_t degrees);
  bool Attach(pair<Eye::EYE_ID,uint8_t[2]> eyes[2]);
  bool Dettach();
  /// @brief Returns true if the eyes handler can be used with the parameters of the constructor.
  /// @return 
  bool IsAvailable() const;
  private:
  static bool isAvailable;
  /// @brief Left eye is idx 0, right one is idx 1
  static Eye eyes[2];
};