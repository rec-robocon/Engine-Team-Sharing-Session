#include <Wire.h>

byte x=1;
void setup()
{
  Serial.begin(9600);
  Wire.begin();
}

void loop()
{
  Serial.println(x);
  Wire.beginTransmission(4);
  Wire.write(x);
  Wire.endTransmission();
  x++;
  if(x=100)
  {
    Wire.requestFrom(4, 1);
    while (Wire.available())
      char c = Wire.read(); 
    Serial.println(c);
  }
}
