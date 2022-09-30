#include <stdio.h>
#include <string.h>

/*
    * prototype: size_t strlen(sont char *str)
    * doesn't count null character
*/


int main(void)
{
    char *str = "Hello World";
    printf("%ld\n", strlen(str));   // 11

    char str1[] = "Hello World";
    printf("%ld\n", strlen(str1));  // 11

    char str2[100] = "Hello World";
    printf("%ld\n", strlen(str2));  // 11  
    return 0;
}