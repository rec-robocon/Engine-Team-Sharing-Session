int button1 = 13;
int button2 = 12;
int led = 2

void setup()
{
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  int b1 = digitalRead(button1);
  int b2 = digitalRead(button2);

  if ((b1 == 1 && b2 == 0) || (b1 == 0 && b2 == 1))
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}
