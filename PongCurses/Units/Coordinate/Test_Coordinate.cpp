#include<iostream>
#include<assert.h>
#include "Coordinate.hpp"


int main()
{
    unsigned int x1 = 10;
    unsigned int y1 = 10;
    unsigned int x2 = 17;
    unsigned int y2 = 17;
    Coordinate coord_1(x1,y1);
    Coordinate coord_2(coord_1);
    Coordinate coord_3(x2,y2);

    assert(coord_1 == coord_2);
    assert(!(coord_2 == coord_3));
    assert(x1 == coord_2.GetX());
    assert(y1 == coord_2.GetY());
    assert(x2 == coord_3.GetX());
    assert(y2 == coord_3.GetY());
    std::cout << std::endl << "Coordinate PASSED TESTS" << std::endl << std::endl;
    return 0;
}


