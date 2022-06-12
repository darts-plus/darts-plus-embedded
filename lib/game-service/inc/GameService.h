#include "DartEngine/Game.hpp"

#include <FunctionalInterrupt.h>
#include <Arduino.h>
#include "lcd-new-display/inc/Lcd.hpp"
#include <memory>


constexpr uint8_t LEFT_BUTTON = 4;
constexpr uint8_t MIDLE_BUTTON = 12;
constexpr uint8_t RIGHT_BUTTON = 5;

enum States { UNKN , // nie wiadomo co sie dzieje
              DISABLED , // wylaczona dioda
              LOGO , // zapal logo
              SCORE , // zapal licznik
              MENU , // zapal licznik
};

enum Cursor { POINTS,
              PLAYERS,
              DOUBLEIN , // zapal logo
              DOUBLEOUT , // zapal licznik
              START , // zapal licznik
};

class GameService
{
private:
  Lcd display;
  // Display display;   
  States state = MENU;
  Cursor cursor = DOUBLEIN;
  std::unique_ptr<Game> game;
  bool doublein = false;
  bool doubleout = false;
  int players = 2;

  void IRAM_ATTR left_button_service();
  void IRAM_ATTR midle_button_service();
  void IRAM_ATTR right_button_service();
  void buttons_init();
  void create_game();
public:
  GameService();
  void run();
};

GameService::GameService(){
  this->state = MENU;
  this->cursor = DOUBLEIN;
  this->doublein = false;
  this->doubleout = false;
  this->players = 2;
  this->buttons_init();

}

void IRAM_ATTR GameService::left_button_service(){
  switch ( this->state ){
    case UNKN :
      break ;
    case DISABLED :
      break ;
    case LOGO :
      break ;
    case SCORE :    
      this->game->buttonDelay();  
      this->game->nextPlayer();
      break ;
    case MENU :
      switch (this->cursor){
        case DOUBLEIN:
          this->cursor = PLAYERS;
          break;
        case DOUBLEOUT:
          this->cursor = DOUBLEIN;
          break;
        case PLAYERS:
          this->cursor = POINTS;
          break;
        case START:
          this->cursor = DOUBLEOUT;
          break;
        case POINTS:
          this->cursor = START;
          break;
        default:
          break;
        }
      break;
  }
}

void IRAM_ATTR GameService::midle_button_service(){
  switch ( this->state ){
      case UNKN :
        break ;
      case DISABLED :
        break ;
      case LOGO :
        break ;
      case SCORE :
        this->state = MENU;
        break ;
      case MENU :
      // obsługa wyboru opcji w zależności od cursor
        switch (this->cursor){
            case DOUBLEIN:
              this->doublein = not this->doublein;
              break;
            case DOUBLEOUT:
              this->doubleout = not this->doubleout;
              break;
            case PLAYERS:
              this->players = (this->players + 1) % 10;
              if (this->players < 2) this->players = 2;
              break;
            case START:
              this->create_game();
              this->state = SCORE;
              break;
            default:
              break;
            }
        break ;
  }
}

void IRAM_ATTR GameService::right_button_service(){
  switch ( this->state ){
      case UNKN :
        break ;
      case DISABLED :
        break ;
      case LOGO :
        break ;
      case SCORE:
        this->game->buttonDelay();
        this->game->nextPlayer();
        break ;
      case MENU :
        switch (this->cursor){
          case DOUBLEIN:
            this->cursor = DOUBLEOUT;
            break;
          case DOUBLEOUT:
            this->cursor = START;
            break;
          case PLAYERS:
            this->cursor = DOUBLEIN;
            break;
          case START:
            this->cursor = POINTS;
            break;
          case POINTS:
            this->cursor = PLAYERS;
            break;
          default:
            break;
          }
        break ;
  }
}

void GameService::buttons_init(){
  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(MIDLE_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
  attachInterrupt(LEFT_BUTTON, [this](){this->left_button_service();}, FALLING);
  attachInterrupt(MIDLE_BUTTON, [this](){this->midle_button_service();}, FALLING);
  attachInterrupt(RIGHT_BUTTON, [this](){this->right_button_service();}, FALLING);
}

void GameService::run(){
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
  switch ( this->state ){
      case UNKN :
        break ;
      case DISABLED :
        break ;
      case LOGO :
        this->display.clear_display();
        // this->display.logo_display();
        // this->display.show_display();   
        break ;
      case SCORE :
        if (!this->game->isEnd())  // And Start the game
        {
        if (hit)
        {
            this->game->playingPlayerScoredPoints(score * multi);    
        }
        this->game->processGame(); //< Need this every loop
        }
        gameOutput = this->game->outputGame();

        this->display.clear_display();
        this->display.score_display("Player x", 301, gameOutput.round.attempts);
        // this->display.show_display();       // Show initial text
        break ;
      case MENU :
        this->display.clear_display();
        this->display.menu_display(this->cursor, this->doublein, this->doubleout, this->players);
        // this->display.show_display();      // Show initial text
        break ;
  }
}

void GameService::create_game(){
  this->game = std::make_unique<Game>(GameStyle::Classic);
  for (int i = 1; i <= this->players; ++i){
    this->game->addPlayer(i);
  }
}



// Global variables changed by buttons 

// int score = 301;
// int throws = 3;
// int players = 2;
// bool doublein = false;
// bool doubleout = false;

// Game game(GameStyle::Classic);


