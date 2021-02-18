#include <Wire.h>

byte array1[100]="";
int i =0;
int a=0;
void setup()
{
  Wire.begin(4);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);
}

void loop()
{
  delay(500);
}
void receiveEvent(int howMany)
{
  while( Wire.available())
  {
        array1[i]=Wire.read();
        i++;
  }
}
void requestEvent() {
  array1[a]+=100;
  Wire.write(array1[a]);
  a++;
}
