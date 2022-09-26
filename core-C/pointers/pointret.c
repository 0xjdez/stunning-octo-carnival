#include <stdio.h>
#include <stdlib.h>

int* add(int* a, int* b){
    int *c = (int*)malloc(sizeof(int));
    *c = (*a) + (*b);
    return c;
}


int main(void) {
    int x = 10, y = 20;

    int* z = add(&x, &y);
    printf("Sum = %d\n", *z);
}