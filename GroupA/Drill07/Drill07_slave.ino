#include <Wire.h>

int num[100] = {};
int counter = 0;
int count_1 = 0;

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

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  while(0 < Wire.available()) // loop through all but the last
  {
    num[counter] = Wire.read(); // receive byte
    counter++;
  }
  if(counter == 100)
  {
    while(count_1 < 100)
    {
      Serial.println(num[count_1] + 100);
      count_1++;
    }
  }
}
