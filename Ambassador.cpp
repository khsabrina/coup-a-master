#include <iostream>
//#include "Game.hpp"
//#include "Player.cpp"
#include "Ambassador.hpp"
using namespace std;
using namespace coup;

        void Ambassador::transfer(Player duke, Player assassin){
            // if(this->game->turn_num != this->num_turn){
            //     cout << "\n" << this->game->turn_num << " " <<this->num_turn;
            // }
            // if(duke.is_active == false || assassin.is_active == false || this->is_active ==false){
            //     throw invalid_argument{"this player is not active"};
            // }
            assassin.coin++;
            duke.coin--;
            string name_player = duke.name + assassin.name;
            string type_player = duke.type + assassin.type;
            this->last_action = "transfer ";
            this->game->next_turn();
        }
        void Ambassador::coup(Player player){
            // if(player.is_active == false || this->is_active ==false){
            //     throw invalid_argument{"this player is not active"};
            // }
            // this->last_action = "coup " + player.name+ " " + player.type;
            // player.is_active = false;
            // this->coin = this->coin -7;
        }
        void Ambassador::block(Player captain){
            // if(this->game->turn_num == this->num_turn){
            //     throw invalid_argument{"not your turn"};
            // }
            // if(captain.is_active == false || this->is_active ==false){
            //     throw invalid_argument{"this player is not active"};
            // }
            // if(captain.type.compare("Captain") !=0){
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
