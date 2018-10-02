#include "Pixel.hpp"
#include "../Coordinate/Coordinate.hpp"

Pixel::Pixel(unsigned int _x, unsigned int _y, unsigned char _pixelChar) :
    m_pixelChar(_pixelChar), m_coordinate(Coordinate(_y,_x)) // Y is row, X is col
{

}

Pixel::~Pixel()
{

}

unsigned char Pixel::GetChar() const 
{
    return m_pixelChar;
}

void Pixel::SetChar(unsigned char _newChar)
{
    m_pixelChar = _newChar;
}

unsigned int Pixel::GetX() const 
{
    return m_coordinate.GetY(); //Y is Row
}

unsigned int Pixel::GetY() const 
{
    return m_coordinate.GetX(); //X is Col
}

bool Pixel::operator<(const Pixel& _otherPixel) const 
{
    return m_coordinate < _otherPixel.m_coordinate;
}

bool Pixel::operator==(const Pixel& _otherPixel) const 
{
    return m_coordinate == _otherPixel.m_coordinate;
}

std::ostream& operator<< (std::ostream& _os, const Pixel& _pixel)
{
    _os << "Pixel: X = " << _pixel.GetX() << ", Y = " << _pixel.GetY() << ", Char = " << _pixel.GetChar() << std::endl;
    return _os;
}

