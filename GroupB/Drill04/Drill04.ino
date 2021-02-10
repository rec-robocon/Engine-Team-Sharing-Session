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

int counter = 0;
void blink();
void read();

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
}

TimedAction timedAction = TimedAction(1000,blink);
TimedAction timedAction2 = TimedAction(2000, read);

void loop()
{
  if (digitalRead(12) == 1)
  {
    timedAction.check();
    counter++;
  }
  timedAction2.check();
}

void blink(){
  ledState ? ledState=false : ledState=true;
  digitalWrite(ledPin,ledState);
}

void read(){
  Serial.println(counter);
}
