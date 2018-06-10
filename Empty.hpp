

#ifndef EMPTY_H
# define EMPTY_H

#include "GameEntity.hpp"

class Empty : public GameEntity
{
    public: 
        Empty();
        char getDirection();
        ~Empty();
};

#endif