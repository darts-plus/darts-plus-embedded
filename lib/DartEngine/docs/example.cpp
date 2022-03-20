#include <DartEngine/Game.hpp>

Game game(GameStyle::Classic);  // Choose style

bool detectScorePoints = true;
bool detectNextPlayerButton = false;


void setup() {
    game.addPlayer(1);  // Add players
    game.addPlayer(2);
}

void loop() {
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
        game.processGame(); //< Need this every loop
    }
}
