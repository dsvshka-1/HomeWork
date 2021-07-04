#ifndef HASH_TABLE3_HPP
#define HASH_TABLE3_HPP

#include "human.hpp"
#include <string>
#include <vector>
#include <list>
#include <memory>

struct hash_table3 final
{
    using string = std::string;
    using ul = unsigned long;

    static constexpr ul max_size = 2;
    std::vector<std::unique_ptr<human>> v;

    ul hash(const string& key){
        ul hash = 0;
        for(size_t i = 0; i < key.size(); ++i)
            hash += static_cast<char>(key[i]);
        return hash%max_size;
    }

    public:
        hash_table3() : v(max_size) {}
        ~hash_table3() {}

        void add(const string& name, const string& phone, const string& address){
            auto index = hash(name);
            if (!v[index]){
                v[index] = std::unique_ptr<human>(new human{name, phone, address});
                return;
            }

            if(v[index]->name == name)
                return;

            for(auto i = (index + 1) % max_size; i != index; i = (i+1) % max_size ){
                if (!v[i]){
                    v[i] = std::unique_ptr<human>(new human{name, phone, address});
                    return;
                }
            }
        }

        void remove(const string& name){
            auto index = hash(name);
            if (v[index] && v[index]->name == name)
                v[index].release();

            for(auto i = (index + 1) % max_size; i != index; i = (i+1) % max_size ){
                if ( v[i] && v[i]->name == name)
                    v[i].release();
            }
        }

        human operator[](const string& name){
            auto index = hash(name);

            if (v[index] && v[index]->name == name)
                return *v[index];

            for(auto i = (index + 1) % max_size; i != index; i = (i+1) % max_size ){
                if (v[i] && v[i]->name == name)
                    return *v[i];
            }
            return human{};
        }

};


#endif // HASH_TABLE3_HPP
