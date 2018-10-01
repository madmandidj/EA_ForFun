#include <iostream>
#include <map>
#include<memory>
#include "../Object_t/Object_t.hpp"
#include "../Pixel/Pixel.hpp"
#include "Window.hpp"

// Window::Window(Window::Window_ID _windowID) : 
//     m_width(0), m_height(0), m_windowID(_windowID)
// {

// }

Window::Window(unsigned int _width, unsigned int _height, Window::Window_ID _windowID) :
    m_width(_width), m_height(_height), m_windowID(_windowID)
{
}

Window::~Window()
{
    // unsigned int numOfObjects = m_objectContainer.size();
    // std::map<Object_t::Object_ID, SharedObjectPtr>::iterator begin = m_objectContainer.begin();
    // std::map<Object_t::Object_ID, SharedObjectPtr>::iterator begin = m_objectContainer.end();
    // while (begin != end)
    // {
    //     SharedObjectPtr curObj = begin->second;
    //     std::map<Object_t::Object_ID, SharedObjectPtr>::iterator next = std::next(it);
    //     delete curObj;
    //     m_objectContainer.erase(begin->second);
    //     begin = next;
    // }
    // // std::map<unsigned int, Pixel* const>::iterator begin = m_pixelContainer.begin();
    // // std::map<unsigned int, Pixel* const>::iterator end = m_pixelContainer.end();
    // // while(begin != end)
    // // {
    // //     delete begin->second;
    // //     m_pixelContainer.erase(begin);
    // //     begin = m_pixelContainer.begin();
    // // }
    m_objectContainer.clear();
}

bool Window::operator<(const Window& _otherWindow) const 
{
    return m_windowID < _otherWindow.m_windowID;
}

bool Window::operator==(const Window& _otherWindow) const 
{
    return m_windowID == _otherWindow.m_windowID;
}

Window::Window_ID Window::GetWindowID() const 
{
    return m_windowID;
}

unsigned int Window::GetWidth() const 
{
    return m_width;
}

unsigned int Window::GetHeight() const 
{
    return m_height;
}

unsigned int Window::GetNumOfPixels() const
{
    return m_width * m_height;
}

Window::SharedObjectPtr Window::CreateObject(Object_t::Object_ID _objectID)
{
    SharedObjectPtr newObject (new Object_t(_objectID));
    m_objectContainer.insert(std::pair<Object_t::Object_ID, SharedObjectPtr>(_objectID, newObject));
    return newObject;
}

// SharedObjectPtr* const Window::RemoveObject(Object_t::Object_ID _objectID)
// {

// }

Window::SharedObjectPtr Window::GetObject(Object_t::Object_ID _objectID)
{
    if (m_objectContainer.find(_objectID) != m_objectContainer.end())
    {
        return m_objectContainer.find(_objectID)->second;
    }
    return Window::SharedObjectPtr();
}

unsigned int Window::GetNumOfObjects() const
{
    return m_objectContainer.size();
}



std::ostream& operator<<(std::ostream& _os, const Window& _window)
{
    unsigned int numOfObjects = _window.GetNumOfObjects();
    unsigned int curNumOfObjects = 0;
    unsigned int curObjectID = 0;
    while(curNumOfObjects < numOfObjects)
    {
        Window::SharedObjectPtr curObjectPtr = const_cast<Window&>(_window).GetObject((Object_t::Object_ID)curObjectID);
        if (!curObjectPtr)
        {
            ++curObjectID;
            continue;
        }
        _os << *curObjectPtr;
        ++curObjectID;
        ++curNumOfObjects;
    }
    // std::map<Object_t::Object_ID, Window::SharedObjectPtr>::iterator it = m_objectContainer.begin();
    // std::map<Object_t::Object_ID, Window::SharedObjectPtr>::iterator end = m_objectContainer.end();
    // while (it != end)
    // {
    //     unsigned int numOfPixels = it->second->GetNumOfPixels();
    //     for (size_t curPixel = 0; curPixel < numOfPixels; ++curPixel)
    //     {
    //         _os << it->second->GetPixel(curPixel);
    //     }
    // }

    return _os;
}
