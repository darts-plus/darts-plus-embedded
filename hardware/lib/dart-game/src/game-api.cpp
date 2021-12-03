#include "game-api.h"


GameStatus GameApi::Tick(){
        for(int i = 0; i < this->settings.numberOfPlayers; ++i){
            this->playerList[i].attemps = 3;
            Serial.print("Throws: " );
            Serial.println(this->playerList[i].nick);
            this->throwingPlayerId = this->playerList[i].id;
            
         

            while(this->playerList[i].attemps != 0){
                //TODO: when button arrived
                while(this->status == GameStatus_Pause);

                Throw hit(0,0);
                while(hit == Throw(0,0)){
                    hit = dartboard.ReadThrow();
                }
                this->value = hit.value;
                this->multiplier = hit.multiplier;

                

                
                if(hit > this->playerList[i].points){
                    this->playerList[i].attemps = 0;
                }
                else if(hit == this->playerList[i].points){
                    Serial.println("Finished");
                    this->status = GameStatus_Finished;
                    this->playerList[i].attemps = 0;
                }
                else{
                    this->playerList[i].points = this->playerList[i].points - hit;
                    Serial.println("OK");
                    --this->playerList[i].attemps;
                }
                serializeJson(this->Document(), mySerial);
                serializeJson(this->Document(), Serial);

                delay(200);
            }
            
        }
    ++this->round;
    return this->status;
}