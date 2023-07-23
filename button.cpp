#include "button.h"

bool button::getState(){ return state; }

int button::getPin(){return pin;}

int button::getNote(){return note;}

bool button::getNoteon(){return noteon;}

bool button::updateButton(){
  state = digitalRead(pin);
  if(state != lastState){
      lastState = state;
      return true;
    }
  return false;
}

void button::changeNote(){noteon = !noteon;}

/*void button::change(){
   lastState = state;
   if(state && !noteon) {
       midi->sendNoteOn(note, 127, 1);
       noteon = true;
    } else if (!state && noteon){
       midi->sendNoteOff(note, 0, 1); 
       noteon = false; 
    }
}*/
