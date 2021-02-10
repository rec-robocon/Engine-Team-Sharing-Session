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

int led=13;
int btn=12;
int counter=0;

void PrintingCounter()
{
  Serial.println(counter);

}

void Control_led()
{
  digitalWrite(led,HIGH);
}

void check_button()
{
  if (digitalRead(btn) == HIGH)
  counter++;

}

TimedAction Counter=TimedAction(2000,PrintingCounter);
TimedAction Ledshine=TimedAction(1000,Control_led);
TimedAction Buttton=TimedAction(1000,check_button);

void setup()
{
  pinMode(led,OUTPUT);
  pinMode(btn,INPUT);
  Serial.begin(9600);// put your setup code here, to run once:

}

void loop()
{
  Button.check();
  Counter.check();
  Ledshine.check();
}
