#include "includes/EyesHandler.h"
/**
 * @brief
 *
 */
void setup()
{
    Serial.begin(115200);
    pinMode(ERROR_PIN, OUTPUT);
    uint8_t error_code = 0;
    uint8_t pinIds[3] = {8, 9, 6};
    EyesHandler::Init();
    if (!EyesHandler::Attach(pinIds))
    {
        error_code = 3;
    }

    if (error_code)
    {
        // Letting know that an error occurred.
        for (uint8_t i = 0; i < error_code; i++)
        {
            delay(2000);
            digitalWrite(ERROR_PIN, HIGH);
            delay(2000);
            digitalWrite(ERROR_PIN, LOW);
        }
    }
    Serial.println("I finish setup()");
}
static int8_t i = 0;
void loop()
{
    if (Serial.available() > 0)
    {
        char a = Serial.read();
        EyesHandler::EyeMovement em;
        switch (a)
        {
        case 'l':
            Serial.println("Move left");
            em.degrees = 130;
            em.moveType = EyesHandler::HORIZONTAL;
            break;
        case 'r':
            Serial.println("Move right");
            em.degrees = 60;
            em.moveType = EyesHandler::HORIZONTAL;
            break;
        case 't':
            Serial.println("Move top");
            em.degrees = 115;
            em.moveType = EyesHandler::VERTICAL;
            break;
        case 'b':
            Serial.println("Move bottom");
            em.degrees = 75;
            em.moveType = EyesHandler::VERTICAL;
            break;
        default:
            Serial.println("Error...");
            em.moveType=EyesHandler::HORIZONTAL;
            em.degrees= 90;
            EyesHandler::MoveEyes(em);
            em.moveType = EyesHandler::VERTICAL;
            break;
        }
        EyesHandler::MoveEyes(em);
    }
}
