#pragma once

#include <Arduino.h>
const unsigned long debounce_delay = 75;
const int high_button_state = HIGH;
const unsigned long medium_press = 1000;
const unsigned long long_press = 5000;

enum Press {
    NOT_PRESSED = 0,
    PRESSED_SHORT = 1,
    PRESSED_MEDIUM = 2,
    PRESSED_LONG = 3
};

class Button
{
private:
    short pinNum;
    unsigned long press_time;
    unsigned long release_time;
    bool button_active;
    unsigned long time_diff;
public:
    Button(int buttonNum);
    ~Button();
    Press button_pressed();
};
