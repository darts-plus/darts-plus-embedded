/**
 * @file game.h
 * @author Jakub Delicat (delicat.kuba@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "Arduino.h"
#include "Vector.h"

#ifndef MAX_PLAYERS
    #define MAX_PLAYERS 10
#endif

enum GameStatus{
    GameStatus_Active, GameStatus_Pause, GameStatus_Save, GameStatus_Finished
};

struct Settings{
    private:
        uint16_t tab[1];
    public:
        const uint16_t id;
        uint8_t amountOfPlayers;
        const uint16_t startPoints;
        const bool doubleIn;
        const bool doubleOut;
        Vector<uint16_t> playersId;

        Settings(const uint16_t &id, const uint8_t &amountOfPlayers, const uint16_t &startPoints, const bool &doubleIn, const bool &doubleOut, Vector<uint16_t> &playersId);
};

class Game{
    private:
        String json;
    public:
        const uint16_t id;
        Settings settings;
        GameStatus status = GameStatus_Active;
        uint16_t throwingPlayerId;
        uint16_t round;
        Player *playerList;


        Game(const Settings &set);
        ~Game();

        String Serialize();
        void Deserialize(const StaticJsonDocument<SIZE_GAME_JSON> &doc);

        GameStatus Loop();
};

#endif