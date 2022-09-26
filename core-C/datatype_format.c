#include <stdio.h>
// #include 


int main(int argc, char *argv[]) {

    unsigned int ui = 0;
    signed int i = 0;

    printf("%u\n", ui-1);   //prints MAX_INT
    printf("%d\n", i-1);

    unsigned long ul = 0;

    printf("%lu\n", ul-1);
    printf("%lx\n", ul-1);  //prints hex format -> ffffffffffffffff

    return 0;
}