#pragma once

#include "ModeGame.hpp"

class ClassicGame : public ModeGame
{
    public:
        ClassicGame();
        virtual Player createPlayer(unsigned int id) const override;
        virtual bool isNextPlayer() const override;
        virtual void processPlayerScore(Player& player, unsigned int score) override;
        virtual bool isPlayerWin(const Player& player) const override;
        virtual void nextRound() override;
};

ClassicGame::ClassicGame()
{ 
    nextRound();
}

Player ClassicGame::createPlayer(unsigned int id) const
{
    return {id, 301};
}

bool ClassicGame::isNextPlayer() const
{
    return ModeGame::getRound().attempts == 0;
}

void ClassicGame::processPlayerScore(Player& player, unsigned int score)
{
    if (player.points >= score)
    {
        player.points -= score;
        ModeGame::getRound().scored_points += score;
        ModeGame::getRound().attempts -= 1;
    }
    else
    {
        player.points += ModeGame::getRound().scored_points;
        ModeGame::getRound().attempts = 0;
    }
}

bool ClassicGame::isPlayerWin(const Player& player) const
{
    return player.points == 0;
}

void ClassicGame::nextRound()
{
    ModeGame::getRound().attempts = 3;
    ModeGame::getRound().scored_points = 0;
}
  