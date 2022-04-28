#include "Player.hpp" 
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;
using namespace coup;

        Player::Player(Game& g, string n, string type){
            this->name = n;
            this->game = &g;
            this->coin=0;
            this->type = type;
            this->is_active =true;
            this->game->add(*this);
            // cout << this->num_turn << '\n';
            // cout << this->game->turn_num;
        }
        void Player::income(){
            //cout << this->game->turn_num;
            // if(this->game->turn_num != this->num_turn){
            //     throw invalid_argument{"not your turn"};
            //     //cout << "\n" << this->game->turn_num << " " <<this->num_turn;
            // }
            coin+=1;
            this->last_action = "income ";
            this->game->next_turn();
        }
        void Player::foreign_aid(){
            // if(this->game->turn_num != this->num_turn){
            //     throw invalid_argument{"not your turn"};
            // }
            coin+=2;
            this->last_action = "foreign_aid ";
            this->game->next_turn();
        }
        int Player::coins(){
            return coin;
        }
        //void coup();

