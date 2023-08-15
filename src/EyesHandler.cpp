#pragma once
#include "../includes/EyesHandler.h"
bool EyesHandler::isAvailable = false;

bool EyesHandler::IsAvailable() const
{
    return isAvailable;
}