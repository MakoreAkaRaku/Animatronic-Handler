#pragma once
#include <Servo.h>
#include <set.h>
/// @brief Class to handle the servo movement.
class ServoMotor
{
  public:
  ServoMotor() = delete;
  /// @brief Creates a new Servo by assigning the pinId. In case the pin is already used
  /// on another servo it will throw an exception. and it will return null.
  ServoMotor(const uint8_t assignedPinId);
  ~ServoMotor();
  private:
  static Set pinIDsUsed;
  const uint8_t pinId;
  const Servo myServo;
};