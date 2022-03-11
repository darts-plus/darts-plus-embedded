#pragma once

#include "Player.hpp"

class ModeGame
{
    public:
        ModeGame();
        virtual Player createPlayer(unsigned int id) const;
        virtual bool isNextPlayer() const;
        virtual void processPlayerScore(Player& player, unsigned int score);
        virtual bool isPlayerWin(const Player& player) const;
};

ModeGame::ModeGame()
{ }

Player ModeGame::createPlayer(unsigned int id) const
{
    return {id, 0};
}

bool ModeGame::isNextPlayer() const
{
    return false;
}

void ModeGame::processPlayerScore(Player& player, unsigned int score)
{ }

bool ModeGame::isPlayerWin(const Player& player) const
{
    return false;
}
