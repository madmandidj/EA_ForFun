#ifndef __MYCLASSES_HPP__
#define __MYCLASSES_HPP__
#include <tr1/memory>

class MyBase
{
public:
    MyBase();
    ~MyBase();
    MyBase(const MyBase& _myBase);
    MyBase& operator=(const MyBase& _myBase);
    unsigned int GetCTOR_Count() const;
    unsigned int GetDTOR_Count() const;
    unsigned int GetCOPYCTOR_Count() const;
    unsigned int GetASSIGNOP_Count() const;
    unsigned int GetID() const;
    static unsigned int GetNumOfObjects() {return s_numOfObjects;}
protected:
    static unsigned int s_CTOR_Count;
    static unsigned int s_DTOR_Count;
    static unsigned int s_COPY_CTOR_Count;
    static unsigned int s_ASSIGN_OP_Count;
    static unsigned int s_numOfObjects;

private:
    unsigned int m_id;
};














#endif//#ifndef __MYCLASSES_HPP__
