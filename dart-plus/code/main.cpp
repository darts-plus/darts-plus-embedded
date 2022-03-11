#include "Game.hpp"

int main()
{
    Game game(GameStyle::Classic);
    game.addPlayer(1);
    game.addPlayer(2);
    game.addPlayer(3);

    while (!game.isEnd())
    {
        game.processGame();
        if (true)
        {
            game.playingPlayerScoredPoints(30);
        }
        if (false)
        {
            game.nextPlayer();
        }
    }
}