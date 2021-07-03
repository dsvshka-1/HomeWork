#ifndef FILE_WRAPPER_HPP
#define FILE_WRAPPER_HPP

#include <fstream>
#include <string>
#include <mutex>
#include <stdexcept>
#include <iostream>
#include <chrono>
#include <thread>

class file_wrapper final
{
    std::ofstream file;
    std::mutex write_mutex;
    public:
        file_wrapper(const std::string& name): file(name), write_mutex() {
            if (!file.is_open())
                throw std::runtime_error("failed to open file " + name);
        }
        virtual ~file_wrapper() {
            file.close();
        }

        file_wrapper& operator<<(const std::string& message){

            std::lock_guard<std::mutex> lock(write_mutex);

            #ifdef DEBUG
                std::cout << "file_wrapper::operator<<(const std::string&)" << std::endl;
                // simulate a long page fetch
                std::this_thread::sleep_for(std::chrono::seconds(2));
            #endif

            file << message;
            return *this;
        }
};

#endif // FILE_WRAPPER_HPP
