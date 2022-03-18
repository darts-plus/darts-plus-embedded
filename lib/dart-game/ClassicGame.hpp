#pragma once

#include "ModeGame.hpp"

class ClassicGame : public ModeGame
{
    public:
        ClassicGame();
        virtual Player createPlayer(unsigned int id) const;
        virtual bool isNextPlayer() const;
        virtual void processPlayerScore(Player& player, unsigned int score);
        virtual bool isPlayerWin(const Player& player) const;
        virtual void nextRound();
};

ClassicGame::ClassicGame()
{ 
    ModeGame::setAttemps(3);
}

Player ClassicGame::createPlayer(unsigned int id) const
{
    return {id, 301};
}

bool ClassicGame::isNextPlayer() const
{
    return ModeGame::getAttemps() == 0;
}

void ClassicGame::processPlayerScore(Player& player, unsigned int score)
{
    if (player.points >= score)
    {
        player.points -= score;
        ModeGame::setAttemps(ModeGame::getAttemps() - 1);
    }
    else
    {
        ModeGame::setAttemps(0);
    }
}

bool ClassicGame::isPlayerWin(const Player& player) const
{
    return player.points == 0;
}

void ClassicGame::nextRound()
{
    ModeGame::setAttemps(3);
}
  