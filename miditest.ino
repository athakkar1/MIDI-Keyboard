#include <MIDI.h>
#include "pitches.h"
#include "button.h"

MIDI_CREATE_DEFAULT_INSTANCE();
button button1(NOTE_C1, D2);
button button2(NOTE_E1, D3);

button *buttlist[] = {&button1, &button2};

int lastbend;

void setup() {
  // put your setup code here, to run once:
  MIDI.begin(MIDI_CHANNEL_OMNI);
  Serial.begin(115200);
  int sensor = analogRead(A0);
  int volt = sensor * ((1918*2)/1023.0);
  int bend = sensor - 1918;
  lastbend = bend;
}

void loop() {
  // put your main code here, to run repeatedly:.
  int sensor = analogRead(A0);
  int volt = sensor * ((1918*2)/1023.0);
  int bend = sensor - 1918;
  if(bend != lastbend){
      MIDI.sendPitchBend(bend, 1);
      lastbend = bend;  
  }
  for(int i = 0; i < sizeof(buttlist)/sizeof(buttlist[0]); i++){
      if(buttlist[i]->updateButton()){
          if(buttlist[i]->getState() && !buttlist[i]->getNoteon()){
              MIDI.sendNoteOn(buttlist[i]->getNote(), 127, 1);
              buttlist[i]->changeNote();
           } else if (!buttlist[i]->getState() && buttlist[i]->getNoteon()){
              MIDI.sendNoteOff(buttlist[i]->getNote(), 0, 1);
              buttlist[i]->changeNote();
           }
       }
    }
}
