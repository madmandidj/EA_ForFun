#ifndef __PCURSES_COORDINATE_HPP__
#define __PCURSES_COORDINATE_HPP__
#include<iostream>

class Coordinate
{
public:
    Coordinate(unsigned int _column, unsigned int _row);
    Coordinate(const Coordinate& _coordinate);
    ~Coordinate();
    unsigned int GetColumn() const;
    unsigned int GetRow() const;
    void SetColumn(unsigned int _column);
    void SetRow(unsigned int _row);
    bool operator<(const Coordinate& _otherCoordinate) const;
    bool operator==(const Coordinate& _otherCoordinate) const;
protected:

private:
    unsigned int m_column;
    unsigned int m_row;
};

std::ostream& operator<< (std::ostream& _os, const Coordinate& _coord);

#endif //#ifndef __PCURSES_COORDINATE_HPP__
