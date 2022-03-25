#include "oled-display/inc/Buttons.h"
#include "oled-display/inc/Display.h"



Display display;


void setup() {
  Serial.begin(9600);
  buttons_init();
  display.init_display();
}

void loop() {
    int score, multi;
    bool hit = false;
    String mess;
    mess = Serial.readString();
    if (mess != String(""))
    {
        hit = true;
        sscanf(mess.c_str(), "%d %d", &score, &multi);
    }
    GameSettings gameOutput;
  switch ( state ){
      case UNKN :
        break ;
      case DISABLED :
        break ;
      case LOGO :
        display.clear_display();
        display.logo_display();
        display.show_display();   
        break ;
      case SCORE :
        if (!game.isEnd())  // And Start the game
        {
        if (hit)
        {
            game.playingPlayerScoredPoints(score * multi);    
        }
        game.processGame(); //< Need this every loop
        }
        gameOutput = game.outputGame();

        display.clear_display();
        display.score_display(String("Player ") + String(gameOutput.players.front().id), gameOutput.players.front().points, gameOutput.currentPlayerAttemps);
        display.show_display();       // Show initial text
        break ;
      case MENU :
        display.clear_display();
        display.menu_display(cursor, doublein, doubleout, players);
        display.show_display();      // Show initial text
        break ;
  }
}