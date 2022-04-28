#pragma once
#include "Game.hpp" 
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;
namespace coup{
class Player{
    public:
        int num_turn;
        int coin;
        string name;
        string type;
        string last_action;
        Game* game;
        bool is_active;
        Player(Game& g, string n, string type);
        Player() {cout << "MyClass:default\n";}
        void income();
        void foreign_aid();
        int coins();

};
}