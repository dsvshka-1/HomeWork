#ifndef MY_SHARED_PTR_HPP
#define MY_SHARED_PTR_HPP

#include "CObject.hpp"
#include <iostream>

class my_shared_ptr final
{
    typedef CObject T;

    T* _ptr;
    size_t* shared_count;

    void dec(){
        --shared_count[0];
        if(shared_count[0] == 0){
            delete shared_count;
            delete _ptr;
        }
    }

    public:
        my_shared_ptr(T* ptr) : _ptr(ptr), shared_count( new size_t(1) ) {}
        ~my_shared_ptr(){
            dec();
        }

        my_shared_ptr(const my_shared_ptr& o): _ptr(o._ptr), shared_count(o.shared_count){
            ++shared_count[0];
        }

        my_shared_ptr& operator=(const my_shared_ptr& o){
            if (this == &o) return *this;
            dec();
            _ptr = o._ptr;
            shared_count = o.shared_count;
            ++shared_count[0];
            return *this;
        }

        T& operator*() { return *_ptr;}
        const T& operator*() const { return *_ptr;}

        T* operator->() { return _ptr;}
        const T* operator->() const { return _ptr;}

        operator bool() const { return _ptr;}

        size_t use_count() const {return shared_count[0];}
        T* get() const { return _ptr; }
};

#endif // MY_SHARED_PTR_HPP
