int button = 10;
int counter = 0;
int led = 13;
int ButtonPressed = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  if(ButtonPressed == 0)
  {
    if(DigitalRead(button)==0)
    {
    }
    else{
      counter++;
      ButtonPressed = 1;
      delay(30);
    }
  }
  else{
    if(DigitalRead(button)==0)
    {
      ButtonPressed = 0;
      delay(30);
    }
    else{

    }
  }

  String x = String(counter);
  for (int i=0; i<length(x); i++)
  {
    if (x[i]==7)
    {
      digitalWrite(led, HIGH);
    }
  }

  if (counter%7 == 0)
  {
    digitalWrite(led, HIGH);
  }

  else
  {
    digitalWrite(led, LOW);
  }

}
//Group G
