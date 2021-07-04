#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

template<typename T>
class Logger
{
    public:
        Logger(){}
        ~Logger(){}

        template<typename... Args>
        void Log(Args&&... message){
            static_cast<T*>(this)->StartLog();
            static_cast<T*>(this)->PutLog(std::forward<Args>(message)...);
            static_cast<T*>(this)->EndLog();
        }
};

class ConsoleLogger final : public Logger<ConsoleLogger>{
    friend Logger<ConsoleLogger>;
    int level;

    public:
        ConsoleLogger():level(0){}
        ~ConsoleLogger(){}

    private:
        void StartLog(){
            std::time_t now = std::time(0);
            std::tm* timeinfo = std::localtime(&now);
            char formatted_time[20];
            std::strftime(formatted_time, 20, "%Y-%m-%d %H:%M:%S", timeinfo);

            std::cout << level << ", " << formatted_time << "\n[";
        }

        template<typename... Args>
        void PutLog(Args&&... message){
            (std::cout << ... << message);
        }

        void EndLog(){
            std::cout << "]" << std::endl;
        }
};

class FileLogger final : public Logger<FileLogger>{
    friend Logger<FileLogger>;
    int level;
    std::ofstream file;

    public:
        FileLogger(const std::string& file_name):level(0), file(file_name){}
        ~FileLogger(){
            file.close();
        }
    private:
        void StartLog(){
            std::time_t now = std::time(0);
            std::tm* timeinfo = std::localtime(&now);
            char formatted_time[20];
            std::strftime(formatted_time, 20, "%Y-%m-%d %H:%M:%S", timeinfo);

            file << level << ", " << formatted_time << "\n[";
        }

        template<typename... Args>
        void PutLog(Args&&... message){
            (file << ... << message);
        }

        void EndLog(){
            file << "]" << std::endl;
        }

};

#endif // LOGGER_HPP
