#pragma once

#include "Player.hpp"
#include "Round.hpp"

class ModeGame
{
    public:
        virtual Player createPlayer(unsigned int id) const = 0;
        virtual bool isNextPlayer() const = 0;
        virtual void processPlayerScore(Player& player, unsigned int score) = 0;
        virtual bool isPlayerWin(const Player& player) const = 0;
        virtual void nextRound() = 0;
        
        Round& getRound() { return mRound; }
        const Round& getRound() const { return mRound; }
    private:
        Round mRound;
};