#pragma once

#include "GameStyle.hpp"
#include "Player.hpp"
#include "Round.hpp"

#include <deque>

#include "json.hpp"

struct GameSettings
{
    GameStyle style;
    Round round;
    std::deque<Player> players;
    std::deque<Player> winners;

    GameSettings();
    GameSettings(nlohmann::json in);
    nlohmann::json output();
    void input(nlohmann::json in);
};

GameSettings::GameSettings()
: style(GameStyle::Classic)
, round({0, 0})
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
    out["round"] = round;
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
    if (in.contains("round"))
    {
        round = in.at("round");
    }
    else
    {
        round = {0, 0};
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
