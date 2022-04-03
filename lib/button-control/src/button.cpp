#include "button.hpp"

Button::Button(uint8_t pin)
: debounce_delay(75)
, medium_press(1000)
, long_press(5000)
, m_pin(pin)
, m_press_time(0)
, m_release_time(0)
, m_current_state(NO_PRESSED)

{   
    using namespace std::placeholders;
    pinMode(m_pin, INPUT_PULLUP);
    attachInterrupt(m_pin, [this](){this->set_current_state();}, CHANGE);
}



// bool Button::button_pressed(Button::button_state state)
// {
//     Button::button_state current_state = m_current_state;
//     m_current_state = NO_PRESSED;
//     return (current_state == state); // ? true : false
// }

Button::button_state Button::get_current_state(){
    Button::button_state current_state = m_current_state;
    m_current_state = NO_PRESSED;
    return current_state;
}

void IRAM_ATTR Button::set_current_state()
{
    if (m_press_time != 0)
    {
        if ((millis() - m_press_time) > debounce_delay)
        {
            m_release_time = millis();
        }
    }else{
        if ((millis() - m_release_time) > debounce_delay)
        {
            m_press_time = millis();
        }
    }

    if (m_press_time != 0 && m_release_time != 0)
    {
        if (m_release_time > 0 && m_press_time > 0)
        {
            if (millis() - m_press_time >= debounce_delay)
            {
                unsigned long time_diff = m_release_time - m_press_time; 
                m_current_state = time_diff > long_press   ? PRESSED_LONG    :
                                (time_diff  > medium_press)  ? PRESSED_MEDIUM  :
                                (time_diff  > 0)             ? PRESSED_SHORT   : NO_PRESSED;
            }
            m_release_time = 0;
            m_press_time = 0;
        }
    }    
}