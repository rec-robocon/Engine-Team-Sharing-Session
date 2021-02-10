void setup()
{
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  bool is_pressed = false, has_seven = false;
  int counter = 0;
  String x;
  while (is_pressed == false)// put your main code here, to run repeatedly:
  {
    if (analogRead(A0) == 1)
    {
      is_pressed =  true;
      counter++;
    }
  }

  x = String(counter);

  for(int i = 0; x[i] != '7'; i++)
  {
    if (x[i] == '7')
      digitalWrite(4, HIGH);
  }


  if (counter%7 == 0)
  {
    digitalWrite(4, HIGH);
  }

}
