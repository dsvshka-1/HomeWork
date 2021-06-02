
#include "aligned_file.h"
#include "stdio.h"

using namespace std;
using namespace HW;

int main(int argc, char** argv)
{    
    if (argc < 2){
        printf("%s\n","Please specify CSV file");
        return 0;
    }
    aligned_file f(argv[1]);
    return 0;
}
