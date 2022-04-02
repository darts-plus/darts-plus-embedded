#include <Arduino.h>

namespace ns_button
{
    const unsigned long debounce_delay = 75;
    const unsigned long medium_press = 1000;
    const unsigned long long_press = 5000;
    
    enum Button_state {
        NOT_PRESSED,
        PRESSED_SHORT,
        PRESSED_MEDIUM,
        PRESSED_LONG,
        UNKNOWN
    };

    static const uint8_t pin_number[] = {12, 13, 14};
    static unsigned long press_time[] = {0, 0, 0};
    static unsigned long release_time[] = {0, 0, 0};

    void IRAM_ATTR  get_time0(){
        if (press_time[0] != 0)
        {
            if ((millis() - press_time[0]) > debounce_delay)
            {
                release_time[0] = millis();
            }
        }else{
            if ((millis() - release_time[0]) > debounce_delay)
            {
                press_time[0] = millis();
            }
        }
        


    }
    void IRAM_ATTR get_time1(){
        if (press_time[1] != 0)
        {
            if ((millis() - press_time[1]) > debounce_delay)
            {
                release_time[1] = millis();
            }
        }else{
            if ((millis() - release_time[1]) > debounce_delay)
            {
                press_time[1] = millis();
            }
        }
        

    }
    void IRAM_ATTR  get_time2(){
        if (press_time[2] != 0)
        {
            if ((millis()- press_time[2]) > debounce_delay)
            {
                release_time[2] = millis();
            }
        }else{
            if ((millis() - release_time[2]) > debounce_delay)
            {
                press_time[2] = millis();
            }
        }

    }


    void init(){
        for (size_t i = 0; i < 3; i++)
        {
            pinMode(pin_number[i], INPUT_PULLUP);      
        }
        attachInterrupt(12, get_time0, CHANGE);
        attachInterrupt(13, get_time1, CHANGE);
        attachInterrupt(14, get_time2, CHANGE);

    }
    bool button_pressed(uint8_t button_id, Button_state state){
        Button_state current_state = NOT_PRESSED;
        if (release_time[button_id] > 0 && press_time[button_id] > 0)
        {
            if (millis() - press_time[button_id] >= debounce_delay)
            {
            unsigned long time_diff = release_time[button_id] - press_time[button_id]; 
            current_state = time_diff   > long_press     ? PRESSED_LONG    :
                            (time_diff  > medium_press)  ? PRESSED_MEDIUM  :
                            (time_diff  > 0)             ? PRESSED_SHORT   : NOT_PRESSED;
                    
            }
            release_time[button_id] = 0;
            press_time[button_id] = 0;
        }

        return current_state == state ? 1 : 0;
    }
}