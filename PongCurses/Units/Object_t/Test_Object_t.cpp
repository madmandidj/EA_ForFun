#include <iostream>
#include <assert.h>
#include "../Pixel/Pixel.hpp"
#include "Object_t.hpp"

static unsigned int WIN_WIDTH = 10;
static unsigned int WIN_HEIGHT = 10;

int main()
{
    Object_t ball(Object_t::BALL);
    Object_t::SharedPixelPtr pixel1 = ball.CreatePixel(5, 5, '*');
    Object_t::SharedPixelPtr pixel2 = ball.CreatePixel(6, 5, '*');

    assert(ball.GetNumOfPixels() == 2);
    assert(pixel1 == ball.GetPixel(0));

    std::cout << *ball.GetPixel(0);
    std::cout << *ball.GetPixel(1);
    ball.Move(1, Object_t::ObjMoveDirection::U, WIN_WIDTH, WIN_HEIGHT);
    std::cout << *ball.GetPixel(0);
    std::cout << *ball.GetPixel(1);
    ball.Move(1, Object_t::ObjMoveDirection::R, WIN_WIDTH, WIN_HEIGHT);
    std::cout << *ball.GetPixel(0);
    std::cout << *ball.GetPixel(1);
    assert (false == ball.Move(10, Object_t::ObjMoveDirection::U, WIN_WIDTH, WIN_HEIGHT));
    assert (false == ball.Move(10, Object_t::ObjMoveDirection::D, WIN_WIDTH, WIN_HEIGHT));
    assert (false == ball.Move(10, Object_t::ObjMoveDirection::L, WIN_WIDTH, WIN_HEIGHT));
    assert (false == ball.Move(10, Object_t::ObjMoveDirection::R, WIN_WIDTH, WIN_HEIGHT));
    std::cout << *ball.GetPixel(0);
    std::cout << *ball.GetPixel(1);
    std::cout << std::endl << "Object_t PASSED TESTS" << std::endl << std::endl;
    return 0;
}
