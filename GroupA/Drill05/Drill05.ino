int x;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available())
  {
    x += Serial.read();
    Serial.print("The total amount is ");
    Serial.println(x);
  }
}
