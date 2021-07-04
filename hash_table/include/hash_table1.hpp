#ifndef HASH_TABLE1_HPP
#define HASH_TABLE1_HPP

#include "human.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>

struct hash_table1 final
{
    using string = std::string;
    using ul = unsigned long;

    static constexpr ul max_size = 2;
    std::vector<std::list<human>> v;

    ul hash(const string& key){
        ul hash = 0;
        for(size_t i = 0; i < key.size(); ++i)
            hash += static_cast<char>(key[i]);
        return hash%max_size;
    }

    public:
        hash_table1() : v(max_size) {}
        ~hash_table1() {}

        void add(const string& name, const string& phone, const string& address){
            std::list<human>& tmp = v[hash(name)];
            for(auto i = tmp.begin(); i != tmp.end(); ++i){
                if (name == i->name)
                    return;
            }
            tmp.push_back( human{name, phone, address} );
        }

        void remove(const string& name){
            std::list<human>& tmp = v[hash(name)];
            for(auto i = tmp.begin(); i != tmp.end(); ++i){
                if (name == i->name){
                    tmp.erase(i);
                    return;
                }
            }
        }

        human operator[](const string& name){
            std::list<human>& tmp = v[hash(name)];
            for(auto i = tmp.begin(); i != tmp.end(); ++i){
                if (name == i->name)
                    return *i;
            }
            return human{};
        }

        string get_phone(const string& name){
            return operator[](name).phone;
        }

        string get_address(const string& name){
            return operator[](name).address;
        }

};

#endif // HASH_TABLE1_HPP
