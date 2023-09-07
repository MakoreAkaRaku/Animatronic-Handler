#include "includes/EyesHandler.h"
/** TYPE ERROR CODE BLINK:
 * _____________________________
 * |    CODE    ||  NºBLINKS    |
 * |----------------------------|
 * | NO_ATTACH  ||      3       |
 * |
 * |
 * |
 * |
 */
void setup()
{
    Serial.begin(9600);
    pinMode(ERROR_PIN,OUTPUT);
    uint8_t error_code =0;
    uint8_t pinIds[3] = { 2, 3, 6 };
    if (!EyesHandler::Attach(pinIds))
    {
        error_code = 3;
    }

    if(error_code)
    {
        //Letting know that an error occurred.
        for (uint8_t i = 0; i < error_code; i++)
        {
            delay(2000);
            digitalWrite(ERROR_PIN,HIGH);
            delay(2000);
            digitalWrite(ERROR_PIN,LOW);
        }
    }
}

void loop()
{

}
