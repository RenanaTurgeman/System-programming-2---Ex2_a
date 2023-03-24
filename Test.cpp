#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;
using namespace ariel;

TEST_CASE("Preparations for the game"){
   // Create two players with their names 
   Player p1("Alice");
   Player p2("Bob");

   //before the game start each player has the same amount of cards
   CHECK(p1.stacksize() == p2.stacksize());
   // each player have 26 cards (52/2)
   CHECK(p1.stacksize()== 26);
}

TEST_CASE("Before starting to play"){
   // Create two players with their names 
   Player p1("Alice");
   Player p2("Bob");

   //the amount of cards each player has won is 0.
   CHECK(p1.cardesTaken()==0);
   CHECK(p2.cardesTaken()==0);
}