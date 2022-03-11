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
    private:
        unsigned int mAttems;
};

ClassicGame::ClassicGame()
: mAttems(3)
{ }

Player ClassicGame::createPlayer(unsigned int id) const
{
    return {id, 301};
}

bool ClassicGame::isNextPlayer() const
{
    return mAttems == 0;
}

void ClassicGame::processPlayerScore(Player& player, unsigned int score)
{
    if (player.points >= score)
    {
        player.points -= score;
        --mAttems;
    }
    else
    {
        mAttems = 0;
    }
}

bool ClassicGame::isPlayerWin(const Player& player) const
{
    return player.points == 0;
}
  