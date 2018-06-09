#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

#include "Arena.hpp"


int main()
{
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

    a.eval();

    std :: cout <<  std :: endl << std ::endl <<  std ::endl;
  //  a.moveLeft();
    a.moveRight();
    a.eval();
    return 0;
}