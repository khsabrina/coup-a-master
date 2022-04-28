
#include <iostream>

#include "Game.hpp" 
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;
using namespace coup;

namespace coup{
    class Contessa : public Player{
        public:
            Contessa(Game& game, string name): Player(game,name,"Contessa"){};
            void block(Player assassin);
    };
}