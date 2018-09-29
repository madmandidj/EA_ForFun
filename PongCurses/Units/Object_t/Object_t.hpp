#ifndef __PCURSES_OBJECT_T_HPP__
#define __PCURSES_OBJECT_T_HPP__
#include <iostream>
#include "../Window/Window.hpp"
#include <set>

class Object_t
{
public:
    typedef enum
    {
        BRICK_L,
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
    Object_t(Object_ID _objectId, const Window& _parentWindow);
    virtual ~Object_t();
    void AddPixel(unsigned int _pixelID);
    bool RemovePixel(unsigned int _pixelID);
    bool Find(unsigned int _pixelID);
    unsigned int GetNumOfPixels() const;
    Window::Window_ID GetParentWindowID() const;
    bool Move(unsigned int _amount, ObjMoveDirection _direction);
    unsigned int GetBorder_U() const {return m_border_U;}
    unsigned int GetBorder_R() const {return m_border_R;}
    unsigned int GetBorder_D() const {return m_border_D;}
    unsigned int GetBorder_L() const {return m_border_L;}
protected:
    unsigned int CalculateNewPixelID(unsigned int _pixelID, ObjMoveDirection _direction) const;
    unsigned int CalculatePixelRow(unsigned int _pixelID) const;
    unsigned int CalculatePixelCol(unsigned int _pixelID) const;

protected:
    std::set<unsigned int> m_pixelIDContainer;
    const Object_ID m_objectID;
    const Window::Window_ID m_parentWindowID;
    const unsigned int m_parentWindowRows;
    const unsigned int m_parentWindowCols;
    unsigned int m_border_U;
    unsigned int m_border_R;
    unsigned int m_border_D;
    unsigned int m_border_L;
private:
};

std::ostream& operator<<(std::ostream&, const Object_t& _object);


#endif//#ifndef __PCURSES_OBJECT_T_HPP__


