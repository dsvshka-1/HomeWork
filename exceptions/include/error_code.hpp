#ifndef ERROR_CODE_HPP
#define ERROR_CODE_HPP

#include <stdio.h>

enum class error_codes{no_error, open_error, file_size_error, bad_alloc, read_error, close_error};

int error_read_file(){

    FILE* fp = nullptr;
    char* buf = nullptr;
    error_codes err_code = error_codes::no_error;

    fp = fopen("test.txt","rb"); // open file
    if (!fp) err_code = error_codes::open_error;

    while(err_code == error_codes::no_error){
        if( fseek(fp, 0L, SEEK_END) ) // seek to the end of file
        {
            err_code = error_codes::file_size_error;
            break;
        }
        size_t sz = ftell(fp);
        rewind(fp);

        buf = new (std::nothrow) char[sz]; // allocate memory
        if (!buf)
        {
            err_code = error_codes::bad_alloc;
            break;
        }

        if( fread(buf, 1, sz, fp) != sz ) // read file into buffer
        {
            err_code = error_codes::read_error;
            break;
        }
        printf("error_read_file:\n%s\n", buf);

        break;
    }

    if(err_code != error_codes::open_error)
        if( fclose(fp) ) err_code = error_codes::close_error; // close the file

    delete[] buf;
    buf = nullptr;

    return static_cast<int>(err_code);
}

#endif // ERROR_CODE_HPP
