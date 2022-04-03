# Button class
Button handling is solved by using interrupts on a slope change.
First slope change happens when someone pushes the button, second slope change- when someone releases this button.
Function set_current_state on first slope change stores time of pressing the button (m_press_time), on second slope change - it sets m_release_time and if both of those values are larger than 0, it measures time_diff between m_release_time and m_press_time. After it's done, function sets state of button according to time diff. At the end function resets m_press_time and m_release time. This function also checks, if elapsed time between press and release of the button was greater than debounce time (now 75 miliseconds)
Function get_current_state returns button state and set m_current_state back to NO_PRESSED to avoid random outputs.
Button constructor requires information on which pin initialized button is mounted. It also attaches interrupt.

POSSIBLE STATES:
- NO_PRESSED
- PRESSED_SHORT
- PRESSED_MEDIUM
- PRESSED_LONG
- UNKNOWN

USAGE EXAMPLE:

  switch (first_button.get_current_state())
  {
  case Button::NO_PRESSED:
    /* code */
    break;
  case Button::PRESSED_SHORT:
    Serial.println("first short");
    break;
  case Button::PRESSED_MEDIUM:
    Serial.println("first medium");
    break;
  case Button::PRESSED_LONG:
    Serial.println("first long");
    break;
  default:
    break;
  }