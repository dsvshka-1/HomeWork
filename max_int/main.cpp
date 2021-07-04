#include <iostream>

using namespace std;

template<size_t digits>
struct max_int{
    static constexpr size_t value = max_int<digits-1>::value * 10 + 9;
};

template<>
struct max_int<0>{
    static constexpr size_t value = 0;
};

template<size_t digits>
void print_all(){
    print_all<digits-1>();
    cout << max_int<digits>::value << endl;
}

template<>
void print_all<0>(){
    cout << max_int<0>::value << endl;
}

int main()
{
    print_all<10>();
    return 0;
}
