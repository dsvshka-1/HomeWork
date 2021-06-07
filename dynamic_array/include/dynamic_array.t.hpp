#ifndef DYNAMIC_ARRAY_T_HPP
#define DYNAMIC_ARRAY_T_HPP

#include "dynamic_array.h"


template<class T>
dynamic_array<T>::dynamic_array(size_t length)
:len(length), capacity(len), arr(len>0?new T[len]:0){
    for(size_t i = 0; i < len; ++i)
        arr[i] = T();
}

template<class T>
dynamic_array<T>::dynamic_array(size_t length, const T& val)
:len(length), capacity(len), arr(len>0?new T[len]:0){
    for(size_t i = 0; i < len; ++i)
        arr[i] = val;
}

template<class T>
dynamic_array<T>::~dynamic_array(){ if(arr != 0) delete[] arr; }

template<class T>
dynamic_array<T>::dynamic_array(const std::initializer_list<T>& other )
:len(other.size()), capacity(len), arr(len>0?new T[len]:0){
    auto it = other.begin();
    size_t i = 0;
    for(; (i < len) && (it != other.end()); ++i, ++it)
        arr[i] = *it;
}

template<class T>
dynamic_array<T>::dynamic_array(const dynamic_array& other)
:len(other.len), capacity(len), arr(len>0?new T[len]:0){
    for( size_t i = 0; i < len; ++i)
        arr[i] = other[i];
}

template<class T>
dynamic_array<T>::dynamic_array(dynamic_array&& other)
:len(other.len), capacity(other.capacity), arr(other.arr){
    other.len = 0;
    other.capacity = 0;
    other.arr = 0;
}

template<class T>
dynamic_array<T>& dynamic_array<T>::operator=(const dynamic_array<T>& other){
    if (this = &other) return *this;

    if(capacity < other.len ){
        if( arr != 0) delete[] arr;
        len = other.len;
        capacity = 2 * len + 1;
        arr = new T[capacity];
        for(size_t i = 0; i < len; ++i)
            arr[i] = other[i];
    } else {
        len = other.len;
        for(size_t i = 0; i < len; ++i)
            arr[i] = other[i];
    }

    return *this;
}

template<class T>
dynamic_array<T>& dynamic_array<T>::operator=(dynamic_array<T>&& other){
    if( arr != 0 ) delete[] arr;

    len = other.len;
    capacity = other.capacity;
    arr = other.arr;

    other.len = 0;
    other.capacity = 0;
    other.arr = 0;

    return *this;
}

template<class T>
void dynamic_array<T>::resize(size_t length){
    if(capacity < length){

        size_t capacity = length * 2 + 1;
        T* new_arr = new T[capacity];

        for(size_t i = 0; i < len; ++i)
            new_arr[i] = arr[i];

        if(arr != 0) delete[] arr;

        arr = new_arr;
    }

    for(size_t i = len; i < length; ++i)
        arr[i] = T();
    len = length;
}

template<class T>
void dynamic_array<T>::resize(size_t length, const T& val){
    if(capacity < length){
        delete[] arr;

        len = length;
        capacity = 2 * len + 1;
        arr = new T[capacity];
    }
    for(size_t i = 0; i < len; ++i)
        arr[i] = val;
}

template <class T>
T& dynamic_array<T>::operator[] (size_t index){
    if (index >= len) throw std::runtime_error("index out of range");
    return arr[index];
}

template<class T>
const T& dynamic_array<T>::operator[] (size_t index) const{
    if (index >= len) throw std::runtime_error("index out of range");
    return arr[index];
}

template<class T>
void dynamic_array<T>::push_back(const T& val){
    if (capacity < ++len){
        resize(len);
    }
    arr[len-1] = val;
}

template<class T>
T& dynamic_array<T>::pop_back(){
    if(len == 0) throw std::runtime_error("array is empty");
    return arr[--len];
}

template<class T>
std::ostream& operator<<(std::ostream& out, const dynamic_array<T>& v){
    out << "dynamic_array{";
    if (v.length() > 0 ) out << v[0];
    for(size_t i = 1; i < v.length(); ++i)
        out << ',' << v[i];
    out << "}\n";
    return out;
}


#endif // DYNAMIC_ARRAY_T_HPP
