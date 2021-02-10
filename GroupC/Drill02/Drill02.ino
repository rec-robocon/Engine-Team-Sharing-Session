const int buttonpin=2, Led=3;
int Pushbuttoncounter=0;
int currentmillis= millis();
int previousmillis= 0, timer=0;

void condition(int);

void setup()
{
  pinMode(buttonpin,INPUT);
  pinMode(Led,OUTPUT);
}

void loop()
{
  int button= digitalRead(buttonpin);
  timer = currentmillis - previousmillis;
  while (timer<=30000) //take in input for 30s
  {
    if (button == HIGH)
      Pushbuttoncounter++;
    timer = currentmillis - previousmillis;
  }

  condition(Pushbuttoncounter);
  Pushbuttoncounter=0;
  previousmillis=currentmillis;
}

void condition(int counter)
{
  if(counter%7==0) //first condition
    digitalwrite(led,HIGH);

  else if (counter%7!=0) //second condition
  {
    while (counter > 0)
    {
      int lastnumber= counter% 10; //read last number
      if (lastnumber == 7)
      {
        digitalWrite(Led, HIGH);
        break; //jump out from while loop
      }
      else
        counter = lastnumber/ 10; //if last number not 7, move on to second last digit
    }
  }
    else // doesnt meet both condution
      digitalWrite(Led, LOW);
} 
