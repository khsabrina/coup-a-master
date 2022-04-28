#pragma once
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
using namespace std;

namespace coup{
class Ambassador : public Player{
    public:
        Ambassador(Game& game, string name): Player(game,name,"Ambassador"){};
        void transfer(Player duke, Player assassin);
        void coup(Player player);
        void block(Player captain);
};
}