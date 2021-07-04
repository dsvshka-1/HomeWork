#include "Logger.hpp"
#include "Creator.hpp"

#include <iostream>
#include <memory>

using namespace std;

int main()
{
    using C = ConsoleLogger;
    auto clCreator = std::unique_ptr<Creator<C>>(new ConsoleLoggerCreator<C>());
    auto cl = std::unique_ptr<Logger<C>>( clCreator->CreateLogger() );

    cl->Log("message1");
    cl->Log("message2");
    cl->Log("message3");
    cl->Log("big message1 ", "big message2 ", "big message3 ");

    using F = FileLogger;
    auto flCreator = std::unique_ptr<Creator<F>>(new FileLoggerCreator<F>("Log.txt"));
    auto fl = std::unique_ptr<Logger<F>>( flCreator->CreateLogger() );

    fl->Log("message1");
    fl->Log("message2");
    fl->Log("message3");
    fl->Log("big message1 ", "big message2 ", "big message3 ");

    return 0;
}
