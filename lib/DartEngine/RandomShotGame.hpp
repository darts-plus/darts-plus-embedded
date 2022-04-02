#pragma once

#include <cstdlib>
#include <ctime>

#include "ModeGame.hpp"

class RandomShotGame : public ModeGame
{
    public:
        RandomShotGame();
        virtual Player createPlayer(unsigned int id) const override;
        virtual bool isNextPlayer() const override;
        virtual void processPlayerScore(Player& player, unsigned int score) override;
        virtual bool isPlayerWin(const Player& player) const override;
        virtual void nextRound() override;
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
    nextRound();
}

Player RandomShotGame::createPlayer(unsigned int id) const
{
    return {id, 0};
}

bool RandomShotGame::isNextPlayer() const
{
    return ModeGame::getRound().attempts == 0;
}

void RandomShotGame::processPlayerScore(Player& player, unsigned int score)
{
    if (score == mRandomShot)
    {
        ++player.points;
        mRandomShot = generateRandomNumber();
    }

    ModeGame::getRound().attempts -= 1;
}

bool RandomShotGame::isPlayerWin(const Player& player) const
{
    return player.points == 20;
}

void RandomShotGame::nextRound()
{
    ModeGame::getRound().scored_points = 0;
    ModeGame::getRound().attempts = 3;
    mRandomShot = generateRandomNumber();
}

unsigned int RandomShotGame::generateRandomNumber()
{
    return rand() % 21;
}
