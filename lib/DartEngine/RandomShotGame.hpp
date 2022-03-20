#pragma once

#include <cstdlib>
#include <ctime>

#include "ModeGame.hpp"

class RandomShotGame : public ModeGame
{
    public:
        RandomShotGame();
        virtual Player createPlayer(unsigned int id) const;
        virtual bool isNextPlayer() const;
        virtual void processPlayerScore(Player& player, unsigned int score);
        virtual bool isPlayerWin(const Player& player) const;
        virtual void nextRound();
    private:
        unsigned int generateRandomNumber();
    private:
        unsigned int mRandomShot;
};

RandomShotGame::RandomShotGame()
: mRandomShot(0)
{
    // this old form is only in v.1
    srand((unsigned)time(NULL));
    mRandomShot = generateRandomNumber();
    ModeGame::setAttemps(3);
}

Player RandomShotGame::createPlayer(unsigned int id) const
{
    return {id, 0};
}

bool RandomShotGame::isNextPlayer() const
{
    return ModeGame::getAttemps() == 0;
}

void RandomShotGame::processPlayerScore(Player& player, unsigned int score)
{
    if (score == mRandomShot)
    {
        ++player.points;
        mRandomShot = generateRandomNumber();
    }

    ModeGame::setAttemps(ModeGame::getAttemps() - 1);
}

bool RandomShotGame::isPlayerWin(const Player& player) const
{
    return player.points == 20;
}

void RandomShotGame::nextRound()
{
    ModeGame::setAttemps(3);
    mRandomShot = generateRandomNumber();
}

unsigned int RandomShotGame::generateRandomNumber()
{
    return rand() % 21;
}
