#ifndef ARENA_HPP
#define ARENA_HPP 

#include "GameEntity.hpp"


class Arena
{
    int x;
    int y;
    short **area; 
    public:
        Arena();
        Arena(int x, int y);
        short getX();
        short getY();
        ~Arena();
        void Render();
};

#endif