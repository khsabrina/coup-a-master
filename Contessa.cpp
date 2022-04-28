
#include <iostream>


#include "Player.hpp" 


//#include "Game.hpp" 
#include "Contessa.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;
using namespace coup;



        void Contessa::block(Player assassin){
            // if(assassin.is_active == false || this->is_active ==false){
            //     throw invalid_argument{"this player is not active"};
            // }
            // if(assassin.type.compare("Assassin") !=0 ){
            //     throw invalid_argument{"Can't block this type of player"};
            // }
            // if(assassin.last_action.compare(0,4,"coup") !=0){
            //     throw invalid_argument{"Can't block this type of player"};
            // }
            this->last_action = "block " + assassin.name+ " " + assassin.type;
            stringstream streamData(assassin.last_action);
            string steal_player_name;
            string steal_player_type;
            getline(streamData, steal_player_name, ' '); 
            getline(streamData, steal_player_name, ' '); 
            getline(streamData, steal_player_type, ' ');
            for(size_t i=0; i<this->game->_players.size();i++){
                if(!this->game->_players[i].name.compare(steal_player_name)){
                    if(!this->game->_players[i].type.compare(steal_player_type))
                        this->game->_players[i].is_active = true;
                }
            }
            this->game->next_turn();
        }
