#include <unistd.h>
#include "Engine.hpp"
#include "../Window/Window.hpp"
#include "../Object_t/Object_t.hpp"
static unsigned int PLAYWIN_WIDTH = 140;
static unsigned int PLAYWIN_HEIGHT = 35;

void CreateBall();
void CreateBrickL();
void CreateBrickR();


int main()
{
    Engine engine;
    engine.CreateWindow(PLAYWIN_WIDTH, PLAYWIN_HEIGHT, Window::Window_ID::PLAY_WIN, 0, 0); 
    Engine::WindowSharedPtr playWin = engine.GetWindow(Window::Window_ID::PLAY_WIN);
    Window::SharedObjectPtr ballPtr = playWin->CreateObject(Object_t::Object_ID::BALL);
    ballPtr->CreatePixel(1, 5, '*');

    Window::SharedObjectPtr brickLPtr = playWin->CreateObject(Object_t::Object_ID::BRICK_L);
    brickLPtr->CreatePixel(2,2,' ');
    brickLPtr->CreatePixel(3,2,'=');
    brickLPtr->CreatePixel(4,2,' ');
    brickLPtr->CreatePixel(2,3,'|');
    brickLPtr->CreatePixel(3,3,' ');
    brickLPtr->CreatePixel(4,3,'|');
    brickLPtr->CreatePixel(2,4,'|');
    brickLPtr->CreatePixel(3,4,' ');
    brickLPtr->CreatePixel(4,4,'|');
    brickLPtr->CreatePixel(2,5,'|');
    brickLPtr->CreatePixel(3,5,' ');
    brickLPtr->CreatePixel(4,5,'|');
    brickLPtr->CreatePixel(2,6,'|');
    brickLPtr->CreatePixel(3,6,' ');
    brickLPtr->CreatePixel(4,6,'|');
    brickLPtr->CreatePixel(2,7,' ');
    brickLPtr->CreatePixel(3,7,'=');
    brickLPtr->CreatePixel(4,7,' ');

    Window::SharedObjectPtr brickRPtr = playWin->CreateObject(Object_t::Object_ID::BRICK_R);
    brickRPtr->CreatePixel(135,2,' ');
    brickRPtr->CreatePixel(136,2,'=');
    brickRPtr->CreatePixel(137,2,' ');
    brickRPtr->CreatePixel(135,3,'|');
    brickRPtr->CreatePixel(136,3,' ');
    brickRPtr->CreatePixel(137,3,'|');
    brickRPtr->CreatePixel(135,4,'|');
    brickRPtr->CreatePixel(136,4,' ');
    brickRPtr->CreatePixel(137,4,'|');
    brickRPtr->CreatePixel(135,5,'|');
    brickRPtr->CreatePixel(136,5,' ');
    brickRPtr->CreatePixel(137,5,'|');
    brickRPtr->CreatePixel(135,6,'|');
    brickRPtr->CreatePixel(136,6,' ');
    brickRPtr->CreatePixel(137,6,'|');
    brickRPtr->CreatePixel(135,7,' ');
    brickRPtr->CreatePixel(136,7,'=');
    brickRPtr->CreatePixel(137,7,' ');
    
    engine.RefreshScreen();
    usleep(100000);
    for (int index = 0; index < 120; ++index)
    {
        ballPtr->Move(1, Object_t::ObjMoveDirection::R, playWin->GetWidth(), playWin->GetHeight());
        if (0 == index % 4)
        {
            brickRPtr->Move(1, Object_t::ObjMoveDirection::D, playWin->GetWidth(), playWin->GetHeight());
            brickLPtr->Move(1, Object_t::ObjMoveDirection::D, playWin->GetWidth(), playWin->GetHeight());
            ballPtr->Move(1, Object_t::ObjMoveDirection::D, playWin->GetWidth(), playWin->GetHeight());
            if (0 == index % 6)
            {
                brickRPtr->Move(1, Object_t::ObjMoveDirection::U, playWin->GetWidth(), playWin->GetHeight());
            }
        }
        engine.RefreshScreen();
        usleep(10000);
    }
    sleep(1);
    engine.DeleteScreen();
    std::cout << std::endl << "Engine PASSED TESTS" << std::endl << std::endl;
    return 0;
}