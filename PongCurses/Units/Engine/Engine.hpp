#ifndef __PCURSES_ENGINE_HPP__
#define __PCURSES_ENGINE_HPP__
#include <curses.h>
#include <iostream>
#include <map>
#include <tr1/memory>
#include "../Window/Window.hpp"
#include "../Object_t/Object_t.hpp"
#include "../Pixel/Pixel.hpp"

class Engine
{
    
public:
    typedef std::tr1::shared_ptr<Window> WindowSharedPtr;
    Engine();
    ~Engine();
    WindowSharedPtr CreateWindow(unsigned int _width, unsigned int _height, Window::Window_ID _windowID,
        unsigned int _offsetWidth, unsigned int _offsetHeight);
    WindowSharedPtr GetWindow(Window::Window_ID _windowID);
    void RefreshScreen();
    void DeleteScreen();
protected:

private:
    Engine(const Engine& _engine);
    Engine& operator=(const Engine& _engine);
private:
    std::map<Window::Window_ID, WindowSharedPtr> m_windowContainer;
    std::map<Window::Window_ID, WINDOW*> m_curseWinContainer;
};




#endif //#ifndef __PCURSES_ENGINE_HPP__
