
#include <iostream>
#include "my_unique_ptr.hpp"
#include "my_shared_ptr.hpp"

using namespace std;

void print(my_unique_ptr& up){
    cout << "Address of unique ptr = " << up.get() << endl << endl;
}

void print(my_shared_ptr& shp){
    cout << "Address of shared ptr = " << shp.get() << endl;
    cout << "Shared pointer count = " << shp.use_count() << endl << endl;
}

int main()
{
    {
        cout << "unique_ptr: move c-tor" << endl;
        auto up1 = my_unique_ptr(new CObject());
        print(up1);

        cout << "unique_ptr: move assign" << endl;
        up1 = my_unique_ptr(new CObject());
        print(up1);

        cout << "unique_ptr: default c-tor" << endl;
        up1 = my_unique_ptr();
        print(up1);
    }

    cout << endl;
    {
        cout << "shared_ptr: move c-tor" << endl;
        auto shp1 = my_shared_ptr(new CObject());
        print(shp1);

        {
            cout << "shared_ptr: copy c-tor" << endl;
            auto shp2 = shp1;
            print(shp1);
        }
        print(shp1);

        {
            cout << "shared_ptr: default c-tor" << endl;
            my_shared_ptr shp2;
            print(shp2);

            cout << "copy assign" << endl;
            shp2 = shp1;
            print(shp1);
        }
        print(shp1);

        {
            cout << "shared_ptr: working with nullptr" << endl;
            my_shared_ptr shp2;
            shp1 = shp2;
            print(shp1);
        }
        print(shp1);

        cout << "shared_ptr: move assign" << endl;
        shp1 = my_shared_ptr(new CObject());
        print(shp1);
    }

    return 0;
}
