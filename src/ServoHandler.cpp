#pragma once
#include "../includes/ServoHandler.h"

Set ServoMotor::pinIDsUsed = Set();
ServoMotor::ServoMotor(const uint8_t assignedPinId)
    : pinId(assignedPinId)
{
    if (pinIDsUsed.has(assignedPinId)|| pinIDsUsed.isFull())
    {
        char err_msg[53]; //Checked how the maximum length of the message can be
        sprintf(err_msg,"ServoMotor(): the pin with ID %d is already in use!",assignedPinId);
        throw Serial.println(err_msg);
    }
};

ServoMotor::~ServoMotor()
{
    pinIDsUsed.sub(pinId);
}
