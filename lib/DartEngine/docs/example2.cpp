#include <DartEngine/Game.hpp>

nlohmann::json save_settings = nlohmann::json::parse(R"({
    "players":
        [
            {"id":1,"points":301},
            {"id":2,"points":301}
        ],
    "round": {"attempts":2,"scored_points":12},
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
            game.buttonDelay(); //< Must be before nextPlayer()
            game.nextPlayer();
        }
        game.processGame();     //< Need this every loop
    }
}