#include <stdio.h>
#include <unistd.h>


// global variable
int x = 0;

int main(){
    for (int i = 0; i < 5; i++) {
        printf("x = %d @ %p\n", x, &x);
        x++;
        sleep(1);
    }
}