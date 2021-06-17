#ifndef MY_UNIQUE_PTR_HPP
#define MY_UNIQUE_PTR_HPP

#include "CObject.hpp"

class my_unique_ptr final
{
    typedef CObject T;

    T* _ptr;
    public:
        my_unique_ptr(T* ptr = nullptr) : _ptr(ptr){}
        ~my_unique_ptr(){ delete _ptr; }

        // no copy
        my_unique_ptr(const my_unique_ptr&) = delete;
        // has move
        my_unique_ptr(my_unique_ptr&& o): _ptr(o._ptr){ o._ptr = nullptr;}

        // no copy
        my_unique_ptr& operator=(const my_unique_ptr&) = delete;
        // has move
        my_unique_ptr& operator=(my_unique_ptr&& o){
            if (this == &o) return *this;
            delete _ptr;
            _ptr = o._ptr;
            o._ptr = nullptr;
            return *this;
        }

        T& operator*() { return *_ptr;}

        T* operator->() { return _ptr;}

        operator bool() const { return _ptr;}

        T* get() const {return _ptr;}
};

#endif // MY_UNIQUE_PTR_HPP
