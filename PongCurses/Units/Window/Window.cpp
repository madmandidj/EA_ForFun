#include <iostream>
#include "Window.hpp"
#include "../Pixel/Pixel.hpp"

Window::Window(Window::Window_ID _windowID) : 
    m_width(0), m_height(0), m_windowID(_windowID)
{

}

Window::Window(unsigned int _width, unsigned int _height, Window::Window_ID _windowID) :
    m_width(_width), m_height(_height), m_windowID(_windowID)
{
    // m_window = newwin(static_cast<int>(_height), static_cast<int>(_width), static_cast<int>(_offsetY), static_cast<int>(_offsetX));
    unsigned int curPixelID = 0;
    for (unsigned int curY = 0; curY < m_height; ++curY)
    {
        for (unsigned int curX = 0; curX < m_width; ++curX)
        {
            Coordinate curCoord(curX, curY);
            Pixel* const curPixel = new Pixel(curCoord, curPixelID);
            m_pixelContainer.insert(std::pair<unsigned int, Pixel* const>(curPixelID, curPixel));
            ++curPixelID;
        }
    }
}

Window::~Window()
{
    // if (this->m_window)
    // {
        std::map<unsigned int, Pixel* const>::iterator begin = m_pixelContainer.begin();
        std::map<unsigned int, Pixel* const>::iterator end = m_pixelContainer.end();
        while(begin != end)
        {
            delete begin->second;
            m_pixelContainer.erase(begin);
            begin = m_pixelContainer.begin();
        }
    //     delwin(this->m_window);
    // }
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
    return m_pixelContainer.size();
}

int Window::GetPixelID(unsigned int _x, unsigned int _y)
{
    if ((_x >= m_width) || (_y >= m_height))
    {
        return -1;
    }
    return (int)((_y * m_width) + _x);
}

unsigned char Window::GetPixelChar(unsigned int _pixelID)  
{
    //TODO: throw exception of coordinate is invalid or if character is invalid
    Coordinate curCoord(0, 0);
    Pixel curPixel(curCoord, _pixelID);
    std::map<unsigned int, Pixel* const>::iterator it = m_pixelContainer.find(_pixelID);
    return it->second->GetChar();
}

void Window::SetPixelChar(unsigned int _pixelID, unsigned char _newChar) 
{
    //TODO: throw exception of coordinate is invalid or if character is invalid
    Coordinate curCoord(0, 0);
    Pixel curPixel(curCoord, _pixelID);
    std::map<unsigned int, Pixel* const>::iterator it = m_pixelContainer.find(_pixelID);
    it->second->SetChar(_newChar);
}

std::ostream& operator<<(std::ostream& _os, const Window& _window)
{
    unsigned int numOfRows = _window.GetHeight();
    unsigned int numOfCols = _window.GetWidth();

    _os << std::endl;
    for (unsigned int curRow = 0; curRow < numOfRows; ++curRow)
    {
        _os << std::endl;
        for (unsigned int curCol = 0; curCol < numOfCols; ++curCol)
        {
            if (0 == curRow)
            {
                _os << const_cast<Window&>(_window).GetPixelChar(curCol);
            }
            else
            {
                _os << const_cast<Window&>(_window).GetPixelChar((numOfCols * curRow) + curCol);
            }
        }
    }
    _os << std::endl;
    return _os;
}
