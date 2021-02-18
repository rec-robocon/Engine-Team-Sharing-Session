#include <Wire.h>

int i = 0;
int arr[100];

void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop()
{
  delay(100);
}

void receiveEvent(int howMany)
{
  while(Wire.available()) // loop through all but the last
  {
    arr[i] = Wire.read(); // receive byte as a character
    i++;
  }

if(arr[99]==100)
{
  for (int j = 0; j<sizeof(arr)/4; j++)
    {
      arr[j] += 100;
      Serial.println(arr[j]);
    }
  }
}
