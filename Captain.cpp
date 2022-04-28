
#include <iostream>
//#include "Game.hpp"
#include "Captain.hpp"
#include "Player.hpp"
using namespace std;
using namespace coup;

        void Captain::steal(Player player){
            // if(this->game->turn_num == this->num_turn){
            //     throw invalid_argument{"not your turn"};
            // }
            player.coin = player.coin -2;
            this->game->next_turn();
        }
        void Captain::block(Player captain){
            // if(this->game->turn_num == this->num_turn){
            //     throw invalid_argument{"not your turn"};
            // }
            // if(captain.is_active == false || this->is_active ==false){
            //     throw invalid_argument{"this player is not active"};
            // }
            // if(captain.type.compare("Captain") !=0 ){
            //     throw invalid_argument{"Can't block this type of player"};
            // }
            // if(captain.last_action.compare(0,5,"steal") !=0){
            //     throw invalid_argument{"Can't block this type of player"};
            // }
            this->last_action = "block " + captain.name+ " " + captain.type;
            stringstream streamData(captain.last_action);
            string steal_player_name;
            string steal_player_type;
            getline(streamData, steal_player_name, ' '); 
            getline(streamData, steal_player_name, ' '); 
            getline(streamData, steal_player_type, ' ');
            for(size_t i=0; i<this->game->_players.size();i++){
                if(!this->game->_players[i].name.compare(steal_player_name) && !this->game->_players[i].type.compare(steal_player_type)){
                    this->game->_players[i].coin= this->game->_players[i].coin+2;
                }
            }
            this->game->next_turn();
        }
