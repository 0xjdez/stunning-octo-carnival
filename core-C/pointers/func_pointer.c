#include <stdio.h>

int sum (int a, int b){
    return a + b;
}

int main(void) {
    int (*fp)(int, int);

    fp = sum;

    printf("%d\n", (*fp)(10,20));
}

