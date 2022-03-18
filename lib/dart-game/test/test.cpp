#include "doctest/doctest.h"
#include "Game.hpp"

TEST_CASE("GameSettings")
{
    SUBCASE("output")
    {
        GameSettings settings;
        settings.currentPlayerAttemps = 3;
        settings.players = {{1, 301}, {2, 301}};
        settings.winners = {};
        settings.style = GameStyle::Classic;
        auto json = settings.output().dump();
        CHECK_EQ(json, "{\"currentPlayerAttemps\":3,\"players\":[{\"id\":1,\"points\":301},{\"id\":2,\"points\":301}],\"style\":0,\"winners\":[]}");
    }
    SUBCASE("output2")
    {
        GameSettings settings;
        auto json = settings.output().dump();
        CHECK_EQ(json, "{\"currentPlayerAttemps\":0,\"players\":[],\"style\":0,\"winners\":[]}");
    }
    SUBCASE("input")
    {
        nlohmann::json json = nlohmann::json::parse("{\"currentPlayerAttemps\":2,\"players\":[{\"id\":1,\"points\":301},{\"id\":2,\"points\":301}],\"style\":0,\"winners\":[{\"id\":4,\"points\":0}]}");

        GameSettings settings;
        std::deque<Player> players;
        players.push_back({1, 301});
        players.push_back({2, 301});
        std::deque<Player> winners;
        winners.push_back({4, 0});
        settings.input(json);
        CHECK_EQ(settings.style, GameStyle::Classic);
        CHECK_EQ(settings.currentPlayerAttemps, 2);
        int player_size = players.size();
        for (int i = 0; i < player_size; ++i)
        {
            Player& p1 = settings.players.front();
            Player& p2 = players.front();
            CHECK_EQ(p1.id, p2.id);
            CHECK_EQ(p1.points, p2.points);
            settings.players.pop_front();
            players.pop_front();
        }
    }
}

TEST_CASE("Game konstuctor")
{
    Game game(GameStyle::Classic);

}