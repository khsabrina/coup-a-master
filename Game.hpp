#pragma once

//#include "Player.hpp" 


#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
namespace coup{
    class Player;
class Game{
    public:
        vector<Player> _players;
        int amout_of_player=0;
        int turn_num;
        Game();
        void next_turn();
        void add(Player& player);
        string turn();
        vector<string> players();
        string winner();
};
}