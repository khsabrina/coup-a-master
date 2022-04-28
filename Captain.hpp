#pragma once
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"

namespace coup{
class Captain : public Player{
    public:
        Captain(Game& game, string name): Player(game,name,"Captain"){};
        void steal(Player player);
        void block(Player captain);
};
}