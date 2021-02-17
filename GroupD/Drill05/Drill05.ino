int total = 0;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  String x = " ";
  while(Serial.available()>0)
  {
    char incomingbyte = Serial.read();
    x += incomingbyte;
    delay(100);
  }

  if (x != " ")
  {
    Serial.print("Your angpau: ");
    Serial.println(x);
    total += x.toInt();
    Serial.print("Total amount of your angpau: ");
    Serial.println(total);
  }
  //Serial.println(Serial.read());

}
