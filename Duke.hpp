#pragma once
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"

namespace coup{
    class Duke : public Player{
        public:
            Duke(Game& game, string name): Player(game,name,"Duke"){};
            void tax();
            void coup(Player player);
            void block(Player& player);
    };
}