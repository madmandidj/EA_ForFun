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

Object_t::SharedPixelPtr Object_t::CreatePixel(unsigned int _column, unsigned int _row, unsigned char _pixelChar)
{
    SharedPixelPtr newPixel(new Pixel(_column, _row, _pixelChar));
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
    unsigned int object_COL_R = 0;
    unsigned int object_COL_L = _parentWinWidth - 1;
    unsigned int object_ROW_U = _parentWinHeight - 1;
    unsigned int object_ROW_D = 0;
    unsigned int numOfPixels = GetNumOfPixels();

    for (size_t curIndex = 0; curIndex < numOfPixels; ++curIndex)
    {
        SharedPixelPtr curPixel = m_pixelVector[curIndex];
        unsigned int curRow = curPixel->GetRow();
        unsigned int curCol = curPixel->GetColumn();
        object_COL_R =  curCol > object_COL_R ? curCol : object_COL_R;
        object_COL_L =  curCol < object_COL_L ? curCol : object_COL_L;
        object_ROW_U =  curRow < object_ROW_U ? curRow : object_ROW_U;
        object_ROW_D =  curRow > object_ROW_D ? curRow : object_ROW_D;
    }

    switch (_direction)
    {
        case R:
            if (object_COL_R + _amount < _parentWinWidth)
            {
                    for (size_t curIndex = 0; curIndex < numOfPixels; ++curIndex)
                    {
                        SharedPixelPtr curPixel = m_pixelVector[curIndex];
                        unsigned int curCol = curPixel->GetColumn();
                        curPixel->SetColumn(curCol + _amount);
                    }
                    return true;
            }
            return false;
        break;
        case L:
            if (*((int*)&object_COL_L) - *((int*)&_amount) >= 0)
            {
                    for (size_t curIndex = 0; curIndex < numOfPixels; ++curIndex)
                    {
                        SharedPixelPtr curPixel = m_pixelVector[curIndex];
                        unsigned int curCol = curPixel->GetColumn();
                        curPixel->SetColumn(curCol - _amount);
                    }
                    return true;
            }
            return false;
        break;
        case U:
            if (*((int*)&object_ROW_U) - *((int*)&_amount) >= 0)
            {
                    for (size_t curIndex = 0; curIndex < numOfPixels; ++curIndex)
                    {
                        SharedPixelPtr curPixel = m_pixelVector[curIndex];
                        unsigned int curRow = curPixel->GetRow();
                        curPixel->SetRow(curRow - _amount);
                    }
                    return true;
            }
            return false;
        break;
        case D:
            if (object_ROW_D + _amount < _parentWinHeight)
            {
                    for (size_t curIndex = 0; curIndex < numOfPixels; ++curIndex)
                    {
                        SharedPixelPtr curPixel = m_pixelVector[curIndex];
                        unsigned int curRow = curPixel->GetRow();
                        curPixel->SetRow(curRow + _amount);
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

