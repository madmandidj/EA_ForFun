#ifndef __PCURSES_PIXEL_HPP__
#define __PCURSES_PIXEL_HPP__
#include<iostream>
#include "../Coordinate/Coordinate.hpp"

class Pixel
{
public:
    Pixel(unsigned int _x, unsigned int _y, unsigned char _pixelChar);
    ~Pixel();
    unsigned char GetChar() const;
    void SetChar(unsigned char _newChar);
    unsigned int GetX() const;
    void SetX(unsigned int _x) {m_coordinate.SetY(_x);} // Y is row
    unsigned int GetY() const;
    void SetY(unsigned int _y){m_coordinate.SetX(_y);} // X is column
    bool operator<(const Pixel& _otherPixel) const;
    bool operator==(const Pixel& _otherPixel) const;
protected:

private:
    unsigned char m_pixelChar;
    Coordinate m_coordinate;
};

std::ostream& operator<< (std::ostream& _os, const Pixel& _pixel);




#endif //#ifndef __PCURSES_PIXEL_HPP__
