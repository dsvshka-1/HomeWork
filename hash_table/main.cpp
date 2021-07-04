#include <iostream>
#include "hash_table1.hpp"
#include "hash_table3.hpp"

using namespace std;

int main()
{
    cout << "Hash table 1:" << endl;
    hash_table1 ht;
    ht.add("John","097","New York");
    ht.add("Bill","096","Los Angeles");
    ht.add("Samanta","095","Kyiv");

    cout << ht["John"] << endl;
    cout << ht["Bill"] << endl;
    cout << ht["Samanta"] << endl;

    cout << endl;
    cout << "remove Samanta:" << endl;
    ht.remove("Samanta");

    cout << ht["John"] << endl;
    cout << ht["Bill"] << endl;
    cout << ht["Samanta"] << endl;

    cout << endl << endl << "Hash table 3:" << endl;
    hash_table3 ht3;
    ht3.add("John","097","New York");
    ht3.add("Bill","096","Los Angeles");
    ht3.add("Samanta","095","Kyiv");

    cout << ht3["John"] << endl;
    cout << ht3["Bill"] << endl;
    cout << ht3["Samanta"] << endl;

    ht3.remove("John");
    ht3.add("Samanta","095","Kyiv");
    cout << endl;
    cout << "remove John and add Samanta:" << endl;

    cout << ht3["John"] << endl;
    cout << ht3["Bill"] << endl;
    cout << ht3["Samanta"] << endl;

    return 0;
}
