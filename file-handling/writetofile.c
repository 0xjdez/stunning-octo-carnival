#include <stdio.h>


FILE *myfile;

int main(){
    // fopen() returns a pointer to a file (FILE*)
    myfile = fopen("myfile.log", "w+");

    fprintf(myfile, "This is a simple log\n");
    fprintf(myfile, "This is a simple log\n");
}