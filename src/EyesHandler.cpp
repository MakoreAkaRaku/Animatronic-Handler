#pragma once
#include "../includes/EyesHandler.h"
bool EyesHandler::isAvailable = false;
// Initializing static servos.
Servo EyesHandler::usedServo[] = {Servo(), Servo(), Servo()};

bool EyesHandler::IsAvailable()
{
    return isAvailable;
}

bool EyesHandler::Attach(uint8_t pinIds[NUM_OF_SERVOS_USED])
{
    isAvailable = true;
    for (uint8_t i = 0; i < NUM_OF_SERVOS_USED; i++)
    {
        // if attaching servos applied on the board exceeds the max ammount return false.
        if (usedServo[i].attach(pinIds[i]) == MAX_SERVOS)
        {
            isAvailable = false;
            break;
        }
    }
    // everything is correctly attached
    return isAvailable;
}

bool EyesHandler::MoveEyes(EyeMovement em)
{
    MoveID moveType = em.moveType;
    switch (moveType)
    {
    case HORIZONTAL:
    case VERTICAL:
    case EYELID:
        int rot = em.degrees;
        if (usedServo[moveType].read() != rot)
        {
            usedServo[moveType].write(rot);
        }
        break;
    default:
        return false;
    }
    return true;
}

int EyesHandler::Init()
{
    static EyeMovement initConfig[] = {
        {EyesHandler::HORIZONTAL,
         INIT_VALUE},
        {EyesHandler::VERTICAL,
         INIT_VALUE},
        {EyesHandler::EYELID,
         INIT_VALUE}};
    bool initOk = true;
    for (auto init : initConfig)
    {
        initOk = initOk && EyesHandler::MoveEyes(init);
    }

    return initOk;
}