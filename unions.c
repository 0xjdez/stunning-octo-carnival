#include <stdio.h>
#include <stdlib.h>

typedef union my_t {
    long long num;
    unsigned char bytes[8];
} my_t;

int main(void) {
    // long long num = 17;
    my_t e;
    e.num = 17;
    e.bytes[1] = 15;
    printf("%lld\n", e.num);
    for (int i = 0; i < 8; i++) {
        printf("%02hhx ", e.bytes[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}