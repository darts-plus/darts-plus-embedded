#include <Arduino.h>
#include <stdint.h>
#include "config.h"
#include <stdlib.h>

#include "ArduinoJson.h"

#include "dartboard.h"
Dartboard dartboard(&pins_master, &pins_slave) PROGMEM;


#include "player.h"
#include "game.h"




void setup() {
    Serial.begin(115200);
    Serial.println("\nInitiating dartboard...");
    delay(100);
    dartboard.Init();


    uint16_t storage[MAX_PLAYERS];
    Vector<uint16_t> playerIds(storage);
    playerIds.push_back(1);
    playerIds.push_back(5);
    playerIds.push_back(15);
    playerIds.push_back(16);
    playerIds.push_back(13);

    Settings set(0, 5 , 301, false, false, playerIds);

    // Serial.println(set.amoutOfPlayers);
    Serial.println("Creatiing settings...");
    delay(100);
    Game game(set);
    delay(100);
    Serial.println("Loading game...");
    
    game.Loop();
    Serial.println("After LOOP");

    game.playerList.clear();
}

void loop() {  
}