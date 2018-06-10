#ifndef PLAYER_H
# define PLAYER_H

# include "GameEntity.hpp"

class Player : public GameEntity
{
    public: 
        Player();
        char getDirection();
        ~Player();
};

#endif