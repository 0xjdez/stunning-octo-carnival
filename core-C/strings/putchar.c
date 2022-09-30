#include <stdio.h>  // for putchar

/*
    * putchar accepts an integer argument (which
    * represents the ascii equivalent it wants to
    * display) and returns an interger representing
    * the character written to the output stream

*/

int main(void)
{
    int ch;
    for (ch = 'A'; ch <= 'Z'; ch++) {
        putchar(ch);
        putchar('\t');
    }
    putchar('\n');
    return 0;
}