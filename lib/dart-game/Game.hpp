#pragma once

#include <deque>
#include <string>
#include <memory>

#include "GameStyle.hpp"
#include "ExtendClassicGame.hpp"
#include "RandomShotGame.hpp"

class Game
{
    public:
        Game(GameStyle style);
        void addPlayer(unsigned int id);
        void playingPlayerScoredPoints(unsigned int points);
        void processGame();
        std::string gameOutput();
        bool isEnd();
        void nextPlayer();
    private:
        std::deque<Player> mPlayers;
        std::deque<Player> mWinners;
        std::unique_ptr<ModeGame> mGameMode;
};

Game::Game(GameStyle style)
: mPlayers()
, mGameMode(nullptr)
{
    switch(style)
    {
        case GameStyle::Classic:
            mGameMode = std::make_unique<ClassicGame>();
            break;
        case GameStyle::ExtendClassic:
            mGameMode = std::make_unique<ExtendClassicGame>();
            break;
        case GameStyle::RandomShot:
            mGameMode = std::make_unique<RandomShotGame>();
            break;
    }
}

void Game::addPlayer(unsigned int id)
{
    mPlayers.emplace_back(mGameMode->createPlayer(id));
}

void Game::playingPlayerScoredPoints(unsigned int points)
{
    mGameMode->processPlayerScore(mPlayers.front(), points);
}

void Game::processGame()
{
    auto& playingPlayer = mPlayers.front();
    if (mGameMode->isPlayerWin(playingPlayer))
    {
        mWinners.push_back(playingPlayer);
        mPlayers.pop_front();
    }
    if (mGameMode->isNextPlayer())
    {
        mGameMode->nextRound();
        nextPlayer();
    }
}

std::string Game::gameOutput()
{
    return "";
}

bool Game::isEnd()
{
    return mPlayers.size() == 1;
}

void Game::nextPlayer()
{
    auto& player = mPlayers.front();
    mPlayers.pop_front();
    mPlayers.push_back(player);
}
