#pragma once

#include <deque>
#include <string>
#include <memory>

#include "GameStyle.hpp"
#include "ExtendClassicGame.hpp"
#include "RandomShotGame.hpp"
#include "GameSettings.hpp"

class Game
{
    public:
        Game(GameStyle style);
        Game(GameSettings settings);
        void addPlayer(unsigned int id);
        void playingPlayerScoredPoints(unsigned int points);
        void processGame();
        GameSettings outputGame();
        bool isEnd();
        void nextPlayer();
    private:
        GameStyle mStyle;
        std::deque<Player> mPlayers;
        std::deque<Player> mWinners;
        std::unique_ptr<ModeGame> mGameMode;
};

Game::Game(GameStyle style)
: mStyle(style)
, mPlayers()
, mWinners()
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

Game::Game(GameSettings settings)
: Game(settings.style)
{
    mGameMode->setAttemps(settings.currentPlayerAttemps);
    mPlayers = settings.players;
    mWinners = settings.winners;
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
        mGameMode->nextRound();
    }
    if (mGameMode->isNextPlayer())
    {
        mGameMode->nextRound();
        nextPlayer();
    }
}

GameSettings Game::outputGame()
{
    GameSettings settings;
    settings.style = mStyle;
    settings.currentPlayerAttemps = mGameMode->getAttemps();
    settings.players = mPlayers;
    settings.winners = mWinners;

    return settings;
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
    mGameMode->nextRound();
}
