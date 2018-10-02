#ifndef __PCURSES_COORDINATE_HPP__
#define __PCURSES_COORDINATE_HPP__
#include<iostream>

class Coordinate
{
public:
    Coordinate(unsigned int _column, unsigned int _row);
    Coordinate(const Coordinate& _coordinate);
    ~Coordinate();
    unsigned int GetX() const;
    unsigned int GetY() const;
    void SetX(unsigned int _column) {m_column = _column;}
    void SetY(unsigned int _row) {m_row = _row;}
    bool operator<(const Coordinate& _otherCoordinate) const;
    bool operator==(const Coordinate& _otherCoordinate) const;
protected:

private:
    unsigned int m_column;
    unsigned int m_row;
};

std::ostream& operator<< (std::ostream& _os, const Coordinate& _coord);

#endif //#ifndef __PCURSES_COORDINATE_HPP__
