#pragma once
#include <iostream>
#include <string>

namespace ariel
{


class Player
{
private:
    std::string name;
public:
    Player(){
        //CHEK IF NEED?
    }
    Player(std::string name);
    // std::string to_string();
    int stacksize(); //prints the amount of cards left.
    int cardesTaken(); //prints the amount of cards this player has won.
};

}//namescap