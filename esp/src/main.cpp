#include "game-service/inc/GameService.h"



GameService game;

void setup() {
  Serial.begin(9600);
}

void loop() {
  game.run();
}
