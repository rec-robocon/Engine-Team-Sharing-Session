const int button1=3;
const int button2=4;
const int ledPin=5;
void setup()
{
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(ledpin,OUTPUT);

}

void loop()
{
  digitalWrite(ledPin,digitalRead(button1));
  digitalWrite(ledPin,digitalRead(button2));


}
