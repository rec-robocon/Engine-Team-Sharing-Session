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

const int buttonpin=5;
const int ledpin=10;
unsigned long prev=0;
int ledState=LOW;
int buttonState=LOW;
int counter = 0;

void blink(){
  ledState ? ledState=false : ledState=true;
  digitalWrite(ledpin,ledState);
}

void print(int counter){
    Serial.println(counter);
}

TimedAction timedAction = TimedAction(1000,blink);
TimedAction timedAction2 = TimedAction(2000,print);

void setup()
{
  pinMode(buttonpin,INPUT);
  pinMode(ledpin,OUTPUT);
}

void loop()
{
  buttonstate=digitalRead(buttonpin);
  if(buttonstate = digitalRead(buttonpin){
    counter++;
  }
    timedAction.check();
    timedAction2.check();
  }
}
