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

TEST_CASE("Preparations for the game- each player have 26 cards"){
   // Create two players with their names 
   Player p1("Alice");
   Player p2("Bob");

   //before the game start each player has the same amount of cards
   CHECK(p1.stacksize() == p2.stacksize());
   // each player have 26 cards (52/2)
   CHECK(p1.stacksize()== 26);
}

TEST_CASE("Preparations for the game- player cant play with himself"){
      Player p1("Alice");
      Game game(p1,p1);//plays with himself
      CHECK_THROWS(game.playTurn());
}

TEST_CASE("Before starting to play - cardes taken need to be 0"){
   // Create two players with their names 
   Player p1("Alice");
   Player p2("Bob");

   //the amount of cards each player has won is 0.
   CHECK(p1.cardesTaken()==0);
   CHECK(p2.cardesTaken()==0);
}
TEST_CASE("After one round the sum of the cards is 52"){
   // Create two players with their names 
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();
    CHECK((p1.stacksize() + p1.cardesTaken() + p2.stacksize() + p2.cardesTaken() == 52));
}

TEST_CASE("During the game- check amount of cards"){
   // Create two players with their names 
   Player p1("Alice");
   Player p2("Bob");
   Game game(p1,p2);

   //serval checks that the number of the card is correct
   CHECK((p1.stacksize() + p2.stacksize() ==52));
   
   game.playTurn();

   CHECK((p1.stacksize()<26));
   CHECK((p2.stacksize()<26));
   bool won1 = p1.cardesTaken()>=1;
   bool won2 = p2.cardesTaken()>=1;
   bool winner =won1|| won2; //one of them won 
   CHECK(winner);

   for (int i=0;i<5;i++) {
      game.playTurn();
      CHECK((p1.stacksize()+p2.cardesTaken()+p2.stacksize()+p1.cardesTaken()==52));
   }
    
}

TEST_CASE("End the game- the stack size need to be 0"){
   // Create two players with their names 
   Player p1("Alice");
   Player p2("Bob");

   Game game(p1,p2);
   game.playAll(); //playes the game untill the end
   CHECK((p1.stacksize() == 0));
   CHECK((p2.stacksize() ==0));
   CHECK_THROWS(game.playTurn());//error need to be throws if we play after thr game is over
}

TEST_CASE("Finish game at most 26 turns"){
   //the game should finish after 26 turns at maxsimum
   // Create two players with their names 
   Player p1("Alice");
   Player p2("Bob");

   Game game(p1,p2);
   int numPlays = 0;
   for (int i = 0; i < 30; i++)
   {
      game.playTurn();
      numPlays++;
      if(p1.stacksize()!=0 || p2.stacksize()!=0)
       break;
   }
   
   CHECK(numPlays<=26); //we can play at most 26 teims
   CHECK(p1.stacksize()==0);
   CHECK(p2.stacksize()==0);
}

TEST_CASE("Plays 15 turns- left max of 11 cards"){
   // Create two players with their names 
   Player p1("Alice");
   Player p2("Bob");

   Game game(p1,p2);  
   for (int i = 0; i < 15; i++)
   {
      game.playTurn();
      if(p1.stacksize()==0||p2.stacksize()==0){
         break;
      }
   }
   
   CHECK(p1.stacksize()<=11);
   CHECK(p2.stacksize()<=11);
   
}

TEST_CASE("the sum of the cardes taken is 52 in the end"){
   // Create two players with their names 
   Player p1("Alice");
   Player p2("Bob");

   Game game(p1,p2);  
   game.playAll();
   CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
   CHECK(p1.stacksize() + p2.stacksize() == 0);
}

TEST_CASE("Winner can printed only in the end of the game"){
   // Create two players with their names 
   Player p1("Alice");
   Player p2("Bob");

   Game game(p1,p2);  
   CHECK_THROWS(game.printWiner()); //here there is print of the winner before the game even start
}
