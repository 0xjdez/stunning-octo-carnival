#include <stdio.h>

int main(void){
    int a, b, *p;
    p = &a;
    p++;

    if (p == &b) {
        printf("%p == %p\n", p, &b);
    } else {
        printf("%p != %p\n", p, &b);
    }
}