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


bool Button::button_pressed(int interval)
{
  bool output = 0;
  int readState = digitalRead(pinNum);

  if (readState == last_button_state && (button_active == false))
  {
    press_time = millis();
    button_active = true;
  }
  else if ((readState != last_button_state) && (button_active == true))
  {
    release_time = millis();
    button_active = false;
  }
  if (release_time > 0 && press_time > 0)
  {

    if (millis() - press_time >= debounce_delay)
    {
      unsigned long time_diff = release_time - press_time < 0 ? 0 : release_time - press_time; 
      output = time_diff > interval ? 1 : 0;
      press_time = 0;
      release_time = 0;
    }
  }
  return output;
}

