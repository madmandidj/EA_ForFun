#include "Coordinate.hpp"

Coordinate::Coordinate(unsigned int _x, unsigned int _y):m_x(_x), m_y(_y)
{

}
Coordinate::~Coordinate()
{

}

Coordinate::Coordinate(const Coordinate& _coordinate) : m_x(_coordinate.m_x), m_y(_coordinate.m_y)
{

}

unsigned int Coordinate::GetX() const 
{
    return m_x;
}

unsigned int Coordinate::GetY() const 
{
    return m_y;
}

bool Coordinate::operator==(const Coordinate& _otherCoordinate) const
{
    return m_x == _otherCoordinate.m_x && m_y == _otherCoordinate.m_y;
}

std::ostream& operator<< (std::ostream& _os, const Coordinate& _coord)
{
    _os << "X = " << _coord.GetX() << ", Y = " << _coord.GetY() << std::endl;
    return _os;
}










