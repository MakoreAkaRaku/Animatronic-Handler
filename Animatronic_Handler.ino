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
    uint8_t error_code =0;
    uint8_t pinIds[3] = { 2, 3, 6 };
    if (!EyesHandler::Attach(pinIds))
    {
        error_code = 3;
    }

    if(error_code){
        Serial.print("Something went wrong");
        pinMode(13,OUTPUT);
        //Letting know that an error occurred.
        for (uint8_t i = 0; i < error_code; i++)
        {
            delay(2000);
            digitalWrite(13,HIGH);
            delay(2000);
            digitalWrite(13,LOW);
        }
    }
}

void loop()
{

}
