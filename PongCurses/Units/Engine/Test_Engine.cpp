#include <unistd.h>
#include "Engine.hpp"
#include "../Window/Window.hpp"
#include "../Object_t/Object_t.hpp"
static unsigned int WIN_WIDTH = 140;
static unsigned int WIN_HEIGHT = 35;

int main()
{
    Engine engine;
    engine.CreateWindow(WIN_WIDTH, WIN_HEIGHT, Window::Window_ID::PLAY_WIN, 0, 0); 
    Engine::WindowSharedPtr playWin = engine.GetWindow(Window::Window_ID::PLAY_WIN);
    // Window win_1(WIN_WIDTH, WIN_HEIGHT, Window::PLAY_WIN);
    Window::SharedObjectPtr ballPtr = playWin->CreateObject(Object_t::Object_ID::BALL);
    ballPtr->CreatePixel(5, 5, '*');
    ballPtr->CreatePixel(6, 5, '*');
    engine.RefreshScreen();
    usleep(100000);
    for (int index = 0; index < 250; ++index)
    {
        ballPtr->Move(1, Object_t::ObjMoveDirection::D, playWin->GetWidth(), playWin->GetHeight());
        engine.RefreshScreen();
        usleep(10000);
    }
    engine.DeleteScreen();
    std::cout << std::endl << "Engine PASSED TESTS" << std::endl << std::endl;
    return 0;
}