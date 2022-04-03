#pragma once

#include <Arduino.h>
#include <FunctionalInterrupt.h>
#include <functional>

class Button
{
    public:
        enum button_state
        {
            NO_PRESSED,
            PRESSED_SHORT,
            PRESSED_MEDIUM,
            PRESSED_LONG,
            UNKNOWN
        };
        
        Button(uint8_t pin);
        // bool button_pressed(button_state state);
        button_state get_current_state();
    private:
        void IRAM_ATTR set_current_state();
        const unsigned int debounce_delay;
        const unsigned int medium_press;
        const unsigned int long_press;   
        uint8_t m_pin;
        unsigned int m_press_time;
        unsigned int m_release_time;
        button_state m_current_state;
};
