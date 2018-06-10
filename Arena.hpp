#ifndef ARENA_HPP
#define ARENA_HPP 

#include <ncurses.h>
#include "GameEntity.hpp"


class Arena
{
    int x;
    int y;
    GameEntity **area; 
    bool  even;

    public:
        Arena();
        Arena(int x, int y);
        short getX();
        short getY();
        void eval();
        GameEntity **get_area();
        void moveLeft();
        void moveRight();
        void spawn_bullet(bool key);
        void display();
        ~Arena();
        void placeEnemy();
};

#endif