#include "Arena.hpp"
#include <iostream>

Arena :: Arena()
{
    this->even = true;
    this->x = 10;
    this->y = 50;
    this->area = new GameEntity*[x];
    Player p;
    Enemy e;
    Empty placeholder;
    
    for (int i = 0; i < this->y; ++i)
        this->area[i] =new GameEntity[y];
   
    for(int j = 0; j < this->x; ++j){
        for(int k = 0; k < this->y; ++k){            
            this->area[j][k] = placeholder;   
        }
    }
    this->area[(this->x - 1) ][(this->y -1) /2] = p;
    for (int i = 0; i < this->x; i++)
        if  (this->even){
            if (i % 2 == 0)
                this->area[0][i] = e;
        }
        else 
            if (i % 2 == 1)
                this->area[0][i] = e;
}

//0 empty
//1 player
//-1 enemy 
//2 bullet
Arena :: Arena (int x, int y)
{
    this->even = true;
    this->x = x;
    this->y = y;
    this->area = new GameEntity*[x];
    Empty placeholder;
    Player p;
    Enemy e;

    for (int i = 0; i < this->y; i++)
        this->area[i] = new GameEntity[y];

     for(int j = 0; j < this->x; j++){
        for(int k = 0; k < this->y; k++){            
            this->area[j][k] = placeholder; 
        }
    }
   this->area[(this->x - 1) ][(this->y -1) /2] = p;
    for (int i = 0; i < this->x; i++)
        if  (this->even){
            if (i % 2 == 0)
                this->area[0][i] = e;
        }
        else 
            if (i % 2 == 1)
                this->area[0][i] = e;

}

Arena :: ~Arena ()
{
    for(int i = 0; i < this->y; ++i)
        delete [] this->area[i];
    delete [] this->area;
}


short Arena :: getX(){
    return this->x;
}

short Arena :: getY(){
 return this->y;
}


void Arena :: eval(){
    Empty placeholder;

    for(int j = 0; j < this->x; ++j){
        std::cout << std::endl;
        for(int k = 0; k < this->y; ++k){            
            std::cout << this->area[j][k].getSig() << ' ';
           switch (this->area[j][k].getSig())
            {
                case 0:
                    break;
                case 1:
                    break;
                case 2:
                    if (this->area[j][k].getDirection() == 'u')
                    {
                        if (k > 0 and this->area[j][k - 1].isAlive() and this->area[j][k - 1].getSig() != 1 )
                        {
                            this->area[j][k - 1] = placeholder;                            
                        }
                        this->area[j][k] = placeholder;

                    }
                    if (this->area[j][k].getDirection() == 'd' )
                    {
                         if (k < this->y and  this->area[j][k + 1].isAlive() and this->area[j][k - 1].getSig() != -1)
                        {
                            this->area[j][k+1] = placeholder;                            
                        }
                        this->area[j][k] = placeholder;
                    }
                    break;
                default:
                    break;

            }
        }
    }
}

GameEntity** Arena :: get_area()
{
    return this->area;
}

void Arena :: moveLeft()
{
    Empty e;
    for (int i = 0; i < this->x ; i++)
    {
        for (int j = 0; j < this->y ; j++)
        {
            if (this->area[i][j].getSig() == 1)
            {
                this->area[i][(j - 1) % this->y] = this->area[i][j]; 
                this->area[i][j] = e;
                return;
            }
        }   
    }
}

void Arena :: moveRight()
{
    Empty e;
    for (int i = 0; i < this->x ; i++)
    {
        for (int j = 0; j < this->y ; j++)
        {
            if (this->area[i][j].getSig() == 1)
            {
                this->area[i][(j + 1) %  this->y] = this->area[i][j];
                this->area[i][j] = e;                       
                return;
            }
        }  
    }
}

void Arena :: spawn_bullet(bool key)
{
        int check = 0;
        for (int i = 0; i < this->x ; i++)
        {
            for (int j = 0; j < this->y ; j++)
            {
                if (key && this->area[i][j].getSig() == 1)
                {
                    Bullet b('u');          
                    this->area[i - 1][j] = b;                       
                    return;
                }
                else
                {
                    if (not key and this->area[i][j].getSig() == -1)
                    {
                        check = rand() % 2; 
                        if (check == 1)
                        {
                            Bullet e('d');          
                            this->area[i + 1][j] = e;
                        }
                    }
                }
            }  
        }
}