#include <stdio.h>


FILE *myfile;

int main(){
    myfile = fopen("myfile.log", "w");

    fprintf(myfile, "This is a simple log");
}