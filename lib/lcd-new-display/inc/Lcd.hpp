#pragma once
#include "Ucglib.h"
#include<iostream>

const int A = 10; 
const int CS = 15;
const int RESET = 16;

class Lcd
{
public:

    typedef struct {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    } rgba_t;

    Lcd();
    void clear_display();
    void menu_display(int cursor, bool doublein = false, bool doubleout = false, int players = 2);
    void score_display(std::string nickname, int score, int attempts);
private:
    //uint8_t current_pos;
    // bool selected_pos;
    // const int points[4] = {101, 301, 501, 701};
    // uint8_t points_index;
    // uint8_t players;
    // bool dbl_in;
    // bool dbl_out;
    uint8_t menu_id;
    Ucglib_ST7735_18x128x160_HWSPI ucg;  
    void scroll_down();
    void scroll_up();
    void select();
    void change_value_up();
    void change_value_down();
    // void print_game_menu();
    // void print_main_menu();
    void go_back();
    void win_animation(std::string nickname);
    
};