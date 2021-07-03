#include <iostream>
#include "file_wrapper.hpp"

using namespace std;
file_wrapper fw("test.txt");

void put_message(const std::string& message){
    fw << message;
}

int main()
{
    std::thread t1(put_message, "message1\n");
    std::thread t2(put_message, "message2\n");
    t1.join();
    t2.join();

    return 0;
}
