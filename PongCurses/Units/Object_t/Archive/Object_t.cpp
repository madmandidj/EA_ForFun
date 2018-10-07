#include "Object_t.hpp"
#include "../Window/Window.hpp"



Object_t::Object_t(Object_ID _objectId, const Window& _parentWindow) : 
    m_objectID(_objectId), m_parentWindowID(_parentWindow.GetWindowID()), 
    m_parentWindowRows(_parentWindow.GetHeight()), 
    m_parentWindowCols(_parentWindow.GetWidth())
{
    m_border_U = 0;
    m_border_R = 0;
    m_border_D = 0;
    m_border_L = 0;
}

Object_t::~Object_t()
{

}

void Object_t::AddPixel(unsigned int _pixelID)
{
    unsigned int pixelCol = CalculatePixelCol(_pixelID);
    unsigned int pixelRow = CalculatePixelRow(_pixelID);
    if (0 == GetNumOfPixels())
    {
        m_border_U = pixelRow;
        m_border_R = pixelCol;
        m_border_D = pixelRow;
        m_border_L = pixelCol;
    }
    else
    {
        m_border_U = pixelRow < m_border_U ? pixelRow : m_border_U;
        m_border_R = pixelCol > m_border_R ? pixelCol : m_border_R;
        m_border_D = pixelRow > m_border_D ? pixelRow : m_border_U;
        m_border_L = pixelCol < m_border_L ? pixelCol : m_border_L;
    }
    m_pixelIDContainer.insert(_pixelID);
}

bool Object_t::RemovePixel(unsigned int _pixelID)
{
    std::set<unsigned int>::iterator it = m_pixelIDContainer.find(_pixelID);
    if (it != m_pixelIDContainer.end())
    {
        m_pixelIDContainer.erase(_pixelID);
        return true;
    }
    return false;
}

bool Object_t::Find(unsigned int _pixelID)
{
    std::set<unsigned int>::iterator it = m_pixelIDContainer.find(_pixelID);
    if (it != m_pixelIDContainer.end())
    {
        return true;
    }
    return false;
}

unsigned int Object_t::GetNumOfPixels() const
{
    return m_pixelIDContainer.size();
}


Window::Window_ID Object_t::GetParentWindowID() const
{
    return m_parentWindowID;
}

bool Object_t::CanMove(unsigned int _amount, ObjMoveDirection _direction)
{
        switch (_direction)
        {
            case U:
                if (m_parentWindowRows < m_border_U - _amount)
                {
                    return false;
                }
                break;
            case R:
                if (m_parentWindowCols <= m_border_R + _amount)
                {
                    return false;
                }
                break;
            case D:
                if (m_parentWindowRows <= m_border_D + _amount)
                {
                    return false;
                }
                break;
            case L:
                if (m_parentWindowCols < m_border_L - _amount)
                {
                    return false;
                }
                break;
            default:
                break;
        }
    return true;
}

bool Object_t::Move(unsigned int _amount, ObjMoveDirection _direction)
{
    //Check if valid move
    //Calculate
    for (unsigned int curAmountNum = 0; curAmountNum < _amount; ++curAmountNum)
    {

        switch (_direction)
        {
            case U:
                // if (0 == m_border_U)
                // {
                //     return false;
                // }
                --m_border_U;
                --m_border_D;
                break;
            case R:
                // if (m_parentWindowCols - 1 == m_border_R)
                // {
                //     return false;
                // }
                ++m_border_R;
                ++m_border_L;
                break;
            case D:
                // if (m_parentWindowRows - 1 == m_border_D)
                // {
                //     return false;
                // }
                ++m_border_U;
                ++m_border_D;
                break;
            case L:
                // if (0 == m_border_L)
                // {
                //     return false;
                // }
                --m_border_R;
                --m_border_L;
                break;
            default:
                break;
        }

        std::set<unsigned int>::iterator it = m_pixelIDContainer.begin();
        while (it != m_pixelIDContainer.end())
        {
            unsigned int newPixelID = CalculateNewPixelID(*it, _direction);
            ++it;
        }
    }
    return true;
}

unsigned int Object_t::CalculateNewPixelID(unsigned int _pixelID, ObjMoveDirection _direction) const
{
    unsigned int newPixelID = _pixelID;
    unsigned int UpDownOffset = m_parentWindowCols;
    switch (_direction)
    {
        case U:
            newPixelID += UpDownOffset;
            break;
        case R:
            newPixelID += 1;
            break;
        case D:
            newPixelID -= UpDownOffset;
            break;
        case L:
            newPixelID -= 1;
            break;
        default:
            break;
    }
    return newPixelID;
}

unsigned int Object_t::CalculatePixelRow(unsigned int _pixelID) const
{
    return _pixelID / m_parentWindowCols;
}

unsigned int Object_t::CalculatePixelCol(unsigned int _pixelID) const
{
    return _pixelID % m_parentWindowCols;
}

std::ostream& operator<<(std::ostream& _os, const Object_t& _object)
{
    _os << "U = " << _object.GetBorder_U() << ", R = " << _object.GetBorder_R() << ", D = " << _object.GetBorder_D() << ", L = " << _object.GetBorder_L() << std::endl;
    return _os;
}

