#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <iostream>
#include <string>

struct human{
    std::string name;
    std::string phone;
    std::string address;
};

std::ostream& operator<<(std::ostream& os, const human& h){
    return os << "name: " << h.name << "; phone: " << h.phone << "; address: " << h.address << ';';
}

#endif // HUMAN_HPP
