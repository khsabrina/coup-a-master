#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "Assassin.hpp"
using namespace coup;

        void Assassin::coup(Player player){
            // if(player.is_active == false || this->is_active ==false){
            //     throw invalid_argument{"this player is not active"};
            // }
            this->last_action = "coup " + player.name+ " " + player.type;
            player.is_active = false;
            this->coin = this->coin -3;
        }
