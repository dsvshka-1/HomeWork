#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>

template<class T>
class dynamic_array
{
    size_t len, capacity;
    T* arr;
    public:
        dynamic_array(size_t length = 0);
        dynamic_array(size_t length, const T& val);
        virtual ~dynamic_array();

        dynamic_array(const std::initializer_list<T>& other);

        dynamic_array(const dynamic_array& other);
        dynamic_array(dynamic_array&& other);

        dynamic_array<T>& operator=(const dynamic_array<T>& other);
        dynamic_array<T>& operator=(dynamic_array<T>&& other);

        void resize(size_t length);
        void resize(size_t length, const T& val);

        T& operator[] (size_t index);
        const T& operator[] (size_t index) const;

        void push_back(const T& val);
        T& pop_back();

        size_t length() const {return len;}
};

template<class T>
std::ostream& operator<<(std::ostream& out, const dynamic_array<T>& v);

#include "dynamic_array.t.hpp"

#endif // DYNAMIC_ARRAY_H
