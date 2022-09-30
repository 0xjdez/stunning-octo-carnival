#include <stdio.h>

int main(void) 
{
    char str[10];
    printf("Enter a string: ");
    // scanf("%s", str);   // scanf() doesn't store whitespace characters. String gets truncated

    fgets("%s", str, stdin);  //gets() and scanf() can't detect when character array 
                //is full. Dangerous! Buffer overflow.
    puts(str);
}