#ifndef __PCURSES_COORDINATE_HPP__
#define __PCURSES_COORDINATE_HPP__
#include<iostream>

class Coordinate
{
public:
    Coordinate(unsigned int _x, unsigned int _y);
    ~Coordinate();
    Coordinate(const Coordinate& _coordinate);
    unsigned int GetX() const;
    unsigned int GetY () const;
    bool operator==(const Coordinate& _otherCoordinate) const;
protected:

private:
    const unsigned int m_x;
    const unsigned int m_y;
};

std::ostream& operator<< (std::ostream& _os, const Coordinate& _coord);

#endif //#ifndef __PCURSES_COORDINATE_HPP__
