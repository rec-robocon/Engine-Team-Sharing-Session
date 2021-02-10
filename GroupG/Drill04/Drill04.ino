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

const int led1=10;
const int b1=2;
int counter=0;

void PrintingCounter()
{
  Serial.println(counter);
}

void Control_led()
{
  for (int i = 255; i>0; i--)
  {
    analogWrite(led1, i);
    delay(10);
  }
}

TimedAction Counter = TimedAction(2000, PrintingCounter);
TimedAction Let_led_shine = TimedAction(1000, Control_led);

void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(b1, INPUT);
}


void loop()
{
  Counter.check();
  Let_led_shine.check();

  int ButtonState = digitalRead(b1);
  if (ButtonState == 1)
  {
    counter++;
    while(ButtonState == 1)
    {
      ButtonState = digitalRead(b1);
    }
  }
}
//Group G
