void setup()
{
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
if (digitalRead(13)==0 && digitalRead(12)==0)
 {
  digitalWrite(11,0);
}
else if
(digitalRead(13)==1 && digitalRead(12)==1
{
  digitalWrite(11,0);
}
else
{
  digitalWrite(11,1);
}
}
