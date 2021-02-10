const int buttonpin=4;
const int ledpin=5;
int total=0;
int n=10;
void setup()
{
  pinmode(buttonpin,INPUT);
  pinmode(ledpin,OUTPUT);

}

void loop()
{
  if(digitalRead(buttonpin)==1)
  {
    if(digitalRead(buttonpin)==0)
      total=total+1;
  }

  int temp = total;//version 1
  while(temp != 0 ){
    int remainder = temp%10;
    if(remainder==7){
      digitalWrite(ledpin, HIGH);
    }
    temp /= 10;
  }

  if(total % 7 == 0 || ((total-n)==7)){//version 2,
    digitalWrite(ledpin,HIGH);
    n=n+10;
    }
}
