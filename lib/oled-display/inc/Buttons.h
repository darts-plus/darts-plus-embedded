#include <Arduino.h>

enum States { UNKN , // nie wiadomo co sie dzieje
              DISABLED , // wylaczona dioda
              LOGO , // zapal logo
              SCORE , // zapal licznik
              MENU , // zapal licznik
};

enum Cursor { DOUBLEIN , // zapal logo
              DOUBLEOUT , // zapal licznik
              PLAYERS , // zapal licznik
              START , // zapal licznik
};

// Global variables changed by buttons 
States state = MENU;
int score = 301;
int throws = 3;
int players = 2;
bool doublein = false;
bool doubleout = false;
Cursor cursor = DOUBLEIN;


constexpr uint8_t LEFT_BUTTON = 14;
constexpr uint8_t MIDLE_BUTTON = 13;
constexpr uint8_t RIGHT_BUTTON = 12;

void IRAM_ATTR left_button_service(){
  switch ( state ){
    case UNKN :
      break ;
    case DISABLED :
      break ;
    case LOGO :
      break ;
    case SCORE :
      if (score > 0){
        score--;
        throws--;
      } 
      break ;
    case MENU :
      switch (cursor){
        case DOUBLEIN:
          cursor = START;
          break;
        case DOUBLEOUT:
          cursor = DOUBLEIN;
          break;
        case PLAYERS:
          cursor = DOUBLEOUT;
          break;
        case START:
          cursor = PLAYERS;
          break;
        default:
          break;
        }
      break;
  }
}

void IRAM_ATTR midle_button_service(){
  switch ( state ){
      case UNKN :
        state = LOGO;
        break ;
      case DISABLED :
        state = LOGO;
        break ;
      case LOGO :
        state = MENU;
        break ;
      case SCORE :
        state = LOGO;
        break ;
      case MENU :
      // obsługa wyboru opcji w zależności od cursor
        switch (cursor){
            case DOUBLEIN:
              doublein = not doublein;
              break;
            case DOUBLEOUT:
              doubleout = not doubleout;
              break;
            case PLAYERS:
              players = (players + 1) % 10;
              if (players < 2) players = 2;
              break;
            case START:
              state = SCORE;
              break;
            default:
              break;
            }
        break ;
  }
}

void IRAM_ATTR right_button_service(){
  switch ( state ){
      case UNKN :
        break ;
      case DISABLED :
        break ;
      case LOGO :
        break ;
      case SCORE :
        if (score < 1000){
          score++;
          throws--;
        } 
        break ;
      case MENU :
        switch (cursor){
          case DOUBLEIN:
            cursor = DOUBLEOUT;
            break;
          case DOUBLEOUT:
            cursor = PLAYERS;
            break;
          case PLAYERS:
            cursor = START;
            break;
          case START:
            cursor = DOUBLEIN;
            break;
          default:
            break;
          }
        break ;
  }
}

void buttons_init(){
  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(MIDLE_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
  attachInterrupt(LEFT_BUTTON, left_button_service, FALLING);
  attachInterrupt(MIDLE_BUTTON, midle_button_service, FALLING);
  attachInterrupt(RIGHT_BUTTON, right_button_service, FALLING);
}
