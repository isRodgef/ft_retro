#include "GameEntity.hpp"


GameEntity :: GameEntity()
{

}

GameEntity :: ~GameEntity()
{

}

bool GameEntity :: isplayable() const
{
    return this->player;
}

char GameEntity :: getDirection()
{
    return 'a';
}

void GameEntity :: operator =(const GameEntity &g)
{
    if (this != &g) 
    {
        this->alive = g.isAlive();
        this->player = g.isplayable();
        this->signature = g.getSig();
    }
}

void GameEntity :: die()
{
    this->alive = false;
}

short GameEntity :: getSig() const
{
    return this->signature;
}

bool GameEntity :: isAlive() const
{
    return this->alive;
}

Player :: Player()
{
    this->player = true;
    this->score = 0;
    this->alive = true;
    this->signature = 1;
}

Player :: ~Player()
{

}

Enemy :: Enemy()
{
    this->player = false;
    this->alive = true;
    this->signature = -1;
}

Enemy :: ~Enemy()
{

}

Empty :: Empty()
{
    this->player = false;
    this->alive = false;
    this->signature = 0;
}

Empty :: ~Empty()
{
  
}

Bullet :: Bullet()
{
    this->player = false;
    this->alive = true;
    this->signature = 2;
}

Bullet :: ~Bullet()
{

}

Bullet :: Bullet(char dir)
{
    this->player = false;
    this->alive = true;
    this->signature = 2;
    this->direction = dir; 
    this->moved = false;
}

char Bullet :: getDirection()
{
    return this->direction;
}

bool GameEntity :: getMoved()
{
    return this->moved;
}

void GameEntity :: setMoved()
{
    this->moved = not this->moved;
}