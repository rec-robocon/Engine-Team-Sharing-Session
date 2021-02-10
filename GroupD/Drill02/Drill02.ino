int b1 = 13;
int led2 = 11;
int counter =0;

void setup()
{
  Serial.begin(9600);
  pinMode (b1, INPUT);
  pinMode (led2, OUTPUT);
}

void loop()
{
  String x = digitalRead (b1);
  for( int i = 0 ; i < 1000 ; i++)
{
    x[i];
    counter++;
    Serial.println(counter);
}
  if (counter % 7 == 0 || x[i] == "7")
    {
        Serial.println(b2, HIGH);
    }
  while(x[i])
{
  
}
}
