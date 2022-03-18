#include "Button.hpp"

Button::Button(int buttonNum)
{
  switch (buttonNum)
  {
  case 0:
    pinNum = 3;
    break;
  case 1:
    pinNum = 2;
    break;
  default:
    // error
    break;
  }

  pinMode(pinNum, OUTPUT);
  press_time = 0;
  release_time = 0;
  button_active = false;

}

Button::~Button()
{
}

Press Button::button_pressed()
{
  Press output = NOT_PRESSED;
  int readState = digitalRead(pinNum);

  if (readState == high_button_state && (button_active == false))
  {
    press_time = millis();
    button_active = true;
  }
  else if ((readState != high_button_state) && (button_active == true))
  {
    release_time = millis();
    button_active = false;
  }
  if (release_time > 0 && press_time > 0)
  {

    if (millis() - press_time >= debounce_delay)
    {
      unsigned long time_diff = release_time - press_time < 0 ? 0 : release_time - press_time; 
      output = time_diff > long_press ? PRESSED_LONG :
              ((time_diff > medium_press) && (time_diff <= long_press)) ? PRESSED_MEDIUM :
              ((time_diff > 0) && (time_diff <= medium_press)) ? PRESSED_SHORT : NOT_PRESSED;
      press_time = 0;
      release_time = 0;
    }
  }
  return output;
}