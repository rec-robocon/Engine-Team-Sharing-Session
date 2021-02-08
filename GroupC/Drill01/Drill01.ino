
const int BUTTON1 = 2;
const int BUTTON2 = 4;
const int LED = 8;

void setup()
{
Serial.begin(9600);
pinMode(BUTTON1, INPUT);
pinMode(BUTTON2, INPUT);
pinMode(LED, OUTPUT);

}

void loop()
{
  BUTTONstate1 = digitalRead(BUTTON1);
  BUTTONstate2 = digitalRead(BUTTON2);
  if (BUTTONstate1 == LOW||BUTTONstate2 == LOW)
  {
    digitalWrite(LED, LOW);
  }
  else if (BUTTONstate1 == HIGH && BUTTONstate2 == HIGH) {
    digitalWrite(LED, LOW);
  }
  else {
    digitalWrite(LED,HIGH);
  }
}
