#include "includes/ServoHandler.h"
ServoMotor* myServoM;
ServoMotor* my2ndServoM;
// 2 servo / ojo
// 
void setup()
{
    Serial.begin(9600);
    try
    {
    myServoM = new ServoMotor(5);
    my2ndServoM = new ServoMotor(5);
    }
    catch(size_t writtenBytes)
    {
        Serial.println("Could not initialize some ServoMotors");
    }

    pinMode(13,OUTPUT);
}

void loop()
{
    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);
}
