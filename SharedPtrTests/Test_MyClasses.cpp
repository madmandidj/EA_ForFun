#include <iostream>
#include <tr1/memory>
#include "MyClasses.hpp"

MyBase FuncReturnObj()
{
    MyBase myBase;
    return myBase;
}

MyBase& FuncObjParamRetRef(MyBase _obj)
{
    return _obj;
}

MyBase& FuncPtrParamRetRef(MyBase* _ptr)
{
    return *_ptr;
}

void FuncRefParamRetVoid(MyBase& _ref)
{
}

void FuncObjParamRetVoid(MyBase _obj)
{
}

int main()
{
    std::cout << std::endl;
    std::cout << " MyBase myBase_CTOR;" << std::endl;
    MyBase myBase_CTOR; // <-- CTOR
    std::cout << " MyBase myBase_CopyCTOR(myBase_CTOR);"  << std::endl;
    MyBase myBase_CopyCTOR(myBase_CTOR); // <-- COPY CTOR
    std::cout << " MyBase myBase_CopyCTOR2 = myBase_CopyCTOR;"  << std::endl;
    MyBase myBase_CopyCTOR2 = myBase_CopyCTOR; // <-- COPY CTOR
    std::cout << " MyBase* myBaseNewPtr = new MyBase;"  << std::endl;
    MyBase* myBaseNewPtr = new MyBase; // <-- CTOR
    std::cout << " myBase_CopyCTOR2 = myBase_CTOR;"  << std::endl;
    myBase_CopyCTOR2 = myBase_CTOR; // <-- operator=
    std::cout << " std::tr1::shared_ptr<MyBase> myBaseSharedPtr(new MyBase(myBase_CopyCTOR2));"  << std::endl;
    std::tr1::shared_ptr<MyBase> myBaseSharedPtr(new MyBase(myBase_CopyCTOR2)); // <-- COPY CTOR
    std::cout << " MyBase& ref1 = FuncObjParamRetRef(myBase_CTOR);"  << std::endl;
    MyBase& ref1 = FuncObjParamRetRef(myBase_CTOR);
    std::cout << " MyBase& ref2 = FuncPtrParamRetRef(&myBase_CTOR);"  << std::endl;
    MyBase& ref2 = FuncPtrParamRetRef(&myBase_CTOR);
    std::cout << " FuncRefParamRetVoid(myBase_CTOR);"  << std::endl;
    FuncRefParamRetVoid(myBase_CTOR);
    std::cout << " MyBase obj1 = FuncReturnObj();"  << std::endl;
    MyBase obj1 = FuncReturnObj();
    



    std::cout << " delete myBaseNewPtr;"  << std::endl;
    delete myBaseNewPtr;
    return 0;
}


