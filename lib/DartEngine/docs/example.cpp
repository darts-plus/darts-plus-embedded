#include <DartEngine/Game.hpp>

Game game(GameStyle::Classic);  // Choose style

bool detectScorePoints = true;
bool detectNextPlayerButton = true;


void setup() {
    game.addPlayer(1);  // Add players
    game.addPlayer(2);
    game.addPlayer(3);
    game.addPlayer(4);
    game.addPlayer(5);
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
            game.buttonDelay();
        }
        game.processGame(); //< Need this every loop
    }
}
