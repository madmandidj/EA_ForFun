#include<iostream>
#include<assert.h>
#include "Coordinate.hpp"

#define  NUM_OF_X 10
#define NUM_OF_Y 3

int main()
{
    unsigned int numOfCoords = NUM_OF_X * NUM_OF_Y;
    Coordinate* coordsArr[NUM_OF_X][NUM_OF_Y];
    for (size_t curX = 0; curX < NUM_OF_X; ++curX)
    {
        for (size_t curY = 0; curY < NUM_OF_Y; ++curY)
        {
            coordsArr[curX][curY] = new Coordinate(curX, curY);
            assert(coordsArr[curX][curY]->GetX() == curX);
            assert(coordsArr[curX][curY]->GetY() == curY);
        }
    }

    for (size_t curCoord = 0; curCoord < numOfCoords - 1; ++curCoord)
    {
        assert(coordsArr[curCoord] < coordsArr[curCoord + 1]);
    }

    for (size_t curX = 0; curX < NUM_OF_X; ++curX)
    {
        for (size_t curY = 0; curY < NUM_OF_Y; ++curY)
        {
            delete coordsArr[curX][curY];
        }
    }

    std::cout << std::endl << "Coordinate PASSED TESTS" << std::endl << std::endl;
    return 0;
}


