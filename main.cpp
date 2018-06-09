#include <iostream>

#include "Arena.hpp"


int main()
{
   Arena a(10,10);
   std::cout << "after a" << std::endl; 

   a.eval();
    return 0;
}