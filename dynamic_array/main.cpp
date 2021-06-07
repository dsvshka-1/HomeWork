#include <iostream>

#include "dynamic_array.h"

using namespace std;
int main()
{
    dynamic_array<int> v1;
    cout << v1 << endl;

    dynamic_array<int> v2(5, -14);
    cout << v2 << endl;

    dynamic_array<int> v3 = {1,2,3};
    cout << v3 << endl;

    dynamic_array<int> v4 (v2);
    v4[3] = 3;
    cout << v4 << endl;
    cout << v2 << endl;

    dynamic_array<int> v5 (dynamic_array<int> ({-1,-2,-3}));
    cout << v5 << endl;

    v5.resize(140);
    cout << v5 << endl;

    v5.push_back(777);
    cout << v5 << endl;

    v5.pop_back();
    v5.pop_back();

    cout << v5 << endl;

    return 0;
}
