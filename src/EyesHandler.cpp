#pragma once
#include "../includes/EyesHandler.h"

bool EyesHandler::isAvailable = false;
//Initializing static servos.
Servo EyesHandler::usedServo[]={ Servo(), Servo(), Servo()}; 

bool EyesHandler::IsAvailable()
{
    return isAvailable;
}

bool EyesHandler::Attach(uint8_t pinIds[NUM_OF_SERVOS_USED])
{
    isAvailable = true;
    for (uint8_t i = 0; i < NUM_OF_SERVOS_USED; i++)
    {
        //if attaching servos applied on the board exceeds the max ammount return false.
        if( usedServo[i].attach(pinIds[i]) == MAX_SERVOS)
        {
            printf("EyesHandler: Maximum amount of servos already in use!");
            isAvailable = false;
            break;
        }
    }
    //everything is correctly attached
    return isAvailable;
}

void EyesHandler::MoveEyes(EyeMovement movements[])
{
    uint8_t numOfMoves = sizeof(movements)/sizeof(EyeMovement);
    if (!AreValidMoves(movements,numOfMoves))
    {
        //Evading non controlled behaviour for extended parallel movements.
        return;
    }
    const int mask = VERTICAL|HORIZONTAL;
    //Check for multiple incongruencies
    bool finishedActions = false;
    while(!finishedActions)
    {
        int oldPosH = usedServo[0].read();
        int oldPosV = usedServo[1].read();
        int oldPosEL = usedServo[2].read();
        for (uint8_t i = 0; i < numOfMoves; i++)
        {
            if (mask & movements[i].moveType)
            {

            }
            ///TODO: Check if there's incongruencies like distinctions of NONE and VERTICAL OR HORIZONTAL.
        }
    }
}

bool EyesHandler::AreValidMoves(EyeMovement moves[],uint8_t numOfMoves)
{
    if (numOfMoves > NUM_OF_SERVOS_USED)
        return false;
        ///TODO: missing to check using only one of each possible movement good combination for moves.
    return true;
}