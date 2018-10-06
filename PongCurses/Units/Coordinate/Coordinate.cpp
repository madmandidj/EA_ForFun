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

unsigned int Coordinate::GetRow() const  
{
    return m_row;
}

unsigned int Coordinate::GetColumn() const 
{
    return m_column;
}

void Coordinate::SetColumn(unsigned int _column) 
{
    m_column = _column;
}

void Coordinate::SetRow(unsigned int _row) 
{
    m_row = _row;
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
    _os << "Coordinate: Column = " << _coord.GetColumn() << ", Y = " << _coord.GetRow() << std::endl;
    return _os;
}










