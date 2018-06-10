#ifndef GAMEENTITY_HPP
#define GAMEENTITY_HPP 


#include <string> 

class GameEntity
{

    protected:
        bool alive;
        bool player;
        short signature;
        bool moved;
        short total;

    public: 
        GameEntity();
        void die();
        bool isAlive() const;
        bool isplayable() const;
        short getSig() const;
        void operator=(const GameEntity &other);
        bool getMoved(); 
        ~GameEntity();
        char getDirection();
        void setMoved();
};

class Player : public GameEntity
{
    short score;

    public: 
        Player();
        char getDirection();
        void increase();
        ~Player();
};

class Enemy : public GameEntity
{

    public: 
        Enemy();
        char getDirection();
        ~Enemy();
};

class Bullet : public GameEntity
{
    char direction; 
    bool moved;
    public: 
        Bullet();
        Bullet(char dir);
        char getDirection();
        ~Bullet();
};

class Empty : public GameEntity
{
    public: 
        Empty();
        char getDirection();
        ~Empty();
};

#endif