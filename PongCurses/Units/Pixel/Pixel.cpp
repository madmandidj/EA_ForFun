#include "Pixel.hpp"
#include "../Coordinate/Coordinate.hpp"

Pixel::Pixel(unsigned int _column, unsigned int _row, unsigned char _pixelChar) :
    m_pixelChar(_pixelChar), m_coordinate(Coordinate(_column,_row))
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

unsigned int Pixel::GetColumn() const 
{
    return m_coordinate.GetColumn();
}

unsigned int Pixel::GetRow() const 
{
    return m_coordinate.GetRow();
}

void Pixel::SetColumn(unsigned int _column)
{
    m_coordinate.SetColumn(_column);
}

void Pixel::SetRow(unsigned int _row) 
{
    m_coordinate.SetRow(_row);
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
    _os << "Pixel: Column = " << _pixel.GetColumn() << ", Row = " << _pixel.GetRow() << ", Char = " << _pixel.GetChar() << std::endl;
    return _os;
}

