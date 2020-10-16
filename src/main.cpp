#include <Arduino.h>

int numLoops = 1;
int buttons[numLoops] = {8};
int relayIn[numLoops] = {2};
int relayOut[numLoops] = {5};
int state[numLoops];
int pressed[numLoops];

void setup() {
  // setup I/O-ports
  for(i=0; i<numLoops; i++){
    pinMode(buttons[i], INPUT);
    pinMode(relayIn[i], OUTPUT);
    pinMode(relayOut[i], OUTPUT);

    digitalWrite(relayIn[i], LOW);
    digitalWrite(relayOut[i], LOW);

    state[i] = LOW;
    pressed[i] = false;
  }
}

void loop() {
  for(i=0; i<numLoops; i++){
    if(digitalRead(buttons[i])){
      if(!pressed[i]){}
        state[i] = !state[i];
        digitalWrite(relayIn[i], state[i]);
        digitalWrite(relayOut[i], state[i]);
        pressed[i]=true;
      }
    } else {
      pressed[i] = false;
    } 
  }
}