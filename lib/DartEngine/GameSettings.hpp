#pragma once

#include "GameStyle.hpp"
#include "Player.hpp"

#include <deque>

#include "nlohmann/json.hpp"

struct GameSettings
{
    GameStyle style;
    unsigned int currentPlayerAttemps;
    std::deque<Player> players;
    std::deque<Player> winners;

    GameSettings();
    GameSettings(nlohmann::json in);
    nlohmann::json output();
    void input(nlohmann::json in);
};

GameSettings::GameSettings()
: style(GameStyle::Classic)
, currentPlayerAttemps(0)
, players()
, winners()
{ }

GameSettings::GameSettings(nlohmann::json in)
: GameSettings()
{
    input(in);
}

nlohmann::json GameSettings::output()
{
    nlohmann::json out;
    out["style"] = style;
    out["currentPlayerAttemps"] = currentPlayerAttemps;
    out["players"] = players;
    out["winners"] = winners;

    return out;
}

void GameSettings::input(nlohmann::json in)
{
    if (in.contains("style"))
    {
        style = in.at("style");
    }
    else
    {
        style = GameStyle::Classic;
    } 
    if (in.contains("currentPlayerAttemps"))
    {
        currentPlayerAttemps = in.at("currentPlayerAttemps");
    }
    else
    {
        currentPlayerAttemps = 0;
    } 
    if (in.contains("players"))
    {
        players = in.at("players");
    }
    else
    {
        players = std::deque<Player>();
    } 
    if (in.contains("winners"))
    {
        winners = in.at("winners");
    }
    else
    {
        winners = std::deque<Player>();
    } 
}
