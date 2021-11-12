#include "player.h"

Player::Player(Dartboard * dartboard, const uint32_t &id, const String &name, const String &nick, const uint16_t &points, const uint8_t &attemps):
dartboard{dartboard}, id{id}, name{name}, nick{nick}, points{points}, attemps{attemps}{

}

const ThrowStatus Player::Throwing(){
    Throw hit(0,0); 
    while(hit == Throw(0,0)){
        hit = dartboard->ReadThrow();
    }
    if (hit > this->points)
        return ThrowStatus_ERROR;
    
    this->points = this->points - hit;
    this->lastThrow = hit;
    if(this->points == 0)
        return ThrowStatus_END;
    return ThrowStatus_OK;
}

String operator+(const String &prefix, const Player &player){
    String x = prefix;
    if(prefix.substring(0,2) != "\t") x = "";
    return  prefix + "\n{\n" +
            x + "\t\"id\": " + String(player.id) + "\",\n"+
            x + "\t\"nick\": \"" + player.nick + "\",\n" +
            x + "\t\"points\": " + String(player.points) + ",\n" +
            x + "\t\"attemps\": " + String(player.attemps) +  ",\n" + 
            x + "\t\"lastThrow\": " + ("\t" + player.lastThrow) + 
            x + "\n}";
}