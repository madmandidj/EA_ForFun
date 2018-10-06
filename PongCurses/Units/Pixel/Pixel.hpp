#ifndef __PCURSES_PIXEL_HPP__
#define __PCURSES_PIXEL_HPP__
#include<iostream>
#include "../Coordinate/Coordinate.hpp"

class Pixel
{
public:
    Pixel(unsigned int _column, unsigned int _row, unsigned char _pixelChar);
    ~Pixel();
    unsigned char GetChar() const;
    void SetChar(unsigned char _newChar);
    unsigned int GetRow() const;
    void SetRow(unsigned int _column);
    unsigned int GetColumn() const;
    void SetColumn(unsigned int _row);
    bool operator<(const Pixel& _otherPixel) const;
    bool operator==(const Pixel& _otherPixel) const;
protected:

private:
    unsigned char m_pixelChar;
    Coordinate m_coordinate;
};

std::ostream& operator<< (std::ostream& _os, const Pixel& _pixel);




#endif //#ifndef __PCURSES_PIXEL_HPP__
