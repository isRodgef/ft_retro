#include "Arena.hpp"
#include <iostream>

Arena :: Arena()
{

}


//0 empty
//1 player
//-1 enemy 
//2 bullet
Arena :: Arena (int x, int y)
{
    this->x = x;
    this->y = y;
    this->area = new short*[x];
    for (int i = 0; i < y; i++)
        this->area[i] =new short[y];

    for(int j = 0; j < this->x; ++j){
        for(int k = 0; k < this->y; ++k){            
            this->area[j][k] = 0;
            std::cout << this->area[j][k];
        }
    }
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