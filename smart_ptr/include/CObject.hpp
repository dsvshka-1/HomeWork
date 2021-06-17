#ifndef COBJECT_HPP
#define COBJECT_HPP

#include <string>

class CObject
{
    public:
        CObject() = default;
        virtual ~CObject() = default;

        // copy
        CObject(const CObject&){}
        // move
        CObject(CObject&&){}

        // copy
        CObject& operator=(const CObject&){return *this;}
        // move
        CObject& operator=(CObject&&){return *this;}

        std::string toString() const { return "CObject.toString()"; }

};

#endif // COBJECT_HPP
