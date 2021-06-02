#ifndef ALIGNED_FILE_H
#define ALIGNED_FILE_H

namespace HW{

    #include <stdio.h>
    #include <string.h>

    class aligned_file
    {
        static constexpr const char* sformat = "%[^,],%[^,],%f,%i\n";
        static constexpr int field_num = 4;
        static constexpr int max_len = 2048;

        static constexpr const char* succeeded_h = "Succeeded", *name_h = "Name", *surname_h = "Surname";
        static constexpr const char* avg_mark_h = "Avg mark", *attended_h = "Attended";
        static constexpr const char* ok = "    +    ", *nok = "         ";

        template<class T>
        static int digits(T num);

        FILE* sfile;
        int isError;

        char* name, *surname;
        float avg_mark;
        int attendes;

        int name_len, surname_len, avg_mark_len, attendes_len;

        aligned_file(const aligned_file& s) = delete;
        void operator=(const aligned_file&) = delete;

        void get_line();
        void put_line();

        void get_field_lens();
        void put_formated();

    public:
        aligned_file(char* source_filename);
        ~aligned_file();

        bool is_open() const;
        bool is_eof() const;
        void close();
    };

}
#endif // ALIGNED_FILE_H
