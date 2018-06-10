#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <csignal>

#include "Arena.hpp"





int main()
{
    srand(0);
   /* initscr();
    noecho();
    curs_set(FALSE);

    mvprintw(0, 0, "Hello, world!");*/
  /*  while (true)
    {
        getch();
        mvprintw(1, 322, "Hello, world!");
        refresh();
    }*/

  
    Arena a(10,10);
    std::signal(SIGSEGV, a.gameover);
    /*a.spawn_bullet(true);
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
    endwin();*/

    a.display();
    return 0;
}