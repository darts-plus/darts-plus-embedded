#include <DartEngine/Game.hpp>

nlohmann::json save_settings = nlohmann::json::parse(R"({
    "currentPlayerAttemps":2,
    "players":
        [
            {"id":1,"points":301},
            {"id":2,"points":301}
        ],
    "style":0,
    "winners":
        [
            {"id":4,"points":0}
        ]
    })");
GameSettings settings(save_settings);   // transfer json to game settings
Game game(settings);    // load game settings

bool detectScorePoints = true;
bool detectNextPlayerButton = false;


void setup() 
{ }

void loop() 
{
    if (!game.isEnd())  // And Start the game
    {
        if (detectScorePoints)
        {
            game.playingPlayerScoredPoints(301);    
        }
        if (detectNextPlayerButton)
        {
            game.nextPlayer();
        }
        game.processGame();     //< Need this every loop
    }
}