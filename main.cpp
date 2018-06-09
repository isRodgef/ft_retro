#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

#include "Arena.hpp"


int main()
{
    srand(0);
    /*
    initscr();
    noecho();
    curs_set(FALSE);

    mvprintw(0, 0, "Hello, world!");
    while (true)
    {
        getch();
        refresh();
    }

  
    endwin();*/
    Arena a(10,10);

    a.spawn_bullet(true);
    a.spawn_bullet(false);
    a.spawn_bullet(false);
    a.eval();

    std :: cout <<  std :: endl << std ::endl <<  std ::endl;
  //  a.moveLeft();
    a.moveRight();
    a.eval();
    std :: cout <<  std :: endl << std ::endl <<  std ::endl;
    a.eval();
    std :: cout <<  std :: endl << std ::endl <<  std ::endl;
    a.eval();
    std :: cout <<  std :: endl << std ::endl <<  std ::endl;
    return 0;
}