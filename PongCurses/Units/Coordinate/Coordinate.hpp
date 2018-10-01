#ifndef __PCURSES_COORDINATE_HPP__
#define __PCURSES_COORDINATE_HPP__
#include<iostream>

class Coordinate
{
public:
    Coordinate(unsigned int _x, unsigned int _y);
    Coordinate(const Coordinate& _coordinate);
    ~Coordinate();
    unsigned int GetX() const;
    unsigned int GetY() const;
    void SetX(unsigned int _x) {m_x = _x;}
    void SetY(unsigned int _y) {m_y = _y;}
    bool operator<(const Coordinate& _otherCoordinate) const;
    bool operator==(const Coordinate& _otherCoordinate) const;
protected:

private:
    unsigned int m_x;
    unsigned int m_y;
};

std::ostream& operator<< (std::ostream& _os, const Coordinate& _coord);

#endif //#ifndef __PCURSES_COORDINATE_HPP__
