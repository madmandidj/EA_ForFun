#include <iostream>
#include <unistd.h>
#include "Window.hpp"
#include "../Pixel/Pixel.hpp"

static unsigned int WIN_WIDTH = 140;
static unsigned int WIN_HEIGHT = 35;

int main()
{
    Window win_1(WIN_WIDTH, WIN_HEIGHT, Window::PLAY_WIN);
    Window::SharedObjectPtr ballPtr = win_1.CreateObject(Object_t::Object_ID::BALL);
    ballPtr->CreatePixel(5, 5, '*');
    ballPtr->CreatePixel(6, 5, '*');
    std::cout << win_1;
    ballPtr->Move(1, Object_t::ObjMoveDirection::R, WIN_WIDTH, WIN_HEIGHT);
    std::cout << win_1;
    ballPtr->Move(2, Object_t::ObjMoveDirection::L, WIN_WIDTH, WIN_HEIGHT);
    std::cout << win_1;
    std::cout << std::endl << "Window PASSED TESTS" << std::endl << std::endl;
    return 0;
}

