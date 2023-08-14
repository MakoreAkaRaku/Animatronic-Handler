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
    EYE_ID mId = NONE;
    uint8_t assignedPins[2];
};