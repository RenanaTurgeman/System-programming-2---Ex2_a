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

TEST_CASE("During the game"){
   // Create two players with their names 
   Player p1("Alice");
   Player p2("Bob");

   Game game(p1,p2);
   for (int i=0;i<5;i++) {
    game.playTurn();
   }
    
   //serval checks that the number of the card is correct
   CHECK((p1.stacksize() + p2.stacksize() ==52));
   CHECK((p1.stacksize()+p2.cardesTaken()- p1.cardesTaken()==26));
   CHECK((p2.stacksize()+p1.cardesTaken() -p2.cardesTaken()==26));
}
