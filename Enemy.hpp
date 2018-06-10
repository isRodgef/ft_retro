
#ifndef ENEMY_H
# define ENEMY_H

#include "GameEntity.hpp"

class Enemy : public GameEntity
{

    public: 
        Enemy();
        char getDirection();
        ~Enemy();
};

#endif
