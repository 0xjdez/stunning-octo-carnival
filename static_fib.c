#include <stdio.h>
#include <stdint.h>

uint64_t fib(){
    static uint64_t first = 0;
    static uint64_t second = 1;
    uint64_t out = first + second;
    first = second;
    second = out;
    return out;
}


int main(void){
    for (size_t i = 0; i < 100; i++) {
        printf("%zu\n", fib());
    }
}