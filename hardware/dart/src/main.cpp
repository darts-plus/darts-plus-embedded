#include <Arduino.h>
#include <stdint.h>
#include "config.h"
#include <stdlib.h>

#include "ArduinoJson.h"

uint8_t *ptr;
#include "dartboard.h"
Dartboard dartboard(&pins_master, &pins_slave);


#include "player.h"
#include "game.h"



Player deli(1, "deli");
void setup() {
    Serial.begin(9600);
    Serial.println("\nInitiating dartboard...");
    dartboard.Init();


    uint16_t storage[MAX_PLAYERS];
    Vector<uint16_t> playerIds(storage);
    playerIds.push_back(1);
    playerIds.push_back(5);
    playerIds.push_back(15);
    playerIds.push_back(16);
    playerIds.push_back(13);

    Throw dupa(0,0);
    StaticJsonDocument<16> doc;
    doc["multiplier"] = 255;
    doc["value"] = 16;
    //  doc["id"] = 0x5987;
    // doc["nick"] = "deli";
    // doc["points"] = 555;
    // doc["attemps"] = 0;
    // doc["lastThrow"] = Throw(2, 20)


    Serial.println(dupa.Serialize());
    dupa.Deserialize(doc);
    Serial.println(dupa.Serialize());
    
    while(1);
    Settings set(0, playerIds.size() , 301, false, false, playerIds);
    Serial.println("Creatiing settings...");
    Game game(set);
    Serial.println("Loading game...");
    
    game.Loop();
    Serial.println("After LOOP");
}

void loop() {
    
    // Throw hit(0,0);
    // hit = dartboard.ReadThrow();
    // if(hit != Throw(0,0)){
    //     Serial.println("" + hit);
    // }
    // delay(100);
    //  for(uint8_t i = 0; i < NUM_LINES_MASTER; ++i) {
    //     digitalWrite((pins_master)[i], HIGH);
    //  }
    //  digitalWrite((pins_master)[0], LOW);
    //     if((pins_slave)[1] == A7){
    //             Serial.print("TAB: ");
    //  Serial.println((pins_master)[0]);
    // Serial.print("Analog7 : ");
    //  Serial.println(analogRead(A7));
    //  Serial.print("Analog6 : ");
    //  Serial.println(analogRead(A6));
        // }
     
}

