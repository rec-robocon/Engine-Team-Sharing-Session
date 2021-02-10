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

///////////////////////////////////////////////////////////////////////
//variables
const int button=2,led=3;
int counter=0;
unsigned long currentmillis=millis(), previousmillis_1=0,previousmillis_2=0;


void ledblink();
void Countervalue(int);

void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
}

void loop()
{
  buttonpress=digitalRead(button);
  if(buttonpress==HIGH)
  {
    counter++;
  }
  ledblink();
  Countervalue(counter);
}

void ledblink() //task 1 blinking led
{
  if(currentmillis-previousmillis_1==1000)
  {
    previousmillis_1=currentmillis;
    if(ledstate==LOW)
      ledstate==HIGH;
    else
      ledstate==LOW;
  }
  digitalWrite(led, ledstate);
}

 //task 2 showing counter
void Countervalue(int c)
{
  if(currentmillis-previousmillis_2==2000)
  {
      previousmilli_2=currentmillis;
      Serial.print(c);
  }
}
