#include <stdlib.h>
#include <stdio.h>

void f(void);

int main(){
    f();
}

void f(void) {
    int *x = malloc(10 * sizeof(int)); // allocate memory for a cuntiguous chunk of ints
    x[9] = 50;
    printf("you inputted: %i.\n", x[9]);
    free(x); // free allocated memmory after use to avoid memory leaks
}