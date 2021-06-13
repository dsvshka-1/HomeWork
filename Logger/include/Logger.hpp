#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>
#include <ctime>
#include <fstream>

class Logger
{
    public:
        virtual ~Logger(){}
        void Log(const std::string& message){
            StartLog();
            PutLog(message);
            EndLog();
        }

    protected:
        virtual void StartLog() = 0;
        virtual void PutLog(const std::string& message) = 0;
        virtual void EndLog() = 0;
};

class ConsoleLogger final:  public Logger{
    int level;

    public:
        ConsoleLogger():level(0){}
        ~ConsoleLogger(){}
    private:
        void StartLog() override{
            std::time_t now = std::time(0);
            std::tm* timeinfo = std::localtime(&now);
            char formatted_time[20];
            std::strftime(formatted_time, 20, "%Y-%m-%d %H:%M:%S", timeinfo);

            std::cout << level << ", " << formatted_time << "\n[";
        }

        void PutLog(const std::string& message) override{
            std::cout << message ;
        }

        void EndLog() override{
            std::cout << ']' << std::endl;
        }
};

class FileLogger final:  public Logger{
    int level;
    std::ofstream file;

    public:
        FileLogger(const std::string& file_name):level(0), file(file_name){}
        ~FileLogger(){
            file.close();
        }
    private:
        void StartLog() override{
            std::time_t now = std::time(0);
            std::tm* timeinfo = std::localtime(&now);
            char formatted_time[20];
            std::strftime(formatted_time, 20, "%Y-%m-%d %H:%M:%S", timeinfo);

            file << level << ", " << formatted_time << "\n[";
        }

        void PutLog(const std::string& message) override{
            file << message ;
        }

        void EndLog() override{
            file << ']' << std::endl;
        }
};

#endif // LOGGER_H
