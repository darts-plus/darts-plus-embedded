#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
// #include "Logo.h"
#include "Display.h"
#include "Buttons.h"


// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
// Adafruit_SSD1306 * display;

Display display;

void setup() {
  Serial.begin(9600);
  buttons_init();
  display.init_display();
}

void loop() {
  switch ( state ){
      case UNKN :
        break ;
      case DISABLED :
        break ;
      case LOGO :
        display.oled->clearDisplay();
        display.logo_display();
        display.oled->display();
        break ;
      case SCORE :
        display.clear_display();
        display.score_display(String("Jan Pawel"), score, throws);
        display.oled->display();      // Show initial text
        break ;
      case MENU :
        display.clear_display();
        display.menu_display(cursor);
        display.oled->display();      // Show initial text
        break ;
  }
}
