
#include "doctest.h"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;
using namespace coup;


TEST_CASE("good inputs"){
    Game game;
	Duke duke{game, "Moshe"};
	Assassin assassin{game, "Yossi"};
	Ambassador ambassador{game, "Meirav"};
	Captain captain{game, "Reut"};
	Contessa contessa{game, "Gilad"};
    vector<string> test = game.players();
    CHECK(test[0]=="Moshe");
    CHECK(test[1]=="Yossi");
    CHECK(test[2]=="Meirav");
    CHECK(test[3]=="Reut");
    CHECK(test[4]=="Gilad");
    for(int i=1;i<30;i++){
        CHECK_NOTHROW(duke.income());
        CHECK_NOTHROW(assassin.income());
        CHECK_NOTHROW(ambassador.income());
        CHECK_NOTHROW(captain.foreign_aid());
        CHECK_NOTHROW(contessa.foreign_aid());
        CHECK(duke.coins()==i);
        CHECK(assassin.coins()==i);
        CHECK(ambassador.coins()==i);
        CHECK(captain.coins()==2*i);
        CHECK(contessa.coins()==2*i);
    }
    CHECK_NOTHROW(assassin.coup(ambassador));
    CHECK_NOTHROW(contessa.block(assassin));
    CHECK_NOTHROW(duke.tax());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_NOTHROW(duke.block(assassin));
}

TEST_CASE("bad input"){

    Game game;
    Duke duke{game, "Moshe"};
	Assassin assassin{game, "Yossi"};
	Ambassador ambassador{game, "Meirav"};
	Captain captain{game, "Reut"};
	Contessa contessa{game, "Gilad"};
    CHECK_THROWS(duke.block(assassin));
    CHECK_THROWS(ambassador.income());
    CHECK_THROWS(contessa.block(captain));
    CHECK_THROWS(contessa.income());
    CHECK_THROWS(game.winner());
}