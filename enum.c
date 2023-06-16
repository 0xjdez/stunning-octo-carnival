#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
* enums are better than for their use case
* since they identify variables which can 
* help greatly in debugging
*/

enum colour_t {
    RED = 7,
    BLUE,
    YELLOW
};

int main(void) {
    enum colour_t color = RED;
    printf("colour value: %d\n", color);
    return EXIT_SUCCESS;
}