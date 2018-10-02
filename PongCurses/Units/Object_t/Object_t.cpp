#include <iostream>
#include <map>
#include <tr1/memory>
#include "../Coordinate/Coordinate.hpp"
#include "../Pixel/Pixel.hpp"
#include "Object_t.hpp"



Object_t::Object_t(Object_ID _objectId) : 
    m_objectID(_objectId)
{

}

Object_t::~Object_t()
{
    // unsigned int numOfPixels = GetNumOfPixels();
    // for (unsigned int curPixel = 0; curPixel < numOfPixels; ++curPixel)
    // {
    //     m_pixelVector.pop_back();
    // }
    m_pixelVector.clear();
}

Object_t::SharedPixelPtr Object_t::CreatePixel(unsigned int _x, unsigned int _y, unsigned char _pixelChar)
{
    SharedPixelPtr newPixel(new Pixel(_y, _x, _pixelChar)); //Y is row, X is Col
    m_pixelVector.push_back(newPixel);
    return newPixel;
}

Object_t::SharedPixelPtr Object_t::GetPixel(size_t _vectorIndex) const
{
    return m_pixelVector[_vectorIndex];
}

void Object_t::RemovePixel(size_t _vectorIndex)
{
    std::vector<SharedPixelPtr>::iterator it = m_pixelVector.begin();
    for(size_t index = 0; index < _vectorIndex; ++index)
    {
        ++it;
    }
    m_pixelVector.erase(it);
}


size_t Object_t::GetNumOfPixels() const
{
    return m_pixelVector.size();
}

bool Object_t::Move(unsigned int _amount, ObjMoveDirection _direction, unsigned int _parentWinWidth, unsigned int _parentWinHeight)
{
    unsigned int object_X_R = 0;
    unsigned int object_X_L = _parentWinWidth - 1;
    unsigned int object_Y_U = _parentWinHeight - 1;
    unsigned int object_Y_D = 0;
    unsigned int numOfPixels = GetNumOfPixels();

    for (size_t curIndex = 0; curIndex < numOfPixels; ++curIndex)
    {
        SharedPixelPtr curPixel = m_pixelVector[curIndex];
        unsigned int curX = curPixel->GetY();
        unsigned int curY = curPixel->GetX();
        object_X_R =  curX > object_X_R ? curX : object_X_R;
        object_X_L =  curX < object_X_L ? curX : object_X_L;
        object_Y_U =  curY < object_Y_U ? curY : object_Y_U;
        object_Y_D =  curY > object_Y_D ? curY : object_Y_D;
    }

    switch (_direction)
    {
        case R:
            if (object_X_R + _amount < _parentWinWidth)
            {
                    for (size_t curIndex = 0; curIndex < numOfPixels; ++curIndex)
                    {
                        SharedPixelPtr curPixel = m_pixelVector[curIndex];
                        unsigned int curX = curPixel->GetX();
                        curPixel->SetX(curX + _amount);
                    }
                    return true;
            }
            return false;
        break;
        case L:
            if (*((int*)&object_X_L) - *((int*)&_amount) >= 0)
            {
                    for (size_t curIndex = 0; curIndex < numOfPixels; ++curIndex)
                    {
                        SharedPixelPtr curPixel = m_pixelVector[curIndex];
                        unsigned int curX = curPixel->GetX();
                        curPixel->SetX(curX - _amount);
                    }
                    return true;
            }
            return false;
        break;
        case U:
            if (*((int*)&object_Y_U) - *((int*)&_amount) >= 0)
            {
                    for (size_t curIndex = 0; curIndex < numOfPixels; ++curIndex)
                    {
                        SharedPixelPtr curPixel = m_pixelVector[curIndex];
                        unsigned int curY = curPixel->GetY();
                        curPixel->SetY(curY - _amount);
                    }
                    return true;
            }
            return false;
        break;
        case D:
            if (object_Y_D + _amount < _parentWinHeight)
            {
                    for (size_t curIndex = 0; curIndex < numOfPixels; ++curIndex)
                    {
                        SharedPixelPtr curPixel = m_pixelVector[curIndex];
                        unsigned int curY = curPixel->GetY();
                        curPixel->SetY(curY + _amount);
                    }
                    return true;
            }
            return false;
        break;

    }
}

std::ostream& operator<<(std::ostream& _os, const Object_t& _object)
{
    size_t numOfPixels = _object.GetNumOfPixels();
    for (size_t index = 0; index < numOfPixels; ++index)
    {
        _os << *_object.GetPixel(index) << std::endl;
    }
    return _os;
}

