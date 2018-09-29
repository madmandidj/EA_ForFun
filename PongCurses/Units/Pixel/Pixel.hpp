#ifndef __PCURSES_PIXEL_HPP__
#define __PCURSES_PIXEL_HPP__
#include<iostream>
#include "../Coordinate/Coordinate.hpp"

class Pixel
{
public:
    Pixel(unsigned int _x, unsigned int _y, unsigned int _pixelID);
    Pixel(Coordinate _coordinate, unsigned int _pixelID);
    ~Pixel();
    unsigned char GetChar() const;
    void SetChar(unsigned char _newChar);
    unsigned int GetX() const;
    unsigned int GetY() const;
    unsigned int GetID() const;
    bool operator<(const Pixel& _otherPixel) const;
    bool operator==(const Pixel& _otherPixel) const;
protected:

private:
    unsigned char m_pixelChar;
    const Coordinate m_coordinate;
    const unsigned int m_pixelID;
};

std::ostream& operator<< (std::ostream& _os, const Pixel& _pixel);




#endif //#ifndef __PCURSES_PIXEL_HPP__
