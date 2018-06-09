#ifndef GAMEENTITY_HPP
#define GAMEENTITY_HPP 


#include <string> 

class GameEntity
{
    short weapon;
    bool alive;
    bool player;

    public: 
        GameEntity();
        GameEntity(bool player);
        virtual bool isAlive() = 0;
        virtual short getWeapon() =0;
        virtual bool isplayable() = 0;
        ~GameEntity();
};

class Player : public GameEntity
{
    short weapon;
    bool alive;
    bool player;
    short score;

    public: 
        Player();
        bool isAlive();
        short getWeapon();
        bool isplayable();
        ~Player();
};

class Enemy : public GameEntity
{
    short weapon;
    bool alive;
    std:: string name;
    bool player;

    public: 
        Enemy();
        bool isAlive() = 0;
        short getWeapon() =0;
        bool isplayable();
        ~Enemy();
};

class Bullet : public GameEntity
    short weapon;
    bool alive;
    std:: string name;
    bool player;

    public: 
        Bullet();
        bool isAlive() = 0;
        short getWeapon() =0;
        bool isplayable();
        ~Bullet();
};
#endif