#ifndef ARENA_HPP
#define ARENA_HPP 

#include "GameEntity.hpp"


class Arena
{
    int x;
    int y;
    GameEntity **area; 
    
    public:
        Arena();
        Arena(int x, int y);
        short getX();
        short getY();
        void eval();
        ~Arena();
};

#endif