#include <curses.h>
#include "Engine.hpp"

Engine::Engine()
{
    initscr();
    noecho();
    cbreak();
    timeout(100);
    printw("PongCurses Test ! ! : - ) ");
    refresh();
}

Engine::~Engine()
{
    m_windowContainer.clear();
    // std::map<Window::Window_ID, WINDOW*>::iterator it = m_curseWinContainer.begin();
    // std::map<Window::Window_ID, WINDOW*>::iterator end = m_curseWinContainer.end();
    // while (it != end)
    // {
    //     delwin(it->second);
    // }
    m_curseWinContainer.clear();
    endwin();
}

Engine::WindowSharedPtr Engine::CreateWindow(unsigned int _width, unsigned int _height, Window::Window_ID _windowID,
    unsigned int _offsetWidth, unsigned int _offsetHeight)
{
    WindowSharedPtr newWindow(new Window(_width, _height, _windowID));
    m_windowContainer.insert(std::pair<Window::Window_ID, WindowSharedPtr>(_windowID, newWindow));
    WINDOW* newCursesWin = newwin(_height, _width, _offsetHeight, _offsetWidth);
    m_curseWinContainer.insert(std::pair<Window::Window_ID, WINDOW*>(_windowID, newCursesWin));
    return newWindow;
}

Engine::WindowSharedPtr Engine::GetWindow(Window::Window_ID _windowID)
{
    return m_windowContainer.find(_windowID)->second;
}

void Engine::RefreshScreen()
{
    std::map<Window::Window_ID, WindowSharedPtr>::iterator winItr = m_windowContainer.begin();
    std::map<Window::Window_ID, WINDOW*>::iterator cursesWinItr = m_curseWinContainer.begin();
    std::map<Window::Window_ID, WindowSharedPtr>::iterator winItrEnd = m_windowContainer.end();
    std::map<Window::Window_ID, WINDOW*>::iterator cursesWinItrEnd = m_curseWinContainer.end();
    curs_set(0);
    while (winItr != winItrEnd)
    {
        werase(cursesWinItr->second);
        box(cursesWinItr->second, 0 , 0);
        wrefresh(cursesWinItr->second);

        // std::map<Object_t::Object_ID, SharedObjectPtr>::iterator objItr = 


        size_t numOfObjects = winItr->second->GetNumOfObjects();
        unsigned int curObjectID = 0;
        unsigned int curObjectNum = 0;
        while (curObjectNum < numOfObjects)
        {
            WindowSharedPtr curWin = winItr->second;
            if ( 0 == curWin->GetObject((Object_t::Object_ID)curObjectID))
            {
                ++curObjectID;
                continue;
            }
            Window::SharedObjectPtr curObjectPtr =  winItr->second->GetObject((Object_t::Object_ID)curObjectID);
            size_t numOfPixels = curObjectPtr->GetNumOfPixels();
            for(unsigned int curPixel = 0; curPixel < numOfPixels; ++curPixel)
            {
                Object_t::SharedPixelPtr curPixelPtr = curObjectPtr->GetPixel(curPixel);
                mvwaddch(cursesWinItr->second, curPixelPtr->GetX(), curPixelPtr->GetY(), curPixelPtr->GetChar());
            }
            ++curObjectID;
            ++curObjectNum;
        }
        wrefresh(cursesWinItr->second);
        ++winItr;
        ++cursesWinItr;
    }
}

void Engine::DeleteScreen()
{
    std::map<Window::Window_ID, WINDOW*>::iterator it = m_curseWinContainer.begin();
    std::map<Window::Window_ID, WINDOW*>::iterator end = m_curseWinContainer.end();
    while (it != end)
    {
        werase(it->second);
        box(it->second, 0 , 0);
        wrefresh(it->second);
        delwin(it->second);
        ++it;
    }
    endwin();
}

