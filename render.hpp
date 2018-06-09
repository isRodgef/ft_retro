#ifndef RENDER_HPP
#define RENDER_HPP 

#include <ncurses.h>

#include "Arena.hpp"

class Render
{
    public:
        Render(Arena g);
        ~Render();
};

#endif