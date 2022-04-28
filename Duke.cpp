#include <iostream>
//#include "Game.hpp"
//#include "Player.hpp"
#include "Duke.hpp"
using namespace std;
using namespace coup;


        void Duke::tax(){
            // if(game->turn_num != this->num_turn){
            //     throw invalid_argument{"not your turn"};
            // }
            // if(is_active ==false){
            //     throw invalid_argument{"this player is not active"};
            // }
            coin = coin +3;
            this->last_action = "tax ";
            game->next_turn();
        }
        void Duke::coup(Player player){
            // if(player.is_active == false || is_active ==false){
            //     throw invalid_argument{"this player is not active"};
            // }
            this->last_action = "coup " + player.name+ " " + player.type;
            player.is_active = false;
            coin = coin -7;
        }
        void Duke::block(Player& player){
            // if(player.is_active == false || is_active ==false){
            //     throw invalid_argument{"this player is not active"};
            // }
            // if(player.last_action.compare(0,11,"foreign_aid") !=0){
            //     throw invalid_argument{"Can't block this type of player"};
            // }
            this->last_action = "block " + player.name+ " " + player.type;
            player.coin = player.coin -2;
        }
