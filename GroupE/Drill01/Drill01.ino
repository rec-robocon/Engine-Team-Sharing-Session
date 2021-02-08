int ledPin=13;
int buttonPin1=12;
int buttonPin2 =11;
void setup()
{
  pinMode (ledPin, OUTPUT);
  pinMode (buttonPin1, INPUT);
  pinMode (buttonPin2, INPUT);

}

void loop()
{
  button1=digitalRead(buttonPin1);
  button2=digitalRead(buttonPin2);
  if ( buttonPin1==1 && buttonPin2 ==1 ){
    digitalWrite(ledPin,LOW);
  }
  else if ( buttonPin1==0 && buttonPin2 ==0 ){
    digitalWrite(ledPin,LOW);
  }
  else{
    digitalWrite(ledPin,HIGH);
  }

}
