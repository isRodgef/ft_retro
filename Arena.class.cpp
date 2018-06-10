#include "Arena.hpp"
#include "Empty.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
// #include "Bullet.hpp"
#include <iostream>
#include <string>
#include <cmath>

Arena::Arena() {
    initscr();
    noecho();
    curs_set(FALSE);
    cbreak();

    this->even = true;
    this->x = 50;
    this->y = 50;
    this->area = new GameEntity*[x];

    Player p;
    Enemy e;
    Empty placeholder;
    
    for (int i = 0; i < this->y; ++i)
        this->area[i] =new GameEntity[y];
   
    for(int j = 0; j < this->x; ++j) {
        for(int k = 0; k < this->y; ++k) {            
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

Arena::Arena (int x, int y) {
    initscr();
    noecho();
    curs_set(FALSE);
    cbreak();

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
        {
            if (i % 2 == 1)
                this->area[0][i] = e;        
        }
}

Arena::~Arena () {
    for(int i = 0; i < this->y; ++i)
        delete [] this->area[i];
    delete [] this->area;
    endwin();
}


short Arena::getX() {
    return this->x;
}

short Arena::getY() {
 return this->y;
}


void Arena::eval() {
    Empty placeholder;
    if(this->area[this->x -1][0].getSig() == -1) {
            this->gameover(0);
    }

     this->placeEnemy();
     this->moveBullet();
     refresh();
     wrefresh(stdscr);
}

GameEntity** Arena :: get_area() {
    return this->area;
}

void Arena::moveLeft() {
    Empty e;
    for (int i = 0; i < this->x ; i++) {
        for (int j = 0; j < this->y ; j++) {
            if (this->area[i][j].getSig() == 1) {
                this->area[i][abs(j - 1) % this->y] = this->area[i][j]; 
                this->area[i][j] = e;
                return;
            } 
        }   
    }
}

void Arena::moveRight() {
    Empty e;
    for (int i = 0; i < this->x ; i++) {
        for (int j = 0; j < this->y ; j++) {
            if (this->area[i][j].getSig() == 1) {
                this->area[i][(j + 1) %  this->y] = this->area[i][j];
                this->area[i][j] = e;
                return;
            }
        }  
    }
}

void Arena :: spawn_bullet(bool key) {
    Bullet b, e;
        int check = 0;
        for (int i = 0; i < this->x ; i++) {
            for (int j = 0; j < this->y ; j++) {
                if (key && this->area[i][j].getSig() == 1) {
                    b = Bullet('u');          
                    this->area[i - 1][j] = b;                       
                    return;
                }
                else {
                    if (not key and this->area[i][j].getSig() == -1)
                    {
                        check = rand() % 15; 
                        if (check == 1)
                        {
                            e = Bullet('d');          
                            if (this->area[i + 1][j].getSig() == 0)
                                this->area[i + 1][j] = e;
                        }
                    }
                }
            }  
        }
}

void Arena :: display()
{
    int xx =0,yy =0;
    getmaxyx(stdscr,yy,xx);
   // clear();
   
        
    while (true){
    box(stdscr,0,0);
    getmaxyx(stdscr,yy,xx); 
    this->eval();
    

    for (int i = 0; i < this->x; i++)
    {
       
        box(stdscr,0,0);
        for (int j = 0; j  < this->y; j++)
        {
            switch(this->area[i][j].getSig())
            {
                move(yy/2   + j + 100 ,xx / 2 + i + 100);
                case 0:
                    
                    if (j % 5 ==0)
                        addstr("_-_");
                    else
                        addstr("   ");
                     
                    break;
                case 1:
                    addstr("<|>");
                    break;
                case -1:
                    addstr("{0}");
                    break;
                case 2:
                    addstr("±±±");
                    break;
            } 
            nodelay(stdscr,TRUE);
            switch(getch())
            {
                case 'a':
                    this->moveLeft();
                    break;
                case 'd':
                    this->moveRight();
                    break;
                case ' ':
                    this->spawn_bullet(true);
                    break;
            }
        }
            addstr("\n");
    }
        clear();
        napms(400);
    }    
}

void Arena :: placeEnemy()
{
    Enemy  e;
    Empty a;
    bool place = false;  
     for (int i = 0; i < this->x; i++)
    {
        for (int j = 0; j < this->y; j++)
        {
            if (this->area[i][j].getSig() == -1)
            {
                if (not place and i + 1 < this->y and this->area[i + 1][j].getSig() == 0 and j % 5 > 0)
                // if (not place and i - 1 < this->y and  this->area[i - 1][j].getSig() != 1)
                {
                    this->area[i + 1][j]  = this->area[i][j];
                    place = true;
                }
                if (not place and j + 1 < this->y and this->area[i][j+1].getSig() == 0)
                {
                    this->area[i][j + 1]  = this->area[i][j];
                    place = true;
                }
               /* if (this->area[i][j+1].getSig() == 2)
                {
                    this->area[i][j]  = e;
                }*/
                if (place )
                    return;
            }
        }
    }
}

void Arena :: moveBullet()
{
    Bullet b;
    Empty e;
    
 
    for (int i = 0; i < this->x; i++)
    {
        for (int j = 0; j  < this->y; j++)
        {
            if (this->area[i][j].getSig() == 2)
            {
                if (i - 1 < this->y and  this->area[i - 1][j].getSig() != 1)
                {
                    if ((this->area[i - 1][j].getSig() == 2 or this->area[i - 1][j].getSig() == -1))             
                    {
                        this->area[i - 1][j]  = e;
                        this->area[i][j] = e;
                    }
                    this->area[i - 1][j]  = this->area[i][j];
                    this->area[i][j] = e;


                }
            }
        }
    }
}

void Arena ::gameover( int value ) {
   endwin();
   (void) value;
    addstr("you lose");
    std::cout << "game over " << std::endl;
    exit(0);
    
  
}