void setup()
{
pinMode(4, OUTPUT);
pinMode(2, INPUT);
pinMode(3, INPUT);
}

void loop()
{
if (digitalRead(2) == 1)
  {
    if (digitalRead(3) == 0)
      digitalWrite(4) = 1;
    else
      digitalWrite(4) =0;
  }
else
  {
    if (digitalRead(3) ==1)
      digitalWrite(4) =1;
  }
}
