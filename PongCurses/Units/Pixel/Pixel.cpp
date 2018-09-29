#include "Pixel.hpp"
#include "../Coordinate/Coordinate.hpp"

Pixel::Pixel(unsigned int _x, unsigned int _y, unsigned int _pixelID) :
    m_pixelChar(' '), m_coordinate(Coordinate(_x,_y)), m_pixelID(_pixelID)
{

}

Pixel::Pixel(Coordinate _coordinate, unsigned int _pixelID) : 
    m_pixelChar(' '), m_coordinate(_coordinate), m_pixelID(_pixelID)
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
    return m_coordinate.GetX();
}

unsigned int Pixel::GetY() const 
{
    return m_coordinate.GetY();
}

unsigned int Pixel::GetID() const
{
    return m_pixelID;
}

bool Pixel::operator<(const Pixel& _otherPixel) const 
{
    return m_pixelID < _otherPixel.m_pixelID;
}

bool Pixel::operator==(const Pixel& _otherPixel) const 
{
    return m_pixelID == _otherPixel.m_pixelID;
}

std::ostream& operator<< (std::ostream& _os, const Pixel& _pixel)
{
    _os << "Pixel ID = " << _pixel.GetID() << ", X = " << _pixel.GetX() << ", Y = " << _pixel.GetY() << ", Char = " << _pixel.GetChar() << std::endl;
    return _os;
}

