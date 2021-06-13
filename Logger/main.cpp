
#include "Logger.hpp"
#include "Creator.hpp"

#include <iostream>
#include <memory>

using namespace std;

int main()
{
    auto clCreator = std::unique_ptr<Creator>(new ConsoleLoggerCreator());
    auto cl = std::unique_ptr<Logger>(clCreator->CreateLogger());

    cl->Log("message1");
    cl->Log("message2");
    cl->Log("message3");

    auto flCreator = std::unique_ptr<Creator>(new FileLoggerCreator("Log.txt"));
    auto fl = std::unique_ptr<Logger>(flCreator->CreateLogger());

    fl->Log("message1");
    fl->Log("message2");
    fl->Log("message3");

    return 0;
}
