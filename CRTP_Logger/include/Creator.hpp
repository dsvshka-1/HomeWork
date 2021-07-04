#ifndef CREATOR_HPP
#define CREATOR_HPP

#include "Logger.hpp"

template<typename T>
class Creator
{
    public:
        virtual ~Creator() {}
        virtual Logger<T>* CreateLogger() const = 0;
};

template<typename T>
class ConsoleLoggerCreator : public Creator<T>
{
    public:
        virtual ~ConsoleLoggerCreator() {}
        virtual Logger<T>* CreateLogger() const override {return new ConsoleLogger();}
};

template<typename T>
class FileLoggerCreator : public Creator<T>
{
    std::string f_name;

    public:
        FileLoggerCreator(const std::string& file_name):f_name(file_name){}
        virtual ~FileLoggerCreator() {}
        virtual Logger<T>* CreateLogger() const override {return new FileLogger(f_name);}
};

#endif // CREATOR_HPP
