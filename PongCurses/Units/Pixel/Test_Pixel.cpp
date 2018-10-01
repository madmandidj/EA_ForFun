#include <iostream>
#include <assert.h>
#include "../Coordinate/Coordinate.hpp"
#include "Pixel.hpp"

#define NUM_OF_X 100
#define NUM_OF_Y 100

int main()
{

    unsigned int numOfPixels = NUM_OF_X * NUM_OF_Y;
    Pixel* pixelArr[NUM_OF_X][NUM_OF_Y];
    for (size_t curX = 0; curX < NUM_OF_X; ++curX)
    {
        for (size_t curY = 0; curY < NUM_OF_Y; ++curY)
        {
            pixelArr[curX][curY] = new Pixel(curX, curY, ' ');
            assert (pixelArr[curX][curY]->GetX() == curX);
            assert (pixelArr[curX][curY]->GetY() == curY);
            assert (pixelArr[curX][curY]->GetChar() == ' ');
            pixelArr[curX][curY]->SetChar('*');
            assert (pixelArr[curX][curY]->GetChar() == '*');
        }
    }

    for (size_t curX = 0; curX < NUM_OF_X; ++curX)
    {
        for (size_t curY = 0; curY < NUM_OF_Y; ++curY)
        {
            Pixel tempPixel(curX, curY, ' ');
            assert(*pixelArr[curX][curY] == tempPixel);
        }
    }

    for (size_t curPixel = 0; curPixel < numOfPixels; ++curPixel)
    {
        assert(pixelArr[curPixel] < pixelArr[curPixel + 1]);
    }

    for (size_t curX = 0; curX < NUM_OF_X; ++curX)
    {
        for (size_t curY = 0; curY < NUM_OF_Y; ++curY)
        {
            delete pixelArr[curX][curY];
        }
    }

    std::cout << std::endl << "Pixel PASSED TESTS" << std::endl << std::endl;
    return 0;
}


