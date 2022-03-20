#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "dart-game/Game.hpp"

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

        int winners_size = winners.size();
        for (int i = 0; i < winners_size; ++i)
        {
            Player& p1 = settings.winners.front();
            Player& p2 = winners.front();
            CHECK_EQ(p1.id, p2.id);
            CHECK_EQ(p1.points, p2.points);
            settings.winners.pop_front();
            winners.pop_front();
        }
    }
    SUBCASE("input2")
    {
        nlohmann::json json = nlohmann::json::parse("{}");

        GameSettings settings;
        std::deque<Player> players;
        std::deque<Player> winners;
        settings.input(json);
        CHECK_EQ(settings.style, GameStyle::Classic);
        CHECK_EQ(settings.currentPlayerAttemps, 0);
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

        int winners_size = winners.size();
        for (int i = 0; i < winners_size; ++i)
        {
            Player& p1 = settings.winners.front();
            Player& p2 = winners.front();
            CHECK_EQ(p1.id, p2.id);
            CHECK_EQ(p1.points, p2.points);
            settings.winners.pop_front();
            winners.pop_front();
        }
    }
}

TEST_CASE("Game")
{
    SUBCASE("constructor/output settings")
    {
        Game game(GameStyle::Classic);
        auto settings = game.outputGame();
        CHECK_EQ(settings.style, GameStyle::Classic);
        CHECK(settings.players.empty());
        CHECK(settings.winners.empty());
        CHECK_EQ(settings.currentPlayerAttemps, 3);
    }
    SUBCASE("constructor/output settings 2")
    {
        Game game(GameStyle::ExtendClassic);
        game.addPlayer(1);
        game.addPlayer(2);
        game.addPlayer(3);
        game.playingPlayerScoredPoints(30);
        game.nextPlayer();
        game.playingPlayerScoredPoints(501);
        game.processGame();
        
        auto settings = game.outputGame();
        CHECK_EQ(settings.style, GameStyle::ExtendClassic);
        CHECK_EQ(settings.currentPlayerAttemps, 3);
        CHECK_EQ(settings.players.size(), 2);
        CHECK_EQ(settings.players.back().points, 471);
        CHECK_EQ(settings.players.front().points, 501);
        CHECK_EQ(settings.winners.size(), 1);
    }
    SUBCASE("settings constructor")
    {
        GameSettings settings;
        settings.currentPlayerAttemps = 2;
        settings.players.push_back({1, 301});
        settings.players.push_back({1, 2});
        settings.winners.push_back({3, 2});
        settings.style = GameStyle::RandomShot;

        Game game(settings);

        game.addPlayer(3);
        game.playingPlayerScoredPoints(30);
        game.nextPlayer();
        game.playingPlayerScoredPoints(501);
        game.processGame();

        auto settings2 = game.outputGame();
        CHECK_EQ(settings2.style, GameStyle::RandomShot);
        CHECK_EQ(settings2.currentPlayerAttemps, 2);
        CHECK_EQ(settings2.players.size(), 3);
        CHECK_EQ(settings2.players.front().points, 2);
        CHECK_EQ(settings2.winners.size(), 1);
    }

    SUBCASE("IS END????")
    {
        Game game(GameStyle::Classic);
        game.addPlayer(1);
        game.addPlayer(2);
        game.addPlayer(3);

        game.playingPlayerScoredPoints(301);
        game.processGame();
        auto settings = game.outputGame();
        CHECK_EQ(settings.players.size(), 2);
        CHECK_EQ(settings.winners.size(), 1);
        CHECK_EQ(game.isEnd(), false);
        game.playingPlayerScoredPoints(301);
        game.processGame();
        settings = game.outputGame();
        CHECK_EQ(settings.players.size(), 1);
        CHECK_EQ(settings.winners.size(), 2);
        CHECK_EQ(game.isEnd(), true);
    }
}