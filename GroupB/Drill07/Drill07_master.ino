//Master
#include <Wire.h>

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
}


void loop()
{
  for(int i = 1;i < 101; i++ ){
    Wire.beginTransmission(4);
    Wire.write(i);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    delay(500);
  }
}
