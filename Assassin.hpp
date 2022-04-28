#pragma once
#include <iostream>
#include "Game.hpp"
//#include "Player.cpp"

namespace coup{
class Assassin : public Player{
    public:
        Assassin(Game& game, string name): Player(game,name,"Assassin"){};
        void coup(Player player);
};
}