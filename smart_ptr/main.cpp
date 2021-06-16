
#include <iostream>
#include "my_unique_ptr.hpp"
#include "my_shared_ptr.hpp"

using namespace std;

void print_shp(const my_shared_ptr& shp){
    cout << "Address of shared ptr = " << shp.get() << endl;
    cout << "Shared pointer count = " << shp.use_count() << endl;
}

int main()
{
    my_unique_ptr up(new CObject());
    cout << "Address of unique ptr = " << up.get() << endl;
    // Address of unique ptr = 0xc41440
    up->print();
    // CObject.print()
    cout << *up << endl;
    // CObject{}

    my_shared_ptr shp1 (new CObject());
    print_shp(shp1);

    // Address of shared ptr = 0xc41460
    // Shared pointer count = 1

    {
        auto shp2 = shp1;
        print_shp(shp2);
        // Address of shared ptr = 0xc41460
        // Shared pointer count = 2
        print_shp(shp1);
        // Address of shared ptr = 0xc41460
        // Shared pointer count = 2
    }

    print_shp(shp1);
    // Address of shared ptr = 0xc41460
    // Shared pointer count = 1

    cout << endl;
    {
        my_shared_ptr shp2(new CObject());
        print_shp(shp2);
        // Address of shared ptr = 0xc417d0
        // Shared pointer count = 1

        shp1 = shp2;
        print_shp(shp2);
        // Address of shared ptr = 0xc417d0
        // Shared pointer count = 2
        print_shp(shp1);
        // Address of shared ptr = 0xc417d0
        // Shared pointer count = 2
    }

    print_shp(shp1);
    // Address of shared ptr = 0xc417d0
    // Shared pointer count = 1

    return 0;
}
