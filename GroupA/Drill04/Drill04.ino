// TimedAction.h
#ifndef TIMEDACTION_H
#define TIMEDACTION_H

//#include "arduino.h"

#define NO_PREDELAY 0

class TimedAction {

  public:
    TimedAction(unsigned long interval,void (*function)());
    TimedAction(unsigned long prev,unsigned long interval,void (*function)());

  void reset();
  void disable();
  void enable();
  void check();

  void setInterval( unsigned long interval );

  private:
    bool active;
    unsigned long previous;
    unsigned long interval;
    void (*execute)();

};

#endif


// TimedAction.cpp
TimedAction::TimedAction(unsigned long intervl,void (*function)()){
    active = true;
  previous = 0;
  interval = intervl;
  execute = function;
}

/*
|| <<constructor>>
*/
TimedAction::TimedAction(unsigned long prev,unsigned long intervl,void (*function)()){
    active = true;
  previous = prev;
  interval = intervl;
  execute = function;
}

void TimedAction::reset(){
    previous = millis();
}

void TimedAction::disable(){
    active = false;
}

void TimedAction::enable(){
  active = true;
}

void TimedAction::check(){
  if ( active && (millis()-previous >= interval) ) {
    previous = millis();
    execute();
  }
}

void TimedAction::setInterval( unsigned long intervl){
  interval = intervl;
}

//Declare Variable
bool is_pressed = false;
int counted, counter = 0, ledState = LOW;

//Declare blink function
void blink()
{
  if (ledState == LOW)
    ledState = HIGH;
  else
    ledState = LOW;

  digitalWrite(4, ledState);
}

//Declare print function
void serialPrint()
{
  Serial.println(counter);
}

//Construct object
TimedAction action1 = TimedAction(1000, blink);
TimedAction action2 = TimedAction(2000, serialPrint);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  action1.check();
  action2.check();

  if (digitalRead(3) == 1)
  {
    is_pressed = true;
    counted = 1;
  }
  while (is_pressed == true)
  {
    if (counted == 1)
    {
      counter++;
      counted = 0;
    }
    if (digitalRead(3) == 0)
    {
      is_pressed = false;
    }
  }
}
