const int LEDpin = 13;
const int button1 = 2;
const int button2 = 3;

void setup()
{
pinMode(button1, INPUT);
pinMode(button2, INPUT);
pinMode(LEDpin, OUTPUT);

  // put your setup code here, to run once:

}

void loop()
{
if(button1==1 && button2==0) // if one button pressed
digitalWrite(LEDpin,1);
else if(button1==0 && button2==1) // if one button pressed
digitalWrite(LEDpin,1);
}
//Group G
