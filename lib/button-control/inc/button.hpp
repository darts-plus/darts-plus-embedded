#pragma once

#include <Arduino.h>
const unsigned long debounce_delay = 100;
const int last_button_state = HIGH;
const int current_button_state = LOW;

class Button
{
private:
    short pinNum;
    unsigned long press_time;
    unsigned long release_time;
    bool button_active;
public:
    Button(int buttonNum);
    ~Button();
    bool button_pressed(int interval = 0);
};

