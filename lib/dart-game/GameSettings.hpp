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
    nlohmann::json output();
    void input(nlohmann::json in);
};

GameSettings::GameSettings()
: style(GameStyle::Classic)
, currentPlayerAttemps(0)
, players()
, winners()
{ }

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
    style = in.contains("style") ? in.at("style") : GameStyle::Classic;
    currentPlayerAttemps = in.contains("currentPlayerAttemps") ? in.at("currentPlayerAttemps") : 0;
    players = in.contains("players") ? in.at("players") : std::deque<Player>();
    winners = in.contains("winners") ? in.at("winners") : std::deque<Player>();
}
