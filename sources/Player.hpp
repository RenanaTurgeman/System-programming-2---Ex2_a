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
    Player(std::string mname){
        name = mname;
    }
};

}//namescap