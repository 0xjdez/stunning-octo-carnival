#include <stdio.h>

void print_hello(char *name){
    printf("Hello, %s\n", name);
}

int main(void) {
    void (*ptr)(char*);
    ptr = print_hello;

    (*ptr)("Jimrox Odezi");
}