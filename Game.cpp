//#pragma once
#include "Player.hpp" 
#include "Game.hpp" 
#include <iostream>
//#include "Game.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;
using namespace coup;



        Game::Game(){
            this->_players.reserve(6);
            this->amout_of_player=0;
            this->turn_num=1;
        }
        void Game::next_turn(){
            if(turn_num == amout_of_player){
                //cout << "here1";
                this->turn_num = 1;
                return;
            }
            for(size_t i=(size_t)turn_num-1;i<amout_of_player+1;i++){
                if(this->_players[i].is_active == true && this->_players[i].num_turn != turn_num){
                    //cout << amout_of_player;
                    turn_num = i+2;
                    //cout << turn_num;
                    return;
                }
            }
            for(size_t i=0;i<amout_of_player;i++){
                if(this->_players[i].is_active == true){
                    if(turn_num == i+1){
                        winner();
                        return;
                    }
                    turn_num = i+1;
                    return;
                }
            }
            cout << turn_num;
        }
        void Game::add(Player& player){
            _players.push_back(player);
            this->amout_of_player= this->amout_of_player + 1;
            player.num_turn = this->amout_of_player;
        }
        string Game::turn(){
            return _players[(size_t)(turn_num-1)].name;
        }
        vector<string> Game::players(){
            vector<string> str_players;
            str_players.reserve((size_t)this->amout_of_player);
            // for(size_t i=0;i< this->_players.size(); i++){
            //     str_players[i] = _players[i].name;
            // }
            // for(size_t i=0;i< this->amout_of_player; i++){
            //     cout << str_players[i];
            // }
            return str_players;
        }
        string Game::winner(){
            return "abcd";
        }
