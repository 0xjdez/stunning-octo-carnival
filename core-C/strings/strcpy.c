#include <stdio.h>
#include <string.h>

/*
    * prototype: char* strcpy(char* destination, const char* source)
    * copies the content of not-midified source (use of const) to the
    * destination character array. It returns the pointer to the first
    * character to destination string (character array)
    * strcpy(dst,src) doesn't check if the character array pointed
    * to by src will fit into dst. This causes potention buffer
    * overflows.
    * 
    * strncpy(dst, src, sizeof(dst)) is a solution to the problem.
*/

// int main(void) {

//     char str1[10] = "Hello";
//     char str2[10];

//     printf("%s\n", strcpy(str2, str1));
//     printf("%s\n", str2);

//     return 0; 
// }

int main(void) {
    char str1[6] = "Hello";
    char str2[5];
    strncpy(str2, str1, sizeof(str2));  //doesn't add a NULL character to str2
    printf("%s\n", str2);   // undefined behaviour

    str2[sizeof(str2)-1] = '\0';
    printf("%s\n", str2);

    return 0;
}