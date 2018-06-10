#include "Arena.hpp"
#include <iostream>

Arena :: Arena()
{
    initscr();
    noecho();
    curs_set(FALSE);
    this->even = true;
    this->x = 10;
    this->y = 50;
    this->area = new GameEntity*[x];
    Player p;
    Enemy e;
    Empty placeholder;
    //WINDOW *win = newwin(0,0,0,0);
    
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
Arena::Arena (int x, int y) {
    initscr();
    noecho();
    curs_set(FALSE);
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
/*
  if (this->area[i][j].getSig() == -1) {
                if (i +1 < this->x) {
                    this->area[(i + 1 )% this->x] [j] = this->area[i][j]; 
                    this->area[i][j] = e;
*/

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

    for(int j = 0; j < this->x; ++j) {
        for(int k = 0; k < this->y; ++k) {            
            //std::cout << this->area[j][k].getSig() << ' ';
            refresh();
           // wrefresh(stdscr);
           this->placeEnemy();
           switch (this->area[j][k].getSig()) {
                case 0:
                    break;
                case 1:
                    break;
                case 2:
                    if (this->area[j][k].getDirection() == 'u')// and not  this->area[j][k].getMoved())
                    {
                       /* if (k > 0 and this->area[j][k - 1].isAlive() and this->area[j][k - 1].getSig() != 1 )
                        {
                            this->area[j][k - 1] = placeholder;                            
                        }
                        else if ( not this->area[j][k-1].isAlive())
                        {
                            this->area[j][k-1] = this->area[j][k];
                        }*/
                        //this->area[j][k-1] = this->area[j][k];
                        this->area[j][k] = placeholder;
                        //this->area[j][k-1].setMoved();
                        //return;
                                        
                    }
                    /*if (this->area[j][k].getDirection() == 'd' )
                    {
                         if (k < this->y and  this->area[j][k + 1].isAlive() and this->area[j][k - 1].getSig() != -1)
                        {
                            this->area[j][k+1] = placeholder;                            
                        }
                        else if ( not this->area[j][k+1].isAlive())
                        {
                           this->area[j][k+1] = this->area[j][k]; 
                        }
                    
                        this->area[j][k] = placeholder;
                    }*/
                   // this->area[j][k] = placeholder;
                    break;
                default:
                    break;

            }
        }
    }
}

GameEntity** Arena :: get_area() {
    return this->area;
}

void Arena::moveLeft() {
    Empty e;
    for (int i = 0; i < this->x ; i++) {
        for (int j = 0; j < this->y ; j++) {
            if (this->area[i][j].getSig() == 1) {
                this->area[i][(j - 1) % this->y] = this->area[i][j]; 
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
                        check = rand() % 2; 
                        if (check == 1)
                        {
                            e = Bullet('d');          
                            this->area[i + 1][j] = e;
                        }
                    }
                }
            }  
        }
}

void Arena :: display()
{
 
    addstr("ss1");
    clear();
    while (true){
    this->eval();
   // this->spawn_bullet(false);
    for (int i = 0; i < this->x; i++)
    {
        for (int j = 0; j  < this->y; j++)
        {
          //  box(stdscr,0,0);
               // std::cout << "before switch" << std::endl;  
            switch(this->area[i][j].getSig())
            {
                addstr("ss");
                    //std::cout << "before case" << std::endl;
                case 0:
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
               // mvprintw(i * 5, i * 5, "Hello, world!");
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
        napms(600);
        clear();
    }    
}

void Arena :: placeEnemy()
{
    Enemy  e;
    Empty a;
    bool place = false;  
     for (int i = 0; i < this->x; i++)
    {
        for (int j = 0; j  < this->y; j++)
        {
            if (this->area[i][j].getSig() == -1)
            {
                if (not place and i + 1 < this->x and this->area[i + 1][j].getSig() == 0)
                {
                    this->area[i + 1][j]  = this->area[i][j];
                    place = true;
                }
                if (not place and j + 1 < this->y and this->area[i][j+1].getSig() == 0)
                {
                    this->area[i][j+1]  = this->area[i][j];
                    place = true;
                }
                if (place )
                    return ;
            }
        }
    }
}