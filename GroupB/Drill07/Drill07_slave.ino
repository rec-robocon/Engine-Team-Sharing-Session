//Slave
#include <Wire.h>
int arry[100] = {}, i = 0;

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
  while(Wire.available())
  {
    arry[i] = Wire.read();
    i++;
  }

  if(arry[99] == 100)
  {
  		for (int a = 0; a < 100; a++)
    	{
      		Serial.println(arry[a] + 100);
         	delay(500);
    	}
  }
}
