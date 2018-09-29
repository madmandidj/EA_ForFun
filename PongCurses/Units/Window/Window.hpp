#ifndef __PCURSES_WINDOW_HPP__
#define __PCURSES_WINDOW_HPP__
#include <iostream>
#include "../Pixel/Pixel.hpp"
#include <map>

class Window
{
public:
    typedef enum
    {
        MASTER_WIN,
        PLAY_WIN,
        MENU_WIN
    }Window_ID;
    Window(Window_ID _windowID);
    Window(unsigned int _width, unsigned int _height, Window_ID _windowID);
    ~Window();
    bool operator<(const Window& _otherWindow) const;
    bool operator==(const Window& _otherWindow) const;
    Window_ID GetWindowID() const;
    unsigned int GetWidth() const;
    unsigned int GetHeight() const;
    unsigned int GetNumOfPixels() const;
    int GetPixelID(unsigned int _x, unsigned int _y);
    unsigned char GetPixelChar(unsigned int _pixelID);
    void SetPixelChar(unsigned int _pixelID, unsigned char _newChar); 
protected:

private:
    const unsigned int m_width;
    const unsigned int m_height;
    const Window_ID m_windowID;
    std::map<unsigned int, Pixel* const> m_pixelContainer;
};

std::ostream& operator<<(std::ostream&, const Window& _window);





#endif //#ifndef __PCURSES_WINDOW_HPP__
