int btn=11;
int led=12;
int counter=0;

void setup()
{ serial.begin(9600);
  pinMode(btn,INPUT);
  pinMode(led,OUTPUT);

}


void ledlight(int n)
{
  if(n%7==0||n%10==7)
  {
    digitalWrite(led,1);
  }
  else{
    digitalWrite(led,0);
  }

}

void loop()
{
  if(digitalRead(btn)==1)
  {
  counter ++;
  serial.print(counter);
  ledlight(counter);
  }


}
