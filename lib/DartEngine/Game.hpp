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
        Game();
        Game(GameStyle style);
        Game(GameSettings settings);
        void addPlayer(unsigned int id);
        void playingPlayerScoredPoints(unsigned int points);
        void processGame();
        GameSettings outputGame();
        bool isEnd();
        void nextPlayer();
        void buttonDelay();
    private:
        enum class State
        {
            PLAY,
            STOP,
            NEXT_PLAYER
        };
    private:
        GameStyle mStyle;
        std::deque<Player> mPlayers;
        std::deque<Player> mWinners;
        std::unique_ptr<ModeGame> mGameMode;
        State mGameState;
};

Game::Game()
: Game(GameStyle::Classic)
{ }

Game::Game(GameStyle style)
: mStyle(style)
, mPlayers()
, mWinners()
, mGameMode(nullptr)
, mGameState(State::PLAY)
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
    mGameMode->getRound() = settings.round;
    mPlayers = settings.players;
    mWinners = settings.winners;
}

void Game::addPlayer(unsigned int id)
{
    mPlayers.emplace_back(mGameMode->createPlayer(id));
}

void Game::playingPlayerScoredPoints(unsigned int points)
{
    if (mGameState == State::PLAY)
    {
        mGameMode->processPlayerScore(mPlayers.front(), points);
    }
}

void Game::processGame()
{
    auto& playingPlayer = mPlayers.front();
    if (mGameMode->isPlayerWin(playingPlayer))
    {
        if (mGameState == State::PLAY)
        {
            mGameState = State::STOP;
        }
        if (mGameState == State::NEXT_PLAYER)
        {
            mWinners.push_back(playingPlayer);
            mPlayers.pop_front();
            mGameMode->nextRound();
            mGameState = State::PLAY;
        }
    }
    if (mGameMode->isNextPlayer())
    {
        if (mGameState == State::PLAY)
        {
            mGameState = State::STOP;
        }
        nextPlayer();
    }
}

GameSettings Game::outputGame()
{
    GameSettings settings;
    settings.style = mStyle;
    settings.round = mGameMode->getRound();
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
    if (mGameState == State::NEXT_PLAYER)
    {
        auto& player = mPlayers.front();
        mPlayers.pop_front();
        mPlayers.push_back(player);
        mGameMode->nextRound();
        mGameState = State::PLAY;
    }
}

void Game::buttonDelay()
{
    switch (mGameState)
    {
        case State::PLAY:
            mGameState = State::STOP;
            break;
        case State::STOP:
            mGameState = State::NEXT_PLAYER;
            break;
        default:
            break;
    }
}