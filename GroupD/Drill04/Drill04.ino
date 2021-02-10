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

int b1 = 12;
int Led = 13;
void setup()
{
  // put your setup code here, to run once:
  pinMode(b1, INPUT);
  pinMode(Led, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  int ledstate = LOW;
  int counter = 0;
    for(int i = 0; digitalRead(b1, HIGH); i++)
    {

      if( (millis()-previous)==2000)
      {
        Serial.print(counter);
      }

      if( (millis()-previous)==1000)
      {
        if(ledstate == LOW)
        {
          ledstate == HIGH;
          counter++;
        }
        else
          ledstate == LOW;
      }
    }
  }
}
