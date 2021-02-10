const int buttonpin=2, Led=3 ,d=7;
int Pushbuttoncounter=0;
bool buttonpress;
string string(x);

void setup()
{
  pinMode(buttonpin,INPUT);
  pinMode(Led,OUTPUT);
}

void loop()
{
  button= digitalRead(buttonpin);
  if (button == LOW)
  {
    buttonpress = true;
    Pushbuttoncounter++;
  }
  condition(Pushbuttoncounter);
}

void condition(int Pushbuttoncounter)
{
  if(Pushbuttoncounter%d==0)
  {
    digitalwrite(led,HIGH);
    serialPrintln(Pushbuttoncounter);
  }
  else if (Pushbuttoncounter > 0)
  {
    while (Pushbuttoncounter > 0)
    {
      if (Pushbuttoncounter % 10 == d)
      {
        digitalWrite(Led, HIGH);
        break;
      }
      Pushbuttoncounter = Pushbuttoncounter / 10;
      else // doesnt meet both condution
     {
        digitalWrite(Led,LOW);
     }
  }
}
