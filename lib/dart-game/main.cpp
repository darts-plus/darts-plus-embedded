#include "Game.hpp"

#include <iostream>

int main()
{
    nlohmann::json json;
        json["style"] = GameStyle::ExtendClassic;
        json["currentPlayerAttemps"] = 2;
        json["players"] = {{1, 301}, {2, 301}, {3, 301}};
        json["winners"] = {{4, 0}};

        GameSettings settings;
        std::deque<Player> players;
        players.push_back({1, 301});
        players.push_back({2, 301});
        players.push_back({3, 301});
        std::deque<Player> winners;
        winners.push_back({4, 0});
        settings.input(json);

}