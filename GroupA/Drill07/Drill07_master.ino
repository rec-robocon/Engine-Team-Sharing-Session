#include <Wire.h>

void setup()
{
  Wire.begin();
  Serial.begin(9600);

  for(int i = 1; i <= 100; i++)
  {
    Serial.println(i);
    Wire.beginTransmission(4); // transmit to device #4
    Wire.write(i);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    delay(500);
  }
}

void loop()
{

}
