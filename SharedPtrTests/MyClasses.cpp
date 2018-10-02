#include <iostream>
#include <tr1/memory>
#include "MyClasses.hpp"

unsigned int MyBase::s_CTOR_Count = 0;
unsigned int MyBase::s_DTOR_Count = 0;
unsigned int MyBase::s_COPY_CTOR_Count = 0;
unsigned int MyBase::s_ASSIGN_OP_Count = 0;
unsigned int MyBase::s_numOfObjects = 0;

MyBase::MyBase()
{
    ++s_CTOR_Count;
    m_id = ++s_numOfObjects;
    std::cout << "CTOR count = " << s_CTOR_Count << ", thisID = " << m_id << std::endl << std::endl;
}

MyBase::~MyBase()
{
    ++s_DTOR_Count;
    std::cout << "DTOR count = " << s_DTOR_Count << ", thisID = " << m_id << std::endl << std::endl;
}

MyBase::MyBase(const MyBase& _myBase)
{
    ++s_COPY_CTOR_Count;
    m_id = ++s_numOfObjects;
    std::cout << "copy CTOR count = " << s_COPY_CTOR_Count << ", thisID = " << m_id << ", otherID = " << _myBase.m_id << std::endl << std::endl;
}

MyBase& MyBase::operator=(const MyBase& _myBase)
{
    ++s_ASSIGN_OP_Count;
    std::cout << "operator= count = " << s_ASSIGN_OP_Count << ", thisID = " << m_id << ", otherID = " << _myBase.m_id << std::endl << std::endl;
    return *this;
}

unsigned int MyBase::GetCTOR_Count() const
{
    return s_CTOR_Count;
}

unsigned int MyBase::GetDTOR_Count() const
{
    return s_DTOR_Count;
}

unsigned int MyBase::GetCOPYCTOR_Count() const
{
    return s_COPY_CTOR_Count;
}

unsigned int MyBase::GetASSIGNOP_Count() const
{
    return s_ASSIGN_OP_Count;
}

unsigned int MyBase::GetID()const
{
    return m_id;
}
