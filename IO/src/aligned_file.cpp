#include "aligned_file.h"

namespace HW{

    aligned_file::aligned_file(char* source_filename):
        sfile(fopen(source_filename, "r")),
        isError(0),
        name(new char[max_len]), surname(new char[max_len]),
        avg_mark(0), attendes(0),
        name_len(strlen(name_h)), surname_len(strlen(surname_h)),
        avg_mark_len(strlen(avg_mark_h)), attendes_len(strlen(attended_h)){
            if ( !is_open() ) isError = 1;
            get_field_lens();
            put_formated();
            if (isError) printf("%s\n", "Something went wrong. Could not align your file");
        }

    aligned_file::~aligned_file()
    {
        delete[] name;
        delete[] surname;
        close();
    }

    void aligned_file::get_line(){
        if (fscanf(sfile, sformat, name, surname, &avg_mark, &attendes) != field_num)
            isError = 1;
    }

    template<class T>
    int aligned_file::digits(T num){
        int res(1), pow(10);
        if (num < 0) num*= -1;
        while( num >= pow){
            pow*= 10;
            ++res;
        }
        return res;
    }

    bool aligned_file::is_open() const{
        return sfile != 0;
    }

    void aligned_file::get_field_lens(){
        int new_len(0);
        while( !is_eof() ){
            if (isError) return;
            get_line();

            new_len = strlen(name);
            if( new_len > name_len ) name_len = new_len;

            new_len = strlen(surname);
            if( new_len > surname_len ) surname_len = new_len;

            new_len = digits(avg_mark);
            if( new_len > avg_mark_len ) avg_mark_len = new_len;

            new_len = digits(attendes);
            if( new_len > attendes_len ) attendes_len = new_len;
        }
    }

    void aligned_file::put_formated(){
        rewind(sfile);
        int att_fact_len = strlen(attended_h), spaces = attendes_len - att_fact_len;
        const char* space = " ";
        if( spaces > 0 ){
            ++spaces;
            spaces/= 2;
            printf("%s %-*s %-*s %*s %*s%*s\n", succeeded_h, name_len, name_h, surname_len, surname_h, avg_mark_len, avg_mark_h, att_fact_len + spaces, attended_h, spaces, space);
        } else{
            printf("%s %-*s %-*s %*s %*s\n", succeeded_h, name_len, name_h, surname_len, surname_h, avg_mark_len, avg_mark_h, attendes_len, attended_h);
        }
        while( !is_eof() ){
            if (isError) return;
            get_line();
            const char* succeeded = (avg_mark>4) && (attendes>5)?ok:nok;
            att_fact_len = digits(attendes);
            spaces = attendes_len - att_fact_len;
            if( spaces > 0 ){
                ++spaces;
                spaces/= 2;
                printf("%s %-*s %-*s %*.2f %*i%*s\n", succeeded, name_len, name, surname_len, surname, avg_mark_len, avg_mark, att_fact_len + spaces, attendes, spaces, space);
            } else{
                printf("%s %-*s %-*s %*.2f %*i\n", succeeded, name_len, name, surname_len, surname, avg_mark_len, avg_mark, attendes_len, attendes);
            }
        }
    }

    bool aligned_file::is_eof() const{
        return feof(sfile);
    }

    void aligned_file::close(){
        fclose(sfile);
    }



}
