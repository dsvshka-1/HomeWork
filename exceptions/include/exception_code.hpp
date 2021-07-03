#ifndef EXCEPTION_CODE_HPP
#define EXCEPTION_CODE_HPP

#include <stdio.h>
#include "file_exception.hpp"
#include <iostream>

void exception_read_file(){

    FILE* fp = nullptr;
    int close_status = 0;
    char* buf = nullptr;

    try{
        fp = fopen("test.txt","rb"); // open file
        if (!fp) throw open_error();

        if( fseek(fp, 0L, SEEK_END) ) throw file_size_error(); // seek to the end of file
        size_t sz = ftell(fp);
        rewind(fp);

        buf = new (std::nothrow) char[sz]; // allocate memory
        if (!buf) throw std::bad_alloc();

        if( fread(buf, 1, sz, fp) != sz ) throw read_error(); // read file into buffer
        printf("exception_read_file:\n%s\n", buf);

        close_status = fclose(fp);
        if( close_status ) throw close_error(); // close the file

        delete[] buf;

    } catch (open_error& e){
        throw e;
    } catch (file_size_error& e){
        close_status = fclose(fp);
        throw e;
    } catch (std::bad_alloc& e){
        close_status = fclose(fp);
        throw e;
    } catch (read_error& e){
        close_status = fclose(fp);
        delete[] buf;
        buf = nullptr;
        throw e;
    } catch (close_error& e){
        delete[] buf;
        buf = nullptr;
        throw e;
    }

    if ( close_status ) throw close_error();

}

#endif // EXCEPTION_CODE_HPP
