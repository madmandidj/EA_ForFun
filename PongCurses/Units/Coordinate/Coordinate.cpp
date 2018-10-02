#include "Coordinate.hpp"

Coordinate::Coordinate(unsigned int _column, unsigned int _row):m_column(_column), m_row(_row)
{

}
Coordinate::~Coordinate()
{

}

Coordinate::Coordinate(const Coordinate& _coordinate) : m_column(_coordinate.m_column), m_row(_coordinate.m_row)
{

}

unsigned int Coordinate::GetY() const  // Y is row
{
    return m_column;
}

unsigned int Coordinate::GetX() const //X is Col
{
    return m_row;
}

bool Coordinate::operator<(const Coordinate& _otherCoordinate) const
{
    if (m_row < _otherCoordinate.m_row)
    {
        return true;
    }
    else if (m_row == _otherCoordinate.m_row)
    {
        return m_column < _otherCoordinate.m_column ? true : false;
    }
    return false;
}

bool Coordinate::operator==(const Coordinate& _otherCoordinate) const
{
    return m_column == _otherCoordinate.m_column && m_row == _otherCoordinate.m_row;
}

std::ostream& operator<< (std::ostream& _os, const Coordinate& _coord)
{
    _os << "Coordinate: X = " << _coord.GetX() << ", Y = " << _coord.GetY() << std::endl;
    return _os;
}










