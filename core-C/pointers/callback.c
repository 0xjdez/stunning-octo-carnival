#include <stdio.h>

void a(){
    printf("Hello\n");
}

void b(void (*ptr)()){
    ptr();  // call back function that ptr points to
}

int main(void){
    void (*p)();
    p = a;
    b(p);
    // b(a);
}