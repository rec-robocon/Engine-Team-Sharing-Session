//Master
#include <Wire.h>

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
}

byte x = 1;

void loop()
{

  for(int i = 0;i < 100; i++ ){
    Wire.beginTransmission(4);
    Wire.write(x);              // sends one byte
    x++;
    Wire.endTransmission();    // stop transmitting
  }

}
