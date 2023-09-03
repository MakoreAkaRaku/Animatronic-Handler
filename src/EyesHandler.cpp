#pragma once
#include "../includes/EyesHandler.h"

bool EyesHandler::isAvailable = false;
//Initialize with null information.
Eye EyesHandler::mEyes[]={Eye(pair<Eye::EYE_ID,uint8_t[2]>()),pair<Eye::EYE_ID,uint8_t[2]>()}; 

bool EyesHandler::IsAvailable()
{
    return isAvailable;
}

bool EyesHandler::Attach(pair<Eye::EYE_ID,uint8_t[2]> eyes[2])
{
    for (uint8_t i = 0; i < NUM_OF_EYES; i++)
    {
        mEyes[i] = Eye(eyes[i]);
        // if the eye did not get attached
        if(!mEyes[i].Attach())
        {
            return false;
        }
    }
    //everything is correctly attached
    return true;
}