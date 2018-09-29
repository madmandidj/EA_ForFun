#include <iostream>
#include "Object_t.hpp"
#include "../Window/Window.hpp"
#include "../Pixel/Pixel.hpp"

static unsigned int WIN_WIDTH = 140;
static unsigned int WIN_HEIGHT = 35;
static unsigned int BALL_WIDTH = 2;
static unsigned int BALL_HEIGHT = 2;


int main()
{
    Window win_1(WIN_WIDTH, WIN_HEIGHT, Window::PLAY_WIN);
    Object_t ball(Object_t::BALL, win_1);
    Pixel pixel_1(10, 11, win_1.GetPixelID(10, 11));
    Pixel pixel_2(10, 12, win_1.GetPixelID(10, 12));
    Pixel pixel_3(11, 11, win_1.GetPixelID(11, 11));
    Pixel pixel_4(11, 12, win_1.GetPixelID(11, 12));

    pixel_1.SetChar('*');
    pixel_2.SetChar('*');
    pixel_3.SetChar('*');
    pixel_4.SetChar('*');
    ball.AddPixel(pixel_1.GetID());
    ball.AddPixel(pixel_2.GetID());
    ball.AddPixel(pixel_3.GetID());
    ball.AddPixel(pixel_4.GetID());
    std::cout << ball << std::endl;
    ball.Move(1, Object_t::R);
    std::cout << ball << std::endl;
    std::cout << std::endl << "Object_t PASSED TESTS" << std::endl << std::endl;
    return 0;
}
