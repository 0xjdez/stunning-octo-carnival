#include <stdio.h>
// #include <math.h>
#include "typedefs.h"


double a_fn(int a, int b){
    return (double)a/b;
}

double apply(a_fn_type f, int a, int b) {
    return f(a,b);
}

int main(void){
    int x = 100, y = 9;
    double result = apply(a_fn, x, y);
    printf("%g\n", result);
}