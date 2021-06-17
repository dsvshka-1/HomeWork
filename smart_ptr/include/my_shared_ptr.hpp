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
        if(!_ptr) return;

        --*shared_count;
        if(*shared_count < 1){
            delete shared_count;
            delete _ptr;
        }
    }

    public:
        my_shared_ptr(T* ptr = nullptr) : _ptr(ptr), shared_count( _ptr?new size_t(1):nullptr ) {}
        ~my_shared_ptr(){
            dec();
        }

        my_shared_ptr(const my_shared_ptr& o): _ptr(o._ptr), shared_count(o.shared_count){
            if(_ptr) ++*shared_count;
        }
        my_shared_ptr& operator=(const my_shared_ptr& o){
            if (this == &o) return *this;

            dec();
            _ptr = o._ptr;
            shared_count = o.shared_count;
            if(_ptr) ++*shared_count;
            return *this;
        }

        my_shared_ptr(my_shared_ptr&& o) : _ptr(o._ptr), shared_count(o.shared_count){
            o._ptr = nullptr;
            o.shared_count = nullptr;
        }
        my_shared_ptr& operator=(my_shared_ptr&& o){
            dec();
            _ptr = o._ptr;
            shared_count = o.shared_count;
            o._ptr = nullptr;
            o.shared_count = nullptr;
            return *this;
        }

        T& operator*() { return *_ptr;}

        T* operator->() { return _ptr;}

        operator bool() const { return _ptr;}

        size_t use_count() const {return shared_count?(*shared_count):0;}
        T* get() const { return _ptr; }
};

#endif // MY_SHARED_PTR_HPP
