void setup()
{
  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(9, OUTPUT);
  int counter = 0;
}

void loop()
{
  if (digitalRead(8) == 1)
  {
    counter++;
    Serial.println("counter");
  }


  if (counter % 7 == 0)
  {
    digitalWrite(9, HIGH);
    delay(500);
    digitalWrite(9, LOW);
  }

}
