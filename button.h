#include <MIDI.h>
#include <iostream>
#include <Arduino.h>

using namespace std;

class button{
    private:
    int note;
    bool state;
    bool lastState;
    bool noteon;
    uint8_t pin;

    public:
    button(int note, uint8_t pin) : note(note), pin(pin){
        state = false;
        lastState = false;
        noteon = false;
        pinMode(pin, INPUT);
     }
    bool getState();
    int getNote();
    int getPin();
    bool getNoteon();
    bool updateButton();
    void changeNote();
    //void change();
 };
