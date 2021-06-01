#include <iostream>
#include "calculator.h"

using namespace std;


int main()
{
    while(1){
        char text[1024];
        cout << "enter expression:" << endl;
        cin >> text;
        double res = calculator::calculate(text);
        cout << res << endl;
    }

    return 0;
}
