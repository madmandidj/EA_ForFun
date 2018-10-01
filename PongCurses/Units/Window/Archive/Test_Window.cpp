#include <iostream>
#include <unistd.h>
#include "Window.hpp"
#include "../Pixel/Pixel.hpp"

static unsigned int WIN_WIDTH = 140;
static unsigned int WIN_HEIGHT = 35;

int main()
{
    Window win_1(WIN_WIDTH, WIN_HEIGHT, Window::PLAY_WIN);
    win_1.SetPixelChar(400, '*');
    assert(' ' == win_1.GetPixelChar(399));
    assert('*' == win_1.GetPixelChar(400));
    assert(WIN_HEIGHT * WIN_WIDTH == win_1.GetNumOfPixels());
    std::cout << win_1.GetPixelID(139, 34);
    // for (unsigned int i = 0; i < win_1.GetNumOfPixels(); ++i)
    // {
    //     if (i%2 == 0)
    //     {
    //         win_1.SetPixelChar(i, '*');
    //     }
    // }
    // std::cout << win_1;
    std::cout << std::endl << "Window PASSED TESTS" << std::endl << std::endl;
    return 0;
}

