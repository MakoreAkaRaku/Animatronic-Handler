#pragma once
#include "utils.h"
#include <Servo.h>
/// @brief Class to handle the eyes movement.
class EyesHandler
{
private:
  /// @brief
  /// Number of Servos used to handle the entire eyes behaviour.
  static const uint8_t NUM_OF_SERVOS_USED = 3;

public:
  enum MoveID
  {
    HORIZONTAL,
    VERTICAL,
    EYELID
  };

  struct EyeMovement
  {
    MoveID moveType;
    int degrees;
  };

  EyesHandler() = delete;
  ~EyesHandler() = delete;
  static bool MoveEyes(EyeMovement em);
  static bool Attach(uint8_t pinIds[NUM_OF_SERVOS_USED]);
  static bool Dettach();
  static int Init();
  /// @brief Checks if handler is available.
  /// @return true if is available, otherwise false.
  static bool IsAvailable();

private:
  static const int MAX_H = 130, MAX_V = 115;//,MAX_EL;
  static const int MIN_H = 60, MIN_V = 75;//,MIN_EL;
  static const int INIT_VALUE = 90;
  static bool isAvailable;
  // First idx is de horizontal servo controller.
  // Second idx is the vertical servo controller.
  // Third idx is eyelids servo controller.
  static Servo usedServo[NUM_OF_SERVOS_USED];
};