#ifndef __PCURSES_WINDOW_HPP__
#define __PCURSES_WINDOW_HPP__
#include <iostream>
#include <map>
#include <tr1/memory>
#include "../Object_t/Object_t.hpp"
#include "../Pixel/Pixel.hpp"

class Window
{
    
public:
    typedef std::tr1::shared_ptr<Object_t> SharedObjectPtr;
    typedef enum
    {
        MASTER_WIN = 0,
        PLAY_WIN,
        MENU_WIN
    }Window_ID;
    Window(unsigned int _width, unsigned int _height, Window_ID _windowID);
    ~Window();
    bool operator<(const Window& _otherWindow) const;
    bool operator==(const Window& _otherWindow) const;
    Window_ID GetWindowID() const;
    unsigned int GetWidth() const;
    unsigned int GetHeight() const;
    unsigned int GetNumOfPixels() const;
    SharedObjectPtr CreateObject(Object_t::Object_ID _objectID);
    SharedObjectPtr RemoveObject(Object_t::Object_ID _objectID);
    SharedObjectPtr GetObject(Object_t::Object_ID _objectID);
    unsigned int GetNumOfObjects() const;
protected:

private:
    Window();
    const unsigned int m_width;
    const unsigned int m_height;
    const Window_ID m_windowID;
    std::map<Object_t::Object_ID, SharedObjectPtr> m_objectContainer;
};

std::ostream& operator<<(std::ostream& _os, const Window& _window);





#endif //#ifndef __PCURSES_WINDOW_HPP__
