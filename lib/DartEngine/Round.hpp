#pragma once

#include "json.hpp"

struct Round
{
    unsigned int attempts;
    unsigned int scored_points;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Round, attempts, scored_points);
};