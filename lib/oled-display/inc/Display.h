#include <Arduino.h>
#include <memory>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Logo.h"


constexpr uint8_t SCREEN_WIDTH = 128; // OLED display width, in pixels
constexpr uint8_t SCREEN_HEIGHT = 64; // OLED display height, in pixels


class Display
{
private:   
    std::shared_ptr<Adafruit_SSD1306> oled;
public:
    Display(/* args */);
    void init_display();
    void logo_display();
    void text_display(String txt); //TODO: funkcja pomocnicza do usunięcia
    void score_display(String name, int score, int throws);
    void menu_display(int cursor, bool doublein = false, bool doubleout = false, int players = 2);
    void show_display();
    void clear_display();
};

Display::Display(/* args */){
    this->oled = std::make_shared<Adafruit_SSD1306>(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
}

void Display::init_display(){
    if(!this->oled->begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
  }
}

void Display::show_display(){
    this->oled->display();
}

void Display::clear_display(){
    this->oled->clearDisplay();
}

void Display::logo_display(){
    this->oled->drawBitmap(
    (this->oled->width()  - LOGO_WIDTH ) / 2,
    (this->oled->height() - LOGO_HEIGHT) / 2,
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
}

void Display::text_display(String txt){
    this->oled->setTextSize(2); // Draw 5X-scale text
    this->oled->setTextColor(WHITE);
    this->oled->setCursor(0, 0);
    this->oled->println(txt);
}

void Display::score_display(String name, int score, int throws){
    int x_pos = (this->oled->width() - name.length() * 12 ) / 2;
    int y_pos = 0;
    this->oled->setTextSize(2); // Draw 5X-scale text
    this->oled->setTextColor(WHITE);
    this->oled->setCursor(x_pos, y_pos);
    this->oled->println(name);

    this->oled->drawLine(0, 16, this->oled->width(), 16, WHITE);

    x_pos = (this->oled->width() - String(score).length() * 24 ) / 2;
    y_pos = 20;
    this->oled->setTextSize(4); // Draw 5X-scale text
    this->oled->setTextColor(WHITE);
    this->oled->setCursor(x_pos, y_pos);
    this->oled->println(String(score));

    for (int i = 0; i < throws; ++i){
        this->oled->drawBitmap((this->oled->width() - 16),(20 + i * 16),dart_bmp, 16, 16, 1);
    }
}

void Display::menu_display(int cursor, bool doublein, bool doubleout, int players){
    
    this->oled->drawLine(0, (cursor+1)*16-1, this->oled->width(), (cursor+1)*16-1, WHITE);
    this->oled->drawLine(0, (cursor)*16, this->oled->width(), (cursor)*16, WHITE);
   
    this->oled->setTextSize(2); // Draw 5X-scale text
    this->oled->setTextColor(WHITE);

    this->oled->setCursor(0, 0);
    this->oled->println("dbl in");
    this->oled->setCursor(this->oled->width() - 16, 0);
    this->oled->println(String(int(doublein)));

    this->oled->setCursor(0, 16);
    this->oled->println("dbl out");
    this->oled->setCursor(this->oled->width() - 16, 16);
    this->oled->println(String(int(doubleout)));

    this->oled->setCursor(0, 32);
    this->oled->println("players");
    this->oled->setCursor(this->oled->width() - 16, 32);
    this->oled->println(String(players));

    this->oled->setCursor(0, 48);
    this->oled->println("start");
}

// void display_init(){
//     // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
//     if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
//         Serial.println(F("SSD1306 allocation failed"));
//         for(;;); // Don't proceed, loop forever
//   }
// }

// void testdrawline() {
//   int16_t i;

//   display.clearDisplay(); // Clear display buffer

//   for(i=0; i<display.width(); i+=4) {
//     display.drawLine(0, 0, i, display.height()-1, WHITE);
//     display.display(); // Update screen with each newly-drawn line
//     delay(1);
//   }
//   for(i=0; i<display.height(); i+=4) {
//     display.drawLine(0, 0, display.width()-1, i, WHITE);
//     display.display();
//     delay(1);
//   }
//   delay(250);

//   display.clearDisplay();

//   for(i=0; i<display.width(); i+=4) {
//     display.drawLine(0, display.height()-1, i, 0, WHITE);
//     display.display();
//     delay(1);
//   }
//   for(i=display.height()-1; i>=0; i-=4) {
//     display.drawLine(0, display.height()-1, display.width()-1, i, WHITE);
//     display.display();
//     delay(1);
//   }
//   delay(250);

//   display.clearDisplay();

//   for(i=display.width()-1; i>=0; i-=4) {
//     display.drawLine(display.width()-1, display.height()-1, i, 0, WHITE);
//     display.display();
//     delay(1);
//   }
//   for(i=display.height()-1; i>=0; i-=4) {
//     display.drawLine(display.width()-1, display.height()-1, 0, i, WHITE);
//     display.display();
//     delay(1);
//   }
//   delay(250);

//   display.clearDisplay();

//   for(i=0; i<display.height(); i+=4) {
//     display.drawLine(display.width()-1, 0, 0, i, WHITE);
//     display.display();
//     delay(1);
//   }
//   for(i=0; i<display.width(); i+=4) {
//     display.drawLine(display.width()-1, 0, i, display.height()-1, WHITE);
//     display.display();
//     delay(1);
//   }

//   delay(2000); // Pause for 2 seconds
// }

// void testdrawrect(void) {
//   display.clearDisplay();

//   for(int16_t i=0; i<display.height()/2; i+=2) {
//     display.drawRect(i, i, display.width()-2*i, display.height()-2*i, WHITE);
//     display.display(); // Update screen with each newly-drawn rectangle
//     delay(1);
//   }

//   delay(2000);
// }

// void testfillrect(void) {
//   display.clearDisplay();

//   for(int16_t i=0; i<display.height()/2; i+=3) {
//     // The INVERSE color is used so rectangles alternate white/black
//     display.fillRect(i, i, display.width()-i*2, display.height()-i*2, INVERSE);
//     display.display(); // Update screen with each newly-drawn rectangle
//     delay(1);
//   }

//   delay(2000);
// }

// void testdrawcircle(void) {
//   display.clearDisplay();

//   for(int16_t i=0; i<max(display.width(),display.height())/2; i+=2) {
//     display.drawCircle(display.width()/2, display.height()/2, i, WHITE);
//     display.display();
//     delay(1);
//   }

//   delay(2000);
// }

// void testfillcircle(void) {
//   display.clearDisplay();

//   for(int16_t i=max(display.width(),display.height())/2; i>0; i-=3) {
//     // The INVERSE color is used so circles alternate white/black
//     display.fillCircle(display.width() / 2, display.height() / 2, i, INVERSE);
//     display.display(); // Update screen with each newly-drawn circle
//     delay(1);
//   }

//   delay(2000);
// }

// void testdrawroundrect(void) {
//   display.clearDisplay();

//   for(int16_t i=0; i<display.height()/2-2; i+=2) {
//     display.drawRoundRect(i, i, display.width()-2*i, display.height()-2*i,
//       display.height()/4, WHITE);
//     display.display();
//     delay(1);
//   }

//   delay(2000);
// }

// void testfillroundrect(void) {
//   display.clearDisplay();

//   for(int16_t i=0; i<display.height()/2-2; i+=2) {
//     // The INVERSE color is used so round-rects alternate white/black
//     display.fillRoundRect(i, i, display.width()-2*i, display.height()-2*i,
//       display.height()/4, INVERSE);
//     display.display();
//     delay(1);
//   }

//   delay(2000);
// }

// void testdrawtriangle(void) {
//   display.clearDisplay();

//   for(int16_t i=0; i<max(display.width(),display.height())/2; i+=5) {
//     display.drawTriangle(
//       display.width()/2  , display.height()/2-i,
//       display.width()/2-i, display.height()/2+i,
//       display.width()/2+i, display.height()/2+i, WHITE);
//     display.display();
//     delay(1);
//   }

//   delay(2000);
// }

// void testfilltriangle(void) {
//   display.clearDisplay();

//   for(int16_t i=max(display.width(),display.height())/2; i>0; i-=5) {
//     // The INVERSE color is used so triangles alternate white/black
//     display.fillTriangle(
//       display.width()/2  , display.height()/2-i,
//       display.width()/2-i, display.height()/2+i,
//       display.width()/2+i, display.height()/2+i, INVERSE);
//     display.display();
//     delay(1);
//   }

//   delay(2000);
// }

// void testdrawchar(void) {
//   display.clearDisplay();

//   display.setTextSize(1);      // Normal 1:1 pixel scale
//   display.setTextColor(WHITE); // Draw white text
//   display.setCursor(0, 0);     // Start at top-left corner
//   display.cp437(true);         // Use full 256 char 'Code Page 437' font

//   // Not all the characters will fit on the display. This is normal.
//   // Library will draw what it can and the rest will be clipped.
//   for(int16_t i=0; i<256; i++) {
//     if(i == '\n') display.write(' ');
//     else          display.write(i);
//   }

//   display.display();
//   delay(2000);
// }

// void testdrawstyles(void) {
//   display.clearDisplay();

//   display.setTextSize(1);             // Normal 1:1 pixel scale
//   display.setTextColor(WHITE);        // Draw white text
//   display.setCursor(0,0);             // Start at top-left corner
//   display.println(F("Hello, world!"));

//   display.setTextColor(BLACK, WHITE); // Draw 'inverse' text
//   display.println(3.141592);

//   display.setTextSize(2);             // Draw 2X-scale text
//   display.setTextColor(WHITE);
//   display.print(F("0x")); display.println(0xDEADBEEF, HEX);

//   display.display();
//   delay(2000);
// }

// void testscrolltext(void) {
//   display.clearDisplay();

//   display.setTextSize(2); // Draw 2X-scale text
//   display.setTextColor(WHITE);
//   display.setCursor(10, 0);
//   display.println(F("scroll"));
//   display.display();      // Show initial text
//   delay(100);

//   // Scroll in various directions, pausing in-between:
//   display.startscrollright(0x00, 0x0F);
//   delay(2000);
//   display.stopscroll();
//   delay(1000);
//   display.startscrollleft(0x00, 0x0F);
//   delay(2000);
//   display.stopscroll();
//   delay(1000);
//   display.startscrolldiagright(0x00, 0x07);
//   delay(2000);
//   display.startscrolldiagleft(0x00, 0x07);
//   delay(2000);
//   display.stopscroll();
//   delay(1000);
// }

// void testdrawbitmap(void) {
//   display.clearDisplay();

//   display.drawBitmap(
//     (display.width()  - LOGO_WIDTH ) / 2,
//     (display.height() - LOGO_HEIGHT) / 2,
//     logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
//   display.display();
//   delay(1000);
// }

// // void testanimate(const uint8_t *bitmap, uint8_t w, uint8_t h) {
//   int8_t f, icons[NUMFLAKES][3];
//   // Initialize 'snowflake' positions
//   for(f=0; f< NUMFLAKES; f++) {
//     icons[f][XPOS]   = random(1 - LOGO_WIDTH, display.width());
//     icons[f][YPOS]   = -LOGO_HEIGHT;
//     icons[f][DELTAY] = random(1, 6);
//     Serial.print(F("x: "));
//     Serial.print(icons[f][XPOS], DEC);
//     Serial.print(F(" y: "));
//     Serial.print(icons[f][YPOS], DEC);
//     Serial.print(F(" dy: "));
//     Serial.println(icons[f][DELTAY], DEC);
//   }
//   for(;;) { // Loop forever...
//     display.clearDisplay(); // Clear the display buffer
//     // Draw each snowflake:
//     for(f=0; f< NUMFLAKES; f++) {
//       display.drawBitmap(icons[f][XPOS], icons[f][YPOS], bitmap, w, h, WHITE);
//     }
//     display.display(); // Show the display buffer on the screen
//     delay(200);        // Pause for 1/10 second
//     // Then update coordinates of each flake...
//     for(f=0; f< NUMFLAKES; f++) {
//       icons[f][YPOS] += icons[f][DELTAY];
//       // If snowflake is off the bottom of the screen...
//       if (icons[f][YPOS] >= display.height()) {
//         // Reinitialize to a random position, just off the top
//         icons[f][XPOS]   = random(1 - LOGO_WIDTH, display.width());
//         icons[f][YPOS]   = -LOGO_HEIGHT;
//         icons[f][DELTAY] = random(1, 6);
//       }
//     }
//   }
// }