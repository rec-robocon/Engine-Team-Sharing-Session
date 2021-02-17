unsigned long x;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available()) 
  {
    x +=Serial.read();
  }
  Serial.println(x);
}
