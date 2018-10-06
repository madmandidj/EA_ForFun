#ifndef __PCURSES_OBJECT_T_HPP__
#define __PCURSES_OBJECT_T_HPP__
#include <iostream>
#include <map>
#include <vector>
#include <tr1/memory>
#include "../Coordinate/Coordinate.hpp"
#include "../Pixel/Pixel.hpp"
// #include "../Window/Window.hpp"

class Object_t
{
public:
    typedef std::tr1::shared_ptr<Pixel> SharedPixelPtr;
    typedef enum
    {
        BRICK_L = 0,
        BRICK_R,
        BALL
    }Object_ID;
    typedef enum
    {
        U,
        R,
        D,
        L
    }ObjMoveDirection;
    Object_t(Object_ID _objectId);
    virtual ~Object_t();
    SharedPixelPtr CreatePixel(unsigned int _column, unsigned int _row, unsigned char _pixelChar);
    SharedPixelPtr GetPixel(size_t _vectorIndex) const;
    void RemovePixel(size_t _vectorIndex);
    size_t GetNumOfPixels() const;
    bool Move(unsigned int _amount, ObjMoveDirection _direction, unsigned int _parentWinWidth, unsigned int _parentWinHeight);
protected:

protected:
    const Object_ID m_objectID;
    std::vector<SharedPixelPtr> m_pixelVector;
private:
};

std::ostream& operator<<(std::ostream&, const Object_t& _object);


#endif//#ifndef __PCURSES_OBJECT_T_HPP__


