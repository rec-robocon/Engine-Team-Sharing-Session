//slave
#include <Wire.h>

int arr[100];
int count=0;

void setup()
{
  Wire.begin(4);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop()
{

      delay(100);


}

void receiveEvent(int howMany)
{
  while(Wire.available())
  {
    arr[count]= int(Wire.read());
    Serial.println(arr[count]);
    count++;
  }
  if(arr[99]==100)
  {
    for(int i=0; i<100; i++)
    {
      Serial.println( arr[i] + 100 );
    }
  }
}
