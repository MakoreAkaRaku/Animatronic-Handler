#pragma once
#include "utils.h"
#include <Servo.h>
#include <stdio.h>

/// @brief Class to handle the eyes movement.
class EyesHandler
{
  private:
  /// @brief
  /// Number of Servos used to handle the entire eyes behaviour.
  static const uint8_t NUM_OF_SERVOS_USED = 3;
  public:
  EyesHandler() = delete;
  ~EyesHandler() = delete;
  static void MoveEyes(uint16_t degrees);
  static bool Attach(uint8_t pinIds[NUM_OF_SERVOS_USED]);
  static bool Dettach();
  /// @brief Checks if handler is available.
  /// @return true if is available, otherwise false.
  static bool IsAvailable();
  private:
  static bool isAvailable;
  // First idx is de horizontal servo controller.
  // Second idx is the vertical servo controller.
  // Third idx is eyelids servo controller.
  static Servo usedServo[NUM_OF_SERVOS_USED];
};