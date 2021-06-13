#ifndef CREATOR_H
#define CREATOR_H

#include "Logger.hpp"

class Creator
{
    public:
        virtual ~Creator() {}
        virtual Logger* CreateLogger() const = 0;
};

class ConsoleLoggerCreator final : public Creator{

    public:
        Logger* CreateLogger() const override { return new ConsoleLogger(); }
};

class FileLoggerCreator final : public Creator{
    std::string f_name;

    public:
        FileLoggerCreator(const std::string& file_name): f_name(file_name){}
        Logger* CreateLogger() const override { return new FileLogger(f_name); }
};

#endif // CREATOR_H
