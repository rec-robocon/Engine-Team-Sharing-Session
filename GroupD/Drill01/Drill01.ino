void setup()
{
  pinMode(3, INPUT);
  pinMode(5, INPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  if(digitalRead(3,HIGH) || digitalRead(5,HIGH))
  {
    digitalWrite(2, HIGH);
  }
  else
    digitalWrite(2, LOW);
}
