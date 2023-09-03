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
    pair<Eye::EYE_ID,uint8_t[2]> eyes[2] ={
        {
            Eye::LEFT,
            8, 9
        },
        {
            Eye::RIGHT,
            10, 11
        }
    };
    if (!EyesHandler::Attach(eyes))
    {
        error_code = 3;
    }

    if(error_code)
    {
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
