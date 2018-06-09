#include <ncurses.h>


#include "render.hpp"
#include "Arena.hpp"

Render(Arena g)
{
    initscr();
    noecho();
    curs_set(FALSE);
}

void Render :: eval()
{
    while (true)
    {
        getch();
        this->g.eval()
        
    }
}

Render :; ~Render()
{
    endwin(); 
}
