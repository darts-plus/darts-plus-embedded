#pragma once

#include "ClassicGame.hpp"

class ExtendClassicGame : public ClassicGame
{
    public:
        ExtendClassicGame();
        virtual Player createPlayer(unsigned int id) const;
};

ExtendClassicGame::ExtendClassicGame()
: ClassicGame()
{ }

Player ExtendClassicGame::createPlayer(unsigned int id) const
{
    return {id, 501};
}
