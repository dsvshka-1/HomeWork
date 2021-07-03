#ifndef FILE_EXCEPTION_HPP
#define FILE_EXCEPTION_HPP

#include <exception>
#include <string>

struct file_exception : public std::exception
{
    const char* message;
    public:
        file_exception(const char* what_arg = "file_exception") noexcept : message(what_arg){}
        file_exception(const std::string& what_arg) noexcept : message(what_arg.c_str()){}
        file_exception(const file_exception& o) noexcept : message(o.message){}
        file_exception& operator=(const file_exception& o) noexcept{
            message = o.message;
            return *this;
        }
        const char* what() const noexcept override{
            return message;
        }
};

struct open_error : file_exception{

    open_error(const char* what_arg = "failed to open the file") noexcept : file_exception(what_arg){}
    open_error(const std::string& what_arg) noexcept : file_exception(what_arg){}
};

struct file_size_error : file_exception{

    file_size_error(const char* what_arg = "failed to determine file size") noexcept : file_exception(what_arg){}
    file_size_error(const std::string& what_arg) noexcept : file_exception(what_arg){}
};

struct read_error : file_exception{

    read_error(const char* what_arg = "failed to read the file") noexcept : file_exception(what_arg){}
    read_error(const std::string& what_arg) noexcept : file_exception(what_arg){}
};

struct close_error : file_exception{

    close_error(const char* what_arg = "failed to close the file") noexcept : file_exception(what_arg){}
    close_error(const std::string& what_arg) noexcept : file_exception(what_arg){}
};
#endif // FILE_EXCEPTION_HPP
