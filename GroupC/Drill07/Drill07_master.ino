//master
#include <Wire.h>

void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  for (byte x=1;x<=100;x++)
    {
      Wire.beginTransmission(4);
      Wire.write(x);
      delay(100);
      Wire.endTransmission();
    }
}
