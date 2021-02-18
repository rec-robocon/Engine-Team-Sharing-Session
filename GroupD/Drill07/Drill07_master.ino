#include <Wire.h>

void setup()
{
  Serial.begin(9600);
  Wire.begin(); // join i2c bus (address optional for master)
  for (int i=1; i<=100; i++)
  {
    Wire.beginTransmission(4); // transmit to device #4
    Serial.println(i);
    Wire.write(i);              // sends one byte
    Wire.endTransmission();    // stop transmitting
	}
  delay(500);
}

void loop()
{


}//---------------------------------------------------------------------------
