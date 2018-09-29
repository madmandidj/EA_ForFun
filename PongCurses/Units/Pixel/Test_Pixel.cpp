#include <iostream>
#include <assert.h>
#include "Pixel.hpp"
#include "../Coordinate/Coordinate.hpp"


int main()
{
    unsigned int x1 = 10;
    unsigned int y1 = 10;
    unsigned int x2 = 17;
    unsigned int y2 = 17;
    Coordinate coord_1(x1,y1);
    Coordinate coord_2(coord_1);
    Coordinate coord_3(x2,y2);
    unsigned int id_1 = 10;
    unsigned int id_2 = 20;
    unsigned int id_3 = 30;

    Pixel pixel_1(x1, y1, id_1);
    Pixel pixel_2(coord_2, id_2);
    Pixel pixel_3(x2, y2, id_3);
    Pixel pixel_4(x2, y2, id_3);

    assert(id_1 == pixel_1.GetID() && id_2 == pixel_2.GetID() && id_3 == pixel_3.GetID());
    assert(pixel_1.GetID() < pixel_2.GetID() && pixel_2.GetID() < pixel_3.GetID());
    assert(x1 == pixel_2.GetX() && y1 == pixel_2.GetY() && x2 == pixel_3.GetX() && y2 == pixel_3.GetY());
    assert(pixel_3 == pixel_4);
    pixel_4.SetChar('*');
    assert('*' == pixel_4.GetChar());
    std::cout << std::endl << "Pixel PASSED TESTS" << std::endl << std::endl;
    return 0;
}
