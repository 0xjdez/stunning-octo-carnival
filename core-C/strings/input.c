#include <stdio.h>

// TODO: debug, contains errors!

int input(char *str, int n)
{
    int ch, i = 0;
    while ((ch = getchar() != '\n')) {
        if (i<n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';  // null termination
    return i;   // return number of bytes read
}


int main()
{
    char str[100];
    int n = input(str, 20);
    // fprintf(stdout, "%d, %s\n", n, str);
    printf("%d %s\n", n, str);
}