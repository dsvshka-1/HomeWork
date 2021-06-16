#ifndef COBJECT_HPP
#define COBJECT_HPP

#include <iostream>

class CObject
{
    public:
        CObject() {}
        virtual ~CObject() {}

        // copy
        CObject(const CObject&){}
        // move
        CObject(CObject&&){}

        // copy
        CObject& operator=(const CObject&){return *this;}
        // move
        CObject& operator=(CObject&&){return *this;}

        operator const char*() const { return "CObject{}\n"; }

        void print() const { std::cout << "CObject.print()" << std::endl; }

};

#endif // COBJECT_HPP
