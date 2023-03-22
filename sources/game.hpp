#pragma once
#include <iostream>

namespace ariel{
    class Game
    {
    private:
        Player player1;
        Player player2;
    public:
        std::string to_string();

        // Constructors:
        Game(){
            //CHECK IF NEED
        }
        Game(Player p1,Player p2);
        void playTurn();
        void printLastTurn(); // print the last turn stats
        void playAll(); //playes the game untill the end
        void printWiner(); // prints the name of the winning player
        void printLog(); // prints all the turns played one line per turn
        void printStats();// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
    };
}
