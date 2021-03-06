#pragma once

#include "nlohmann/json.hpp"
struct Player
{
    unsigned int id;
    unsigned int points;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Player, id, points);
};
