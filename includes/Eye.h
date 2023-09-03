#pragma once
#include "utils.h"
#include <Servo.h>

class Eye
{
public:
    enum EYE_ID
    {
        NONE = 0,
        LEFT,
        RIGHT
    };
    Eye(pair<EYE_ID,uint8_t[2]> eye_Identifier);
    EYE_ID GetIdentifier() const;
    void MoveLeft();
    void MoveRight();
    void MoveDown();
    void MoveUp();
    bool Attach();
    bool Dettach();
    ~Eye();
private:
    //Number of SERVOS used to handle the eye behaviour.
    static const uint8_t NUM_OF_SERVOS_USED = 2;
    // First idx is de horizontal servo controller.
    // Second idx is the vertical servo controller.
    Servo usedServos[NUM_OF_SERVOS_USED];
    // Eye identifier; tells which eye is the one is being used. 
    EYE_ID mId = NONE;
};